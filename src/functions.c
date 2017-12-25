/***********************
 * Name: Vicky Mohammad
 * ID: 0895381
 ***********************/

//import lib
//import library
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "functions.h"

/**
sort function to chose which function to sort
param menuSelection to check chose which option
*/
void sort( char* menuSelection,int array[], SortAlgorithm sorter, int numOfArray, CompareFunc compare){
    //decalre var
    int menu = 0;
    //menu
    printf("************************************\n");
    //initial
    printf("Initial: ");
    printArray(array, numOfArray);
    printf("\n");
    //sort
    menu = atoi(menuSelection);
    if(menu == 1){
        printf("bubbleSort ( increasing order)\n");
        sorter(array, numOfArray, compare);
    }else if(menu == 2){
        printf("bubbleSort ( decreasing order )\n");
        sorter(array, numOfArray, compare);
    }else if(menu == 3){
        printf("bubbleSort ( increasing order – evens numbers before odd numbers )\n");
        sorter(array, numOfArray, compare);
    }else if(menu == 4){
        printf("selectionSort( increasing order)\n");
        sorter(array, numOfArray, compare);
    }else if(menu == 5){
        printf("selectionSort( decreasing order )\n");
        sorter(array, numOfArray, compare);
    }else if(menu == 6){
        printf("selectionSort( increasing order – evens numbers before odd numbers )\n");
        sorter(array, numOfArray, compare);
    }//end if
    //result
    printf("result: ");
    printArray(array, numOfArray);
    printf("\n");
    printf("************************************\n");
}//end func

/**
compare for ascending order
param num1 for the first number
param num2 for the second number
return 1 if greater, return -1 is smaller
*/
int compareAscending(const int* num1, const int* num2){
    int result = *num1 - *num2;
    if(result < 0){
        return -1;
    }else if(result > 0){
        return 1;
    }else{
        return 0;
    }//end if
}//end func

/**
compare for descending order
param num1 for the first number
param num2 for the second number
return 1 if greater, return -1 is smaller
*/
int compareDescending(const int* num1, const int* num2){
    int result = *num2 - *num1;
    if(result < 0){
        return -1;
    }else if(result > 0){
        return 1;
    }else{
        return 0;
    }//end if
}//end func

/**
compare for even first and odd after in ascending order
param num1 for the first number
param num2 for the second number
return 1 if greater, return -1 is smaller
*/
int compareEvenOdd(const int* num1, const int* num2){
    //int result;
    if(*num1%2 == 0 && *num2%2 == 1){
        return -1;
    }else if(*num1%2 == 1 && *num2%2 == 0){
        return 1;
    }else{
        return compareAscending(num1, num2);
    }//end if
}//end func

/**
sort the array with bubble sort
param array 
param numOfArray for the size of the array
param compare function that that compare 2 number
*/
void bubbleSort(int array[], int numOfArray, int(*compare)(const int*, const int*)){
    int x, y, temp;
    for (x = 0; x < numOfArray-1; x++){
        for (y = 0; y < numOfArray-x-1; y++){
            if (compare(&array[y], &array[y+1]) > 0){
                temp = array[y];
                array[y] = array[y+1];
                array[y+1] = temp;
            }//end if
        }//end for
    }//end for
}//end func

/**
sort the array with selection sort
param array 
param numOfArray for the size of the array
param compare function that that compare 2 number
*/
void selectionSort(int array[], int numOfArray, int(*compare)(const int*, const int*)){
    int x, y, min, temp;
    for (x = 0; x < numOfArray-1; x++){
        min = x;
        for (y = x+1; y < numOfArray; y++){
            if (compare(&array[y], &array[min]) < 0){
                min = y;
            }//end if
        }//end for
        temp = array[min];
        array[min] = array[x];
        array[x] = temp;
    }//end for
}//end func

/**
 * Print an array of integers with a specific length.
 */
void printArray( int* arr, int length ){
    for(int i =0 ; i < length; i++ ){
        printf("%d ", arr[i]);
    }//end for
}//end func