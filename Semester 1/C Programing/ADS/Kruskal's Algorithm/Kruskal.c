#include <stdio.h>
#define MAX 10
int adj[MAX][MAX] = {0}, parent[MAX] = {0}, i, j, u, v, cost = 0;

int find(int x)
{
    while (x != parent[x])
        x = parent[x];
    return x;
}

void UNION(int x, int y)
{
    u = find(x);
    v = find(y);
    parent[v] = u;
}

void main()
{
    int N, e = 0;
    printf("Enter the number of vertices:");
    scanf("%d", &N);
    if (N <= MAX)
    {
        printf("Enter the adjacency matrix:\n");
        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
                scanf("%d", &adj[i][j]);
        for(i=1;i<=N;i++)
        {
            parent[i]=i;
        }
            

        printf("Minimum Spanning Tree is:\n");
        while (e < N - 1)
        {
            int min = 999;
            for (i = 1; i <= N; i++)
            {
                for (j = 1; j <= N; j++)
                {
                    if (adj[i][j] < min && adj[i][j] != 0)
                    {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
            if (find(u) != find(v))
            {
                UNION(u, v);
                e += 1;
                cost += min;
                printf("Edge {%d,%d}=%d\n", u, v, min);
            }
            adj[u][v] = 0;
            adj[v][u] = 0; 
        }
        printf("Total cost=%d", cost);
    }
}