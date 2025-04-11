#include <stdio.h>

void addition(int a, int b)
{
    printf("%d + %d = %d", a, b, a+b);
}

void subtraction(int a, int b)
{
    printf("%d - %d = %d", a, b, a-b);
}

void multiplication(int a, int b)
{
    printf("%d * %d = %d", a, b, a*b);
}

void division(int a, int b)
{
    if(b != 0)
        printf("%d / %d = %.2f", a, b, (float)a/b);
    else
        printf("Cannot divide by 0");
}

void remainder(int a, int b)
{
    if(b != 0)
        printf("%d %% %d = %d", a, b, a%b);
    else
        printf("Cannot divide by 0");
}

int main() {

    void (*ptrArr[])(int, int) = {addition, subtraction, multiplication, division, remainder};
    int num1, num2;
    char choice;
    printf("Choose: \n0 -> addition \n1 -> subtraction \n2 -> multiplication \n3 -> division \n4 -> remainder \n");
    scanf("%d", &choice);
    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);

    (ptrArr[choice])(num1, num2);

    return 0;
}
