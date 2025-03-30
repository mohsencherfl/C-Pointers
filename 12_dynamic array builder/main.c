#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to dynamically fill array with user input
int *fillArray(int *arr, int *size)
{
    *size = 1; // Initialize size to 1
    int value; // Temporary variable to store user input

    arr = (int*)malloc((*size) * sizeof(int)); // Allocate initial memory
    if (arr == NULL) {
        printf("Memory allocation failed...\n");
        return NULL;
    }

    // Input the first value
    printf("Enter a value: ");
    scanf("%d", &value);

    // Handle special case: First value is -1
    if (value == -1) {
        free(arr); // Free allocated memory
        return NULL; // Signal no values entered
    }

    // Loop until user enters -1
    while (value != -1) {
        arr[*size - 1] = value; // Assign value to array
        printf("Enter a value: ");
        scanf("%d", &value);

        if (value != -1) {
            (*size)++; // Increase size of array

            // Safely reallocate memory
            void *temp = realloc(arr, (*size) * sizeof(int));
            if (temp == NULL) {
                free(arr); // Free original memory if realloc fails
                return NULL; // Signal allocation failure
            }
            arr = (int*)temp; // Update pointer to newly allocated memory
        }
    }

    return arr; // Return pointer to dynamically allocated array
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
    grades = fillArray(grades, &totalGrades);

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
