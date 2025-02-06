#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL,*top1=NULL,*temp,*newnode,*prev;

int i,j,n,count=0;

void creation(){
    printf("How many nodes do you want :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("Enter data :");
        scanf("%d",&newnode->data);
        count++;
        if(top==NULL){
            top=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
}

void reversal(){
    int A[20];
    temp=top;
    for(i=0;i<count;i++){
        A[i]=temp->data;
        temp=temp->next;
    }
    i=0;
    for(i=count-1;i>=0;i--){
        newnode=malloc(sizeof(struct node));
        newnode->next=NULL;
        if(i==count-1){
            top1=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        temp->data=A[i];
    }
}

void display(){
    printf("\nEntered Elements :");
    temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\nReversed Elements :");
    temp=top1;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void deletion(){
    temp=top;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(temp==top){
        top=NULL;
        free(temp);
    }
    else{
        prev->next=NULL;
        free(temp);
    }
    temp=top1;
    if(count==1){
        top1=NULL;
        free(temp);
    }
    else{
        top1=temp->next;
        free(temp);
    }
    count--;
}

void main(){
    creation();
    reversal();
    display();
    deletion();
    display();
    deletion();
    display();
}