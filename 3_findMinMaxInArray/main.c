#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void inputArray(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Enter value #%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size)
{
    printf("Array elements = { ");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("} \n");
}

void findMinMax(int *min, int *max, int *arr, int size)
{
    *max = arr[0];
    *min = arr[0];

    for(int i=1; i<size; i++)
    {
        if(arr[i] > *max) *max = arr[i];
        if(arr[i] < *min) *min = arr[i];
    }
}

void printMinMax(int *min, int *max)
{
    printf("Max value: %d \n", *max);
    printf("Min value: %d \n", *min);
}

int main()
{
    int grades[SIZE];
    int min, max;
    inputArray(grades, SIZE);
    displayArray(grades, SIZE);
    findMinMax(&min, &max, grades, SIZE);
    printMinMax(&min, &max);
}
