#include <stdio.h>

void printInt(void* a)
{
    printf("%d ", *(int*)a);
}

void printFloat(void* a)
{
    printf("%.1f ", *(float*)a);
}

void printDouble(void* a)
{
    printf("%.1lf ", *(double*)a);
}

void printChar(void* a)
{
    printf("%c ", *(char*)a);
}

void printDoubleInt(void* a)
{
    printf("%d ", 2 * *(int*)a);
}

void performOperation(void* arr, int length, int elementSize, void (*operation)(void*))
{
    for(int i=0; i<length; i++)
    {
        operation((char*)arr+i*elementSize);
    }
    printf("\n");
}

int main() {

    int arrInt[] = {1, 2, 3, 4, 5};
    float arrFloat[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double arrDouble[] = {1.2, 2.3, 3.4, 4.5, 5.6};
    char arrChar[] = {'g', 'o', 'o', 'g', 'l', 'e'};

    // Int array
    performOperation(arrInt, 5, sizeof(int), printInt);
    // Float array
    performOperation(arrFloat, 5, sizeof(float), printFloat);
    // Double array
    performOperation(arrDouble, 5, sizeof(double), printDouble);
    // Char array
    performOperation(arrChar, 6, sizeof(char), printChar);
    // Double the integer array
    performOperation(arrInt, 5, sizeof(int), printDoubleInt);

    return 0;
}
