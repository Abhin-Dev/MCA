#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL,*temp,*newnode,*tail=NULL,*prev;
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
    int ch=1,c;
    while(ch){
        printf("\n1.Insertion At Beginning\n2.Insertion At Anywhere\n3.Insertion At End\n");
        printf("4.Deletion At Beginning\n5.Deletion At Anywhere\n6.Deletion At End");
        printf("\n7.Display\n8.Stop\n");
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
            printf("Invalid choice");
            break;
        }
    }
}