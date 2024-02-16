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
void init(Queue *);
bool isEmpty(Queue *);
bool isFull(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
void display(Queue *);

int main(void)
{

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
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue *queue, int item)
{
    if(isFull(queue))
    {
        printf("Queue Overflow!\n");
        return;
    }
    if(isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
}

int dequeue(Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    int value = queue->array[queue->front];
    if(queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else 
    {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return value;
}

void display(Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("Empty Queue\n");
        return;
    }
    printf("Items in Queue: ");
    for (int i = queue->front+1;i <= queue->rear;i++)
    {
        printf("%d\n", queue->array[i]);
    }
}