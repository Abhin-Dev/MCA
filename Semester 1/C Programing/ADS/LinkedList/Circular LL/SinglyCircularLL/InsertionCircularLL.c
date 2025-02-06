#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL,*temp,*newnode,*tail=NULL;
int count=0,pos,i;
void creation(){
    newnode=malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    count++;
}
void printlist(){
    if(head==NULL){
        printf("Empty list");
    }
    else {
        temp = head;
        printf("Elements are: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);  // loop back when we reach the head
        printf("\nCount: %d", count);
    }
}
void ins_beg(){
    creation();
    if(head==NULL){
        head=newnode;
        tail=newnode;
        newnode->next=head;
    }
    else{
        newnode->next=head;
        head=newnode;
        tail->next=newnode;
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
        newnode->next=head;
        tail=newnode;
        printlist();
    }
}
void ins_any(){
    printf("Which position do you want to insert:");
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
        printf("Invalid position!!!");
    }
}
void main(){
    int ch=1,c;
    while(ch){
        printf("\n1.Beginning\n2.Anywhere\n3.End\n4.Display\n5.Stop\n");
        printf("Which operation do you want:");
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
            printf("Invalid choice");
            break;
        }
    }
}