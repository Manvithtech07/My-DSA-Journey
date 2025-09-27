# Introduction to Data Structures and Algorithms

## What is a Data Structure?

A **Data Structure** is a systematic way of organizing, storing, and managing data in a computer's memory so that it can be accessed and manipulated efficiently. The choice of data structure determines how data is stored and the operations that can be performed on it.

* **Examples:** Arrays, Linked Lists, Stacks, Queues, Trees, Graphs.
 
## What is an Algorithm?

An **Algorithm** is a finite, well-defined sequence of steps or instructions designed to solve a specific problem or perform a computation. It takes a set of inputs and produces a desired output.

* **Characteristics of a good algorithm:**
    * **Input:** It has zero or more well-defined inputs.
    * **Output:** It produces at least one well-defined output.
    * **Finiteness:** It must terminate after a finite number of steps.
    * **Definiteness:** Each step must be clear and unambiguous.
    * **Effectiveness:** Every instruction must be basic enough to be carried out.
 

# Performance Analysis of Algorithms

Analyzing an algorithm's performance is crucial for writing efficient code. We primarily measure two things:

1.  **Time Complexity:** The amount of time an algorithm takes to run as a function of the length of the input. We use **Asymptotic Notations** to describe this.
2.  **Space Complexity:** The amount of memory (space) an algorithm requires as a function of the length of the input.

### Asymptotic Notations

* **Big-O Notation (O):** Describes the **worst-case scenario**. It provides an upper bound on the time complexity.
* **Omega Notation (Ω):** Describes the **best-case scenario**. It provides a lower bound.
* **Theta Notation (Θ):** Describes the **average-case scenario**. It provides a tight bound, meaning the best and worst cases are the same.

# Analysis of Recursive Algorithms

Analyzing recursive algorithms involves understanding how many times the function calls itself and the work done at each step.

A common way to express the runtime of a recursive algorithm is through a **recurrence relation**.

* **Example for Binary Search:** `T(n) = T(n/2) + c`
    * This means the time to solve a problem of size `n`, `T(n)`, is the time to solve a problem of half the size, `T(n/2)`, plus some constant time `c` for the comparison.

Two common methods to solve recurrence relations are:

1.  **Substitution Method:** We guess a bound and then use mathematical induction to prove our guess is correct.
2.  **Recursion Tree Method:** We draw a tree representing the recursive calls and sum up the work done at each level.
