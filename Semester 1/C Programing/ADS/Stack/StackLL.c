#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head,*newnode,*temp;
void main(){
    int ch,i,a,b,c=1;
    head=0;
    while(c){
    printf("1.Push\n2.Pop\n3.Display\n4.Top\n5.Exit\n");
    scanf("%d",&ch);
        switch(ch){
            case 1:
            newnode=malloc(sizeof(struct node));
            printf("Enter Your Data:");
            scanf("%d",&newnode->data);
            if(head==0){
                head=newnode;
                temp=newnode;
                newnode->next=0;
            }
            else{
                newnode->next=head;
                head=newnode;
            }
            break;
            case 2:
            if(head==0){
                printf("Stack Is Empty\n");
            }
            else{
                printf("Popped Element Is:%d\n",head->data);
                temp=head->next;
                head->next=0;
                head=temp;
            }
            break;
            case 3:
            if(head==0){
                printf("Stack Is Empty\n");
            }
            else{
                temp=head;
                printf("Elements In The Stack Are: ");
                while(temp!=0){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
            }
            break;
            case 4:
            if(head==0){
                printf("Stack Is Empty\n");
            }
            else{
                printf("Top Element Is:%d\n",head->data);
            }
            break;
            case 5:
            c=0;
            break;
            default:
            printf("Invalid Choice");
            break;
        }
    }

}