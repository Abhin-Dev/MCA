#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head,*temp,*newnode,*prevnode;

int count=0,pos,i,j;

void printlist(){
    if(head==NULL){
        printf(" List Is Empty");
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
    newnode=malloc(sizeof(struct node));
    printf("Enter Your Data:");
    scanf("%d",&newnode->data);
    count++;
    if(head==NULL){
        head=newnode;
        head->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    printlist();
}
void ins_end(){
    if(head==NULL){
        ins_beg();
    }
    else{
        newnode=malloc(sizeof(struct node));
        printf("Enter Your Data:");
        scanf("%d",&newnode->data);
        count++;
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL){
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
void del_beg(){
    if(head==NULL){
        printlist();
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
        count--;
    }
    printlist();
}
void del_end(){
    if(head==NULL){
        printlist();
    }
    else if(count==1){
        temp=head;
        head=NULL;
        free(temp);
        count--;
        printlist();
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            prevnode=temp;
            temp=temp->next;
        }
        prevnode->next=NULL;
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
        if(pos>0 && pos<=count){
            if(pos==1){
                del_beg();
            }
            else if(count==pos){
                del_end();
            }
            else{
                temp=head;
	            j=1;
                while(j<pos){
                    prevnode=temp;
                    temp=temp->next;
                    j++;
                }
            prevnode->next=temp->next;
            free(temp);
            count--;
            printlist();
            }
        }
        else{
            printf("Invalid Entry ");
        }
    }
}
void main(){
    int ch=1,c;
    head=NULL;
    while(ch){
        printf("\n1.Insertion At Beginning\n2.Insertion At Anywhere\n3.Insertion At End\n4.Deletion At Beginning");
        printf("\n5.Deletion At Anywhere\n6.Deletion At End\n7.Display\n8.Stop\n");
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
            del_beg();
            break;
            case 5:
            del_any();
            break;
            case 6:
            del_end();
            break;
            case 7:
            printlist();
            break;
            case 8:
            ch=0;
            break;
            default:
            printf("Invalid Entry");
            break;
        }
    }
}