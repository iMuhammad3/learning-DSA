#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

// Structure for each node in the linked list
typedef struct Node
{
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node *table[SIZE]; // Array of pointers to linked lists
} HashTable;

Node *createNode(const char *, int);
HashTable *createHashTable();
unsigned int hash(const char *key);
void insert(HashTable *, const char *, int);
int get(HashTable *, const char *);
void displayTable(HashTable *);
void freeTable(HashTable *);

int main(void)
{
    HashTable *hashTable = createHashTable();
    FILE *f = fopen("alpha.txt", "r");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1000];
    int i = 1;

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        // Remove newline character, if present
        size_t length = strlen(buffer);
        if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }
        insert(hashTable, buffer, i++);
    }
    displayTable(hashTable);
    freeTable(hashTable);
    fclose(f);

}

Node *createNode(const char *key, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->key = strdup(key); // strdup allocates memory for a copy of the string
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashTable *createHashTable()
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    if (hashTable == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++)
    {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

unsigned int hash(const char *key)
{
    int hashValue = 0;
    while (*key)
    {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % SIZE;
}

void insert(HashTable *hashTable, const char *key, int value)
{
    int index = hash(key);
    Node *newNode = createNode(key, value);
    // sets the next pointer of the new node to point to the current head of the linked list
    newNode->next = hashTable->table[index];
    // updates the head of the linked list at the specified index in the hash table to point to the new node
    hashTable->table[index] = newNode;
}

int get(HashTable *hashTable, const char *key)
{
    int index = hash(key);
    Node *temp = hashTable->table[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Key not found
}

void displayTable(HashTable *hashTable)
{
    printf("HashTable: \n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d. ", i);
        Node *temp = hashTable->table[i];
        while (temp != NULL)
        {
            printf("{ %s: %d }, ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeTable(HashTable *hashTable)
{
    for (int i = 0; i < SIZE; ++i)
    {
        Node *current = hashTable->table[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashTable);
}