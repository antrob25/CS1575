// Programmer: Anthony Robles    section: cs1575 a

#include <iostream>
#include <string>
using namespace std;

template < typename T >
MyBSTree<T>::~MyBSTree()
{
    clear();
}

template < typename T >
const MyBSTree<T>& MyBSTree<T>::operator= ( const MyBSTree<T>& rhs )
{
    if ( this != &rhs )
    {
        clear();
        clone( rhs.m_root );
    }
    return *this;
}

template < typename T >
MyBSTree<T>::MyBSTree( const MyBSTree<T>& copy )
{
    *this = copy;
}

template < typename T >
const T& MyBSTree<T>::recursive_getMin( TreeNode<T>* t ) const 
{
    if ( t->m_left == NULL )
        return t->m_data;
    else
        return recursive_getMin( t->m_left );    
}

template < typename T >
const T& MyBSTree<T>::recursive_getMax( TreeNode<T>* t ) const
{
    if ( t->m_right == NULL )
        return t->m_data;
    else 
        return recursive_getMax( t->m_right );    
}

template < typename T >
int MyBSTree<T>::recursive_find( TreeNode<T>* t, const T& x, int level ) const
{
    if ( t == NULL )
        return -level;
    if ( t->m_data == x )
        return level;
    else if ( x < t->m_data )
    {
        level++;
        return recursive_find( t->m_left, x, level );
    }    
    else 
    {
        level++;
        return recursive_find( t->m_right, x, level ); 
    }   
}

template < typename T >
TreeNode<T>*  MyBSTree<T>::recursive_insert( TreeNode<T>* t, const T& x ) 
{
    if ( t == NULL )
    {
        return new TreeNode<T>( x, NULL, NULL);
        m_size++;
    }

    if ( x < t->m_data )
        t->m_left = recursive_insert( t->m_left, x );
    else if ( x > t->m_data )
        t->m_right = recursive_insert( t->m_right, x );  
    return t;         
}

template < typename T >
void MyBSTree<T>::recursive_remove( TreeNode<T>* t, const T& x ) 
{
    if ( x < t->m_data )
        recursive_remove( t->m_left, x );

    else if ( x > t->m_data )
        recursive_remove( t->m_right, x );

    else if ( t->m_left == NULL && t->m_right == NULL )
    {
        delete t;
        t = NULL;
        m_size--;
    } 

    else if ( t->m_left == NULL || t->m_right == NULL )
    {
        TreeNode<T>* child = t->m_left;
        if ( child == NULL )
            child = t->m_right;
        delete t;
        t = child;
        m_size--;    
    }

    else 
    {
        t->m_data = recursive_getMax( t->m_left );
        recursive_remove( t->m_left, t->m_data );
    }
}

template < typename T >
void MyBSTree<T>::recursive_print( const TreeNode<T>* t ) const
{
    if ( t == NULL )
        cout << endl;
    else 
    {
        recursive_print( t->m_right );
        cout << "    " << t->m_data << endl;
        recursive_print( t->m_left );
    }    
}

template < typename T >
void MyBSTree<T>::recursive_destructor( TreeNode<T>* t ) 
{
    recursive_destructor( t->m_left );
    recursive_destructor( t->m_right );
    delete t;
}

template < typename T >
int MyBSTree<T>::recursive_height( TreeNode<T>* t, int h ) const
{
    if ( t == NULL )
        return h;
    else
    {
        h++;
        recursive_height( t->m_right, h );
        recursive_height( t->m_left, h );
        return h;
    } 
}

template < typename T >
void MyBSTree<T>::recursive_preorder( TreeNode<T>* t ) const
{
    cout << t->m_data;
    recursive_preorder( t->m_left );
    recursive_preorder( t->m_right );
}

template < typename T >
void MyBSTree<T>::recursive_postorder( TreeNode<T>* t ) const
{
    recursive_postorder( t->m_left );
    recursive_postorder( t->m_right );
    cout << t->m_data;
}

template < typename T >
int MyBSTree<T>::size() const 
{
    return m_size;
}

template < typename T >
bool MyBSTree<T>::isEmpty() const 
{
    return ( m_size == 0? true: false );
}

template < typename T >
int MyBSTree<T>::height() const 
{
    int h = 0;
    if ( isEmpty() == true )
        return h;
    else 
        return recursive_height( m_root, h );
}

template < typename T >
const T& MyBSTree<T>::getMax() const throw (Oops) 
{   
    Oops oops( "The tree is empty!" );
    if ( isEmpty() == true )
        throw oops;
    else     
        return recursive_getMax( m_root );
}

template < typename T >
const T& MyBSTree<T>::getMin() const throw (Oops) 
{
    Oops oops( "The tree is empty!" );
    if ( isEmpty() == true )
        throw oops;
    else     
        return recursive_getMin( m_root );
}

template < typename T >
int MyBSTree<T>::find( const T& x ) const 
{
    int level = 1;
    if ( isEmpty() == true )
        return 0;
    else     
        return recursive_find( m_root, x, level );
}

template < typename T >
void MyBSTree<T>::clear() 
{
    if ( isEmpty() == false )
        return;
    else 
    {
        recursive_destructor( m_root );
        m_size = 0;
    }    
}

template < typename T >
void MyBSTree<T>::insert(const T& x) 
{
    if ( m_root == NULL )
    {
        m_root = new TreeNode<T>( x, NULL, NULL );
        m_size++;
    }    
    else    
        recursive_insert( m_root, x );
}

template < typename T >
void MyBSTree<T>::remove(const T& x) 
{
    if ( isEmpty() == true )
        return;
    else 
        recursive_remove( m_root, x );    
}

template < typename T >
void MyBSTree<T>::print() const 
{
    if ( isEmpty() == true )
        return;
    else 
        recursive_print( m_root );    
}

template < typename T >
void MyBSTree<T>::printPreOrder() const 
{
    if ( isEmpty() == true )
        return;
    else 
        recursive_preorder( m_root );
}

template < typename T >
void MyBSTree<T>::printPostOrder() const 
{
    if ( isEmpty() == true )
        return;
    else 
        recursive_postorder( m_root );
}

template < typename T >
TreeNode<T>* MyBSTree<T>::clone( const TreeNode<T>* t )
{
    if ( t == NULL )
        return NULL;
    else
        return new TreeNode<T>( t->m_data, clone(t->m_left), clone(t->m_right) );
}

template < typename T >
void MyBSTree<T>::recursive_operator( TreeNode<T>* t )
{
    insert( t->m_data );
    if ( t->m_left != NULL)
        recursive_operator( t->m_left );
    if (  t->m_right != NULL )    
        recursive_operator( t->m_right );
}