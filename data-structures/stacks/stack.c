#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int array[MAX_SIZE];
    int top;
} Stack;

bool isFull(Stack *);
bool isEmpty(Stack *);
void push(Stack *, int);
int pop(Stack *);
void display(Stack *);
void search(Stack *, int);

int main()
{
    Stack stack;
    // intialize top to -1
    stack.top = -1;
    // push ten items to stack
    for(int i = 0;i < 10;i++)
    {
        push(&stack, i+1);
    }
    // pop an item from top of the stack and save the value in a var
    int topItem = pop(&stack);
    display(&stack);
    printf("Top is %d\n", topItem);
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->array[stack->top--];
}

void display(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Empty stack\n");
        return;
    }
    printf("Printing elements in stack: \n");
    for(int i = 0;i <= stack->top;i++)
    {
        printf("%d\n", stack->array[i]);
    }
}

void search(Stack *stack, int item)
{
    bool isFound = false;
    for (int i = 0;i < stack->top - 1;i++)
    {
        if(stack->array[i] == item)
        {
            printf("%d found at index %d\n", item, i);
            isFound = true;
            break;
        }
    }

    if(!isFound)
    {
        printf("Item is not in Stack\n");
    }
}