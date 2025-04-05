#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocColumn(double **matrix)
{
    for(int i=0; i<4; i++)
    {
        matrix[i] = calloc(2, sizeof(double));
    }
}

void swapRows(void **matrix, int row1, int row2)
{
    void *temp;
    temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;
}

void printAddress(double **matrix)
{
    for(int i=0; i<4; i++)
    {
        printf("%p \n", matrix[i]);
    }
    printf("\n");
}

int main() {

    double **matrix;
    matrix = calloc(4, sizeof(double*));
    if(!matrix)
        return 1;

    allocColumn(matrix);
    printAddress(matrix);

    swapRows(matrix, 0, 3);
    printAddress(matrix);

    return 0;
}
