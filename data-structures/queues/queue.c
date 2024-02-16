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
    Queue queue;
    init(&queue);
    for(int i = 0;i < 10;i++)
    {
        enqueue(&queue, i);
    }
    dequeue(&queue);
    display(&queue);
}

void init(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue *queue)
{
    return queue->front == -1;
}

bool isFull(Queue *queue)
{
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue *queue, int value)
{
    if(isFull(queue))
    {
        printf("Queue Overflow\n");
        exit(1);
    }
    if(isEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    queue->array[++queue->rear] = value;
}

int dequeue(Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue underflow\n");
        exit(1);
    }
    return queue->array[++queue->front];
}

void display(Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Empty queue\n");
        return;
    }
    for(int i = queue->front+1;i <= queue->rear;i++)
    {
        printf("%d\n", queue->array[i]);
    }
}