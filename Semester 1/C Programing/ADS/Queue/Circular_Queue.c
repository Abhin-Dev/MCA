#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int a,b,i;
int front=-1,rear=-1;
void full(){
    printf("Queue Is Full"); 
}
void empty(){
    printf("Queue Is Empty");
}
void enqueue(){
    if(front==-1 && rear==-1){
        front++;
        rear++;
        printf("Enter Your Number:");
        scanf("%d",&a);
        queue[rear]=a;
        printf("Entered Element Is:%d",queue[rear]);
    }
    else if((rear+1)%max==front){
        full();
    }
    else{
        rear=(rear+1)%max;
        printf("Enter Your Number:");
        scanf("%d",&a);
        queue[rear]=a;
        printf("Entered Element Is:%d",queue[rear]);
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        empty();
    }
    else if(front==rear){
        b=queue[front];
        printf("Dequeued Element :%d",b);
        front=rear=-1;
    }
    else{
        b=queue[front];
        printf("Dequeued Element :%d",b);
        front=(front+1)%max;
    }
}
void display(){
        if(front==-1 && rear==-1){
        empty();
        }
        else{
            printf("Elements in the Queue:");
            for(i=front;((i+1)%max)<=rear;i++){
                printf("%d ",queue[i]);
            }
            printf("%d",queue[rear]);
        }
}
void peek(){
        if(front==-1 && rear==-1){
        empty();
        }
        else{
            printf("Top Element:%d",queue[front]);
        }
}
void main(){
while(1){
    printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit");
    printf("\n\nSelect Your Choice:");
    scanf("%d",&b);
    switch(b){
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        peek();
        break;
        case 5:
        printf("Exiting...");
        break;
        default:
        printf("Invalid Choice");
        break;
    }
    if(b==5){
        break;
    }
}
}