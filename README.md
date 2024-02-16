# Learning DSA

Resources I use to learn:
- [Javatpoint](https://www.javatpoint.com/data-structure-tutorial)

## Data Structures
**Data Structure** is a particular way of storing and organizing data in the memory of the computer so that these data can easily be retrieved and efficiently utilized in the future when required. 

### Types of Data Structures
- Arrays
- Linked Lists
- Stacks
- Queues
- Trees
- Graphs

### Basic Operations of Data Structures

- **Traversal**
- **Search**
- **Insertion**
- **Deletion**
- **Sorting**
- **Merge**
- **Create**
- **Selection**
- **Update**

### Arrays
**Arrays** are defined as the collection of similar types of data items stored at contiguous memory locations. It is one of the simplest data structures where each data element can be randomly accessed by using its index number.

### Linked Lists
**Linked list** is a linear data structure that includes a series of connected nodes. Linked list can be defined as the nodes that are randomly stored in the memory. A node in the linked list contains two parts, i.e., first is the data part and second is the address part. The last node of the list contains a pointer to the null.

```c
// How to create type Node in C
typedef struct node
{
    int item;
    struct node *next;
} node;
```

#### Types of Linked Lists
- **Singly-linked list** - Singly linked list can be defined as the collection of an ordered set of elements. A node in the singly linked list consists of two parts: data part and link part.
[Check my implementation of singly linked lists](/data-structures/linked-list/singly-linked-list.c)
- **Doubly linked list** - Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence. Therefore, in a doubly-linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer), and pointer to the previous node (previous pointer).
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
- **Circular singly linked list** - In a circular singly linked list, the last node of the list contains a pointer to the first node of the list. We can have circular singly linked list as well as circular doubly linked list.
- **Circular doubly linked list** - Circular doubly linked list is a more complex type of data structure in which a node contains pointers to its previous node as well as the next node. Circular doubly linked list doesn't contain NULL in any of the nodes. The last node of the list contains the address of the first node of the list. The first node of the list also contains the address of the last node in its previous pointer.

### Stacks
A **Stack** is a linear data structure that follows the LIFO (Last-In-First-Out) principle. a **Stack** can also be defined as a container in which insertion and deletion can be done from the one end known as the top of the stack.
Stacks can be implemented using arrays or linked lists, here I learnt how to implement stacks using arrays.
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

```c
// define an array queue structure
typedef struct {
    int array[MAX_SIZE];
    int rear;
    int front;
} Queue;
```

#### Types of Queues
- **Simple or Linear Queue**: In Linear Queue, an insertion takes place from one end while the deletion occurs from another end. The end at which the insertion takes place is known as the rear end, and the end at which the deletion takes place is known as front end. It strictly follows the FIFO rule.
The major drawback of using a linear Queue is that insertion is done only from the rear end. If the first three elements are deleted from the Queue, we cannot insert more elements even though the space is available in a Linear Queue. In this case, the linear Queue shows the overflow condition as the rear is pointing to the last element of the Queue.
[Check my implementation of linear queue using arrays](/data-structures/queues/linear-queue.c).
- **Circular Queue**: In Circular Queue, all the nodes are represented as circular. It is similar to the linear Queue except that the last element of the queue is connected to the first element. It is also known as Ring Buffer, as all the ends are connected to another end.
[Check my implementation of linear queue using arrays](/data-structures/queues/circular-queue.c).
- **Priority Queue**: It is a special type of queue in which the elements are arranged based on the priority. It is a special type of queue data structure in which every element has a priority associated with it.