
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to dynamically fill array with user input
int *adjustableReallocation(int *arrSize)
{
    int num;
    int size = 2;
    int lastIndex = 0;

    int *arr = NULL;
    int *temp = NULL;

    printf("Enter a value: ");
    scanf("%d", &num);

    if(num == -1)
    {
        *arrSize = 0;
        return NULL;
    }
    else
    {
        arr = (int*)malloc(size * sizeof(int));
        if(!arr) return NULL;
    }

    while(num != -1)
    {
        if(lastIndex == size)
        {
            size *= 2;      // Double the size
            temp = (int*)realloc(arr, size *sizeof(int));
            if(!temp)
            {
                free(arr);  // Free memory on realloc failure
                return NULL;
            }
            arr = temp;
        }
        arr[lastIndex] = num;
        lastIndex++;
        printf("Enter another value: ");
        scanf("%d", &num);
    }

    if(lastIndex < size)
    {
        temp = (int*)realloc(arr, lastIndex * sizeof(int));
        if(!temp)
        {
            free(arr);      // Free memory on realloc failure
            return NULL;
        }
        arr = temp;
    }

    *arrSize = lastIndex;       // Update size in calling function

    return arr;
}

// Function to print array and total size
void printArray(int *arr, int size)
{
    printf("Grades = { ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("Total grades = %d\n", size);
}

// Main function
int main()
{
    int *grades;      // Pointer to dynamically allocated array
    int totalGrades;  // Variable to store size of array

    // Fill array with user input
    grades = adjustableReallocation(&totalGrades);

    if (grades == NULL) {
        printf("No values.\n");
        return 1;
    }

    // Print the filled array
    printArray(grades, totalGrades);

    // Free allocated memory
    free(grades);

    return 0;
}
