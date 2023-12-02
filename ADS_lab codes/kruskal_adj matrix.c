#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

#define MAX_SIZE 10

int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalMST(int n, int graph[MAX_SIZE][MAX_SIZE]) {
    int parent[MAX_SIZE], rank[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    int minCost = 0;
    printf("Edges in the constructed MST:\n");
    for (int count = 0; count < n - 1; ++count) {
        int minWeight = INT_MAX, u = -1, v = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (findParent(parent, i) != findParent(parent, j) && graph[i][j] && graph[i][j] < minWeight) {
                    minWeight = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (u != -1 && v != -1) {
            unionSet(u, v, parent, rank);
            printf("%d -- %d == %d\n", u, v, minWeight);
            minCost += minWeight;
        }
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main() {
    int n;
    printf("Enter the number of vertices (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    int graph[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    kruskalMST(n, graph);

    return 0;
}
