#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Define the size of the hash table

int hashTable[TABLE_SIZE]; // Hash table array
int size = 0; // To keep track of number of elements in the table

// Function to initialize the hash table with -1 (indicating empty slots)
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function: returns the hash index for a given key
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key using linear probing
void insert(int key) {
    if (size == TABLE_SIZE) {
        printf("Hash table is full!\n");
        return;
    }
    int index = hashFunction(key);

    // Linear probing to find an empty slot
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index] = key;
    size++;
    printf("Inserted %d at index %d\n", key, index);
}

// Function to search for a key in the hash table
int search(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    // Linear probing to find the key
    while (hashTable[index] != key) {
        index = (index + 1) % TABLE_SIZE;
        // If we return to the start index, the key is not present
        if (index == startIndex || hashTable[index] == -1) {
            return -1;
        }
    }

    return index;
}

// Function to display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: [empty]\n", i);
    }
}

int main() {
    int choice, key;
    initHashTable();

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int result = search(key);
                if (result != -1) {
                    printf("Key %d found at index %d\n", key, result);
                } else {
                    printf("Key %d not found!\n", key);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

