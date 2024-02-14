#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
typedef struct node{
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
void safeMalloc(node *);

int main(){

    insertItem(20);
    insertAtBegin(0);
    fillList(10);
    printList();
    freeMemory();
    
    return 0;
}

void fillList(int count){

    node *current = HEAD;
    
    for (int i = 0; i < count; i++){
        node *newNode = (node *)malloc(sizeof(node));

        safeMalloc(newNode);

        newNode->item = i + 1;
        newNode->next = NULL;

        // If the list is empty, assign HEAD to the new node
        if (HEAD == NULL) {
            HEAD = newNode;
        } else {
            // Link the current node to the new node
            current->next = newNode;
        }

        // Update current pointer to the newly added node
        current = newNode;
    }

}

void printList(){
    node *temp = HEAD;
    printf("Printing Linked List: \n");
    while(temp != NULL){
        printf("%d\n", temp->item);
        temp = temp->next;
    }
}

void freeMemory(){
    node *current = HEAD;
    while(current != NULL){
        node *temp = current;
        current = current->next;
        free(temp);
    }
    HEAD = NULL;
}

void insertItem(int item){
    node *newNode = malloc(sizeof(node));

    safeMalloc(newNode);

    newNode->item = item;
    newNode->next = NULL;

    if(HEAD == NULL){
        HEAD = newNode;
        return;
    }

    node *current = HEAD;

    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = newNode;
}

void insertAtBegin(int item){
    node *newNode = malloc(sizeof(node));

    safeMalloc(newNode);

    newNode->item = item;
    newNode->next = NULL;

    if(HEAD == NULL){
        HEAD = newNode;
        return;
    }

    newNode->next = HEAD;
    HEAD = newNode;
}

void safeMalloc(node *newNode){
    // check if malloc fails
    if(newNode == NULL){
        printf("Failed to allocate memory\n");
        exit(1);
    }
}