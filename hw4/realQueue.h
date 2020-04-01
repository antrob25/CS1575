#ifndef REALQUEUE_H
#define REALQUEUE_H

#include <string>
#include "abstractqueue.h"
#include <iostream>

using namespace std;

struct customer
{
    string m_name;
    int m_want, m_eaten;

    customer() : m_name(""), m_want(0), m_eaten(0) {}
    customer( string name, int number, int eaten ) : m_name(name), m_want(number), m_eaten(eaten) {}
    int getWant();
    void eatPopplers( int boxNum, randomEngine & rEng );

};

class realQueue : public AbstractQueue<customer>
{
    int m_size;
    int m_max;
    customer * customers;
    void grow();
    void shrink();

    public:
        realQueue() : m_size(0), m_max(0), customers(NULL) {};
        realQueue(int s, const customer & x);
        ~realQueue();
        realQueue& operator=(const realQueue & rhs);
        bool isEmpty() const;
        void enqueue(const customer & x);
        void dequeue();
        const customer& front() const throw (Oops);
        const customer& back() const throw (Oops);
        customer & find( int x ) throw (Oops);
        void clear();
        int size() { return m_size; }
        customer customerNum( int num ) { return customers[ num ]; }
        friend ostream & operator<<( ostream & out, const realQueue & q );
        friend ostream & operator<<( ostream & out, const customer & c );

};

ostream & operator<<( ostream & out, const customer & c )
{
  if ( c.m_want == 0 )
    return out << c.m_name << " eats " << c.m_eaten << " popplers. " << c.m_name << " is satisfied after eating " << c.m_eaten << " popplers." << endl;  
  else
    return out << c.m_name << " eats " << c.m_eaten << " popplers. " << c.m_name << " wants " << c.m_want << " more poppler!" << endl;  
}

ostream & operator<< ( ostream & out, const realQueue & q )
{
  for (int i = 0; i < q.m_size; i++)
    out << q.customers[i] << endl;
  return out;
}

#include "realQueue.hpp"
#endif