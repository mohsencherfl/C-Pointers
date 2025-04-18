#include <stdio.h>

void swap(int *ptr1, int *ptr2);

int main()
{
    int num1 = 10;
    int num2 = 20;

    printf("Before swapping: \n");
    printf("**num1** = %d \n", num1);
    printf("**num2** = %d \n", num2);
    swap(&num1, &num2);
    printf("After swapping: \n");
    printf("**num1** = %d \n", num1);
    printf("**num2** = %d \n", num2);

}

void swap(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
