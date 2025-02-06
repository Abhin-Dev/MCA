#include <stdio.h>
int main()
{
    int n, a[20], i, s, flag = 0;
    printf("How Many Numbers\n");
    scanf("%d", &n);
    printf("Enter Your Numbers\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter Your Searchkey\n");
    scanf("%d", &s);
    for (i = 0; i < n; i++)
    {
        if (a[i] == s)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("Your NUmber is at %d th position", i + 1);
    if (flag == 0)
        printf("Error Not found");
}