# Operations on linked list are performed like: 
Basic Operations

    slist_new(): Creates and returns a new, empty list.

    display_list(): Traverses the list and prints the data of each node.

    slist_free(): Frees all memory allocated for the list and its nodes.

Insertion Operations

    slist_add_head(List *list, int32_t data): Adds a new node with the given data to the beginning of the list.

    slist_add_tail(List *list, int32_t data): Adds a new node with the given data to the end of the list.

    slist_add_at_postion(List *list, int32_t data, uint32_t position): Adds a new node at a specified position.

Deletion Operations

    slist_delete_head(List *list): Deletes the first node of the list.

    slist_delete_tail(List *list): Deletes the last node of the list.

    slist_delete_at_position(List *list, uint32_t position): Deletes a node from a specified position.

Utility and Advanced Operations

    slist_search(List *list, int32_t key): Searches for a given key and returns its position.

    slist_reverse_and_nth_from_end(List *list, uint32_t n): Reverses the list and finds the Nth node from the end.

    slist_get_min_max(List *list, int32_t *min, int32_t *max): Finds the minimum and maximum elements in the list.

    slist_remove_duplicates(List *list): Removes duplicate elements from the list.

    slist_bubble_sort(List *list): Sorts the list using the bubble sort algorithm.

    slist_union(List *list1, List *list2): Computes the union of two linked lists.

    slist_intersection(List *list1, List *list2): Computes the intersection of two linked lists.
