//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  Modified by Tiziana Ligorio for Hunter College CSCI 235
//  modified position s.t. 0 <= position < item_count_
//  some style modification, mainly variable names

/** ADT list: Singly linked list implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"

template<class T>
class LinkedList
{

public:
   LinkedList(); // constructor
   LinkedList(const LinkedList<T>& a_list); // copy constructor
   virtual ~LinkedList(); // destructor

   /**@return true if list is empty - item_count_ == 0 */
   bool isEmpty() const;

    /**@return the number of items in the list - item_count_ */
   int getLength() const;


    /**
     @pre list positions follow traditional indexing from 0 to item_count_ -1
     @param position indicating point of insertion
     @param new_entry to be inserted in list
     @post new_entry is added at position in list (the node previously at that position is now at position+1)
     @return true if valid position (0 <= position <= item_count_) */
   bool insert(int position, const T& new_entry);


    /**
     @pre list positions follow traditional indexing from 0 to item_count_ -1
     @param position indicating point of deletion
     @post node at position is deleted, if any. List order is retains
     @return true if there is a node at position to be deleted, false otherwise */
   bool remove(int position);



   /**@post the list is empty and item_count_ == 0*/
   void clear();


    /**
     @pre list positions follow traditional indexing from 0 to item_count_ -1
     @param position indicating the position of the data to be retrieved
     @return data item found at position. If position is not a valid position < item_count_
            throws  PrecondViolatedExcep */
   T getEntry(int position) const;

   // A wrapper to a recursive method that inverts the contents of the list
   // @post the contents of the list are inverted such that
   // the item previously at position 1 is at position item_count_,
   // the item previously at position 2 is at position item_count_-1 ...
   // the item previously at position ⌊item_count/2⌋ is at position ⌈item_count_/2⌉
   void invert();

   // @pre k >= 0
   // @post the contents of the list are rotated to the right by k places, s.t.
   // every element at position i shifts to position i+k % item_count_
   void rotate(int k);


private:
    Node<T>* head_ptr_; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int item_count_;           // Current count of list items



    // Locates a specified node in this linked list.
    // @pre list positions follow traditional indexing from 0 to item_count_ -1
    // @param position the index of the desired node
    //       0 <= position < item_count_
    // @return  A pointer to the node at the given position or nullptr if position is >= item_count_
    Node<T>* getNodeAt(int position) const;

    //private function to invert, used for safe programming to avoid
    //exposing pointers to list in public methods
    // @post the contents of the list are inverted such that
    // the item previously at position 1 is at position item_count_,
    // the item previously at position 2 is at position item_count_-1 ...
    // the item previously at position ⌊item_count/2⌋ is at position
    //⌈item_count_/2⌉
    void invertRest(Node<T>* current_first_ptr);

}; // end LinkedList

#include "LinkedList.cpp"
#endif
