/*4. Design data structure for single linked list. Write function to insert element in O(1) time and find the maximum and minimum element in 
O(1) time */
#ifndef MIN_MAX_SLL_H
#define MIN_MAX_SLL_H
#include <stdint.h>

typedef struct _node_ Node;
typedef struct _slist_ List;

struct _node_{
	int32_t data;
	Node *next;
};
struct _slist_{
	Node *head;
	Node *tail;
	uint32_t length;
	int32_t min;
	int32_t max;
};

List *slist_new();
List *slist_add_head(List *list, int32_t data);
int32_t slist_get_min(const List *list);
int32_t slist_get_max(const List *list);
void display_list(List *list);
void slist_free(List *list);
#endif