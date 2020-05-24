//
// Created by susautw on 2020/5/24.
//


#include "linkedlist.h"
#include "stdlib.h"
#include "stdio.h"

Node* init_node(void* data, Node* next){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

// init, add, remove, insert, list_find, list_get
LinkedList* init_linkedlist(){
    LinkedList* self = malloc(sizeof(LinkedList));
    self->head = init_node(NULL, NULL);
    self->last = self->head;
    self->size = 0;
    return self;
}


//add : add a data at end of list
void list_add(LinkedList* this, void* data){
    Node* node = init_node(data, NULL);
    this->last->next = node;
    this->last = node;
    this->size++;
}
//remove: remove the data from list, and return it.
int list_remove(LinkedList* this, void* data){
    Node* node = this->head;
    while (node->next != NULL && node->next->data != data)
        node = node->next;
    if(node->next == NULL){
        return 0;
    }
    if(node->next == this->last){
        this->last = node;
    }
    node->next = node->next->next;
    this->size--;
    return 1;
}
//insert: insert a data at a position
int list_insert(LinkedList* this, void * data, int pos){
    if (pos > this->size - 1)
        return 0;
    Node * node = this->head;
    int at = -1;
    for(;at < pos - 1; at++){
        node = node->next;
    }
    Node* new_node = init_node(data, node->next);
    node->next = new_node;
    this->size++;
    return 1;
}
//find: find a data and return its position
int list_find(LinkedList* this, void* data){
    int pos = -1;
    Node* node = this->head;
    while (node->next != NULL && node->next->data != data) {
        pos++;
        node = node->next;
    }

    if(node->next == NULL){
        return -1;
    }
    pos++;
    return pos;
}
//get: get a data at the position
void* list_get(LinkedList* this, int pos){
    if (pos > this->size - 1)
        return 0;
    Node * node = this->head;
    int at = -1;
    for(;at < pos; at++){
        node = node->next;
    }
    return node->data;
}

void print_list(LinkedList* this){
    printf("[");
    Node * node = this->head;
    for(int i = 0;i < this->size - 1; i++){
        node = node->next;
        printf("%p, ", node->data);
    }
    if(this->size > 0)
        printf("%p", node->next->data);
    puts("]");
}