#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

typedef struct 
{
    int numVertices;
    Node **adjacencyList;
} Graph;

Node *createNode(int);
Graph *createGraph(int);
void addEdge(Graph *, int, int);
void printGraph(Graph *);

int main()
{

}

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int numVertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (Node **)malloc(numVertices * sizeof(Node *));
    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}