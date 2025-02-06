#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL,*temp,*newnode,*tail=NULL,*prev;
int i,j,a,count=0,pos,ch=1,c;
void printlist(){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        printf("Entered Elements Are:");
        temp=head;
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",tail->data);
    }
    printf("\nCount:%d",count);
}
void del_beg(){
    if(head==NULL){
        printlist();
    }
    else if(head==tail){
        free(head);
        count--;
        head=NULL;
        tail=NULL;
        printlist();
    }
    else{
        temp=head;
        head=head->next;
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
        temp=head;
        while(temp->next!=head){
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
        tail=prev;
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
        printf("Which position do you want to delete:");
        scanf("%d",&pos);
        if(0<pos && pos<=count){
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
                    prev=temp;
                    temp=temp->next;
                    i++;
                }
                prev->next=temp->next;
                free(temp);
                count--;
                printlist();
            }
        }
        else{
            printf("Invalid position!!!");
        }
    }
}
void main(){
    printf("How many nodes do you want:");
    scanf("%d",&a);
    for(j=0;j<a;j++){
        newnode=malloc(sizeof(struct node));
        printf("Enter Your Data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        count++;
        if(head==NULL){
            head=newnode;
            tail=newnode;
            newnode->next=head;
        }
        else{
            tail->next=newnode;
            newnode->next=head;
            tail=newnode;
        }
    }
    printlist();
    while(ch){
        printf("\n1.Beginning\n2.Anywhere\n3.End\n4.Display\n5.Stop\n");
        printf("Which operation do you want:");
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
            printf("Invalid Choice");
            break;
        }
    }
}