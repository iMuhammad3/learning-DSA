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

int main(void)
{
    Queue queue;
}

void init(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

void enqueue(Queue *queue, int value)
{

}

int dequeue(Queue *queue)
{

}

void display(Queue *queue)
{

}