#include<stdio.h>
#include<stdlib.h>
int i,j=1,a,b,ch=1,count=0,pos;
 struct node{
     int data;
     struct node *next;
 }*head,*temp,*newnode,*nextnode,*prevnode;
 void empty(){
     printf("Empty");
 }
 void printlist(){
     if(head==0){
         empty();
     }
     else{
         temp=head;
         printf("\nElements Are:");
         while(temp!=0){
             printf("%d ",temp->data);
             temp=temp->next;
         }
         printf("\nCount=%d",count);
     }
 }
 void beg(){
     if(head==0){
        empty();
     }
     else{
         temp=head;
         head=head->next;
         free(temp);
         count--;
     }
     printlist();
 }
 void end(){
     if(head==0){
        empty();
     }
     else if(count==1){
        temp=head;
        head=0;
        free(temp);
        count--;
        printlist();
     }
     else{
         temp=head;
         while(temp->next!=0){
             prevnode=temp;
             temp=temp->next;
         }
         prevnode->next=0;
         free(temp);
         count--;
         printlist();
     }
 }
 void any(){
     printf("\nWhich position do you want to delete:");
     scanf("%d",&pos);
     if(pos>0 && pos<=count){
         if(pos==1){
             beg();
         }
         else if(count==pos){
             end();
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
 
 void main(){
     head=0;
     printf("How many nodes do you want?");
     scanf("%d",&a);
     for(i=0;i<a;i++){
         newnode=malloc(sizeof(struct node));
         printf("Enter Your data:");
         scanf("%d",&newnode->data);
         newnode->next=0;
         if(head==0){
             head=newnode;
             temp=newnode;
             count++;
         }
         else{
             temp->next=newnode;
             temp=newnode;
             count++;
         }
     }
     temp=head;
     printf("Entered Elements Are:");
     while(temp!=0){
         printf("%d ",temp->data);
         temp=temp->next;
     }
     printf("\nCount=%d",count);
     printf("\nWhat deletion operation do you want?");
     while(ch){
         printf("\n1.Beginning\n2.Anywhere\n3.End\n4.Display\n5.Stop\n");
         scanf("%d",&b);
         switch(b){
             case 1:
             beg();
             break;
             case 2:
             any();
             break;
             case 3:
             end();
             break;
             case 4:
             printlist();
             break;
             case 5:
             ch=0;
             break;
             default:
             printf("Invalid Entry ");
             break;
         }
     }
 }