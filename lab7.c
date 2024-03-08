// Rachel Nieman
// Lab Assignment 7
// March 7th, 2024

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data; // Number
    int swaps; // Number of Swaps
} element;

// Total number of swaps is half of the individual swaps added together. 
void bubbleSort(int* arr, int size) 
{
    int total = 0;

    element* swap = (element*) malloc(sizeof(element)*size);
    for(int x = 0; x < size; x++)
    {
        swap[x].data = arr[x];
        swap[x].swaps = 0;
    }

    int i, j, temp, temp2;
    for (i = 1; i < size; i++)
        for (j = 0; j < size - i; j++)
        {
            if (swap[j].data > swap[j + 1].data)
            {
                // Count
                swap[j].swaps++;
                swap[j + 1].swaps++;

                // Temps
                temp = swap[j].data;
                temp2 = swap[j].swaps;

                // Swap
                swap[j].data = swap[j + 1].data;
                swap[j].swaps = swap[j + 1].swaps;
                swap[j + 1].data = temp;
                swap[j + 1].swaps = temp2;
            }
        }

    for (int q = 0; q < size; q++)
    {
        printf("%d: %d\n", swap[q].data, swap[q].swaps);
        total += swap[q].swaps;
    }
    
    total = total / 2;
    printf("%d\n", total);

    free(swap);
}

// Select Sort - Find the minimum and swap it to the first.
void selectionSort(int *arr, int size)
{
    int total = 0;
    element* swap = (element*) malloc(sizeof(element)*size);
    for(int x = 0; x < size; x++)
    {
        swap[x].data = arr[x];
        swap[x].swaps = 0;
    }

    int i, j, minindex, temp, temp2;

    for (i = 0; i < size - 1; i++)
    {
        // Find the Minimum Element
        minindex = i;

        for (j = i; j < size; j++)
        {
            if (swap[j].data < swap[minindex].data)
                minindex = j;
        }

        if (i == minindex) // Checks to make sure Minimum and i aren't Equal
            continue;

        // Count
        swap[i].swaps++;
        swap[minindex].swaps++;

        // Temps
        temp = swap[i].data;
        temp2 = swap[i].swaps;

        // Swap the Minimum with the 1st
        swap[i].data = swap[minindex].data;
        swap[i].swaps = swap[minindex].swaps;
        swap[minindex].data = temp;
        swap[minindex].swaps = temp2;
    }

    for (int q = 0; q < size; q++)
    {
        printf("%d: %d\n", swap[q].data, swap[q].swaps);
        total += swap[q].swaps;
    }
    
    total = total / 2;
    printf("%d\n", total);

    free(swap);
}



int main()
{
    int array1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int size = 9; // array1 and array2 are the same size!

    // Bubble Sort
    printf("Bubble Sort Array 1: \n");
    bubbleSort(array1, size);

    printf("Bubble Sort Array 2: \n");
    bubbleSort(array2, size);
    printf("\n");

    // Selection Sort
    printf("Selection Sort Array 1: \n");
    selectionSort(array1, size);

    printf("Selection Sort Array 2: \n");
    selectionSort(array2, size);

    return 0;
}