#include <stdio.h>
#define SIZE 6

void swapCharacters(char *ptr1, char *ptr2)
{
    char temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
void printArray(char *arr, int size)
{
    for(int i=0; i<size; i++)
        printf("%c", arr[i]);
    printf("\n");
}
void reverseArrayIterative(char *arr, int size)
{
    for(int i=0; i<size/2; i++)
    {
        swapCharacters(&arr[i], &arr[size-1-i]);
//        swapCharacters(arr+i, arr+size-1-i);      // pointer arithmetic
    }
}
void reverseArrayRecursive(char *arr, int size)
{
    if(size > 1)
    {
        swapCharacters(&arr[0], &arr[size-1]);
//        swapCharacters(arr, arr+size-1);          // pointer arithmetic
        reverseArrayRecursive(arr+1, size-2);
    }
}

int main()
{
    char name[SIZE] = {'m','o','h','s','e','n'};

    printf("Before reversing: \n");
    printArray(name, SIZE);
    reverseArrayIterative(name, SIZE);
    reverseArrayRecursive(name, SIZE);
    printf("After reversing: \n");
    printArray(name, SIZE);

    return 0;
}
