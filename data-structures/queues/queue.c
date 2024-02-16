#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

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
    Queue queue;
    init(&queue);
    if(isEmpty(&queue))
    {
        printf("Empty\n");
    }
}

void init(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue *queue)
{
    return queue->rear == queue->front;
}

bool isFull(Queue *queue)
{
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue *queue, int value)
{

}

int dequeue(Queue *queue)
{
    return 1;
}

void display(Queue *queue)
{
    
}