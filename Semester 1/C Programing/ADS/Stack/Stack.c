#include <stdio.h>
#include <stdlib.h>
#define max 5
int stack[max];
int top = -1;
int a, b, c, i;
void full()
{
    printf("Stack Is Full");
}
void empty()
{
    printf("Stack Is Empty");
}
void push()
{
    if (top == max - 1)
    {
        full();
    }
    else
    {
        top++;
        printf("Enter Your Number:");
        scanf("%d", &a);
        stack[top] = a;
        printf("\nPushed Element:%d", stack[top]);
    }
}
void pop()
{
    if (top == -1)
    {
        empty();
    }
    else
    {
        b = stack[top];
        printf("\nPopped Element:%d", b);
        top--;
    }
}
void peek()
{
    if (top == -1)
    {
        empty();
    }
    else
    {
        printf("\nTop Element:%d", stack[top]);
    }
}
void display()
{
    if (top == -1)
    {
        empty();
    }
    else
    {
        printf("\nElements In The Stack:");
        for (i = top; i >= 0; i--)
        {
            printf("%d  ", stack[i]);
        }
    }
}
void main()
{
    while (1)
    {
        printf("\n\n1.Push\n2.Pop\n3.Peek\n4.Display\n");
        printf("\nSelect Your Operation:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("\n\nInvalid Choice");
            break;
        }
    }
}