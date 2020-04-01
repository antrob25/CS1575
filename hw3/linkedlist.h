/* @file: linkedlist.h
 * Definition of templated class LinkedList
 * Implementation of List A.D.T.
 * @C - Galaxy Express Software
 *
 * Version 19.3
 */

/* __________________
  /                  \
  | LinkedList Class |
  \__________________/

    Purpose: Implements a List ADT using a dynamically allocated
        linked list to store the elements of the list.

    Design: This linked list implementation is designed as an "Encapsulated"
        Linked list. With 2 classes, a "Node" class to store data and a
        "LinkedList" class to encampsulate. The "LinkedList" class has two
        pointers, one to the head of the list and one to the tail.
        This is a VERY POINTER HAPPY design...   :-)

    Error Handling: Whenever a function is given invalid parameter values
        the list should remain unchanged.
        If such function returns a value this value is specified in the
        function description.

*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// --------------- Class Node ---------------
template <class T>
class LLNode
{
public:
  T m_data;              // Data to be stored
  LLNode<T>* m_next;     // Pointer to the next element in the list


  // Purpose: Default constructor
  // Postconditions: next pointer set to NULL
  // ---INLINE---
  LLNode() : m_next(NULL) {}

  // Purpose: Auxiliaty constructor, construct from parameters
  // Postconditions: data and next pointer set to parameters
  // ---INLINE---
  LLNode(const T& x, LLNode<T>* p) 
             : m_data(x), m_next(p) {}

};


// --------------- Class LinkedList ---------------
template <class T>
class LinkedList
{

  LLNode<T>* m_head;     // Pointer to the first element
  LLNode<T>* m_back;     // Pointer to the last element
  int m_size;           // The number of elements in the list

public:

  // Purpose: Default constructor
  // Postconditions: this list represents the empty list
  LinkedList();


  // -------------
  // --------- Big 3 Member Functions ---
  // -------------

  // Purpose: Destructor
  ~LinkedList();

  // Purpose: performs a deep copy of the data from rhs into this linkedlist
  // Parameters: rhs is linked list to be copied
  // Returns: *this
  // Postconditions: this list contains same data values (in the same order)
  //     as are in rhs; any memory previously used by this list has been
  //     deallocated.
  const LinkedList<T>&  operator= (const LinkedList<T>& rhs);

  // Purpose: copy constructor
  // Parameters: rhs is the LinkedList that is to be copied
  // Postconditions: this list contains same data values (in same order) 
  //      as in rhs.
  LinkedList(const LinkedList<T>& rhs);
  
  

  // -------------
  // --------- Basic Accessor Operations ---
  // -------------

  // Purpose: accessor function to the size the list
  // Returns: current size of the list
  int size() const;

  // Purpose: determines whether the list is empty
  // Returns: 'true' if list is empty; 'false' otherwise
  bool isEmpty() const;

  // Purpose: Get a pointer to the first element node
  // Returns: pointer to the first node in the list; 
  //     returns NULL if the list is empty
  LLNode<T>* getFirstPtr();

  // Purpose: Get a pointer to constant to the first element node
  // Returns: pointer to constant to the first node in the list;
  //     returns NULL if the list is empty
  const LLNode<T>* getFirstPtr() const;

  // Purpose: accessor function for last element node
  // Returns: pointer to the last element's node in the list; 
  //     returns NULL if list is empty
  LLNode<T>* getLastPtr();

  // Purpose: accessor function for a node in the list
  // Returns: pointer to the node at the i'th position in the list;
  //          counting starts from '0' .
  //     returns NULL if no such element exists.
  LLNode<T>* getAtPtr(int i);



  // -------------
  // --------- Basic Mutator Operations ---
  // -------------

  // Purpose: effectively "empties" the list, 
  //          Turn the list into an empty list.
  // Postconditions: ALL dynamically allocated memory for elements is
  //.                deallocated
  void clear();

  // Purpose: insert element x in the front of the list 
  // Parameters: x is data value to inserted
  // Postconditions: x is the first element of the list
  void insert_front(const T& x);

  // Purpose: insert element x in the back of the list 
  // Parameters: x is data value to inserted
  // Postconditions: x is the last element of the list
  void insert_back(const T& x);

  // Purpose: puts the data value x at the position pointed by pos
  // Parameters: x is data value to inserted
  //     pos pointer to the position to insert x at.
  // Preconditions: pos is a pointer to a node in this list.
  // Postconditions: x is inserted at the position pointed by pos
  void insert(const T& x, LLNode<T>* pos);


  // Purpose: remove the element in the front of the list 
  // Postconditions: the first element of the list is removed
  void remove_front();

  // Purpose: removes the element at the back of the list 
  // Postconditions: the last element of the list is removed
  void remove_back();

  // Purpose: remove the element in the position pointed by pos
  // Parameters: pos pointer to the position to remove.
  // Preconditions: pos is a pointer to a node in this list.
  // Postconditions: element pointed by pos is removed from the list
  void remove(LLNode<T>* pos);


  // --------
  // ---- Complex Operations ---
  // --------

  // Purpose: determines whether this list is identical to rhs list in
  // terms of data values and their order in the list
  // Parameters: rhs is list to be compared to this list
  // Returns: true if lists are identical; otherwise, false
  bool operator== (const LinkedList<T>& rhs) const;

  // Purpose: determines whether x is in the list
  // Parameters: x is data value to be found
  // Returns: a pointer to the position of x in the list; 
  //     otherwise, NULL
  LLNode<T>* find(const T& x);
    
  // Purpose: reverses the elements from the list
  // Postconditions: the list is now in reverse order
  void reverse();

  // Purpose: appends two lists
  // Parameters: xlist, a list to append to the end of 'this' list
  // Postconditions: elements of xlist are appended to 'this' list 
  void append(const LinkedList<T>& xlist);

  // Purpose: removes a section of a lists
  // Parameters:    start pointer to the begining of the section to remove.
  //                end pointer to the end of the section to remove.
  // Preconditions: start and end are pointers to nodes in this list.
  //                start precedes end in this list.
  // Postconditions: elements between start and end (inclusive) are removed
  //                 from the list.
  void clip(LLNode<T>* start, LLNode<T>* stop);
  
  // Purpose: Makes this list a slice of another list.
  // Parameters:    xlist, the source of a slice of data.
  //                start pointer to the begining of the slice.
  //                end pointer to the end of the slice.
  // Preconditions: start and end are pointers to nodes in the 'xlist' list.
  //                start precedes end in this list
  // Postconditions: 'this' list is made a copy of the elements between start 
  //                  and end in xlist.
  void slice( const LinkedList<T>& xlist, LLNode<T>* start, LLNode<T>* stop);


}; // of class LinkedList



// ---------------  Utility Function for Printing
// Purpose: prints a LinkedList
template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list);

#include "linkedlist.hpp"

#endif
