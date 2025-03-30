#include <stdio.h>
#include <stdlib.h>

int *createNoDuplexArray(int *arr, int *arrSize)
{
    int *temp = NULL;
    int *newArr = NULL;
    int size = 2;
    int lastIndex = 0;
    int foundDuplicate = 0;
    int uniqueValue = 1;

    if(*arrSize <= 0)       // Return if the array size in main is empty.
    {
        printf("Array size error! \n");
        return NULL;
    }

    if(*arrSize == 1)        // Return the passed array itself if it has only one element.
        return arr;

    temp = malloc(size * sizeof(int));      // Initial memory allocation of size 2
    if(!temp)
    {
        printf("Memory allocation failed! \n");
        return NULL;
    }
    newArr = temp;

    // Loop through the elements
    for(int i=0; i<*arrSize; i++) {              // Selecting an element
        foundDuplicate = 0;
        uniqueValue = 1;
        for(int j=0; j<i; j++) {             // Comparing the selected element with its left-side elements
            if(arr[i] == arr[j]) {       // We break out of the loop if we have already taken into account the duplicate value
                foundDuplicate = 1;
                break;
            }
        }
        if(foundDuplicate == 1)
            continue;
        else {
            for(int j=i+1; j<*arrSize; j++) {       // Comparing the selected element with its right-side elements
                if(arr[i] == arr[j]) {
                    uniqueValue = 0;            // Take care of the non-unique values

                    if(lastIndex == size)
                    {
                        size *= 2;
                        temp = realloc(newArr, size * sizeof(int));     // Double the size of the newArr

                        if(!temp)
                        {
                            printf("Memory reallocation failed! \n");
                            free(newArr);       // Free memory on realloc failure
                            return NULL;
                        }
                        newArr = temp;
                    }
                    newArr[lastIndex] = arr[i];
                    lastIndex++;
                    break;
                }
            }
            if(uniqueValue == 1)        // Take care of the unique values
            {
                if(lastIndex == size)
                {
                    size *= 2;
                    temp = realloc(newArr, size * sizeof(int));     // Double the size of the newArr

                    if(!temp)
                    {
                        printf("Memory reallocation failed! \n");
                        free(newArr);       // Free memory on realloc failure
                        return NULL;
                    }
                    newArr = temp;
                }
                newArr[lastIndex] = arr[i];
                lastIndex++;
            }
        }

    }

    if(lastIndex < size)
    {
        temp = realloc(newArr, lastIndex * sizeof(int));
        if(!temp)
        {
            printf("Memory reallocation failed! \n");
            free(newArr);       // Free memory on realloc failure
            return NULL;
        }
        newArr = temp;
    }
    *arrSize = lastIndex;       // Update size in calling function

    return newArr;
}

// Function to print the array
void printArray(int *arr, int size)
{
    printf("Edited array = { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("Edited array size = %d \n", size);
}

// Main function
int main()
{
    int originalArray[] = {1,1,3,5,6,7,7,7,8,12,12};
    int size = sizeof(originalArray) / sizeof(originalArray[0]);
    int *ptr;

    ptr = createNoDuplexArray(originalArray, &size);

    if(!ptr)
        return NULL;

    printArray(ptr, size);

    if(size == 1)
    {
        printf("The original array only has one element, so no need to free any memory as no memory has been allocated dynamically.");
        return 2;
    }

    free(ptr);

    return 0;
}

