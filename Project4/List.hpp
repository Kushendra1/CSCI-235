//
//  List.hpp
//  List
//  A doubly-liked list implementation for class project CSci 235 Software Design and Analysis II
//
//  Created by Tiziana Ligorio on 10/21/18.
//  Modified 6/5/19
//  Copyright © 2018 Tiziana Ligorio. All rights reserved.
//

#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"

template<class T>
class List
{
    
public:
    List(); // constructor
    List(const List<T>& a_list); // copy constructor
    ~List(); // destructor
    
    /**@return true if list is empty - item_count_ == 0 */
    bool isEmpty() const;
    
    /**@return the number of items in the list - item_count_ */
    size_t getLength() const;
    
    
    /**
     @param position indicating point of insertion
     @param new_element to be inserted in list
     @post new_element is added at position in list (the node previously at that position is now at position+1)
     @return true always - it always inserts, if position > item_count_ it inserts at end of list */
    bool insert(size_t position, const T& new_element);
    
    /**
     @param position indicating point of deletion
     @post node at position is deleted, if any. List order is retains
     @return true if ther eis a node at position to be deleted, false otherwise */
    bool remove(size_t position);
    
    /**
     @pre assumes there is an item at position - NO ERROR HANDLING
     @param position of item to be retrieved
     @return the item at position in list if there is one, otherwise it throws exception: PrecondViolatedExcep */
    T getItem(size_t position) const;
    
    /**@post the list is empty and item_count_ == 0*/
    void clear();
   
    
    
protected:
    Node<T>* first_;      // Pointer to first node
    Node<T>* last_;       // Pointer to last node
    size_t item_count_;    // number of items in the list
    
    //if position > item_count_ returns nullptr
    Node<T>* getPointerTo(size_t position) const;
    
}; // end List

#include "List.cpp"
#endif // LIST_H_





