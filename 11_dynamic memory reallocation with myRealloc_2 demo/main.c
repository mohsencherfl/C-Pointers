#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputArray(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("Enter value #%d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void reinputArray(int *arr, int size, int n)
{
    for(int i=size-n; i<size; i++)
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

void *myRealloc(void *oldArr, int oldsize, int newsize)
{
    char *newArr = (char*)malloc(newsize);

    if(newArr == NULL)
        return NULL;

    int elementsToCopy = (oldsize < newsize)? oldsize : newsize;

    for(int i=0; i<elementsToCopy; i++)
        newArr[i] = ((char*)oldArr)[i];

    free(oldArr);

    return newArr;
}

int main()
{
    int *grades = NULL;
    int *temp = NULL;
    int totalGrades;
    printf("How many grades do you have: ");
    scanf("%d", &totalGrades);
    grades = (int*)malloc(totalGrades * sizeof(int));

    if(grades == NULL)
    {
        printf("Memory allocation failed... \n");
        return 1;
    }

    inputArray(grades, totalGrades);
    printArray(grades, totalGrades);

    int newsize;
    printf("how many grades do you have now: ");
    scanf("%d", &newsize);

    // code
    // code
    // code

    if(newsize > 0)
    {
        temp = (int*)myRealloc(grades, totalGrades*sizeof(int), newsize*sizeof(int));

        if(temp == NULL)
        {
            printf("Memory reallocation failed... \n");
            return 1;
        }

        grades = temp;
        reinputArray(grades, newsize, newsize-totalGrades);
        printArray(grades, newsize);
    }
    else if(newsize < 0)
    {
        temp = (int*)myRealloc(grades, totalGrades*sizeof(int), newsize*sizeof(int));

        if(temp == NULL)
        {
            printf("Memory reallocation failed... \n");
            return 1;
        }

        grades = temp;
        printArray(grades, newsize);
    }
    else
        printf("You have decided not to resize your array, so we move on... \n");


    // code
    // code
    // code


    free(grades);

    return 0;
}

