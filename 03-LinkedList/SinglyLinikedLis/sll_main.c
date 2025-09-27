#include <stdio.h>
#include "sll.h"
void linearSearch(List *list, int32_t key){
	uint32_t position = slist_search(list,key);
		if(position>0){
			printf("Found key %d at position %u.\n",key,position);
		}else{
			printf("Key %d was not found in the list\n",key);
		}
}
int main(){
	List *list = slist_new();
	List *list2 = slist_new();
	display_list(list);
	slist_add_head(list,20);
	display_list(list);
	slist_add_head(list,10);
	display_list(list);
	slist_add_head(list,10);
	display_list(list);
	slist_add_tail(list,30);
	display_list(list);
	slist_add_tail(list,40);
	display_list(list);
	slist_add_at_postion(list,99,3);
	display_list(list);
	slist_add_at_postion(list,69,4);
	display_list(list);
	//slist_delete_head(list);
	//display_list(list);
	//slist_delete_tail(list);
	//display_list(list);
	//slist_delete_at_position(list,3);
	//display_list(list);
	linearSearch(list,69);
	linearSearch(list,10);
	linearSearch(list,-10);
	//slist_reverse(list);
	display_list(list);
	slist_reverse_and_nth_from_end(list, 3);
	int32_t min_val,max_val;
	if(slist_get_min_max(list,&min_val,&max_val)){
		printf("Min: %d Max: %d\n",min_val,max_val);
	}else{
		printf("list empty\n");
	}
	slist_remove_duplicates(list);
	display_list(list);
	slist_bubble_sort(list);
	display_list(list);	
	slist_add_tail(list2, 30);
    slist_add_tail(list2, 40);
    slist_add_tail(list2, 50);
    slist_add_tail(list2, 60);
    display_list(list2);
   	List *union_list = slist_union(list,list2);
   	display_list(union_list);
   	List *intersection_list = slist_intersection(list,list2);
   	display_list(intersection_list);
	slist_free(list);
    return 0;
}
