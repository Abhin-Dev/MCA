#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
}*head=NULL,*tail=NULL,*newnode,*temp;
int count=0;
void printlist(){
    if(head==NULL){
        printf("''List is Empty''");
    }
    else{
        temp=head;
        printf("Entered elements are:");
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
    printf("\nCount=%d",count);
}
void creation(){
    newnode=malloc(sizeof(struct node));
    printf("Enter Your data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    count++;
}
void ins_beg(){
    if(head==NULL){
        creation();
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        creation();
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        head->prev=tail;
        tail->next=head;
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
        tail->next=head;
        head->prev=tail;
        printlist();
    }
}
void ins_any(){
    int pos,i;
    printf("Which position do you want to insert:");
    scanf("%d",&pos);
    if(pos>0 && pos<=count+1){
        if(head==NULL){
            ins_beg();
        }
        else if(pos==count+1){
            ins_end();
        }
        else{
            creation();
            temp=head;
            i=1;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            temp->next->prev=newnode;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->prev=temp;
            printlist();
        }
    }
    else{
        printf("Enter a valid position");
    }
}
void main(){
    int ch=1,c;
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