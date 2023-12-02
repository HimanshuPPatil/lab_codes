#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* adjacencyList[MAX_SIZE];
bool visited[MAX_SIZE];
int vertices;

void initGraph() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        adjacencyList[i] = NULL;
        visited[i] = false;
    }
}

void addEdge(int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    // For undirected graph
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

void displayGraph() {
    int i;
    printf("Adjacency List:\n");
    for (i = 0; i < vertices; i++) {
        struct Node* temp = adjacencyList[i];
        printf("Vertex %d -> ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = true;
    struct Node* temp = adjacencyList[vertex];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int choice, src, dest;

    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &vertices);
    initGraph();

    do {
        printf("\nDFS Menu:\n");
        printf("1. Add Edge\n");
        printf("2. Display Adjacency List\n");
        printf("3. Perform DFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertex (0 to %d): ", vertices - 1);
                scanf("%d %d", &src, &dest);
                if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                    addEdge(src, dest);
                } else {
                    printf("Invalid vertex index.\n");
                }
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &src);
                if (src >= 0 && src < vertices) {
                    printf("DFS Traversal: ");
                    dfs(src);
                    printf("\n");
                    for (int i = 0; i < vertices; i++) {
                        visited[i] = false; // Resetting visited array after traversal
                    }
                } else {
                    printf("Invalid starting vertex.\n");
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
