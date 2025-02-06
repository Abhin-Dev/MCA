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
        head->prev=tail;
        tail->next=head;
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
        del_beg();
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        count--;
        printlist();
    }
}
void del_any(){
    int pos,i;
    if(head==NULL){
        printlist();
    }
    else{
        printf("Which position do you want to delete:");
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
                i=1;
                while(i<pos){
                    temp=temp->next;
                    i++;
                }
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
                count--;
                printlist();
            }
        }
        else{
            printf("Enter a valid position");
        }
    }
}
void main(){
    int n,ch=1,c;
    printf("How many nodes do you want:");
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        newnode=malloc(sizeof(struct node));
        printf("Enter your data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        count++;
        if(head==NULL){
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
            tail->next=head;
            head->prev=tail;
        }
    }
    printf("Elements are:");
    temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
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