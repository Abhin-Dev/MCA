#include <stdio.h>
int main()
{
    int a;
    printf("Enter Your Number");
    scanf("%d", &a);
    if (a > 0)
    {
        printf("Positive");
    }
    else
    {
        printf("Negative");
    }
}