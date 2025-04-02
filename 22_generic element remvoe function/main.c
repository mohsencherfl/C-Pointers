#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *elementRemoval(void *sourceArray, int sourceSize, int index, int elementSize) {
    void *newArr;

    // Allocate memory for the new array
    newArr = malloc((sourceSize - 1) * elementSize);
    if (!newArr) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    // Copy elements before the removed index
    memcpy(newArr, sourceArray, index * elementSize);
    // Copy elements after the removed index
    memcpy((char*)newArr + index * elementSize,
           (char*)sourceArray + (index + 1) * elementSize,
           (sourceSize - index + 1) * elementSize);

    return newArr;
}

void printOriginalArray(float *arr, int size) {
    printf("Original array = {  ");
    for (int i = 0; i < size; i++) {
        printf("%.2f  ", arr[i]);
    }
    printf("}\n");
    printf("Original array size = %d \n\n", size);
}

void printUpdatedArray(float *arr, int size) {
    printf("Updated array = {  ");
    for (int i = 0; i < size; i++) {
        printf("%.2f  ", arr[i]);
    }
    printf("}\n");
    printf("Updated array size = %d \n\n", size);
}

int main() {
    float originalArray[] = {1.5, 5.5, 99.1, 83.1, 75.8, 88.88, 32.9, 41.4};
    float *updatedArray = NULL;
    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]); // Calculate actual size dynamically
    int removedIndex = 2;
    int updatedArraySize = originalSize - 1;

    printOriginalArray(originalArray, originalSize);
    updatedArray = elementRemoval(originalArray, originalSize, removedIndex, sizeof(float));

    printUpdatedArray(updatedArray, updatedArraySize);

    if (!updatedArray) {
        printf("Main function returned null.\n");
        return 1;
    }

    free(updatedArray);

    return 0;
}

