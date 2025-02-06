#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node *next;
    struct node *prev;
}*head=NULL,*temp,*newnode,*tail;
void main(){
    int n,count=0,i;
    printf("How many nodes do you want :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->prev=NULL;
        printf("Enter Data :");
        scanf(" %c",&newnode->data);
        count++;
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    temp=head;
    printf("Entered data :");
    while(temp!=NULL){
        printf("%c ",temp->data);
        temp=temp->next;
    }
    temp=head;
    printf("\nVowels:");
    while(temp!=NULL){
        if(temp->data=='A' || temp->data=='E' || temp->data=='I' || temp->data=='O' || temp->data=='U'){
            printf("%c ",temp->data);
        }
        temp=temp->next;
    }
}
