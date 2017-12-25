#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * Create a typedef for a  Compare Function 
 */
typedef int (*CompareFunc)(const int* a, const int* b);

/**
 * Create a typedef for a Sort Algorithm of an array
 */
typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

/***
 * NOTE: You will implement this function, it will be used to call all sorting algorithms. 
 *      It will also output the all the information required by the output section of the lab.
 *       
 * menuSelection is the text for the menu option that was selected.
 * sorter -> is the sorting function
 * array -> is the input array given by the user
 * length-> is the length of the array
 * compare -> is a comparison function pointer.
 */
void sort( char* menuSelection, int array[], SortAlgorithm sorter, int numOfArray, CompareFunc compare);

/**
compare for ascending order
param num1 for the first number
param num2 for the second number
return 1 if greater, return -1 is smaller
*/
int compareAscending(const int* num1, const int* num2);

/**
compare for descending order
param num1 for the first number
param num2 for the second number
return 1 if greater, return -1 is smaller
*/
int compareDescending(const int* num1, const int* num2);

/**
compare for even first and odd after in ascending order
param num1 for the first number
param num2 for the second number
return 1 if greater, return -1 is smaller
*/
int compareEvenOdd(const int* num1, const int* num2);

/**
sort the array with bubble sort
param array 
param numOfArray for the size of the array
param compare function that that compare 2 number
*/
void bubbleSort(int array[], int numOfArray, int(*compare)(const int*, const int*));

/**
sort the array with selection sort
param array 
param numOfArray for the size of the array
param compare function that that compare 2 number
*/
void selectionSort(int array[], int numOfArray, int(*compare)(const int*, const int*));

/**
 * Print an array of integers with a specific length.
 */
void printArray( int* arr, int length );

#endif