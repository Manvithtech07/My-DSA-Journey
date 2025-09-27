# 02 - Arrays and Sorting Algorithms

This directory contains C programs that demonstrate fundamental array operations and a variety of essential sorting algorithms. Each file is a self-contained program that solves a specific problem or implements a particular algorithm.

---

## 📋 Implemented Programs

The table below provides a summary of the programs currently in this directory.

| File Name | Description | Key Concepts Demonstrated |
| :--- | :--- | :--- |
| **`01_store_and_search.c`** | A basic program to populate an array and search for an element using a linear scan. | `Array Initialization`, `Linear Search`, `Iteration` |
| **`bubblesort.c`** | Implementation of the **Bubble Sort** algorithm, which repeatedly swaps adjacent elements if they are in the wrong order. | `Comparison Sort`, `Swapping`, `O(n²)` Time Complexity |
| **`selectionsort.c`** | Implementation of the **Selection Sort** algorithm, which repeatedly finds the minimum element and moves it to the sorted portion. | `Finding Minimum`, `In-place Sort`, `O(n²)` Time Complexity |
| **`insertionsort.c`** | Implementation of the **Insertion Sort** algorithm, building the final sorted array one item at a time. | `Shifting Elements`, `Efficient for nearly sorted data` |
| **`mergesort.c`** | Implementation of the **Merge Sort** algorithm, a highly efficient sorting method based on the "Divide and Conquer" paradigm. | `Divide and Conquer`, `Recursion`, `O(n log n)` Time Complexity |
| **`quicksort.c`** | Implementation of the **Quick Sort** algorithm, another efficient "Divide and Conquer" algorithm that uses a pivot element. | `Pivoting`, `Partitioning`, `Recursion` |

---

## 🚀 How to Compile and Run

Each `.c` file can be compiled and run individually using a C compiler like `gcc`.

1.  **Open your terminal.**
2.  **Navigate** to this directory (`02-Arrays`).
3.  **Compile the desired file** using the following command format:
    ```bash
    gcc <filename>.c -o <executable_name>
    ```
    *Example:*
    ```bash
    gcc mergesort.c -o mergesort_program
    ```
4.  **Run the compiled program:**
    ```bash
    ./mergesort_program
    ```

---

## 🔮 Future Additions

This directory will be updated with more programs focusing on:
* Advanced search algorithms (e.g., Binary Search)
* 2D arrays (Matrices)
* Dynamic arrays
* Array rotation problems
* And more!
