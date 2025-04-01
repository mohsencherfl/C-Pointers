#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *elementInsertion(void *sourceArray, int sourceSize, void *element, int index, int elementSize) {
    void *insertedArr;

    // Allocate memory for the new array
    insertedArr = malloc((sourceSize + 1) * elementSize);
    if (!insertedArr) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    // Copy elements before the insertion index
    memcpy(insertedArr, sourceArray, index * elementSize);
    // Insert the new element
    memcpy((char*)insertedArr + index * elementSize, element, elementSize);
    // Copy elements after the insertion index
    memcpy((char*)insertedArr + (index + 1) * elementSize,
           (char*)sourceArray + index * elementSize,
           (sourceSize - index) * elementSize);

    return insertedArr;
}

void printOriginalArray(float *arr, int size) {
    printf("Original array = {  ");
    for (int i = 0; i < size; i++) {
        printf("%.2f  ", arr[i]);
    }
    printf("}\n");
    printf("Original array size = %d \n\n", size);
}

void printInsertedArray(float *arr, int size) {
    printf("Inserted array = {  ");
    for (int i = 0; i < size; i++) {
        printf("%.2f  ", arr[i]);
    }
    printf("}\n");
    printf("Inserted array size = %d \n\n", size);
}

int main() {
    float originalArray[] = {1.5, 5.5, 99.1, 83.1, 75.8, 88.88, 32.9, 41.4};
    float *insertedArray = NULL;
    float elementToInsert = 28.3;
    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]); // Calculate actual size dynamically
    int insertIndex = 2;
    int insertedArraySize = originalSize + 1;

    printOriginalArray(originalArray, originalSize);
    insertedArray = elementInsertion(originalArray, originalSize, &elementToInsert, insertIndex, sizeof(float));

    printInsertedArray(insertedArray, insertedArraySize);

    if (!insertedArray) {
        printf("Main function returned null.\n");
        return 1;
    }

    free(insertedArray);

    return 0;
}

