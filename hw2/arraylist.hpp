//  Programmer: Anthony Robles           Section: 1575 a

using namespace std;

template <typename T>
ArrayList<T>::ArrayList(int s, const T& x)
{
	m_size = s;
	for (int i = 0; i <= m_size; i++) // fills the array with the value of x
		m_data[i] = x;
}

template <typename T>
ArrayList<T>::~ArrayList<T>()
{
	m_size = 0;
	m_max = 0;
	delete []m_data;
	m_data = NULL;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
	if (this != &rhs)  // alias test
	{  
		if (m_size == m_max)   // checks if the array is full
		{
			while (m_max < rhs.m_max)  // grows until m_max == rhs.m_max
				ArrayList<T>::grow();
		}

		for (int i = 0; i < rhs.m_size; i++)  // fills the array
			m_data[i] = rhs.m_data[i];

		m_size = rhs.m_size;
	}
	return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
	m_data = new T[rhs.m_size];  // assigns an array with the m_size of cpy
	*this = cpy;
}

template <typename T>
void ArrayList<T>::grow()
{
	T* tmp;
	if (m_max == 0)  // checks if the array is empty
	{
		tmp = new T[1];
		m_data = tmp;
		m_max = 1;
	}
	else
	{
		tmp = new T[m_max * 2];

		for (int j = 0; j < m_size; j++)  // fills the array
			tmp[j] = m_data[j];

		delete[]m_data;
		m_data = tmp;
		m_max *= 2;
	}
	return;
}

template <typename T>
void ArrayList<T>::shrink()
{
	if (m_max == 0)
		return;
	else 
	{
		T* tmp;
		tmp = new T[m_max / 2];

		for (int j = 0; j < m_size; j++)  // fills the array
			tmp[j] = m_data[j];

		delete[]m_data;
		m_data = tmp;
		m_max /= 2;
		return;
	}
}


template <typename T>
int ArrayList<T>::size() const
{
	return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
	if (m_size > 0)
		return m_data[0];
	else
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST.first!! (List is empty)"
			 << endl;
		return m_errobj;
	}
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
	if (i > m_size) 
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST.[]!! (Index out of bounds)"
			 << endl;
		return m_errobj;
	}
	else
		return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
	if (i > m_size)
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST.[]!! (Index out of bounds)"
			 << endl;
		return m_errobj;
	}
	else
		return m_data[i];
}

template <typename T>
int ArrayList<T>::find(const T& x) const
{
	int i = 0;
	bool found = false;

	while (i < m_size && found == false)  // searches array for x
	{
		if (m_data[i] == x)
			found = true;
		else
			i++;
	};

	if (found == true)
		return i;
	else
		return -1;
}

template <typename T>
void ArrayList<T>::clear()
{
	delete []m_data;
	m_data = NULL;
	m_size = 0;
	m_max = 0;
	return;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
	if (m_size == m_max)  // checks if the array is full
		ArrayList<T>::grow();

	m_data[m_size] = x;
	m_size++;
	return;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
	if (i <= m_size)  // checks if i is a valid input
	{
		if (m_size == m_max)  // checks if the array is full
			ArrayList<T>::grow();

		for (int k = m_size; k > i; k--)  // fills the array
			m_data[k] = m_data[k - 1];

		m_data[i] = x;
		m_size++;
	}
	else
	{
		cout <<"!--ERROR : PANIC in ARRAYLIST!!.insert() (Index out of bounds)"
			 << endl;
	}
	return;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
	if (i < m_size && m_size > 0)  // checks if i is a valid input
	{
		if (m_size < (m_max / 4))  // checks if the array can be shrunk
		{
			ArrayList<T>::shrink();

			for (int k = i; k < (m_size - 1); k++)  // fills the array
				m_data[k] = m_data[k + 1];

			m_size--;
		}
		else 
		{
			for (int k = i; k < m_size; k++)  // fills the array
				m_data[k] = m_data[k + 1];

			m_size--;
		}
	}
	else
	{
		cout <<"!--ERROR : PANIC in ARRAYLIST!!.remove() (Index out of bounds)"
			 << endl;
	}
	return;
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
	if (i <= m_size && k <= m_size)  // checks if i is a valid input
	{
		T tmp;
		tmp = m_data[i];
		m_data[i] = m_data[k];
		m_data[k] = tmp;
	}
	else
	{
		cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap() (Index out of bounds)"
			 << endl;
	}
	return;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
	if ((alist.m_size + m_size) > m_max)  // checks if the array needs to grow
		ArrayList<T>::grow();

	int c = 0;
	for (int k = m_size; k <= m_max; k++)  // fills the array
	{
		m_data[k] = alist.m_data[c];
		c++;
	}

	m_size += alist.m_size;
	return;
}

template <typename T>
void ArrayList<T>::reverse()
{
	T* tmp = new T[m_size];

	for (int i = 0; i <= m_size; i++)  // fills the array
		tmp[i] = m_data[(m_size-1)-i];

	delete[]m_data;
	m_data = tmp;
	return;
}