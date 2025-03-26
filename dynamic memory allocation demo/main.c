#include <stdio.h>
#include <stdlib.h>

void inputArray(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Enter value #%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int size)
{
    printf("{ ");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

int main()
{
    int *arr1, *arr2;
    int arrSize;
    printf("Enter the size of arrays: ");
    scanf("%d", &arrSize);
    arr1 = (int*)malloc(arrSize * sizeof(int));
    arr2 = (int*)calloc(arrSize, sizeof(int));

    if(arr1 || arr2 != NULL)
        printf("Allocation succeeded! \n");
    else
        printf("Allocation failed! \n");

    printf("Array elements before assigning values (with malloc function): \n");
    printArray(arr1, arrSize);
    printf("Array elements before assigning values (with calloc function): \n");
    printArray(arr2, arrSize);

    inputArray(arr1, arrSize);
    printf("Array elements after assigning values (with malloc function): \n");
    printArray(arr1, arrSize);

    inputArray(arr2, arrSize);
    printf("Array elements after assigning values (with calloc function): \n");
    printArray(arr2, arrSize);

    free(arr1);
    free(arr2);

    return 0;
}
