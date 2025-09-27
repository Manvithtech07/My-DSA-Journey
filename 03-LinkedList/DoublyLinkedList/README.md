# Operations Implemented

This implementation provides the core functions for manipulating a doubly linked list from both ends.

Insertion Operations

    add_head(List *list, int data): Creates a new node with the given data and adds it to the beginning of the list.

    add_tail(List *list, int data): Creates a new node with the given data and adds it to the end of the list.

Deletion Operations

    delete_head(List *list): Removes the node from the beginning of the list and frees its memory.

    delete_tail(List *list): Removes the node from the end of the list and frees its memory.

Utility Functions

    dll_new(): Initializes and returns a new, empty list.

    display_list(List *list): Prints all the elements of the list from head to tail.

File Structure

The project is organized into the following files:

    dll.h: The header file with structure definitions and function prototypes.

    dll.c: The implementation file containing the C code for the doubly linked list functions.

    main.c: A driver program to test the implemented operations.
