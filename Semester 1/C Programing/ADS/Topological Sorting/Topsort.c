#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<limits.h>

void main(){
    int adj[10][10],i,j,n;
    printf("How many nodes do you want :");
    scanf("%d",&n);
    int vertices[n];
    for(i=0;i<n;i++){
        printf("Enter vertice %d :",i+1);
        scanf("%d",&vertices[i]);
    }
    printf("Adjacency Matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%d][%d] :",i+1,j+1);
            scanf("%d",&adj[i][j]);
        }
    }
    int count=0,flag;
    int visited[10]={0};

    printf("Visited Order :");

    while(count!=n){
        for(i=0;i<n;i++){
            flag=1;
            for(j=0;j<n;j++){
                if (vertices[i]==visited[j]){
                    flag=0;
                    break;
                }
            }
            for(j=0;j<n;j++){
                if(adj[j][i]==1){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                visited[i]=vertices[i];
                count++;
                for(j=0;j<n;j++){
                    if(adj[i][j]==1){
                        adj[i][j]=0;
                    }
                }
                printf("%d ",visited[i]);
            }
        }
    }
}