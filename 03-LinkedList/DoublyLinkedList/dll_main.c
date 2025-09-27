#include<stdio.h>
#include "dll.h"
int main()
{	
	List *list = dll_new();
	dll_add_head(list,20);
	dll_add_head(list,10);
	display_list(list);
	dll_add_tail(list,30);
	dll_add_tail(list,40);
	display_list(list);
	dll_delete_head(list);
	display_list(list);
	dll_delete_tail(list);
	display_list(list);
	dll_free(list);
	return 0;
}