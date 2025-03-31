#include <stdio.h>
#include <stdlib.h>

int *separateLowerUpperLetters(int *sourceArray, int sourceSize, int *lowerSize, int **upperArr, int *upperSize)
{
    int *newLowerArr;
    for(int i=0; i<sourceSize; i++)
    {
        if(sourceArray[i] >= 'a' && sourceArray[i] <= 'z')
            (*lowerSize)++;
        else if(sourceArray[i] >= 'A' && sourceArray[i] <= 'Z')
            (*upperSize)++;
    }

    newLowerArr = malloc(*lowerSize * sizeof(int));
    if(!newLowerArr)
    {
        printf("Memory allocation for lower letters array failed. Exiting program. \n");
        exit(1);
    }

    *upperArr = malloc(*upperSize * sizeof(int));
    if(!upperArr)
    {
        printf("Memory allocation for upper letters array failed. Exiting program. \n");
        exit(1);
    }

    for(int i=0,j=0,k=0; i<sourceSize; i++)
    {
        if(sourceArray[i] >= 'a' && sourceArray[i] <= 'z')
        {
            newLowerArr[j] = sourceArray[i];
            j++;
        }
        else if(sourceArray[i] >= 'A' && sourceArray[i] <= 'Z')
        {
            (*upperArr)[k] = sourceArray[i];        // *upperArr must be in parenthesis
            k++;
        }
    }

    return newLowerArr;
}

void printOriginalArray(int *arr, int size)
{
    printf("Original array = { ");
    for (int i = 0; i < size; i++) {
        printf("%c-", arr[i]);
    }
    printf("}\n");
    printf("Original array size = %d \n\n", size);
}

void printlowerCaseArray(int *arr, int size)
{
    printf("Lowercase letters array = { ");
    for (int i = 0; i < size; i++) {
        printf("%c-", arr[i]);
    }
    printf("}\n");
    printf("Lowercase letters array size = %d \n\n", size);
}

void printUpperCaseArray(int *arr, int size)
{
    printf("Uppercase letters array = { ");
    for (int i = 0; i < size; i++) {
        printf("%c-", arr[i]);
    }
    printf("}\n");
    printf("Uppercase letters array size = %d \n\n", size);
}

int main()
{
    int originalArray[] = {'M', 'o', 'h', 's', 'E', 'n', 'C', 'h', 'e', 'R', 'F', 'l'};
    int originalSize = sizeof(originalArray) / sizeof(originalArray[0]);
    int *lowerCaseArray = NULL;
    int *upperCaseArray = NULL;
    int lowerArraySize = 0;
    int upperArraySize = 0;

    printOriginalArray(originalArray, originalSize);
    lowerCaseArray = separateLowerUpperLetters(originalArray, originalSize, &lowerArraySize, &upperCaseArray, &upperArraySize);

    printlowerCaseArray(lowerCaseArray, lowerArraySize);
    printUpperCaseArray(upperCaseArray, upperArraySize);

    if(!lowerCaseArray || !upperCaseArray)
    {
        printf("Main function returned null. \n");
        return 1;
    }

    free(lowerCaseArray);
    free(upperCaseArray);

    return 0;
}

