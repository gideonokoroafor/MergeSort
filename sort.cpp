/*
 * File:   sortMain.cpp
 * Author: Gideon Okoroafor
 *
 */

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <assert.h>
using namespace std;

const int MAX_ITEM = 999;

/*
 * Fills an array with random elements in
 * the range [0..MAX_ITEM].
 */
void fill(int a[], int n) {
  for (int i = 0; i < n; i++) {
    a[i] = rand() % (MAX_ITEM+1);
  }
}

const int ROW_SIZE = 10;

/*
 * Displays the contents of an array, adding
 * a new line break every ROW_SIZE elements.
 */
void display(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if ( i % ROW_SIZE == 0 ) {
      cout << endl;
    }
    cout << setw(5) << a[i];
  }
  cout << endl;
}

/*
 * Tests if an integer array is arranged in ascending order.
 */
bool inOrder(int a[], int n) {
  for (int i = 0; i < n-1; i++) {
    if (a[i] > a[i+1]) return false;
  }
  return true;
}

/*
 *  Merges two adjacent subranges of an array.
 *  "a" is the array with entries to be merged.
 *  "from" is the index of the first element of the first range.
 *  "mid" is the index of the last element of the first range.
 *  "to" is the index of the last element of the second range.
 *  A temporary array should be created to receive the merged elements.
 *  Then the temporary array elements should be copied back to "a".
 */
void merge(int a[], int from, int mid, int to) {

  // You provide
   int i, j, k, temp[to - from+1];
   i = from;
   j = mid+1;
   k = 0;

   //Merge the two parts into temp[]
   while (i <= mid && j <= to){
     if (a[i] < a[j]){
       temp[k] = a[i];
       k++;
       i++;
     }
     else{
       temp[k] = a[j];
       k++;
       j++;
     }
   }

   //inserting the remaining values from i to mid into temp[]
   while (i <= mid){
     temp[k] = a[i];
     k++;
     i++;
   }

   //inserting the remaining values from j to "to" into temp[]
   while (j <= to){
     temp[k] = a[j];
     k++;
     j++;
   }

   //assign the sorted data from temp[] to a[]
   for (i = from; i <= to; i++){
     a[i] = temp[i-from];
   }
}

/*
 *  Sorts a range of an array, using the merge sort algorithm.
 *  "a" is the array to sort.
 *  "from" is the first index of the range to sort.
 *  "to" is the last index of the range to sort.
 */
void mergeSort(int a[], int from, int to) {
  if (from == to) return; // array portion is just one element
  int mid = (from + to) / 2;
  mergeSort(a, from, mid);
  mergeSort(a, mid + 1, to);
  merge(a, from, mid, to);
}

/*
 * This tests your merge sort.
 */
int main(int argc, char** argv) {

  // Testing merge sort
  const int n = 100;
  int a1[n];
  fill(a1, n);                // fill the array with random integers
  display(a1, n);             // display the unsorted array
  assert( !inOrder(a1, n) );  // array will not be in order at this point
  mergeSort(a1, 0, n-1);      // carry out the merge sort
  display(a1, n);             // display again
  assert( inOrder(a1, n) );   // array should be in order

  cout << "Merge Sort Test Passed" << endl;
}
