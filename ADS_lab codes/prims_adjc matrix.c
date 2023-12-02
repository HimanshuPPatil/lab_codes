#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_SIZE 10

int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[MAX_SIZE][MAX_SIZE], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[MAX_SIZE][MAX_SIZE], int vertices) {
    int parent[MAX_SIZE];
    int key[MAX_SIZE];
    bool mstSet[MAX_SIZE];

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, vertices);
}

int main() {
    int graph[MAX_SIZE][MAX_SIZE];
    int vertices;

    printf("Enter the number of vertices (max %d): ", MAX_SIZE);
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nThe Minimum Spanning Tree (MST) using Prim's algorithm:\n");
    primMST(graph, vertices);

    return 0;
}
