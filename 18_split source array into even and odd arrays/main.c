#include <stdio.h>
#include <stdlib.h>

void separateEvenOddValues(int *sourceArray, int sourceSize, int **evenArr, int *evenSize, int **oddArr, int *oddSize)
{
    int i, j;
    int *newArrEven;
    int *newArrOdd;
    for(int i=0; i<sourceSize; i++)
    {
        if(sourceArray[i] % 2 == 0)
            (*evenSize)++;
        else
            (*oddSize)++;
    }

    newArrEven = malloc(*evenSize * sizeof(int));
    if(!newArrEven)
    {
        printf("Memory allocation for even array failed. Exiting program. \n");
        exit(1);
    }

    newArrOdd = malloc(*oddSize * sizeof(int));
    if(!newArrOdd)
    {
        printf("Memory allocation for odd array failed. Exiting program. \n");
        exit(1);
    }

    for(int i=0,j=0,k=0; i<sourceSize; i++)
    {
        if(sourceArray[i] % 2 == 0)
        {
            newArrEven[j] = sourceArray[i];
            j++;
        }
        else
        {
            newArrOdd[k] = sourceArray[i];
            k++;
        }
    }

    *evenArr = newArrEven;
    *oddArr = newArrOdd;
}

void printOriginalArray(int *arr, int size)
{
    printf("Original array = { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("Original array size = %d \n\n", size);
}

void printEvenArray(int *arr, int size)
{
    printf("Even array = { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("Even array size = %d \n\n", size);
}

void printOddArray(int *arr, int size)
{
    printf("Odd array = { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("Odd array size = %d \n\n", size);
}

int main()
{
    int originalArray[] = {1,1,3,5,6,7,7,7,8,12,12};
    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]);
    int *evenArray = NULL;
    int *oddArray = NULL;
    int evenArraySize = 0;
    int oddArraySize = 0;

    printOriginalArray(originalArray, originalSize);
    separateEvenOddValues(originalArray, originalSize, &evenArray, &evenArraySize, &oddArray, &oddArraySize);

    printEvenArray(evenArray, evenArraySize);
    printOddArray(oddArray, oddArraySize);

    if(!evenArray || !oddArray)
    {
        printf("Main function returned null. \n");
        return 1;
    }

    free(evenArray);
    free(oddArray);

    return 0;
}
