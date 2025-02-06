#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL,*temp,*newnode,*tail=NULL;
void main(){
    int i,a,count=0;
    printf("How many nodes do you want:");
    scanf("%d",&a);
    for(i=0;i<a;i++){
        newnode=malloc(sizeof(struct node));
        printf("Enter Your Data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        count++;
        if(head==NULL){
            head=newnode;
            tail=newnode;
            tail->next=head;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }
    if(head==NULL){
        printf("Empty");
    }
    else{
        printf("Entered Elements Are:");
        temp=head;
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",tail->data);
    }
}