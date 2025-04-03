#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int **arr;
    int rows;
    int *columns;       // We store the number of columns for each row for further usage

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    if(rows <= 0)       // Validate number of rows
    {
        printf("Invalid number of rows. Exiting the program! \n");
        return 1;
    }

    // Allocate memory for array of pointers (rows)
    arr = (int**)calloc(rows, sizeof(int*));
    if(!arr)
    {
        printf("Memory allocation failed for rows. Exiting the program! \n");
        return 1;
    }

    // Allocate memory for columns
    columns = (int*)calloc(rows, sizeof(int));
    if(!columns)
    {
        printf("Memory allocation failed for column sizes. Exiting the program! \n");
        free(arr);
        return 1;
    }

    for(int i=0; i<rows; i++)      // Assign number of columns for each row.
    {
        printf("Enter the number of columns for row #%d: ", i+1);
        scanf("%d", &columns[i]);

        if(columns[i] <= 0)
        {
            printf("Invalid number of columns for row #%d. Exiting the program! \n", i+1);
            // Free previously allocated rows
            for(int j=0; j<i; j++)
                free(arr[j]);
            free(arr);
            free(columns);
            return 1;
        }

        arr[i] = calloc(columns[i], sizeof(int));      // Allocate the exact amount of memory for each row based on the number of its columns.
        if(!arr[i])
        {
            printf("Memory allocation failed for row #%d. Exiting the program! \n");
            // Free previously allocated rows
            for(int j=0; j<i; j++)
                free(arr[j]);
            free(arr);
            free(columns);
            return 1;
        }
    }

    for(int i=0; i<rows; i++)      // Fill the matrix with values.
    {
        for(int j=0; j<columns[i] ; j++)
        {
            printf("Value of arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<rows; i++)      // print the values in the matrix.
    {
        for(int j=0; j<columns[i] ; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<rows; i++)      // Free allocated memory.
        free(arr[i]);
    free(arr);
    free(columns);

    return 0;
}

