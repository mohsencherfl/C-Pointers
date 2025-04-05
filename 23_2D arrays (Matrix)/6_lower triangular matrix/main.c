#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputValue(int **a, int row)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void printValue(int **a, int row)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void **lowerTriangularMatrix(int **a, int *row)
{
    printf("Enter the row size: ");
    scanf("%d", row);
    a = calloc(*row, sizeof(int*));
    if(!a)
        return NULL;

    for(int i=0; i<*row; i++)
    {
        a[i] = calloc(i+1, sizeof(int));
    }

    inputValue(a, *row);
    printValue(a, *row);

    return a;
}

void freeMatrix(int **a, int row)
{
    for(int i=0; i<row; i++)
    {
        free(a[i]);
    }
    free(a);
}

int main() {

    int **matrix;
    int row;
    matrix = lowerTriangularMatrix(matrix, &row);
    if(!matrix)
        return 1;

    freeMatrix(matrix, row);

    return 0;
}
