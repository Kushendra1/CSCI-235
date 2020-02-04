//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Tiziana Ligorio for Hunter College CSCI 235

/** @file Node.cpp
 Node for Singly Linked List*/


#include "Node.hpp"
//#include <cstddef>

//default constructor
template<class T>
Node<T>::Node() : next_(nullptr)
{
} // end default constructor


//parameterized constructor
template<class T>
Node<T>::Node(const T& an_item) : item_(an_item), next_(nullptr)
{
} // end constructor

//parameterized constructor
template<class T>
Node<T>::Node(const T& an_item, Node<T>* next_node_ptr) :
                item_(an_item), next_(next_node_ptr)
{
} // end constructor


/** @param an_item contained in the node
 @post sets item_ to an_item */
template<class T>
void Node<T>::setItem(const T& an_item)
{
   item_ = an_item;
} // end setItem


/** @param next_node_ptr points to the next node in the chain
 @post sets next_ to next_node_ptr */
template<class T>
void Node<T>::setNext(Node<T>* next_node_ptr)
{
   next_ = next_node_ptr;
} // end setNext

 /**@return item_*/
template<class T>
T Node<T>::getItem() const
{
   return item_;
} // end getItem

 /**@return next_*/
template<class T>
Node<T>* Node<T>::getNext() const
{
   return next_;
} // end getNext
