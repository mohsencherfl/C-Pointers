#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrlen(char *str)
{
    int length = 0;
    while(str[length] != '\0')
        length++;
    return length;
}

// A better choice when str1 has enough size to contain str2
void myStrcat_1(char *str1, char *str2)     // This will update the str1 string globally
{
    int lengthStr1 = myStrlen(str1);
    int lengthStr2 = myStrlen(str2);
    for(int i=0; i<lengthStr2; i++)
    {
        str1[i+lengthStr1] = str2[i];
    }
}

// A better choice when str1 has enough size to contain str2
char *myStrcat_2(char *str1, char *str2)    // This will update the str1 string globally and return it as well
{
    int lengthStr1 = myStrlen(str1);
    int lengthStr2 = myStrlen(str2);
    for(int i=0; i<lengthStr2; i++)
    {
        str1[i+lengthStr1] = str2[i];
    }
    return str1;
}

// A better choice when str1 does not have enough size to contain str2
char *myStrcat_3(char *str1, char *str2)        // This will allocate a dynamic memory for newStr string,
{                                               // assign str1 and str2 elements to it and
    int lengthStr1 = myStrlen(str1);            // return newStr after the assignment operation is done.
    int lengthStr2 = myStrlen(str2);            // But this will not update str1 globally
    char *newStr = malloc(lengthStr1 + lengthStr2 + 1);

    if(!newStr)
    {
        printf("Memory allocation failed. Exiting the program! \n");
        exit(2);
    }

    for(int i=0; i<lengthStr1; i++)
    {
        newStr[i] = str1[i];
    }

    for(int i=0; i<lengthStr2; i++)
    {
        newStr[i+lengthStr1] = str2[i];
    }
    newStr[lengthStr1+lengthStr2] = '\0';

    return newStr;
}

int main() {

    char str_1[40] = "Hello ";
    char str_2[] = "World! ";
    char str_3[] = "How you doin? ";
    char str_4[] = "I am fine!";
    char *str_5;
    char *str_6;

    printf("Str_1 before concatenation: %s \n", str_1);
    myStrcat_1(str_1, str_2);
    printf("Str_1 after first concatenation: %s \n", str_1);
    str_5 = myStrcat_2(str_1, str_3);
    printf("Str_1 after second concatenation: %s \n", str_1);
    str_6 = myStrcat_3(str_1, str_4);
    printf("Str_1 after third concatenation: %s \n", str_1);

    printf("Str_5: %s \n", str_5);
    printf("Str_6: %s \n", str_6);

    free(str_6);

    return 0;
}

