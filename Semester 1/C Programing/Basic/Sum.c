#include <stdio.h>
int main()
{
    int i, n, sum = 0;
    printf("Enter Your no.of numbers\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    printf("Required sum is %d", sum);
}