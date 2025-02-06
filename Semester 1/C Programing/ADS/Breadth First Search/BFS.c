#include <stdlib.h>
#include <stdio.h>

void bfs(int start);
int dequeue();
void enqueue(int node);

int start, i, j, n, front = -1, rear = -1;
int adj[20][20], visited[20], queue[20];

void main() {
    printf("How many nodes do you want (max 20): ");
    scanf("%d", &n);

    if (n > 20) {
        printf("Number of nodes exceeds the maximum limit of 20.\n");
        exit(1);
    }

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            do {
                printf("[%d][%d]: ", i, j);
                scanf("%d", &adj[i][j]);
                if (adj[i][j] != 0 && adj[i][j] != 1) {
                    printf("Invalid input. Please enter 0 or 1.\n");
                }
            } while (adj[i][j] != 0 && adj[i][j] != 1);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node. Please enter a value between 0 and %d.\n", n - 1);
        exit(1);
    }

    printf("BFS --> ");
    bfs(start);
    printf("\n");
}

void bfs(int start) {
    int node;
    enqueue(start);
    visited[start] = 1;
    printf("%d ", start);

    while (front != -1) {
        node = dequeue();
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(i);
            }
        }
    }
}

void enqueue(int node) {
    if (rear == 19) {
        printf("Queue overflow. Too many nodes.\n");
        exit(1);
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = node;
}

int dequeue() {
    int node = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return node;
}
