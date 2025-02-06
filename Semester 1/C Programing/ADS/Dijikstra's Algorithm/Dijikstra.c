#include <stdio.h>
#include <limits.h>

#define MAX 100  // Maximum number of vertices
#define INF INT_MAX  // Infinity value

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX];    // Distance from start to each vertex
    int visited[MAX] = {0};  // Visited vertices
    int i, j, minDistance, nextNode;

    // Initialize distances
    for (i = 0; i < n; i++) {
        distance[i] = graph[start][i];
    }
    distance[start] = 0; // Distance to self is 0
    visited[start] = 1;  // Mark the source vertex as visited

    // Find the shortest path for all vertices
    for (i = 1; i < n; i++) {
        minDistance = INF;
        nextNode = -1;

        // Find the nearest unvisited vertex
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                nextNode = j;
            }
        }

        if (nextNode == -1) {
            break;  // All reachable vertices are visited
        }

        visited[nextNode] = 1;

        // Update distances of adjacent vertices
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[nextNode][j] != INF && distance[nextNode] + graph[nextNode][j] < distance[j]) {
                distance[j] = distance[nextNode] + graph[nextNode][j];
            }
        }
    }

    // Print the distances
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", i);
        if (distance[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", distance[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX], n, start, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j) {
                graph[i][j] = 0;  // Distance to self is 0
            }
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
