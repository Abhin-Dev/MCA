#include <stdio.h>
int main()
{
    int a[5], i;
    printf("Enter Your Numbers\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Entered Values are\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t", a[i]);
    }
}