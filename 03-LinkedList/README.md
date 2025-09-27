# Linked Lists in C

This repository contains a C implementation of various types of linked lists, a fundamental data structure in computer science. It covers the creation, manipulation, and traversal of Singly, Doubly, and Circular Linked Lists.

---

## 📖 Table of Contents
1.  [What is a Linked List?](#-what-is-a-linked-list)
2.  [Types of Linked Lists](#-types-of-linked-lists)
    * [Singly Linked List](#1-singly-linked-list)
    * [Doubly Linked List](#2-doubly-linked-list)
    * [Circular Linked List](#3-circular-linked-list)
3.  [Complexity Analysis](#-complexity-analysis)
4.  [C Implementation Details](#-c-implementation-details-singly-list)
5.  [Implemented Operations (Singly List)](#-implemented-operations-singly-list)

---

## 🤔 What is a Linked List?

A linked list is a linear data structure where elements are not stored at contiguous memory locations. Instead, each element is a separate object called a **node**. A node consists of two items: the **data** and a **pointer** (or link) to the next node in the sequence.

**Key advantages over arrays:**
* **Dynamic Size:** Linked lists can grow or shrink during program execution.
* **Efficient Insertion/Deletion:** Inserting or deleting nodes from the beginning or end of the list is very fast (O(1)).



---

## ⛓️ Types of Linked Lists

### 1. Singly Linked List

This is the simplest type of linked list where each node contains data and a **single pointer** (`next`) that points to the next node in the sequence. Traversal is only possible in one direction.

`[HEAD] -> [Node 1 | next] -> [Node 2 | next] -> [Node 3 | NULL]`


### 2. Doubly Linked List

In a doubly linked list, each node contains data and **two pointers**: one pointer to the **next** node and another pointer to the **previous** node. This allows for traversal in both forward and backward directions.

`[NULL] <- [HEAD | prev | next] <-> [Node 2 | prev | next] <-> [TAIL | prev | next] -> [NULL]`


### 3. Circular Linked List

A circular linked list is a variation where the `next` pointer of the last node points back to the **head** node instead of pointing to `NULL`. This forms a circle. A circular list can be either singly or doubly linked.

`[HEAD] -> [Node 1] -> [Node 2] -> (points back to HEAD)`


---

## 📈 Complexity Analysis

The efficiency of linked list operations is a key aspect of their utility.

| Operation | Singly List | Doubly List |
| :--- | :---: | :---: |
| **Access (by index)** | `O(n)` | `O(n)` |
| **Search (by value)** | `O(n)` | `O(n)` |
| **Insertion (Head)** | `O(1)` | `O(1)` |
| **Insertion (Tail)** | `O(1)` | `O(1)` |
| **Deletion (Head)** | `O(1)` | `O(1)` |
| **Deletion (Tail)** | `O(n)` | `O(1)` |

***Note:** Deleting the tail in a singly list is `O(n)` because you must traverse the list to find the second-to-last node. A doubly list makes this `O(1)` because the tail's `prev` pointer directly gives you the new tail.*

---

## 💻 C Implementation Details (Singly List)

The implementation is built around two core structures: `Node` and `List`.

* **`struct _node_`**: Represents a single element in the list. It holds the integer `data` and a pointer `next` to the subsequent node.
* **`struct _slist_`**: Represents the entire list. It contains pointers to the `head` (first node) and `tail` (last node) of the list, as well as its `length`.

```c
#include<stdint.h>

// The main list structure
typedef struct _slist_ {
    Node *head;
    Node *tail;
    uint32_t length;
} List;

// The node structure
typedef struct _node_ {
    int32_t data;
    Node *next;
} Node;
```

---

## 🚀 Implemented Operations (Singly List)

Below is a complete list of the implemented functions for the singly linked list.

```c
/* ~~~~~~~~~~~~~~ BASIC OPERATIONS ~~~~~~~~~~~~~~ */
// Creates and initializes a new, empty list.
List *slist_new();
// Frees all memory associated with the list and its nodes.
void slist_free(List *list);
// Displays all elements in the list from head to tail.
void display_list(List *list);

/* ~~~~~~~~~~~~~~ INSERTION ~~~~~~~~~~~~~~ */
// Adds a new node with 'data' to the beginning of the list.
List *slist_add_head(List *list, int32_t data);
// Adds a new node with 'data' to the end of the list.
List *slist_add_tail(List *list, int32_t data);
// Adds a new node at a specific 'position' (0-indexed).
List *slist_add_at_postion(List *list, int32_t data, uint32_t position);

/* ~~~~~~~~~~~~~~ DELETION ~~~~~~~~~~~~~~ */
// Removes the first node from the list.
List *slist_delete_head(List *list);
// Removes the last node from the list.
List *slist_delete_tail(List *list);
// Removes a node from a specific 'position' (0-indexed).
List *slist_delete_at_position(List *list, uint32_t position);

/* ~~~~~~~~~~~~~~ UTILITY & ADVANCED OPERATIONS ~~~~~~~~~~~~~~ */
// Searches for 'key' and returns its 0-indexed position.
uint32_t slist_search(List *list, int32_t key);
// Reverses the list and finds the Nth node from the end.
void slist_reverse_and_nth_from_end(List *list, uint32_t n);
// Finds the minimum and maximum values in the list.
int32_t slist_get_min_max(List *list, int32_t *min, int32_t *max);
// Removes all duplicate elements from the list.
void slist_remove_duplicates(List *list);
// Sorts the list using the Bubble Sort algorithm.
void slist_bubble_sort(List *list);

/* ~~~~~~~~~~~~~~ SET OPERATIONS ~~~~~~~~~~~~~~ */
// Returns a new list containing the union of two lists.
List *slist_union(List *list1,List *list2);
// Returns a new list containing the intersection of two lists.
List *slist_intersection(List *list,List *list2);
```
