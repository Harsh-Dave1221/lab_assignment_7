/* Author: Harsh Dave
Date: July 9, 2023
Course: COP 3502C
Lab Assignment 7

Prompt: Consider running Bubble Sort on the array shown below. 
Write a c program to compute the number of swaps needed for each index in the array. 
97  16  45  63  13  22  7  58  72 

Sorted: 7  13  16  22  45  58  63  72  97 */

#include <stdio.h>

void bubbleSort(int initialArray[], int numOfElements); // bubble sort function, accepts an array and int for number of elements
void printArray(int initialArray[], int numOfElements); // print array, accepts an array and int for number of elements

int main() 
{   
    // initialize array and calculate the number of elements
    int initialArray[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int numOfElements = sizeof(initialArray) / sizeof(initialArray[0]);
    
    // call printArray to print the initial array
    printf("Initial array: ");
    printArray(initialArray, numOfElements);
    
    // call bubbleSort to sort the initial array
    bubbleSort(initialArray, numOfElements);
    
    // call printArray to print the sorted array
    printf("Sorted array: ");
    printArray(initialArray, numOfElements);
    
    return 0;
}

void bubbleSort(int initialArray[], int numOfElements) 
{
    // declare variables for for loops, counter, and temp storage for swapping
    int i, j, temp, swapCounter;

    // initialize an array for the sorted elements
    int sorted[numOfElements];
    
    for (i = 0; i < numOfElements; i++) 
    {   
        // initialize sorted array each index
        sorted[i] = 0; 
    }
    
    for (i = 0; i < numOfElements-1; i++) 
    {
        // initialize swap counter for each pass of bubble sort
        swapCounter = 0; 
        
        for (j = 0; j < numOfElements-i-1; j++) 
        {
            if (initialArray[j] > initialArray[j+1]) 
            {
                // swap elements the elements in adjacent indexes
                temp = initialArray[j];
                initialArray[j] = initialArray[j+1];
                initialArray[j+1] = temp;
                
                // increment the swapCounter
                swapCounter++; 
            }
        }
        
        // for current pass, store the number of swaps within the sorted array
        sorted[i] = swapCounter;
    }
    
    printf("Swaps needed for:\n");
    for (int i = 0; i < numOfElements; i++) 
    {
        // print the index and the number of swaps for each index
        printf("Index %d: %d swaps\n", i, sorted[i]);
    }
}

void printArray(int initialArray[], int numOfElements) 
{
    for (int i = 0; i < numOfElements; i++) 
    {
        // print each element of the array
        printf("%d ", initialArray[i]);
    }
    printf("\n");
}