#include <stdio.h>
void main()
{
    float a, b, c, sum = 0, avg = 0;
    printf("Enter Your Numbers");
    scanf("%f%f%f", &a, &b, &c);
    sum = a + b + c;
    avg = sum / 3;
    printf("Sum is %f", sum);
    printf("\nAverage is %f", avg);
}