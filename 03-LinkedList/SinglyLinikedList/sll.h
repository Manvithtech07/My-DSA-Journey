#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_

#include<stdint.h>

typedef struct _slist_ List;
typedef struct _node_ Node;

struct _slist_ {
	Node *head;
	Node *tail;
	uint32_t length;
};
struct _node_ {
	int32_t data;
	Node *next;
};

//function prototypes

List *slist_new();
List *slist_add_head(List *list, int32_t data);
List *slist_add_tail(List *list, int32_t data);
List *slist_add_at_postion(List *list, int32_t data, uint32_t position);
List *slist_delete_head(List *list);
List *slist_delete_tail(List *list);
List *slist_delete_at_position(List *list, uint32_t position);
uint32_t slist_search(List *list, int32_t key);
void slist_reverse_and_nth_from_end(List *list, uint32_t n);
int32_t slist_get_min_max(List *list, int32_t *min, int32_t *max);
void slist_remove_duplicates(List *list);
void slist_bubble_sort(List *list);
List *slist_union(List *list1,List *list2);
List *slist_intersection(List *list,List *list2);
void display_list(List *list);
void slist_free(List *list);
#endif