#include <stdio.h>
int main()
{
    int n,i;
    printf("How many numbers you want to print :");
    scanf("%d",&n);
    for (i = 1; i <=n; i++)
    {
        printf("%d\t", i);
    }
}