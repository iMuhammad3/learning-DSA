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
- **Circular singly linked list** - In a circular singly linked list, the last node of the list contains a pointer to the first node of the list. We can have circular singly linked list as well as circular doubly linked list.
- **Circular doubly linked list** - Circular doubly linked list is a more complex type of data structure in which a node contains pointers to its previous node as well as the next node. Circular doubly linked list doesn't contain NULL in any of the nodes. The last node of the list contains the address of the first node of the list. The first node of the list also contains the address of the last node in its previous pointer.