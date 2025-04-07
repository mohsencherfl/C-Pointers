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

void myStrcpy(char *str1, char *str2, int size1, int size2)
{
    if(size1 < size2)
    {
        printf("Destination array size is not sufficient to hold source array. Exiting the program! \n");
        exit(2);
    }

    int i = 0;
    while(str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

int main() {

    char str_1[] = "Hello World!";
    char str_2[] = "hi there, how are things?";

    int size_str1 = sizeof(str_1);
    int size_str2 = sizeof(str_2);

    printf("Destination array size = %d \n", size_str1);
    printf("Source array size = %d \n", size_str2);

    printf("Str_1 before copying: %s \n", str_1);
    myStrcpy(str_1, str_2, size_str1, size_str2);
    printf("Str_1 after copying: %s \n", str_1);

    return 0;
}

