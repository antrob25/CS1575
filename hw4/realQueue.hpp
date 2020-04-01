using namespace std;

int customer::getWant()
{
	return m_want;
}

void customer::eatPopplers( int boxNum, randomEngine & rEng)
{
	int dice;
    for ( int i = 0; i < boxNum; i++)
    {
		m_want--;
		m_eaten++;
        dice = rEng.rollD(6);
        if ( dice == 6 )
            m_want++;
    }
	return;
}

realQueue::realQueue(int s, const customer & x)
{
	m_size = s;
	m_max = s;
	for (int i = 0; i < m_size; i++) 
		customers[i] = x;
}

realQueue::~realQueue()
{
	m_size = 0;
	m_max = 0;
	delete [] customers;
	customers = NULL;
}

bool realQueue::isEmpty() const
{
    return ( m_size == 0? true: false );
}

void realQueue::grow()
{
	customer* tmp;
	if (m_max == 0)  
	{
		tmp = new customer[1];
		customers = tmp;
		m_max++;
	}
	else
	{
		tmp = new customer[m_max * 2];

		for (int j = 0; j < m_size; j++)  
			tmp[j] = customers[j];

		delete[]customers;
		customers = tmp;
		m_max *= 2;
	}
	return;
}

realQueue& realQueue::operator=(const realQueue & rhs)
{
	if (this != &rhs)  
	{  
		if (m_size == m_max)   
		{
			while (m_max < rhs.m_max)  
				realQueue::grow();
		}

		for (int i = 0; i < rhs.m_size; i++)  
			customers[i] = rhs.customers[i];

		m_size = rhs.m_size;
	}
	return *this;
}

void realQueue::enqueue(const customer & x)
{
    if (m_size == m_max)  
		realQueue::grow();

	customers[m_size] = x;
	m_size++;
	return;
}

void realQueue::dequeue()
{
    if ( m_size > 0 )  
	{
		for (int k = 0; k < m_size; k++)
			customers[k] = customers[k + 1];
		m_size--;
	}
	return;
}

const customer & realQueue::front() const throw (Oops)
{
	Oops oops("Customer cannot be found!");
    if ( m_size == 0 ) throw oops;

	else 
        return customers[0];    
}

customer & realQueue::find( int x ) throw (Oops)
{
	Oops oops("Customer cannot be found!");
	if ( m_size == 0 ) throw oops;

	else
        return customers[x];  
}

const customer & realQueue::back() const throw (Oops) 
{
	Oops oops("Customer cannot be found!");
    if ( m_size == 0 )  throw oops;

	else
	{
		for (int k = 0; k < m_size; k++) 
        {
			if ( k == (m_size-1) )
                return customers[k];
        }
	}
}

void realQueue::clear()
{
	delete []customers;
	customers = NULL;
	m_size = 0;
	m_max = 0;
	return;
}

