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

void *myRealloc(void *oldArr, int newsize, int elementsize)
{
    void *newArr = malloc(newsize*elementsize);

    if(newArr == NULL)
        return NULL;

    memcpy(newArr, oldArr, newsize*elementsize);

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

    int n;
    printf("How many grades do you want to add or remove (use positive number for addition and negative number for removing: ");
    scanf("%d", &n);
    totalGrades += n;

    // code
    // code
    // code

    if(n > 0)
    {
        temp = (void*)myRealloc(grades, totalGrades, sizeof(int));

        if(temp == NULL)
        {
            printf("Memory reallocation failed... \n");
            return 1;
        }

        grades = temp;
        reinputArray(grades, totalGrades, n);
        printArray(grades, totalGrades);
    }
    else if(n < 0)
    {
        temp = (void*)myRealloc(grades, totalGrades, sizeof(int));

        if(temp == NULL)
        {
            printf("Memory reallocation failed... \n");
            return 1;
        }

        grades = temp;
        printArray(grades, totalGrades);
    }
    else
        printf("You have decided not to resize your array, so we move on... \n");


    // code
    // code
    // code


    free(grades);

    return 0;
}
