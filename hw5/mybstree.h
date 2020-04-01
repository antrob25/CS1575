// Programmer: Anthony Robles    section: cs1575 a

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include <iostream>
#include "abstractbstree.h"

using namespace std;

template < typename T >
class TreeNode
{
    public:
        T m_data;
        TreeNode* m_left;
        TreeNode* m_right;
        TreeNode( T data, TreeNode* left, TreeNode* right ) : m_data( data ), m_left( left ), m_right( right ) {}
};

template < typename T >
class MyBSTree : public AbstractBSTree<T>
{
    TreeNode<T>* m_root;
    int m_size;

    const T& recursive_getMin( TreeNode<T>* t ) const;

    const T& recursive_getMax( TreeNode<T>* t ) const;

    int recursive_find( TreeNode<T>* t, const T& x, int level ) const;

    TreeNode<T>* recursive_insert( TreeNode<T>* t, const T& x );

    void recursive_remove( TreeNode<T>* t, const T& x );

    void recursive_print( const TreeNode<T>* t ) const;

    void recursive_destructor( TreeNode<T>* t );

    int recursive_height( TreeNode<T>* t, int h ) const;

    void recursive_preorder( TreeNode<T>* t ) const;

    void recursive_postorder( TreeNode<T>* t ) const;

    void recursive_operator( TreeNode<T>* t );

    public:
        MyBSTree() : m_root( NULL ), m_size( 0 ) {}

        ~MyBSTree();

        const MyBSTree<T>& operator= ( const MyBSTree<T>& rhs );

        MyBSTree( const MyBSTree<T>& copy );

        int size() const;

        bool isEmpty() const;

        int height() const;

        const T& getMax() const throw (Oops);

        const T& getMin() const throw (Oops); 

        int find(const T& x) const;

        void clear();

        void insert(const T& x);

        void remove(const T& x);

        void printPreOrder() const;

        void printPostOrder() const;

        void print() const;

        TreeNode<T>* clone( const TreeNode<T>* t ); 
};

#include "mybstree.hpp"

#endif