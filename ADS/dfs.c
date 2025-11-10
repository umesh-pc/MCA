#include <stdio.h>

#define MAX 10

int visited[MAX];
int adj[MAX][MAX];
int n; // number of vertices

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, v1, v2;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1; // for undirected graph
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    DFS(start);

    return 0;
}
