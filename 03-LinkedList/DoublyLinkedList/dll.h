#ifndef _DLL_H
#define _DLL_H
#include <stdint.h>
typedef struct _dll_ List;
typedef struct _node_ Node;
struct _node_ {
	int32_t data;
	Node *next;
	Node *prev;
};
struct _dll_ {
	Node *head;
	Node *tail;
	uint32_t length;
};

//function prototypes
List *dll_new();
List *dll_add_head(List *list, int32_t data);
List *dll_add_tail(List *list, int32_t data);
List *dll_delete_head(List *list);
List *dll_delete_tail(List *list);
void display_list(List *list);
void dll_free(List *list);
#endif



