//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//  Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

/*Kushendra Ramrup
Tiziana Ligorio
CSCI 235
9/15/2019
*/

#include "ArrayBag.hpp"

/** default constructor**/
template<class T>
ArrayBag<T>::ArrayBag(): item_count_(0)
{
}  // end default constructor


/**
 @return item_count_ : the current size of the bag
 **/
template<class T>
int ArrayBag<T>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize


/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class T>
bool ArrayBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty


/**
 @return true if new_etry was successfully added to items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::add(const T& new_entry)
{
	bool has_room = (item_count_ < DEFAULT_CAPACITY);
	if (getFrequencyOf(new_entry) == 0) {
		if (has_room)
		{
			items_[item_count_] = new_entry;
			item_count_++;
					return true;
		}  // end if
	}
	return false;
}  // end add


/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::remove(const T& an_entry)
{
  int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if

	return can_remove;
}  // end remove


/**
 @post item_count_ == 0
 **/
template<class T>
void ArrayBag<T>::clear()
{
	item_count_ = 0;
}  // end clear

template<class T>
void ArrayBag<T>::display() const
{
	for (int i = 0; i < item_count_; i++) {         //prints out the contents of items_
		if( i < item_count_-1){
			std::cout << items_[i] << ", ";
		}
		else {
			std::cout << items_[i] << std::endl;
		}
	}
}

/**
 @return the number of times an_entry is found in items_
 **/
template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if

      cun_index++;          // Increment to next entry
   }  // end while

   return frequency;
}  // end getFrequencyOf


/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains


/**
 @return a vector having the same cotntents as items_
 **/
template<class T>
std::vector<T> ArrayBag<T>::toVector() const
{
   std::vector<T> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);

   return bag_contents;
}  // end toVector





// ********* PRIVATE METHODS **************//

/**
 @param target to be found in items_
 @return either the index target in the array items_ or -1,
 if the array does not containthe target.
 **/
template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const
{
	bool found = false;
   int result = -1;
   int search_index = 0;

   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {
      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      }
      else
      {
         search_index++;
      }  // end if
   }  // end while

   return result;
}  // end getIndexOf

/** implements Set Union
 The union of two sets A and B is the set of elements which are in A,
 in B, or in both A and B.
 @param a_bag to be combined with the contents of this (the calling) bag
 @post adds as many items from a_bag as space allows
 */
 template<class T>
 void ArrayBag<T>::operator+=(const ArrayBag<T>& a_bag)
 {
	 for (int i = 0; i < a_bag.getCurrentSize(); i++){
		 add(a_bag.items_[i]);
	 }
 }

 /** implements Set Difference
The (set) difference between two sets A and B is the set that
consists of the elements of A which are not elements of B
@param a_bag to be subtracted from this (the calling) bag
@post removes all data from items_ that is also found in a_bag
*/
template<class T>
void ArrayBag<T>::operator-=(const ArrayBag<T>& a_bag){
	for (int i = 0; i < a_bag.getCurrentSize(); i++){
		remove(a_bag.items_[i]);
	}
}

/** implements Set Intersection
The intersection of two sets A and B is the set that
consists of the elements that are in both A and B
@param a_bag to be intersected with this (the calling) bag
@post items_ no longer contains data not found in a_bag
*/
template<class T>
void ArrayBag<T>::operator /=(const ArrayBag<T>& a_bag){
	for (int i = 0; i < a_bag.getCurrentSize(); i++){
		if (!a_bag.contains(items_[i])) {
			remove(items_[i]);
		}
	}
}
