
#include <stdio.h>
#include <stdlib.h>

void inputArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size)
{
    printf("Array elements = { ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

void updateArray(int **arr, int *size, int value)
{
    *size += 1;
    *arr = realloc(*arr, (*size) * sizeof(int));
    if (*arr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    (*arr)[*size - 1] = value;
}

int sumArray(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void findAverage(int *arr, int size, double *ptrAverage)
{
    *ptrAverage = (double)sumArray(arr, size) / size;
    printf("Average = %.2lf\n\n", *ptrAverage);
}

void updateAverage(int **arr, int *size, double *ptrAverage, int newValue)
{
    updateArray(arr, size, newValue);
    displayArray(*arr, *size);
    findAverage(*arr, *size, ptrAverage);
}

int main()
{
    int size = 5;
    int *grades = malloc(size * sizeof(int));   // Allocate a dynamic memory
    double average;

    if (grades == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }


    inputArray(grades, size);
    displayArray(grades, size);
    findAverage(grades, size, &average);

    updateAverage(&grades, &size, &average, 10);    // Passing pointer by reference (&grades)
    updateAverage(&grades, &size, &average, 20);
    updateAverage(&grades, &size, &average, 30);
    updateAverage(&grades, &size, &average, 40);
    updateAverage(&grades, &size, &average, 50);
    updateAverage(&grades, &size, &average, 60);


    // Free allocated memory
    free(grades);

    return 0;
}
