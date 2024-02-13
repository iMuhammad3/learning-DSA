#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int item;
    struct node *next;
} node;

int main(){

    node *head = NULL;
    node *current = NULL;
    
    for (int i = 0; i < 5; i++){
        node *newNode = (node *)malloc(sizeof(node));

        if(newNode == NULL){
            printf("Failed to allocate memory\n");
            return 1;
        }

        newNode->item = i;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
        } else {
            current->next = newNode;
        }

        current = newNode;
    }


    printf("Printing Linked List: \n");
    current = head;
    while(current != NULL){
        printf("%d\n", current->item);
        current = current->next;
    }

    current = head;
    while(current != NULL){
        node *temp = current;
        current = current->next;
        free(temp);
    }
    
    printf("Done and dusted\n");
    return 0;
}