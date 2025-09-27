# Stacks in C

This section covers the C implementation of a Stack, a fundamental linear data structure that follows the **LIFO (Last-In, First-Out)** principle.

---

##  What is a Stack?

A stack is an abstract data type that serves as a collection of elements. You can only add a new item to the **top** of the stack, and you can only remove an item from the **top**.

**Key characteristics:**
* **LIFO Principle:** The last element added to the stack is the first one to be removed.
* **Restricted Access:** Elements can only be added (pushed) and removed (popped) from the top.

---

##  Core Operations

* **`push(data)`:** Adds an element to the top of the stack.
* **`pop()`:** Removes and returns the element from the top of the stack.
* **`peek()`** or **`top()`**: Returns the top element of the stack without removing it.
* **`isEmpty()`:** Checks if the stack is empty.
* **`isFull()`:** Checks if the stack is full (applies to array-based implementations).

---

##  Complexity Analysis

For both array-based and linked-list-based implementations, the core operations are highly efficient.

| Operation | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| **Push** | `O(1)` | `O(n)` |
| **Pop** | `O(1)` | `O(n)` |
| **Peek / Top** | `O(1)` | `O(n)` |
| **Search** | `O(n)` | `O(n)` |

---

##  C Implementation Details (Array-based)

A stack can be easily implemented using an array and a variable `top` that keeps track of the index of the last inserted element.

```c
#include <stdint.h>

typedef struct _stack_ {
    int32_t *items; // Pointer to the array holding stack items
    int32_t top;      // Index of the top element
    uint32_t capacity; // Maximum number of items the stack can hold
} Stack;
```

---

##  Function Prototypes

Here is a set of function prototypes for a typical array-based stack implementation.

```c
// Creates and returns a new stack with a given capacity.
Stack* create_stack(uint32_t capacity);

// Frees all memory associated with the stack.
void destroy_stack(Stack* stack);

// Checks if the stack is full. Returns 1 if full, 0 otherwise.
int32_t is_full(Stack* stack);

// Checks if the stack is empty. Returns 1 if empty, 0 otherwise.
int32_t is_empty(Stack* stack);

// Adds an item to the top of the stack.
void push(Stack* stack, int32_t item);

// Removes and returns the item from the top of the stack.
int32_t pop(Stack* stack);

// Returns the top item of the stack without removing it.
int32_t peek(Stack* stack);
```
