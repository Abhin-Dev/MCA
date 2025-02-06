#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
 void main(){
     struct node *head,*temp,*newnode;
     int i,a,count=0;
     head=NULL;
     printf("How Many Nodes Do You want:");
     scanf("%d",&a);
     for(i=0;i<a;i++){
        newnode=malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("Enter Your Data:");
        scanf("%d",&newnode->data);
        count++;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
     }
     printf("Entered Elements Are:");
     temp=head;
     while(temp!=NULL){
         printf("%d ",temp->data);
         temp=temp->next;
     }
     printf("\nCount=%d",count);
 }