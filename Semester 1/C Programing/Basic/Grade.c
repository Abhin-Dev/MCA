#include <stdio.h>
#include<stdlib.h>
int main()
    {
    int m,g;
    printf("Enter Your Mark\n");
    scanf("%d",&m);
    g=m/10;
    switch(g)
    {
        case 10:
        case 9:
        printf("Your Garde Is A+");
        break;
        case 8:
        printf("Your Garde Is A");
        break;
        case 7:
        printf("Your Garde Is B+");
        break;
        case 6:
        printf("Your Garde Is B");
        break;
        case 5:
        printf("Your Garde Is C+");
        break;
        case 4:
        printf("Your Garde Is C");
        break;
        case 3:
        printf("Your Grade Is D+");
        break;
        default:
        printf("You Lost Idiot!!!");
        break;
        }
}