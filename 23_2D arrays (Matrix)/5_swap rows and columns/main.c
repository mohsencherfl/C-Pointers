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

void swapColumns(double **matrix, int col_1, int col_2)
{
    for(int i=0; i<4; i++)
    {
        double temp = matrix[i][col_1];
        matrix[i][col_1] = matrix[i][col_2];
        matrix[i][col_2] = temp;
    }
}

void printAddress(double **matrix)
{
    for(int i=0; i<4; i++)
    {
        printf("%p \n", matrix[i]);
    }
    printf("\n");
}

void printValues(double **matrix)
{
    for(int i=0; i<4; i++)
    {
        printf("\t");
        for(int j=0; j<2; j++)
        {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
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

    matrix[0][0] = 10;
    matrix[0][1] = 20;

    matrix[1][0] = 30;
    matrix[1][1] = 40;

    matrix[2][0] = 50;
    matrix[2][1] = 60;

    matrix[3][0] = 70;
    matrix[3][1] = 80;

    printf("Matrix before swapping columns: \n");
    printValues(matrix);

    swapColumns(matrix, 0, 1); // Swap the first and second columns

    printf("Matrix after swapping columns: \n");
    printValues(matrix);

    return 0;
}

