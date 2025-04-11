#include <stdio.h>
#include <stdbool.h>

    // Creating comparison functions

bool ascending(int a, int b)
{
    return a < b;
}

bool descending(int a, int b)
{
    return a > b;
}

    // Sorting function

void swap(int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void sort(int* arr, int n, bool (*compare)(int, int))
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(!compare(arr[j], arr[j+1]))
                swap(&arr[j], &arr[j+1]);
}

void printArray(int *arr, int n)
{
    printf("Array: \n");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("=============== \n\n");
}

int main() {

    int arr[] = { 2,1,6,8,4,9 };
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    sort(arr, n, ascending);
    printArray(arr, n);
    sort(arr, n, descending);
    printArray(arr, n);
    return 0;
}
