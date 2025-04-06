#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputValue(int **a, int row, int column)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void printValue(int **a, int row, int column)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void alloc2DArrByRef(int ***matrix, int *row, int *column)
{
    *matrix = calloc(*row, sizeof(int*));
    if(!*matrix)
        exit(2);

    for(int i=0; i<*row; i++)
    {
        (*matrix)[i] = calloc(column, sizeof(int));
        if(!(*matrix)[i])
            exit(2);
    }
}

void freeMatrix(int **matrix, int row) {
    if (matrix != NULL) {
        for (int i = 0; i < row; i++) {
            if (matrix[i] != NULL) {
                free(matrix[i]);
            }
        }
        free(matrix);
    }
}

int main() {

    int **MyMatrix;
    int rows, columns;
    printf("Enter the row size: ");
    scanf("%d", &rows);
    printf("Enter the column size: ");
    scanf("%d", &columns);

    alloc2DArrByRef(&MyMatrix, &rows, &columns);
    if(!MyMatrix)
        return 1;

    inputValue(MyMatrix, rows, columns);
    printValue(MyMatrix, rows, columns);

    freeMatrix(MyMatrix, rows);

    return 0;
}

