#include <stdio.h>
#include <stdlib.h>

// Set reasonable limits for the graph size
#define MAX_VERTICES 100
#define INFINITY 9999 // Represents no direct edge or a weight that will never be chosen

// 1. Data Structure for an Edge
typedef struct {
    int src, dest, weight;
} Edge;

// 2. Union-Find Global Arrays and Variables
int parent[MAX_VERTICES];
int num_vertices;

// Function Prototypes (Declarations)
int find(int i);
void unionSets(int u, int v);
int compareEdges(const void* a, const void* b);
void kruskalMST(Edge edges[], int E);


// =======================================================
//                    UNION-FIND FUNCTIONS
// =======================================================

/**
 * @brief Finds the representative (root) of the set containing element i, 
 * using Path Compression for efficiency.
 */
int find(int i) {
    // If i is the parent of itself, it's the root
    if (parent[i] == i) 
        return i;
    
    // Path Compression: Set i's parent directly to the root
    return parent[i] = find(parent[i]);
}

/**
 * @brief Merges the sets containing elements u and v.
 */
void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u != root_v) {
        // Simple Union: Make one root the parent of the other
        parent[root_v] = root_u; 
    }
}


// =======================================================
//                    KRUSKAL'S CORE LOGIC
// =======================================================

/**
 * @brief Comparison function required by qsort to sort edges by weight.
 */
int compareEdges(const void* a, const void* b) {
    const Edge* edgeA = (const Edge*)a;
    const Edge* edgeB = (const Edge*)b;
    
    // Sort in non-decreasing (ascending) order of weight
    return edgeA->weight - edgeB->weight;
}

/**
 * @brief Constructs the Minimum Spanning Tree using Kruskal's algorithm.
 */
void kruskalMST(Edge edges[], int E) {
    
    // 1. Sort all edges by weight
    qsort(edges, E, sizeof(Edge), compareEdges);

    // 2. Initialize Union-Find: Every vertex starts in its own set
    for (int i = 0; i < num_vertices; i++) {
        parent[i] = i;
    }

    int mst_weight = 0;
    int edges_in_mst = 0;
    int i = 0; // Index for sorted edges

    printf("\n--- Edges of the Minimum Spanning Tree (MST) ---\n");
    printf("Format: (Source - Destination) Weight\n");

    // 3. Iterate through sorted edges and build the MST
    // Loop until V-1 edges are included OR all edges are processed
    while (edges_in_mst < num_vertices - 1 && i < E) {
        Edge current_edge = edges[i++];
        
        int u = current_edge.src;
        int v = current_edge.dest;
        
        // Check if adding this edge creates a cycle (i.e., if u and v are already connected)
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            // No cycle: Accept the edge
            printf("  (%d - %d) Weight: %d\n", u, v, current_edge.weight);
            
            mst_weight += current_edge.weight;
            edges_in_mst++;
            
            // Merge the two sets/trees
            unionSets(u, v); 
        }
        // If root_u == root_v, the edge is discarded (it creates a cycle).
    }

    // Final result output
    if (edges_in_mst == num_vertices - 1) {
        printf("\nTotal weight of MST: %d\n", mst_weight);
    } else {
        printf("\nWarning: MST could not be formed. The graph might be disconnected.\n");
    }
}


// =======================================================
//                       MAIN FUNCTION
// =======================================================

int main() {
    
    // 1. Get the number of vertices
    printf("Enter the number of vertices (V, max %d): ", MAX_VERTICES);
    if (scanf("%d", &num_vertices) != 1 || num_vertices <= 1 || num_vertices > MAX_VERTICES) {
        printf("Invalid or unsupported number of vertices.\n");
        return 1;
    }
    
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    
    printf("\nEnter the cost adjacency matrix (%d x %d):\n", num_vertices, num_vertices);
    printf("Use a weight (e.g., %d) or a weight of 0 for edges that DO NOT exist.\n", INFINITY);
    printf("Vertices are numbered from 0 to %d.\n", num_vertices - 1);
    
    // 2. Read the Adjacency Matrix
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (scanf("%d", &adj_matrix[i][j]) != 1 || adj_matrix[i][j] < 0) {
                printf("Invalid input. Weights must be non-negative.\n");
                return 1;
            }
        }
    }

    // 3. Extract Edges from the Adjacency Matrix
    
    // Max edges for V vertices is V*(V-1)/2
    int max_possible_edges = num_vertices * (num_vertices - 1) / 2;
    Edge* graph_edges = (Edge*)malloc(max_possible_edges * sizeof(Edge));
    if (graph_edges == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int num_edges = 0;
    // Iterate only through the upper triangle (j > i) to count each edge once
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            int weight = adj_matrix[i][j];
            
            // Only consider valid edges (weight > 0 and not INFINITY)
            if (weight > 0 && weight < INFINITY) {
                graph_edges[num_edges].src = i;
                graph_edges[num_edges].dest = j;
                graph_edges[num_edges].weight = weight;
                num_edges++;
            }
        }
    }
    
    // 4. Run Kruskal's Algorithm
    if (num_edges == 0 && num_vertices > 1) {
        printf("\nNo valid edges found in the graph. MST cannot be formed.\n");
    } else if (num_vertices == 1) {
        printf("\nSingle vertex graph. MST weight is 0.\n");
    } else {
        kruskalMST(graph_edges, num_edges);
    }

    // 5. Clean up
    free(graph_edges);
    
    return 0;
}