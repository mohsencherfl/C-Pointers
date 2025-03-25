#include <stdio.h>
#define SIZE 7

int howArrayIsSorted(int *arr, int *isReallySorted)
{
    *isReallySorted = 1;

    for(int i=1; i<SIZE-1; i++)
    {
        if(arr[i] <= arr[i-1])
            *isReallySorted = 0;
        if(arr[i] < arr[i-1])
            return 0;
    }

    return 1;
}

int main()
{
    int myArray[SIZE] = {2,4,7,11,13,30,40};
    int returnValue;
    int isReallySortFlag;

    returnValue = howArrayIsSorted(myArray, &isReallySortFlag);

    if(returnValue == 1 && isReallySortFlag == 1)
        printf("The array is really sorted. \n");
    else if(returnValue == 1 && isReallySortFlag == 0)
        printf("The array is sorted. \n");
    else if(returnValue == 0 && isReallySortFlag == 0)
        printf("The array is not sorted. \n");
}

