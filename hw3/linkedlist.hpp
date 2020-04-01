// Programmer: Anthony Robles        Section: 1575 A

template <typename T>                 
LinkedList<T>::LinkedList()
{
    m_head = NULL;
    m_back = NULL;
    m_size = 0;
}

template <typename T>                 
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>                 
const LinkedList<T>&  LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
    clear();
    LLNode<T>* tmp = rhs.m_head;
    while ( tmp != NULL )
    {
        insert_back(tmp->m_data);
        tmp = tmp->m_next;
    }
    return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
    m_head = NULL;
    m_back = NULL;
    m_size = 0;
    *this = rhs;
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
    if (m_size != 0 )
    {
        LLNode<T>* tmp = new LLNode<T>( x, m_head );
        m_head = tmp;
        m_size++;
    }

    else 
    {
        LLNode<T>* tmp = new LLNode<T>( x, NULL );
        m_back = m_head = tmp;
        m_size++;
    }
}

template <typename T>
int LinkedList<T>::size() const
{
    return m_size;
}


template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return ((m_size == 0)? true: false);
}

template <typename T>
LLNode<T>* LinkedList<T>::getFirstPtr()
{
    return ((m_size != 0)? m_head: NULL);
}

template <typename T>
const LLNode<T>* LinkedList<T>::getFirstPtr() const
{
    return ((m_size != 0)? m_head: NULL);
}

template <typename T>
LLNode<T>* LinkedList<T>::getLastPtr()
{
    return ((m_size != 0)? m_back: NULL);
}

template <typename T>
LLNode<T>* LinkedList<T>::getAtPtr(int i) 
{
    LLNode<T>* p = m_head;

    if ( m_size != 0 && i < m_size)
    {
        int k = 0;
        while( k < i && p->m_next != NULL )
        {
            p = p->m_next;
            k++;
        }
        return p; 
    }    
    return NULL;
}

template <typename T>
void LinkedList<T>::clear()
{
    int k = m_size;
    for ( int i = 0; i < k; i++ )
    {
        remove_front();
    }
}

template <typename T>
void LinkedList<T>::insert_back(const T& x)
{     
    LLNode<T>* tmp = new LLNode<T>( x, NULL );
    if ( m_head == NULL )
    {
        m_head = tmp;
        m_back = tmp;
        m_size++;
    }  

    else
    {
        m_back->m_next = tmp;
        m_back = tmp;
        m_size++;
    }
}

template <typename T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos)
{
    if ( pos == m_back)
    {
        insert_back(x);
    }
    else if ( pos == m_head )
    {
        insert_front(x);
    }
    
    else
    {
        LLNode<T>* tmp = new LLNode<T>(x, pos);
        LLNode<T>* p = m_head;

        if ( m_size != 0 )
        {
            int k = 0;

            while( p->m_next != pos && k < m_size )
            {
                p = p->m_next;
                k++;
            }

            p->m_next = tmp;
            m_size++;
        }    
    }
}

template <typename T>
void LinkedList<T>::remove_front()
{
    if ( m_size > 1 )
    {
        LLNode<T>* tmp = m_head;
        m_head = m_head->m_next;
        m_size--;
        delete tmp;
    }    

    else if ( m_size == 1 )
    {
        delete m_head;
        m_back = NULL;
        m_head = NULL;
        m_size--;
    }
}

template <typename T>
void LinkedList<T>::remove_back()
{
    if ( m_size > 1 )
    {
        LLNode<T>* tmp = m_head;
        LLNode<T>* tmp2;

        while ( tmp->m_next != NULL )
        {
            tmp2 = tmp;
            tmp = tmp->m_next;
        }

        m_back = tmp2;
        tmp2->m_next = NULL;
        m_size--;
        delete tmp;
    }

    else if ( m_size == 1 )
    {
        delete m_back;
        m_back = NULL;
        m_head = NULL;
        m_size--;
    }    
}

template <typename T>
void LinkedList<T>::remove(LLNode<T>* pos)
{
    if ( m_size > 1 )
    {
        LLNode<T>* tmp = m_head;
        int i = 0;

        while ( i < m_size && tmp->m_next != pos )
        {
            tmp = tmp->m_next;
            i++;
        }

        tmp->m_next = pos->m_next;
        delete pos;
        pos = NULL;
        m_size--;
    } 

    else if ( m_size == 1 )
    {
        delete m_head;
        m_back = NULL;
        m_head = NULL;
        m_size--;
    }
}

template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
    LLNode<T>* tmp = m_head;
    LLNode<T>* tmp1 = rhs.m_head;
    int i = 0;
    int cnt = 0;

    while( i < m_size )
    {
        if ( tmp->m_data == tmp1->m_data )
        {
            cnt++;
        }    
        tmp = tmp->m_next;
        tmp1 = tmp1->m_next;
        i++;
    }
    return ((cnt == m_size)? true: false);
}

template <typename T>
LLNode<T>* LinkedList<T>::find(const T& x)
{
    LLNode<T>* p = m_head;
    int k = 0;

    if ( m_size != 0 )
    {
        while( p->m_data != x && k < m_size && p->m_next != NULL)
        {
            p = p->m_next;
            k++;
        }
    }    

    return ((p != NULL)? p: NULL);
}

template <typename T>
void LinkedList<T>::reverse()
{
    int cnt = m_size;
    for (int i = (cnt-2); i >= 0 ; i--)
    {
        insert(getAtPtr(i)->m_data, m_back);
    }

    for (int i = 0; i < (cnt-1); i++)
    {
        remove_front();
    }
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
    LinkedList<T> tmp = xlist;
    for ( int i = 0; i < tmp.m_size; i++ )
    {
        insert_back(tmp.getAtPtr(i)->m_data);
    }
}

template <typename T>
void LinkedList<T>::clip(LLNode<T>* start, LLNode<T>* stop)
{
    LLNode<T>* tmp = start;
    LLNode<T>* tmp2;
    while ( tmp != stop->m_next )
    {
        tmp2 = tmp->m_next;
        remove(tmp);
        tmp = tmp2;
    }
}

template <typename T>
void LinkedList<T>::slice( const LinkedList<T>& xlist, LLNode<T>* start, LLNode<T>* stop)
{
    
    clear();
    const LLNode<T>* tmp = xlist.getFirstPtr();

    while(tmp != start) 
    {
        tmp = tmp->m_next;
    }

    while(tmp != stop) 
    {
        insert_back(tmp->m_data);
        tmp = tmp->m_next;
    }

    insert_back(tmp->m_data);
}

template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
    const LLNode<T>* tmp = list.getFirstPtr();

    out << "[ ";
    for ( int i = 0; i < list.size(); i++ )
    {
        out << tmp->m_data << ", ";
        tmp = tmp->m_next;
    }
    out << " ]";

    return out;
}
