#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*newnode,*temp,*nextnode,*tail;
int count=0,pos,i,j;
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
        printf(" List is Empty");
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
        printf("\n1.Insertion At Beginning\n2.Insertin At Anywhere\n3.Insertion At End\n4.Deletion At Beginning\n");
        printf("5.Deletion At Anywhere\n6.Deletion At End\n7.Display Elements\n8.Stop\n");
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
            printf("Invalid Entry!!!");
            break;
        }
    }
}