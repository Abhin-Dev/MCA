#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head,*temp,*newnode;

int count=0,pos,i;

void printlist(){
    if(head==0){
        printf("Empty");
    }
    else{
        temp=head;
        printf("Elements Are:");
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\nCount=%d",count);
}
void ins_beg(){
    newnode=malloc(sizeof(struct node));
    printf("Enter Your Data:");
    scanf("%d",&newnode->data);
    count++;
    if(head==0){
        head=newnode;
        head->next=0;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    printlist();
}
void ins_end(){
    if(head==0){
        ins_beg();
    }
    else{
        newnode=malloc(sizeof(struct node));
        printf("Enter Your Data:");
        scanf("%d",&newnode->data);
        count++;
        newnode->next=0;
        temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
        printlist();
    }
}
void ins_any(){
    printf("Which Position Do You Want To Insert:");
    scanf("%d",&pos);
    if(pos>0 && pos<=count+1){
        if(pos==1){
            ins_beg();
        }
        else if(pos==count+1){
            ins_end();
        }
        else{
            newnode=malloc(sizeof(struct node));
            printf("Enter Your Data:");
            scanf("%d",&newnode->data);
            count++;
            temp=head;
            i=1;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            printlist();
        }
    }
    else{
        printf("Invalid Position");
    }
}
void main(){
    int ch=1,c;
    printf("Which Operation Do You Want");
    while(ch){
        printf("\n1.Beginning\n2.Anywhere\n3.End\n4.Display\n5.Stop\n");
        scanf("%d",&c);
        switch(c){
            case 1:
            ins_beg();
            break;
            case 2:
            ins_any();
            break;
            case 3:
            ins_end();
            break;
            case 4:
            printlist();
            break;
            case 5:
            ch=0;
            break;
            default:
            printf("Invalid Entry");
            break;
        }
    }
}