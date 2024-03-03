#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int size;
    int maxSize;
} MaxHeap;

MaxHeap *createHeap(int);
void swap(int *, int *);
void heapify(MaxHeap *, int);
void insert(MaxHeap *, int);
void printHeap(MaxHeap *);

int main(void)
{
    MaxHeap *heap = createHeap(10);
    insert(heap, 1);
    insert(heap, 10);
    insert(heap, 21);
    insert(heap, 3);
    insert(heap, 77);
    insert(heap, 12);
    insert(heap, 44);
    printHeap(heap);
}

MaxHeap *createHeap(int maxSize)
{
    MaxHeap *heap = malloc(sizeof(MaxHeap));
    heap->array = malloc(sizeof(int) * (maxSize + 1));
    heap->maxSize = maxSize;
    heap->size = 0;
    heap->array[0] = __INT_MAX__;
    return heap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MaxHeap *heap, int index)
{
    int leftChild = index * 2;
    int rightChild = index * 2 + 1;
    int largest = index;

    if (leftChild > heap->maxSize || rightChild > heap->maxSize)
        return;

    if (heap->array[leftChild] > largest)
        largest = leftChild;

    if (heap->array[rightChild] > largest)
        largest = rightChild;

    if (largest != index)
    {
        swap(&heap->array[index], &heap->array[largest]);
        heapify(heap, largest);
    }
}

void insert(MaxHeap *heap, int value)
{
    if (heap->size >= heap->maxSize)
    {
        printf("Heap is full!\n");
        return;
    }
    int index = ++heap->size;
    heap->array[index] = value;
    while (index > 1 && heap->array[index] > heap->array[index / 2])
    {
        swap(&heap->array[index], &heap->array[index / 2]);
        index = index / 2;
    }
}

void printHeap(MaxHeap *heap)
{
    for (int i = 1; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}