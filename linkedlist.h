//
// Created by susautw on 2020/5/24.
//

#ifndef PLAYGROUND_LINKEDLIST_H
#define PLAYGROUND_LINKEDLIST_H

#include <stddef.h>

typedef struct Node Node;
struct Node{
    Node* next;
    void* data;
};

typedef struct LinkedList LinkedList;
struct LinkedList{
    Node* head;
    Node* last;
    int size;
};

Node* init_node(void* data, Node* next);

LinkedList*  init_linkedlist();

// init, add, remove, insert, list_find, list_get
//add : add a data at end of list
void list_add(LinkedList* this, void* data);
//remove: remove the data from list.
int list_remove(LinkedList* this, void* data);
//insert: insert a data at a position
int list_insert(LinkedList* this, void * data, int pos);
//find: find a data and return its position
int list_find(LinkedList* this, void* data);
//get: get a data at the position
void* list_get(LinkedList* this, int pos);

void print_list(LinkedList* this);
#endif //PLAYGROUND_LINKEDLIST_H
