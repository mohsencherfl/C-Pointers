#include <stdio.h>
#include <stdlib.h>

char *elementInsertion(char *sourceArray, int sourceSize, char element, int index)
{
    char *insertedArr;

    insertedArr = malloc((sourceSize+1) * sizeof(char));
    if(!insertedArr)
    {
        printf("Memory allocation failed. Exiting program. \n");
        exit(1);
    }
    for(int i=0; i<sourceSize+1; i++)
    {
        if(i == index)
            insertedArr[i] = element;
        else
        {
            if(i < index)
                insertedArr[i] = sourceArray[i];
            if(i > index)
                insertedArr[i] = sourceArray[i-1];
        }
    }

    return insertedArr;
}

void printOriginalArray(char *arr, int size)
{
    printf("Original array = { ");
    for (int i = 0; i < size; i++) {
        printf("%c-", arr[i]);
    }
    printf("}\n");
    printf("Original array size = %d \n\n", size);
}

void printInsertedArray(char *arr, int size)
{
    printf("Inserted array = { ");
    for (int i = 0; i < size; i++) {
        printf("%c-", arr[i]);
    }
    printf("}\n");
    printf("Inserted array size = %d \n\n", size);
}

int main()
{
    char originalArray[] = {'M', 'o', 'h', 's', 'E', 'n', 'C', 'h', 'e', 'R', 'F', 'l'};
    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]);
    char *insertedArray = NULL;
    char elementToInsert = '%';
    int insertIndex = 6;
    int insertedArraySize = originalSize+1;

    printOriginalArray(originalArray, originalSize);
    insertedArray = elementInsertion(originalArray, originalSize, elementToInsert, insertIndex);

    printInsertedArray(insertedArray, insertedArraySize);

    if(!insertedArray)
    {
        printf("Main function returned null. \n");
        return 1;
    }

    free(insertedArray);

    return 0;
}

