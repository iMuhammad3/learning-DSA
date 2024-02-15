#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int array[MAX_SIZE];
    int top;
} Stack;

int main()
{
    Stack stack;
    stack.top = -1;
}
