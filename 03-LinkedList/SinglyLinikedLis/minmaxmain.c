#include <stdio.h>
#include "minmaxo1.h"
int main(){
    List *list = slist_new();
    display_list(list);
    slist_add_head(list,30);
    display_list(list);
    slist_add_head(list,20);
    display_list(list);
    slist_add_head(list,10);
    display_list(list);
    printf("Current Min: %d, Current Max: %d\n\n", slist_get_min(list), slist_get_max(list));
    slist_free(list);
    return 0;
}
