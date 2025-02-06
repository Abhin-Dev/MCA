#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
}*head=NULL,*tail=NULL,*newnode,*temp;
void main(){
    int n;
    printf("How many nodes do you want:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=malloc(sizeof(struct node));
        printf("Enter your data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
            tail->next=head;
            head->prev=tail;
        }
    }
    printf("Elements are:");
    temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}