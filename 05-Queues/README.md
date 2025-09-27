# Queues in C

This section covers the C implementation of a Queue, a fundamental linear data structure that follows the **FIFO (First-In, First-Out)** principle.

---

## 🤔 What is a Queue?

A queue is a linear collection of elements where insertions happen at one end, called the **rear**, and deletions happen at the other end, called the **front**. This behavior mimics a real-world queue, like a line at a checkout counter. The first person to get in line is the first person to be served.

**Key characteristics:**
* **FIFO Principle:** The first element added to the queue is the first one to be removed.
* **Two Ends:** Operations occur at both the front (deletions) and rear (insertions).



---

## ⚙️ Core Operations

* **`enqueue(data)`:** Adds an element to the **rear** of the queue.
* **`dequeue()`:** Removes and returns the element from the **front** of the queue.
* **`front()`**: Returns the front element of the queue without removing it.
* **`rear()`**: Returns the rear element of the queue without removing it.
* **`isEmpty()`:** Checks if the queue is empty.
* **`isFull()`:** Checks if the queue is full (for array-based implementations).

---

## 📈 Complexity Analysis

Queues offer very efficient primary operations, making them ideal for managing tasks in order.

| Operation | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| **Enqueue** | `O(1)` | `O(n)` |
| **Dequeue** | `O(1)` | `O(n)` |
| **Front / Rear** | `O(1)` | `O(n)` |
| **Search** | `O(n)` | `O(n)` |

---

## 💻 C Implementation Details (Circular Array-based)

A queue is often implemented using a circular array to make `enqueue` and `dequeue` operations efficient `O(1)` time. Pointers for `front` and `rear` wrap around to the beginning of the array as needed.

```c
#include <stdint.h>

typedef struct _queue_ {
    int32_t *items;   // Pointer to the array holding queue items
    int32_t front;    // Index of the front element
    int32_t rear;     // Index of the rear element
    uint32_t size;     // Current number of items in the queue
    uint32_t capacity; // Maximum capacity of the queue
} Queue;
```

---

## 🚀 Function Prototypes

Here are the essential function prototypes for a circular queue implementation.

```c
// Creates and returns a new queue with a given capacity.
Queue* create_queue(uint32_t capacity);

// Frees all memory associated with the queue.
void destroy_queue(Queue* queue);

// Checks if the queue is full.
int32_t is_full(Queue* queue);

// Checks if the queue is empty.
int32_t is_empty(Queue* queue);

// Adds an item to the rear of the queue.
void enqueue(Queue* queue, int32_t item);

// Removes and returns the item from the front of the queue.
int32_t dequeue(Queue* queue);

// Returns the front item of the queue.
int32_t front(Queue* queue);

// Returns the rear item of the queue.
int32_t rear(Queue* queue);
```
