/***********************
 * Name: Vicky Mohammad
 * ID: 0895381
 ***********************/

//import library
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "functions.h"
//macros
#define TRUE 1
#define FALSE 0

int userInputToInt(char* input){
    //declare var
    int num;
    //ask for user input
    input[0] = '\0';
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0';
    num = atoi(input);
    //return
    return num;
}//end func

char* userInput(char* input){
    //ask for user input
    input[0] = '\0';
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0';
    //return
    return input;
}//end func

int main(int argc, char **argv){
    //declare var
    int menu = 0, numOfArray = 0, exit = FALSE, x = 0;
    char stringBuffer[99];
    SortAlgorithm sorter;
    CompareFunc compare;

    //aks the user and assign the number of array
    do{
        printf("Please enter the number of integer for Array (number valid from 2 to 20):\n");
        numOfArray = userInputToInt(stringBuffer);
    }while(numOfArray <= 2 || numOfArray >= 20);
    int arrayOfInt[numOfArray-1];

    //ask the intger in the array
    printf("Please input the %d integers \n", numOfArray);
    for(x=0; x<=numOfArray-1; x++){
        scanf("%d", &arrayOfInt[x]);
    }//end for
    getchar();

    //loop the menu
    while(exit == FALSE){
        //ask the user for which option
        printf("1) bubbleSort Sorting ( increasing order)\n"); 
        printf("2) bubbleSort ( decreasing order )\n");
        printf("3) bubbleSort ( increasing order – evens numbers before odd numbers )\n");
        printf("4) selectionSort ( increasing order)\n");
        printf("5) selectionSort ( decreasing order )\n");
        printf("6) selectionSort ( increasing order – evens numbers before odd numbers )\n");
        printf("7) Quit\n");
        printf("Enter the option:\n");
        menu = userInputToInt(stringBuffer);
        //option path
        if(menu == 1){
            sorter = &bubbleSort;
            compare = &compareAscending;
            sort(stringBuffer, arrayOfInt, sorter, numOfArray, compare);
        }else if(menu == 2){
            sorter = &bubbleSort;
            compare = &compareDescending;
            sort(stringBuffer, arrayOfInt, sorter, numOfArray, compare);
        }else if(menu == 3){
            sorter = &bubbleSort;
            compare = &compareEvenOdd;
            sort(stringBuffer, arrayOfInt, sorter, numOfArray, compare);
        }else if(menu == 4){
            sorter = &selectionSort;
            compare = &compareAscending;
            sort(stringBuffer, arrayOfInt, sorter, numOfArray, compare);
        }else if(menu == 5){
            sorter = &selectionSort;
            compare = &compareDescending;
            sort(stringBuffer, arrayOfInt, sorter, numOfArray, compare);
        }else if(menu == 6){
            sorter = &selectionSort;
            compare = &compareEvenOdd;
            sort(stringBuffer, arrayOfInt, sorter, numOfArray, compare);
        }else if(menu == 7){
            exit = TRUE;
        }//end if
    }//end if
    //exit program
    return 0;   
}//end func