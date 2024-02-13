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
void fillList(int count);
void printList();
void freeMemory();

int main(){

    fillList(10);
    printList();
    freeMemory();
    
    return 0;
}

void fillList(int count){

    node *current = NULL;
    
    for (int i = 0; i < count; i++){
        node *newNode = (node *)malloc(sizeof(node));

        // Check if memory allocation fails
        if(newNode == NULL){
            printf("Failed to allocate memory\n");
            return;
        }

        newNode->item = i + 1;
        newNode->next = NULL;

        // If the list is empty, assign HEAD to the new node
        if(HEAD == NULL){
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

