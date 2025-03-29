#include <stdio.h>
#include <stdlib.h>

// Function to create a 1D array dynamically
void creat1DArrayByRef(int **arr, int size)
{
    // Validate size
    if (size <= 0) {
        printf("Invalid array size. Exiting program.\n");
        exit(2); // Exit with error code 2 for invalid input
    }

    int *newArr = malloc(size * sizeof(int));
    if (!newArr) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1); // Exit with error code 1 for memory failure
    }

    inputArray(newArr, size);

    *arr = newArr; // Update the original pointer in main
}

// Function to take user input for the array
void inputArray(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to print the array
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
    int *ptr = NULL;  // Pointer to the dynamically allocated array
    int size;

    // Get the size of the array from the user
    printf("Please enter the size of the array: ");
    scanf("%d", &size);

    // Create the array dynamically
    creat1DArrayByRef(&ptr, size);

    // Print the array
    printArray(ptr, size);

    // Free allocated memory
    free(ptr);

    return 0;
}
