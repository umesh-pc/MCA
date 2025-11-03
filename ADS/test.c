#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

int parent[100];

int find( int i) {
    if (parent[i] != i)
        parent[i] = find( parent[i]);
    return parent[i];
}

void Union( int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

   parent[xroot]=yroot;
}

int compareEdges(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V]; // To store the resulting MST
    int e = 0; // index for result[]
    int i = 0; // index for sorted edges

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    for (int v = 0; v < V; ++v) {
       parent[v]=v;
    }

    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find( nextEdge.src);
        int y = find( nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union( x, y);
        }
    }

    printf("\nEdges in the Minimum Cost Spanning Tree:\n");
    int minCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Minimum Cost of Spanning Tree = %d\n", minCost);

}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    KruskalMST(edges, V, E);

    free(edges);
    return 0;
}