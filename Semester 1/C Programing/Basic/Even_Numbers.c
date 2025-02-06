#include <stdio.h>
int main()
{
    int i, n;
    printf("Enter Your Number\n");
    scanf("%d", &n);
    for (i = 2; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            printf("%d\t", i);
        }
    }
}
