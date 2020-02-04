//
//  SortingComparison.cpp
//  SortTest
//
//  Created by Tiziana Ligorio on 10/4/19.
//  Course project, Hunter Collegge, CSci 235 - Software Design and Analysis II
//  Sorting functions implementation adapted from Big C++, Late Objects, Wiley
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
// ********** ADD YOUR CONTRIBUTION INFORMATION HERE!!! ******************


#include "SortingComparison.hpp"

//parameterized constructor allocate values_ with array_size
SortingComparison::SortingComparison(size_t array_size): SIZE(array_size), values_(new int[SIZE]){}



/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/



/*************** SELECTION SORT + HELPER **************************/

/**
 @post Gets the position of the smallest element in an array range.
 @param a the array
 @param from the beginning of the range
 @param to the end of the range
 @return the position of the smallest element in
 the range a[from]...a[to]
 */
int SortingComparison::minPosition(int a[], int from, int to, int& comparisons)       //pass comparisons as a reference parameter
{
    int min_pos = from;
    for (int i = from + 1; i <= to; i++){
        if (a[i] < a[min_pos]) {
          min_pos = i;
        }
        comparisons+=1;                                                               //there is a comparison made here, so add one to int value
      }
    return min_pos;
}


/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::selectionSort(int a[], size_t size)
{
    int comparisons = 0;                                                            //here is where comparison is actually instantiated, as it will
    for (int i = 0; i < size; i++)                                                  //be called in the helper fnction shown below
    {
        // Find the position of the minimum
        int min_pos = minPosition(a, i, static_cast<int>(size - 1), comparisons);   //comparison will be passed by reference
        // Swap the next element and the minimum
        std::swap(a[i], a[min_pos]);
    }


    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}




/*************** INSERTION SORT **************************/


/**
 @post Sorts an array in ascending order using insertion sort.
 @param a the array to sort
 @param size of the array
 @return the number of comparisons of two  array elements made by the algorithm
 */
int SortingComparison::insertionSort(int a[], size_t size)
{
    int comparisons = 0;                                                           //instantiate the comparison count variable
    for (int i = 1; i < size; i++)
    {
        int next = a[i];
        // Move all larger elements up
        int j = i;
        if (a[j - 1] <= next){
          comparisons +=1;                                                         //comparison made so add 1 to value
        }
        while (j > 0 && a[j - 1] > next)
        {
            a[j] = a[j - 1];
            j--;
            comparisons +=1;                                                      //comparison made so add 1 to value
        }
        // Insert the element
        a[j] = next;
    }


    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}


/************************* MERGE SORT + HELPER **************************/

/**
 @post Merges two adjacent subarrays.
 @param a the array with the elements to merge
 @param from the start of the first subarray
 @param mid the end of the first subarray
 @param to the end of the second subarray
 */
void SortingComparison::merge(int a[], int from, int mid, int to, int& comparisons)  //pass comparisons as a reference parameter
{
    // int temp = comparisons;
    int n = to - from + 1; // Size of the range to be merged
    // Merge both halves into a temporary array temp_array
    int* temp_array = new int[n];

    int i1 = from;
    // Next element to consider in the first half
    int i2 = mid + 1;
    // Next element to consider in the second half
    int j = 0; // Next open position in temp_array

    // Compare elements in subarrays for merging
    // As long as neither i1 nor i2 is past the end,
    // move the smaller element into temp_array

    while (i1 <= mid && i2 <= to)
    {
        if (a[i1] < a[i2])
        {
            temp_array[j] = a[i1];
            i1++;
            comparisons += 1;                                                       //comparison made so add 1 to value
        }
        else
        {
           temp_array[j] = a[i2];
            i2++;
            comparisons += 1;                                                      //comparison made so add 1 to value
        }
        j++;
    }


    // Note that only one of the two while loops below is executed

    // Copy any remaining entries of the first half
    while (i1 <= mid)
    {
        temp_array[j] = a[i1];
        i1++;
        j++;
        comparisons += 1;                                                          //comparison made so add 1 to value
    }
    // Copy any remaining entries of the second half
    while (i2 <= to)
    {
        temp_array[j] = a[i2];
        i2++;
        j++;
        comparisons += 1;                                                         //comparison made so add 1 to value
    }

    // Copy back from the temporary array
    for (j = 0; j < n; j++)
    {
        a[from + j] = temp_array[j];
        comparisons+=1;                                                           //comparison made so add 1 to value
    }

    delete[] temp_array;
}

