#include <stdio.h>
#include <stdlib.h>

int *filterOriginalArray(int *sourceArray, int sourceSize, int *count)
{
    int i, j;
    *count = 1;
    int *NoDuplicateArray;
    for(int i=0; i<sourceSize-1; i++)
    {
        if(sourceArray[i] != sourceArray[i+1])
            (*count)++;
    }
    NoDuplicateArray = malloc(*count * sizeof(int));

    if(!NoDuplicateArray)
    {
        printf("Memory allocation failed! \n");
        return NULL;
    }

    for(i=0,j=0; i<sourceSize-1; i++)
    {
        if(sourceArray[i] != sourceArray[i+1])
        {
            NoDuplicateArray[j] = sourceArray[i];
            j++;
        }
    }
    NoDuplicateArray[j] = sourceArray[sourceSize-1];

    return NoDuplicateArray;
}

void printOriginalArray(int *arr, int size)
{
    printf("Original array = { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("Original array size = %d \n", size);
}

void printEditedArray(int *arr, int size)
{
    printf("Edited array = { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("Edited array size = %d \n", size);
}

int main()
{
    int originalArray[] = {1,1,3,5,6,7,7,7,8,12,12};
    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]);
    int *filteredArray = NULL;
    int filteredSize = 0;

    printOriginalArray(originalArray, originalSize);
    filteredArray = filterOriginalArray(originalArray, originalSize, &filteredSize);
    printEditedArray(filteredArray, filteredSize);

    if(!filteredArray)
        return 1;

    free(filteredArray);

    return 0;
}

