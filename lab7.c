// Rachel Nieman
// Lab Assignment 4
// March 7th, 2024

#include <stdio.h>

/* typedef struct element {
    int data;

} element; */


// Total number of swaps is half of the 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// element bubbleSort(int *arr, int sizeofarray)
bubbleSort(int *arr, int sizeofarray)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            { // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

            printArray(arr, n);
        }
    
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    // CHANGE LATER
    int array1[8] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[8] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = 9;
    int size1 = 9;
    printf("Array before sorting: \n");
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}


// Find the minimum and swap it to the first.  Should it count something swapped with itself?  Choose either.
// Select Sort
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        printArray(arr, n);
    }
}

int main()
{
    int arr[] = { 5, 8, 3, 1, 4, 7, 6, 2};
    int n = 8; //size of the array
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}