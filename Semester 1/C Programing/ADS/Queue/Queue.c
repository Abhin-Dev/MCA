#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1,rear=-1,a,i,c;
void isfull(){
    printf("\nQueue Is Full");
}
void isempty(){
    printf("\nQueue Is Empty");
}
void enqueue(){
    if(rear==max-1){
        isfull();
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        printf("Enter Your Number:");
        scanf("%d",&a);
        queue[rear]=a;
        printf("Enqueued Element:",queue[rear]);
    }
    else{
        rear++;
        printf("Enter Your Number:");
        scanf("%d",&a);
        queue[rear]=a;
        printf("Enqueued Element:",queue[rear]); 
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        isempty();
    }
    else if(front==rear){
        a=queue[front];
        printf("Dequeued Element:%d",a);
        front=-1;
        rear=-1;
    }
    else{
        a=queue[front];
        printf("Dequeued Element:%d",a);
        front++;
    }
}
void peek(){
    if(front==-1 && rear==-1){
        isempty();
    }
    else{
        printf("Front Element:%d",queue[front]);
    }
}
void display(){
    if(front==-1 && rear==-1){
        isempty();
    }
    else{
        printf("Elements In The Queue:");
        for(i=front;i<=rear;i++){
            printf(" %d  ",queue[i]);
        }
    }
}
void main(){
    while(1){
    printf("\n\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n");
    printf("\nSelect Your Operation:");
    scanf("%d",&c);
        switch(c){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("\n\nInvalid Choice");
            break;
        }
    }
}