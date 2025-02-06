#include<stdio.h>
#include<stdlib.h>

int U[10]={1,2,3,4,5,6,7,8,9,10};
int bitA[10],bitB[10],Union[10],Intersection[10];
int a,b,c,d,i,j;

void main(){
    printf("Enter size of first set :");
    scanf("%d",&a);
    int A[a];
    i=0;
    int flag;
    while(i<a){
        flag=0;
        printf("A[%d] :",i+1);
        scanf("%d",&c);
        for(j=0;j<10;j++){
            if(c==A[j]){
                printf("Element Already Exist !!");
                printf("\nA[%d] :",i+1);
                scanf("%d",&c);
            }
        }
        for(j=0;j<10;j++){
            if(c==U[j]){
                flag=1;
                break;
            }
            else{
                flag=0;
            }
        }
        if(flag==1){
            A[i]=c;
            i++;
        }
        else{
            printf("Element do not exist in universal list\n");
        }
    }
    printf("Enter the size of second set :");
    scanf("%d",&b);
    int B[b];
    i=0;
    while(i<b){
        printf("B[%d] :",i+1);
        scanf("%d",&c);
        flag=0;
        for(j=0;j<b;j++){
            if(c==B[j]){
                printf("Element Already Exist !!");
                printf("\nB[%d] :",i+1);
                scanf("%d",&c);
            }
        }
        for(j=0;j<10;j++){
            if(c==U[j]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            B[i]=c;
            i++;
        }
        else{
            printf("Element not exist in universal set \n");
        }
    }
    printf("\nFirst set :");
    for(i=0;i<a;i++){
        printf("%d ",A[i]);
    }
    printf("\nSecond set:");
    for(i=0;i<b;i++){
        printf("%d ",B[i]);
    }
    for(i=0;i<10;i++){
        flag=0;
        for(j=0;j<a;j++){
            if(A[j]==U[i]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            bitA[i]=1;
        }
        else{
            bitA[i]=0;
        }
    }
    for(i=0;i<10;i++){
        flag=0;
        for(j=0;j<b;j++){
            if(B[j]==U[i]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            bitB[i]=1;
        }
        else{
            bitB[i]=0;
        }
    }
    printf("\nBitstring of A :");
    for(i=0;i<10;i++){
        printf("%d ",bitA[i]);
    }
    printf("\nBitstring of B :");
    for(i=0;i<10;i++){
        printf("%d ",bitB[i]);
    }
    printf("\nUnion :");
    for(i=0;i<10;i++){
        if(bitA[i]==1 || bitB[i]==1){
            Union[i]=1;
        }
        else{
            Union[i]=0;
        }
        printf("%d ",Union[i]);
    }
    printf("\nIntersection :");
    for(i=0;i<10;i++){
        if(bitA[i]==1 && bitB[i]==1){
            Intersection[i]=1;
        }
        else{
            Intersection[i]=0;
        }
        printf("%d ",Intersection[i]);
    }
}