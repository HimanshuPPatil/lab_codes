#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Node {
    int key;
    char data[50];
    struct Node* next;
};

struct HashTable {
    struct Node* table[SIZE];
};

struct Node* createNode(int key, const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void initializeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < SIZE; ++i) {
        hashTable->table[i] = NULL;
    }
}

int hash(int key) {
    return key % SIZE;
}

void insert(struct HashTable* hashTable, int key, const char* data) {
    int index = hash(key);

    struct Node* newNode = createNode(key, data);

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        struct Node* current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void search(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct Node* current = hashTable->table[index];

    while (current != NULL) {
        if (current->key == key) {
            printf("Key found: %d, Data: %s\n", key, current->data);
            return;
        }
        current = current->next;
    }

    printf("Key not found: %d\n", key);
}

void display(struct HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("[%d] -> ", i);
        struct Node* current = hashTable->table[i];
        while (current != NULL) {
            printf("(%d, %s) -> ", current->key, current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);

    int choice, key;
    char data[50];

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%s", data);
                insert(&hashTable, key, data);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(&hashTable, key);
                break;

            case 3:
                display(&hashTable);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}