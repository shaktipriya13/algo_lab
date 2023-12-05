#include <stdio.h>

#define MAX 10
int adj[MAX][MAX];
int visited[MAX];
int n; // number of nodes in the graph

void DFS(int vertex) {
    printf("%d ", vertex); // Print the current vertex
    visited[vertex] = 1; // Mark the current vertex as visited

    for (int i = 1; i <= n; ++i) {
        // Check adjacent vertices and visit them if they are connected and not visited
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            DFS(i); // Recursive call to visit the adjacent vertex
        }
    }
}

int main() {
    int i, j, startVertex;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 1; i <= n; ++i) {
        visited[i] = 0; // Initialize visited array to mark all vertices as not visited
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth-First Traversal: ");
    DFS(startVertex);

    return 0;
}
