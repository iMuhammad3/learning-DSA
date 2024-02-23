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
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
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

void addEdge(Graph *graph, int src, int dest)
{
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        Node* temp = graph->adjacencyList[i];
        printf("Adjacency list of vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}