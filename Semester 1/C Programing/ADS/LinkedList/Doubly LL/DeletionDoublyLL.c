#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head,*tail,*temp,*newnode;
int count=0,j,pos;
void printlist(){
    if(head==NULL){
        printf("List Is Empty");
    }
    else{
        temp=head;
        printf("Elements Are:");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\nCount=%d",count);
    }
}
void del_beg(){
    if(head==NULL){
        printlist();
    }
    else if(head==tail){
        temp=head;
        head=NULL;
        tail=NULL;
        free(temp);
        count--;
        printlist();
    }
    else{
        temp=head;
        head=head->next;
        temp->prev=NULL;
        free(temp);
        count--;
        printlist();
    }
}
void del_end(){
    if(head==NULL){
        printlist();
    }
    else if(head==tail){
        temp=tail;
        tail=NULL;
        head=NULL;
        free(temp);
        count--;
        printlist();
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
        count--;
        printlist();
    }
}
void del_any(){
    if(head==NULL){
        printlist();
    }
    else{
        printf("which Position Do You want to delete:");
        scanf("%d",&pos);
        if(pos>0 && pos<=count){
            if(pos==1){
            del_beg();
            }
            else if(pos==count){
            del_end();
            }
            else{
                temp=head;
                j=1;
                while(j<pos){
                    temp=temp->next;
                    j++;
                }
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
                count--;
                printlist();
            }
        }
        else{
            printf("Invalid Position");
        }
    }
}
void main(){
    int i,ch=1,c,a;
    head=NULL;
    tail=NULL;
    printf("How many nodes do you want:");
    scanf("%d",&a);
    for(i=0;i<a;i++){
        newnode=malloc(sizeof(struct node));
        printf("Enter Your Data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        count++;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    printlist();
    while(ch){
    
        printf("\n1.Beginning\n2.Anywhere\n3.End\n4.Display\n5.Stop");
        printf("\nWhich deletion operation do you want:");
        scanf("%d",&c);
        switch(c){
            case 1:
            del_beg();
            break;
            case 2:
            del_any();
            break;
            case 3:
            del_end();
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