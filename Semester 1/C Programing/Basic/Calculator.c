#include <stdio.h>
int main()
{
    float a, b, ans;
    int c;
    printf("1.Addition 2.Subtraction 3.Multipilcation 4.Division \nEnter Your Choice  ");
    scanf("%d", &c);
    printf("\nEnter Your Numbers\n");
    scanf("%f%f", &a, &b);
    switch (c)
    {
    case 1:
        ans = a + b;
        printf("Result=%f", ans);
        break;
    case 2:
        ans = a - b;
        printf("Result=%f", ans);
        break;
    case 3:
        ans = a * b;
        printf("Result=%f", ans);
        break;
    case 4:
        ans = a / b;
        printf("Result=%f", ans);
        break;
    default:
        printf("Invalid Choice");
        break;
    }
}