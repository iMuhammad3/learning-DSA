#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for each node in the doubly linked list
typedef struct node
{
    struct node *prev;
    int item;
    struct node *next;
} node;

node *HEAD = NULL;

void fillList(int);
void printList();
void insertItem(int);
void deleteItem(int);
void freeMemory();

int main()
{
    fillList(10);
    insertItem(10);
    insertItem(20);
    deleteItem(10);
    printList();
    freeMemory();
}

void fillList(int count)
{

    node *current = HEAD;

    for (int i = 0; i < count; i++)
    {
        node *newNode = (node *)malloc(sizeof(node));

        if (newNode == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }

        newNode->prev = NULL;
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
            newNode->prev = current;
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

void insertItem(int item)
{
    node *newNode = malloc(sizeof(node));

    newNode->prev = NULL;
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
    newNode->prev = temp;
}

void deleteItem(int item)
{
    if(HEAD == NULL)
    {
        printf("Empty List\n");
        return;
    }

    node *temp = HEAD;
    bool isFound = false;
    int i = 1;

    while (temp->next != NULL)
    {
        if(temp->item == item)
        {
            isFound = true;
            temp->prev->next = temp->next;
            free(temp);
            printf("Deleted item (%d) at index %d\n", item, i);
        }
        temp = temp->next;
        i++;
    }

    if(!isFound)
    {
        printf("Item wasn't found");
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
