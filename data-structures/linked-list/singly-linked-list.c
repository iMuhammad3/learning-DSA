#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for each node in the linked list
typedef struct node
{
    int item;
    struct node *next;
} node;

// Declare HEAD pointer to maintain the start of the linked list
node *HEAD = NULL;

// Function prototypes
void fillList(int);
void printList();
void freeMemory();
void insertItem(int);
void insertAtBegin(int);
void deleteAt(int);
void search(int);
void safeMalloc(node *);

int main()
{

    insertAtBegin(40);
    fillList(10);
    insertItem(40);
    search(40);
    freeMemory();

    return 0;
}

void fillList(int count)
{

    node *current = HEAD;

    for (int i = 0; i < count; i++)
    {
        node *newNode = (node *)malloc(sizeof(node));

        safeMalloc(newNode);

        newNode->item = i + 1;
        newNode->next = NULL;

        // If the list is empty, assign HEAD to the new node
        if (HEAD == NULL)
        {
            HEAD = newNode;
        }
        else
        {
            // Go to the last node and append the new node to the list
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        // Update current pointer to the newly added node
        current = newNode;
    }
}

void printList()
{
    node *temp = HEAD;
    printf("Printing Linked List: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->item);
        temp = temp->next;
    }
}

void freeMemory()
{
    node *current = HEAD;
    while (current != NULL)
    {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    HEAD = NULL;
}

void insertItem(int item)
{
    node *newNode = malloc(sizeof(node));

    safeMalloc(newNode);

    newNode->item = item;
    newNode->next = NULL;

    if (HEAD == NULL)
    {
        HEAD = newNode;
        return;
    }

    node *temp = HEAD;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtBegin(int item)
{
    node *newNode = malloc(sizeof(node));

    safeMalloc(newNode);

    newNode->item = item;
    newNode->next = NULL;

    if (HEAD == NULL)
    {
        HEAD = newNode;
        return;
    }

    newNode->next = HEAD;
    HEAD = newNode;
}

void deleteAt(int index)
{
    if (HEAD == NULL)
    {
        printf("List is empty");
        return;
    }

    node *temp = HEAD;
    node *before = NULL;

    if (index == 0)
    {
        HEAD = HEAD->next;
        free(temp);
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        if (temp == NULL || temp->next == NULL)
        {
            printf("No items at %d\n", index);
            return;
        }
        temp = temp->next;
    }

    // Check if the node to be deleted exists
    if (temp->next == NULL)
    {
        printf("No items at %d\n", index);
        return;
    }

    node *after = temp->next->next;

    free(temp->next);

    temp->next = after;
}

void search(int item)
{
    if(HEAD == NULL)
    {
        printf("Empty list\n");
        return;
    }
    node *temp = HEAD;
    int i = 0;
    bool isFound = false;

    while(temp->next != NULL)
    {
        if(temp->item == item)
        {
            printf("Item (%d) found at %d\n", item, i);
            isFound = true;
        }
        i++;
        temp = temp->next;
    }

    if(!isFound)
    {
        printf("Item not found!\n");
    }
}

void safeMalloc(node *newNode)
{
    // check if malloc fails
    if (newNode == NULL)
    {
        printf("Failed to allocate memory\n");
        exit(1);
    }
}