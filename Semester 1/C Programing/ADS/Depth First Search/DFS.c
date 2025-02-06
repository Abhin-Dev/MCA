#include <stdlib.h>
#include <stdio.h>

void dfs(int node);

int adj[20][20], visited[20];
int n, start;

void main() {
    printf("How many nodes do you want (max 20): ");
    scanf("%d", &n);

    if (n > 20) {
        printf("Number of nodes exceeds the maximum limit of 20.\n");
        exit(1);
    }

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            do {
                printf("[%d][%d]: ", i, j);
                scanf("%d", &adj[i][j]);
                if (adj[i][j] != 0 && adj[i][j] != 1) {
                    printf("Invalid input. Please enter 0 or 1.\n");
                }
            } while (adj[i][j] != 0 && adj[i][j] != 1);
        }
    }

    for (int i = 0; i < 20; i++) {
        visited[i] = 0;
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node. Please enter a value between 0 and %d.\n", n - 1);
        exit(1);
    }

    printf("DFS --> ");
    dfs(start);
    printf("\n");
}

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}
