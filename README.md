# Learning DSA

Resources I use to learn:

-   [Javatpoint](https://www.javatpoint.com/data-structure-tutorial)
-   [Geeks for Geeks](https://www.geeksforgeeks.org/learn-data-structures-and-algorithms-dsa-tutorial/)

## Data Structures

**Data Structure** is a particular way of storing and organizing data in the memory of the computer so that these data can easily be retrieved and efficiently utilized in the future when required.

### Types of Data Structures

-   Arrays
-   Linked Lists
-   Stacks
-   Queues
-   Trees
-   Graphs

### Basic Operations of Data Structures

-   **Traversal**
-   **Search**
-   **Insertion**
-   **Deletion**
-   **Sorting**
-   **Merge**
-   **Create**
-   **Selection**
-   **Update**

### Arrays

**Arrays** are defined as the collection of similar types of data items stored at contiguous memory locations. It is one of the simplest data structures where each data element can be randomly accessed by using its index number.
![array representation](/data-structures/images/array.png)

### Linked Lists

**Linked list** is a linear data structure that includes a series of connected nodes. Linked list can be defined as the nodes that are randomly stored in the memory. A node in the linked list contains two parts, i.e., first is the data part and second is the address part. The last node of the list contains a pointer to the null.
![linked list representation](/data-structures/images/linked-list.png)

```c
// How to create type Node in C
typedef struct node
{
    int item;
    struct node *next;
} node;
```

#### Types of Linked Lists

-   **Singly-linked list** - Singly linked list can be defined as the collection of an ordered set of elements. A node in the singly linked list consists of two parts: data part and link part.
    [Check my implementation of singly linked lists](/data-structures/linked-list/singly-linked-list.c)
-   **Doubly linked list** - Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence. Therefore, in a doubly-linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer), and pointer to the previous node (previous pointer).

```c
// Node for doubly linked list
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
```

[Check my implementation of doubly linked lists](/data-structures/linked-list/doubly-linked-list.c)

-   **Circular singly linked list** - In a circular singly linked list, the last node of the list contains a pointer to the first node of the list. We can have circular singly linked list as well as circular doubly linked list.
-   **Circular doubly linked list** - Circular doubly linked list is a more complex type of data structure in which a node contains pointers to its previous node as well as the next node. Circular doubly linked list doesn't contain NULL in any of the nodes. The last node of the list contains the address of the first node of the list. The first node of the list also contains the address of the last node in its previous pointer.

### Stacks

A **Stack** is a linear data structure that follows the LIFO (Last-In-First-Out) principle. a **Stack** can also be defined as a container in which insertion and deletion can be done from the one end known as the top of the stack.
Stacks can be implemented using arrays or linked lists, here I learnt how to implement stacks using arrays.
![stack representation](/data-structures/images/stack.png)

[Check my implementation of stacks using arrays](/data-structures/stacks/stack.c)

```c
// define maximum size value for array
#define MAX_SIZE 100

// define structure for stack
typedef struct {
    int array[MAX_SIZE];
    int top;
} Stack;
```

### Queues

**Queue** is the data structure that is similar to the queue in the real world. A **queue** is a data structure in which whatever comes first will go out first, and it follows the FIFO (First-In-First-Out) policy. **queue** can also be defined as the list or collection in which the insertion is done from one end known as the rear end or the tail of the **queue**, whereas the deletion is done from another end known as the front end or the head of the **queue**.
![queue representation](/data-structures/images/queue.png)

```c
// define an array queue structure
typedef struct {
    int array[MAX_SIZE];
    int rear;
    int front;
} Queue;
```

#### Types of Queues

-   **Simple or Linear Queue**: In Linear Queue, an insertion takes place from one end while the deletion occurs from another end. The end at which the insertion takes place is known as the rear end, and the end at which the deletion takes place is known as front end. It strictly follows the FIFO rule.
    The major drawback of using a linear Queue is that insertion is done only from the rear end. If the first three elements are deleted from the Queue, we cannot insert more elements even though the space is available in a Linear Queue. In this case, the linear Queue shows the overflow condition as the rear is pointing to the last element of the Queue.
    [Check my implementation of linear queue using arrays](/data-structures/queues/linear-queue.c).
-   **Circular Queue**: In Circular Queue, all the nodes are represented as circular. It is similar to the linear Queue except that the last element of the queue is connected to the first element. It is also known as Ring Buffer, as all the ends are connected to another end.
    [Check my implementation of linear queue using arrays](/data-structures/queues/circular-queue.c).
-   **Priority Queue**: It is a special type of queue in which the elements are arranged based on the priority. It is a special type of queue data structure in which every element has a priority associated with it.

### Hash Table

A **Hash table** is a data structure that stores some information, and the information has basically two main components, i.e., key and value. The **hash table** can be implemented with the help of an associative array. The efficiency of mapping depends upon the efficiency of the hash function used for mapping.
![linked list representation](/data-structures/images/hash-table.png)

```c
#define SIZE 26

// Structure for each node in the linked list
typedef struct Node
{
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node *table[SIZE]; // Array of pointers to linked lists
} HashTable;
```

A **Hash table** could also be seen as an Array of Linked Lists.

[View implementation of Hash table](/data-structures/hash-tables/hash-table.c)

### Trees

A **Tree** is a data structure that represents data hierarchically. It is a collection of nodes in a parent-child relationship. A **tree** can be defined as a collection of nodes in which each node is a data structure consisting of a value, address of the parent node, and address of the child nodes.

#### Types of Trees

-   **General Trees**: A general tree is a tree in which each node can have any number of children.
-   **Binary Trees**: A binary tree is a tree in which each node can have at most two children.
-   **Binary Search Trees**: A binary search tree is a binary tree in which the value of each node is greater than or equal to the value of its left child and less than or equal to the value of its right child.
-   **AVL Tree**: An AVL tree is a self-balancing binary search tree where the heights of the two child subtrees of any node differ by at most one.
-   **Treap**: A treap is a type of binary search tree that combines the properties of a binary heap and a binary search tree, where each node has a priority value and satisfies the heap property based on priorities and the binary search tree property based on keys.
-   **B- Tree**: A B-tree is a self-balancing tree data structure that maintains sorted data and allows for efficient search, insertion, and deletion operations by keeping the tree balanced and minimizing the number of accesses to disk or memory.

### Binary Trees

The Binary tree means that the node can have maximum two children. Here, binary name itself suggests that 'two'; therefore, each node can have either 0, 1 or 2 children.
![binary tree representation](/data-structures/images/binary-tree.png)

```c
// Define structure for binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
```

#### Types of Binary trees

-   **Full/Strict Binary trees**: The full binary tree is also known as a strict binary tree. The tree can only be considered as the full binary tree if each node must contain either 0 or 2 children.
-   **Complete Binary Tree**: The complete binary tree is a tree in which all the nodes are completely filled except the last level. In the last level, all the nodes must be as left as possible.
-   **Perfect Binary Tree**: A tree is a perfect binary tree if all the internal nodes have 2 children, and all the leaf nodes are at the same level.
-   **Balanced Binary Tree**: A balanced binary tree is a binary tree in which the heights of the two subtrees of every node differ by at most one.

### Binary Search Trees

A **Binary Search tree** is a **Binary tree** where the value of left node must be smaller than the parent node, and the value of right node must be greater than the parent node.

![binary search representation](/data-structures/images/binary-search-tree.png)

[Check my implementation of binary search tree](/data-structures/trees/binary-tree.c).

### Graph

A graph is a data structure that consists of a set of nodes (vertices) and a set of edges that connect pairs of nodes.

#### Types of Graph

-   **Directed Graph (Digraph)**: In a directed graph, each edge has a direction, meaning it goes from one node to another.

    ![Directed graph representation](/data-structures/images/directed-graph.png)

-   **Undirected Graph**: In an undirected graph, edges have no direction, meaning they connect nodes in both directions.

    ![undirected graph representation](/data-structures/images/undirected-graph.png)

#### Graph representation

-   **Adjacency Matrix**: A 2D array where the presence or absence of an edge between two nodes is represented by a 1 or 0, respectively.

    ![adjacency matrix representation](/data-structures/images/graph-adjacency-matrix.png)

-   **Adjacency List**: A collection of lists or arrays where each node has a list of its adjacent nodes.

    ![adjacency list representation](/data-structures/images/graph-adjacency-list.png)

#### Adjancency list structure could be defined like this

```c
// structure to represent a node of adjacency list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// structure to represent the graph
typedef struct
{
    int numVertices;
    Node **adjacencyList;
} Graph;
```

#### Or like this

```c
// structure to represent a node of adjacency list
struct Node {
    int data;
    struct Node* next;
};

// structure to represent an adjacency list
struct AdjList {
    struct AdjNode* head;
};

// structure to represent the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};
```

[View implementation of undirected graph](/data-structures/graphs/undirected-graph.c)

### Heap

A heap is a complete binary tree, and the binary tree is a tree in which the node can have utmost two children.

![Heap data structure](/data-structures/images/heap-ds.png)

#### Types of Heap

-   **Min Heap**: The value of the parent node is less than or equal to either of its children.
-   **Max Heap**: The value of the parent node is greater than or equal to either of its children.

[View implementation of Max Heap](/data-structures/heap/max-heap.c)

## Algorithms

An **algorithm** is a process or a set of rules required to perform calculations or some other problem-solving operations on data.

### Types of Algorithms

-   Searching Algorithms
-   Sorting Algorithms

### Searching Algorithms

-   **Linear Search**: It is the simplest searching algorithm, we simply traverse the list completely and match each element of the list with the item whose location is to be found. If the match is found, then the location of the item is returned; otherwise, the algorithm returns NULL or -1.

![linear search representation](/algorithms/images/linear-search.png)

[Check my implementation of Linear search in java](/algorithms/searching/LinearSearch.java).

-   **Binary Search**: Binary search is the search technique that works efficiently on sorted lists. It follows the divide and conquer approach in which the list is divided into two halves, and the item is compared with the middle element of the list. If the match is found then, the location of the middle element is returned. Otherwise, we search into either of the halves depending upon the result produced through the match.

![binary search representation](/algorithms/images/binary-search.png)

[Check implementation of Binary search in java](/algorithms/searching/BinarySearch.java).

### Sorting Algorithms

-   **Bubble Sort**: Bubble sort works on the repeatedly swapping of adjacent elements until they are not in the intended order. Although it is simple to use, it is primarily used as an educational tool because the performance of bubble sort is poor in the real world. It is not suitable for large data sets. The average and worst-case complexity of Bubble sort is O(n²)

**Implementation of Bubble sort**

```java
    private static void sort(int[] array) {
        int i, j;
        for (i = 0; i < array.length; i++)
            for (j = i + 1; j < array.length; j++)
                if (array[i] > array[j])
                    swap(array, i, j);
    }

    private static void swap(int array[], int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
```

-   **Selection sort**: **Selection sort** is a simple sorting algorithm that works by repeatedly finding the minimum (or maximum, depending on sorting order) element from the unsorted part of the array and moving it to the beginning.

**Implementation of Selection sort**

```java
    private static void sort(int[] array) {
            int n = array.length;

            for (int i = 0; i < n - 1; i++) {
                int minIndex = i;

                for (int j = i + 1; j < n; j++) {
                    if (array[j] < array[minIndex]) {
                        minIndex = j;
                    }
                }
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
    }
```

-   **Insertion sort**: **Insertion sort** is a simple sorting algorithm that builds the final sorted array one element at a time. It iterates over the input array and, in each iteration, it removes one element from the input data, finds the location it belongs to in the sorted array, and inserts it there.

**Implementation of Insertion sort**

```java
    private static void sort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
```

-   **Heap Sort**: **Heap sort** is a comparison-based sorting algorithm that uses the heap data structure to sort elements in an array. It works by first building a heap from the input array and then repeatedly extracting the maximum (for a max heap) or minimum (for a min heap) element from the heap and placing it at the end of the array. The process is repeated until the heap is empty, resulting in a sorted array.

[View implementation of Heap Sort](/algorithms/sorting/HeapSort.java)

-   **Quick Sort**: **Quick sort** is a highly efficient, comparison-based sorting algorithm that falls under the category of divide-and-conquer algorithms. It works by dividing the input array into smaller sub-arrays, sorting each sub-array recursively, and then combining them to produce the sorted output.

**Implementation of Quick Sort**

```java
    private static void sort(int arr[], int start, int end) {
        if (start < end) {
            int p = partition(arr, start, end);
            sort(arr, start, p - 1);
            sort(arr, p + 1, end);
        }
    }

    private static int partition(int arr[], int start, int end) {
        int pivot = arr[end];
        int i = (start - 1);
        for (int j = start;j < end;j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, end);
        return (i + 1);
    }
```

### Common Algorithms for Trees

- **Depth First Search (DFS)** In the context of binary trees, DFS (Depth-First Search) is a tree traversal algorithm that systematically explores the nodes of the tree in a depth-first manner.
    1. Pre-Order Traversal <small>[View Implementation](/algorithms/trees/pre-order.c)</small>
    2. Post-Order Traversal <small>[View Implementation](/algorithms/trees/post-order.c)</small>
    3. In-Order Traversal <small>[View Implementation](/algorithms/trees/in-order.c)</small>

- **Breadth First Search (BFS)** BFS is a traversal algorithm that systematically explores the nodes of a tree level by level, starting from the root node and moving towards the leaves. Unlike DFS (Depth-First Search), which explores nodes depth-wise, BFS explores nodes breadth-wise, visiting all nodes at the same level before moving to the next level.
