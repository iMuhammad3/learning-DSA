#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 11

typedef struct {
    int array[MAX_SIZE];
    int rear;
    int front;
} Queue;

// method declarations
void enqueue(Queue *, int);
int dequeue(Queue *);
void init(Queue *);
void display(Queue *);
bool isEmpty(Queue *);
bool isFull(Queue *);

int main(void)
{

}