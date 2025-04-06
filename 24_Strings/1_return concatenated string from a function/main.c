#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strConcat(char *originalStr);
void printStr(char *str);

int main() {

    char *myStr = malloc(strlen("mohsen Cherfl ") + 1);
    if(!myStr)
    {
        printf("Memory allocation for myStr failed! \n");
        return 2;
    }
    strcpy(myStr, "mohsen Cherfl ");
    printStr(myStr);

    char *tempStr = strConcat(myStr);

    if(!tempStr)
    {
        printf("Memory allocation failed during concatenation. \n");
        free(myStr);
        return 1;
    }

    free(myStr);
    myStr = tempStr;
    printStr(tempStr);

    free(myStr);

    return 0;
}

char *strConcat(char *originalStr)
{
    char *newStr;
    int lengthOriginal = strlen(originalStr);
    int i;
    newStr = malloc(2*lengthOriginal*sizeof(char) + 1);

    if(!newStr)
    {
        printf("Memory allocation for newStr failed! \n");
        return NULL;
    }

    for(i=0; i<lengthOriginal; i++)
    {
        newStr[i] = originalStr[i];
        newStr[i+lengthOriginal] = originalStr[i];
    }
    newStr[i+lengthOriginal] = '\0';

    return newStr;
}

void printStr(char *str)
{
    int lengthStr = strlen(str);
    for(int i=0; i<lengthStr; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

