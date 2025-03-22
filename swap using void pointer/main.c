#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void genericSwap(void *a, void *b, int size);

int main()
{
    int num1 = 10, num2 = 20;
    double average1 = 70.45, average2 = 80.80;

    printf("Before swapping: \n");
    printf("Integer values: num1 = %d, num2 = %d \n", num1, num2);
    printf("Integer values: average1 = %lf, average2 = %lf \n", average1, average2);
    genericSwap(&num1, &num2, sizeof(int));
    genericSwap(&average1, &average2, sizeof(double));
    printf("After swapping: \n");
    printf("Integer values: num1 = %d, num2 = %d \n", num1, num2);
    printf("Integer values: average1 = %lf, average2 = %lf \n", average1, average2);

    return 0;
}

void genericSwap(void *a, void *b, int size)
{
    void *tempMemory = malloc(size);

    memcpy(tempMemory, a, size);
    memcpy(a, b, size);
    memcpy(b, tempMemory, size);

    free(tempMemory);
}

