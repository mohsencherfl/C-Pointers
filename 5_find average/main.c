#include <stdio.h>

void updateAverage(int num1, int num2, float *avg)
{
    *avg = (num1 + num2) / 2.0;
}

int main()
{
    int a, b;
    float average;
    printf("Enter a value for 'a': ");
    scanf("%d", &a);
    printf("Enter a value for 'b': ");
    scanf("%d", &b);

    updateAverage(a, b, &average);

    printf("Average = %f \n", average);
}
