#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rowHandle(int row)
{
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    if(row <= 0)       // Validate number of rows
    {
        printf("Invalid number of rows. Exiting the program! \n");
        exit(1);
    }

    return row;
}

int **allocate2DMatrix(int row)
{
    // Allocate memory for array of pointers (rows)
    int **arr = (int**)calloc(row, sizeof(int*));
    if(!arr)
    {
        printf("Memory allocation failed for rows. Exiting the program! \n");
        exit(1);
    }

    return arr;
}

int *allocateToKeepNumOfColumns(int row, int **matrix)
{
    // Allocate memory for columns
    int *column = (int*)calloc(row, sizeof(int));
    if(!column)
    {
        printf("Memory allocation failed for column sizes. Exiting the program! \n");
        free(matrix);
        exit(1);
    }

    return column;
}

void columnHandle(int row, int *colArr, int **matrix)
{
    for(int i=0; i<row; i++)      // Assign number of columns for each row.
    {
        printf("Enter the number of columns for row #%d: ", i+1);
        scanf("%d", &colArr[i]);

        if(colArr[i] <= 0)
        {
            printf("Invalid number of columns for row #%d. Exiting the program! \n", i+1);
            // Free previously allocated rows
            for(int j=0; j<i; j++)
                free(matrix[j]);
            free(matrix);
            free(colArr);
            exit(1);
        }

        matrix[i] = calloc(colArr[i], sizeof(int));      // Allocate the exact amount of memory for each row based on the number of its columns.
        if(!matrix[i])
        {
            printf("Memory allocation failed for row #%d. Exiting the program! \n");
            // Free previously allocated rows
            for(int j=0; j<i; j++)
                free(matrix[j]);
            free(matrix);
            free(colArr);
            exit(1);
        }
    }
}

void inputMatrix(int row, int *colArr, int **matrix)
{
    for(int i=0; i<row; i++)      // Fill the matrix with values.
    {
        for(int j=0; j<colArr[i] ; j++)
        {
            printf("Value of myMatrix[%d][%d]: ", i, j);
            if(scanf(" %d", &matrix[i][j]) != 1)
            {
                printf("Invalid input. Exiting the program! \n");
                exit(1);
            }
        }
    }
}

void printMatrix(int row, int *colArr, int **matrix)
{
    for(int i=0; i<row; i++)      // print the values in the matrix.
    {
        for(int j=0; j<colArr[i] ; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMemory(int row, int **colArr, int ***matrix) {
    for (int i = 0; i < row; i++) {
        free((*matrix)[i]); // Free each row
    }
    free(*matrix);         // Free the array of row pointers
    *matrix = NULL;        // Set the matrix pointer to NULL
    free(*colArr);          // Free the column array
    *colArr = NULL;         // Set the colArr pointer to NULL
}


int main() {

    int **myMatrix;
    int rows;
    int *columnArray;       // We store the number of columns for each row for further usage

    rows = rowHandle(rows);
    myMatrix = allocate2DMatrix(rows);
    columnArray = allocateToKeepNumOfColumns(rows, myMatrix);
    columnHandle(rows, columnArray, myMatrix);
    inputMatrix(rows, columnArray, myMatrix);
    printMatrix(rows, columnArray, myMatrix);
    freeMemory(rows, &columnArray, &myMatrix);

    // Check if freeMemory function works as intended!
    if(myMatrix == NULL && columnArray == NULL)
        printf("Now myMatrix and columnArray point to null. \n");
    else
    {
        myMatrix = NULL;
        columnArray = NULL;
    }

    return 0;
}
