#include<stdio.h>
#include<stdlib.h>
#include "minmaxo1.h"
List *slist_new(){
	List *list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
};
static Node*_create_new_node(int32_t data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}
List *slist_add_head(List *list, int32_t data){
	Node *node = _create_new_node(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->min = data;
        list->max = data;
    } else {
        // If the list is NOT empty, add to the head
        // and then compare to update min and max.
        node->next = list->head;
        list->head = node;

        if (data < list->min) {
            list->min = data;
        }
        if (data > list->max) {
            list->max = data;
        }
    }
	++list->length;
	return list;
}
int32_t slist_get_min(const List* list) {
    return list->min;
}
int32_t slist_get_max(const List* list) {
    return list->max;
}
void display_list(List *list){
	printf("List (length %u) HEAD-> ",list->length);
	Node *current = list->head;
	while(current!=NULL){
		printf("%d -> ",current->data);
		current = current->next;
	}
	printf("NULL\n");
}
void slist_free(List *list){
	Node *current = list->head;
	while(current!=NULL){
		Node *p = current;
		current = current->next;
		free(p);
	}
	free(list);
}