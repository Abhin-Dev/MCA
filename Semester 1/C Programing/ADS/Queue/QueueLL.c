#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head,*temp,*newnode;
void enqueue(){
                newnode=malloc(sizeof(struct node));
            newnode->next=0;
            printf("Enter Your Data:");
            scanf("%d",&newnode->data);
            if(head==0){
                head=newnode;
                temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
}
void dequeue(){
                if(head==0){
                printf("Queue Is Empty\n");
            }
            else{
                printf("Deqeued Element Is:%d\n",head->data);
                temp=head->next;
                head=temp;
            }
}
void top(){
    if(head==0){
                printf("Queue Is Empty\n");
            }
            else{
                printf("Top Element Is:%d\n",head->data);
            }
}
void display(){
    if(head==0){
                printf("Queue Is Empty");
            }
            else{
                temp=head;
                printf("Elements In The Queue Are:");
                while(temp!=0){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
            }
	    temp=head;
	    while(temp->next!=0){
	        temp=temp->next;
	    }	
}
void main(){
    int a,b,i,ch,c=1;
    head=0;
    while(c){
        printf("\n1.Enqueue\n2.Dequeue\n3.Top\n4.Display\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            top();
            break;
            case 4:
            display();
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