/**
 @post Sorts the elements in a range of a array.
 @param a the array with the elements to sort
 @param from the first position in the range to sort
 @param to the last position in the range to sort (included)
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::mergeSort(int a[], int from, int to)
{
    int comparisons = 0;                                                        //here is where comparison is actually instantiated, as it will
    if (from == to) { return 0; }                                               //be called and passed in the helper function below
    int mid = (from + to) / 2;
    // Recursively sort the first and the second half
    comparisons+=mergeSort(a, from, mid);                                       //comparison is made Recursively, so add the comparisons to the new ones
    comparisons+=mergeSort(a, mid + 1, to);
    merge(a, from, mid, to, comparisons);


    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}


/************************* QUICK SORT + HELPER**************************/

/**
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
*/
int SortingComparison::partition(int a[], int from, int to, int& comparisons)   //pass comparisons as a reference parameter
{
   // int temp = comparisons;
   int pivot = a[from];
   int i = from - 1; //index of data item being compared from left
   int j = to + 1;   //index of data item being compared from right
   while (i < j)    // as long as i and j did not cross (meet)
   {
      i++;
      comparisons+=1;
      while (a[i] < pivot){//increment i until a[i] >= pivot
          i++;
          comparisons += 1;                                                     //comparison made so add 1 to value
      }
      j--;
      while (a[j] > pivot){ //decrement j until a[j] <= pivot
          j--;
          comparisons += 1;                                                     //comparison made so add 1 to value
      }
      if (i < j){
          std::swap(a[i], a[j]);
          comparisons+=1;                                                       //comparison made so add 1 to value
      }
   }
   return j; // the pivot index
}

/**
   @post Sorts an array in ascending order using quick sort.
   @param a the array to sort
   @param from the first index of the portion to be sorted
   @param to the last index of the portion to be sorted
  @return the number of comparisons made by the algorithm
*/
int SortingComparison::quickSort(int a[], int from, int to)
{
    int comparisons = 0;                                                        //here is where comparison is actually instantiated, as it will
    if (from >= to){return 0;}                                                  //be called and passed in the helper function below

    int p = partition(a, from, to, comparisons);
    comparisons+=quickSort(a, from, p);                                         //comparison is made Recursively, so add the comparisons to the new ones
    comparisons+=quickSort(a, p + 1, to);

    return comparisons;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}





/*****************************************************************/
/******************  TEST FUNCTION *******************************/
/*****************************************************************/


//*************  IMPLEMENT runComparison HERE!!!! ************//
/**
@post Sorts a copy of values_ in ascending order with each available sorting functions
and prints the number of comparisons made by each sorting algorithm
@param array_type data_distribution of values_ in {RANDOM, INCREASING, DECREASING}
*/
void SortingComparison::runComparison(data_distribution array_type){
  int some_random_variable=0;
  int svalues_[SIZE], mvalues_[SIZE], ivalues_[SIZE], qvalues_[SIZE];       //instantiate the copy arrays
  if (array_type == RANDOM){                                                //if it is a random array
    std::srand(static_cast<unsigned>(time(NULL)));
    for(int i = 0; i<SIZE; i++){                                            //fill array with random numbers
      values_[i] = std::rand() % SIZE;
    }
  }
  if (array_type == INCREASING){                                            //if it is an increasing array
    for(int i = 0; i<SIZE; i++){
      values_[i] = i;                                                       //copy array over in that fashion
    }
  }
  if (array_type == DECREASING){
    int Avalue = SIZE-1;
    for(int i = 0; i<SIZE; i++){
      values_[i] = Avalue;
      Avalue-=1;
    }
  }
  for (int i = 0; i<SIZE; i++){                                            //actually fill in the arrays, one for each type of sorting algorithm
    svalues_[i] = values_[i];
    mvalues_[i] = values_[i];
    ivalues_[i] = values_[i];
    qvalues_[i] = values_[i];
  }
  std::cout<< "Selection sort comparisons: " << selectionSort(svalues_, SIZE) << "\n\n";      //printe out the message displaying number of comparisons
  std::cout<< "Insertion sort comparisons: " << insertionSort(ivalues_, SIZE) << "\n\n";      //one for each algorithm
  std::cout<< "Merge sort comparisons: " << mergeSort(mvalues_, 0, SIZE-1) << "\n\n";
  std::cout<< "Quick sort comparisons: " << quickSort(qvalues_, 0, SIZE-1) << "\n\n";
}
