#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrcmp(char *str1, char *str2)
{
    int i = 0;
    int flag = 0;

    while(flag == 0)
    {
        if(str1[i] < str2[i])
            flag = -1;
        else if(str1[i] > str2[i])
            flag = 1;
        if(str1[i] == '\0')
            break;
        i++;
    }

    return flag;
}

int main() {

    char str_1[] = "mohsen";
    char str_2[] = "cherfl";
    int result = myStrcmp(str_1, str_2);

    switch(result)
    {
        case 1:
            printf("First string is greater than the second string! \n");
            break;
        case -1:
            printf("First string is less than the second string! \n");
            break;
        case 0:
            printf("Identical strings! \n");
            break;
    }

    return 0;
}

