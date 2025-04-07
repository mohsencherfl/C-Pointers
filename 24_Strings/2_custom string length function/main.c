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

int main() {

    char myStr[] = "Hello World!";

    printf("String length = %d \n", myStrlen(myStr));

    return 0;
}
