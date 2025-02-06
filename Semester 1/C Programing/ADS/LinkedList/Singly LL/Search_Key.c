#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL,*temp,*newnode;

int count=0,n,pos,flag;

void creation(){
    printf("\nHow many nodes do you want :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("Enter data :");
        scanf("%d",&newnode->data);
        count++;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
}

void display(){
    temp=head;
    if(head==NULL){
        printf("\n---List is empty---\n");
    }
    else{
        printf("\nEntered Elements :");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void search(){
    int key;
    if(head==NULL){
        printf("\n---List is empty---\n");
    }
    else{
        pos=0,flag=0;
        printf("\nEnter the key to be searched :");
        scanf("%d",&key);
        temp=head;
        while(temp!=NULL){
            pos++;
            if(temp->data==key){
                printf("\n%d is found at  position %d",key,pos);
                flag=1;
                break;
            }
            else{
                temp=temp->next;
            }
        }
        if(flag==0){
            printf("\n%d is not found on the list",key);
        }
    }
}
void main(){
    int choice,c=1;
    while(c){
        printf("\n1.Creation\n2.Display\n3.Search\n4.Exit\n");
        printf("\nSelect your operation : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            creation();
            break;
            case 2:
            display();
            break;
            case 3:
            search();
            break;
            case 4:
            printf("\nExiting...");
            c=0;
            break;
            default :
            printf("\n---Inavalid choice---");
            break;
        }
    }
}