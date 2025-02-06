#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void main(){
    int V[20]={0};
    int i,j,n;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    int adj[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Cost[%d][%d]:",i,j);
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0){
                adj[i][j]=INT_MAX;
            }
        }
    }
    int min=0,a,b,cost=0;
    V[0]=1;
    int e=1;
    while(e<n){
        for(i=0;i<n;i++){
            if(V[i]==1){
                min=INT_MAX;
                for(j=0;j<n;j++){
                    if(adj[i][j]<min && V[j]==0){
                        min=adj[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        V[b]=1;
        printf("\n%d-%d :%d",a,b,min);
        cost+=min;
        e++;
    }
    printf("\nMinimum Cost=%d",cost);
}