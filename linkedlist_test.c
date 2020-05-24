//
// Created by susautw on 2020/5/24.
//

#include "linkedlist.h"
#include "stdio.h"

int main(){
    // initialization test
    LinkedList* list = init_linkedlist();
    print_list(list);

    // add test
    int item[10] = {0, 1, 2, 3, 4, 5, 6 ,7, 8, 9};
    list_add(list, &item[0]);
    print_list(list);
    list_add(list, &item[2]);
    print_list(list);
    list_add(list, &item[1]);
    print_list(list);

    // remove test
    list_remove(list, &item[2]);
    print_list(list);
    list_remove(list, &item[1]);
    print_list(list);

    // insert test
    list_insert(list, &item[1], 0);
    print_list(list);
    list_insert(list, &item[2], 0);
    print_list(list);
    list_insert(list, &item[3], 2);
    print_list(list);

    // find test
    printf("%d\n", list_find(list, &item[3]) == 2);
    printf("%d\n", list_find(list, &item[2]) == 0);
    printf("%d\n", list_find(list, &item[1]) == 1);
    print_list(list);
    puts("");
    // get test
    int pos[4] = {3, 1, 0, 2};
    for( int i = 0 ; i < 4; i++)
        printf("%d\n", list_get(list, pos[i]) == &item[i]);
    print_list(list);
}