#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int array[MAX_SIZE];
    int top;
} Stack;

bool isFull(Stack);
bool isEmpty(Stack);
void push(Stack, int);
void pop(Stack);
void display(Stack);

int main()
{
    Stack stack;
    stack.top = -1;
}

bool isFull(Stack stack)
{
    return stack.top == MAX_SIZE - 1;
}

bool isEmpty(Stack stack)
{
    return stack.top == -1;
}

void push(Stack stack, int item)
{

}

void pop(Stack stack)
{

}

void display(Stack stack)
{
    
}