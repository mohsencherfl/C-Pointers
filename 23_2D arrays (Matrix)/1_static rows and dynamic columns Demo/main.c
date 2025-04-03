#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int *arr[5];
    int numOfColumns[5];       // We store the number of columns for each row for further usage.

    for(int i=0; i<5; i++)      // Assign number of columns for each row.
    {
        printf("Enter the number of columns for row #%d: ", i+1);
        scanf("%d", &numOfColumns[i]);

        arr[i] = calloc(numOfColumns[i], sizeof(int));      // Allocate the exact amount of memory for each row based on the number of its columns.

        if(!arr[i])
        {
            for(int j=0; j<i; j++)
                free(arr[i]);
            return 1;
        }
    }

    for(int i=0; i<5; i++)      // Fill the matrix with values.
    {
        for(int j=0; j<numOfColumns[i] ; j++)
        {
            printf("Value of arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<5; i++)      // print the values in the matrix.
    {
        for(int j=0; j<numOfColumns[i] ; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<5; i++)      // Free allocated memory.
        free(arr[i]);

    return 0;
}
