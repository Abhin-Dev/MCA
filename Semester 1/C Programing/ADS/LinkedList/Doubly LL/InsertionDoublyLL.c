#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*newnode,*temp,*nextnode,*tail;
int count=0,pos,i;
void creation(){
    newnode=malloc(sizeof(struct node));
    printf("Enter Your Data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    count++;
}
void printlist(){
    if(head==NULL){
        printf("Empty");
    }
    else{
        temp=head;
        printf("Elements Are:");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\nCount=%d",count);
}
void ins_beg(){
    creation();
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    printlist();
}
void ins_end(){
    if(head==NULL){
        ins_beg();
    }
    else{
        creation();
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
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
            creation();
            i=1;
            temp=head;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            nextnode=temp->next;
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next=newnode;
            nextnode->prev=newnode;
            printlist();
        }
    }
    else{
        printf("Invalid Position");
    }
}
void main(){
    int ch=1,c;
    head=NULL;
    tail=NULL;
    while(ch){
        printf("\n1.Beginning\n2.Anywhere\n3.End\n4.Display\n5.Stop\n");
        printf("Which Operation Do You Want:");
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
            printf("Invalid Entry!!!");
            break;
        }
    }
}