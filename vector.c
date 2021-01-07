//
// Created by Sriharsha Singam on 12/12/2020.
//

#include "vector.h"
#include <stdlib.h>
#include <string.h>


vector* vector_init() {
    return vector_init_create_type(0);
}

vector* vector_init_create_type(uint32_t size) {
    vector* vector_object = (vector*) malloc(sizeof(vector));
    vector_object->linked_list = doubly_linked_list_init(NULL);
    vector_object->data_size = size;
    return vector_object;
}

void vector_push_back(vector* vector, void* value) {
    if (vector == NULL) return;
    insert_doubly_linked_list_entry(vector->linked_list, value);
}

void vector_push_back_type(vector* vector, void* value) {
    if (vector == NULL) return;
    vector_push_back_create_type(vector, value, vector->data_size);
}

void vector_push_back_create_type(vector* vector, void* value, uint32_t size) {
    if (vector == NULL) return;
    void* create_type = (void*) malloc(size);
    memcpy(create_type, value, size);
    insert_doubly_linked_list_entry(vector->linked_list, create_type);
}

void vector_push_front(vector* vector, void* value) {
    if (vector == NULL) return;
    insert_front_doubly_linked_list_entry(vector->linked_list, value);
}

void vector_push_front_type(vector* vector, void* value) {
    if (vector == NULL) return;
    vector_push_front_create_type(vector, value, vector->data_size);
}

void vector_push_front_create_type(vector* vector, void* value, uint32_t size) {
    if (vector == NULL) return;
    void* create_type = (void*) malloc(size);
    memcpy(create_type, value, size);
    insert_front_doubly_linked_list_entry(vector->linked_list, create_type);
}

void* vector_pop_back(vector* vector) {
    if (vector == NULL) return NULL;
    return remove_doubly_linked_list_entry(vector->linked_list, vector->linked_list->last);
}

void* vector_pop_front(vector* vector) {
    if (vector == NULL) return NULL;
    return remove_doubly_linked_list_entry(vector->linked_list, vector->linked_list->head);
}

void* vector_at(vector* vector, uint32_t index) {
    if (vector == NULL) return NULL;
    return get_doubly_linked_list_entry(vector->linked_list, index)->value;
}

uint32_t vector_size(vector* vector) {
    if (vector == NULL) return 0;
    return length_of_doubly_linked_list_entries_list(vector->linked_list);
}

void vector_print(vector* vector) {
    if (vector == NULL) return;
    print_doubly_linked_list(vector->linked_list);
}

void vector_print_index(vector* vector, uint32_t index) {
    if (vector == NULL) return;
    print_doubly_linked_list_entry((doubly_linked_list*) vector_at(vector, index));
}

bool vector_empty(vector* vector) {
   if (vector_size(vector) > 0)
       return TRUE;
   return FALSE;
}

void vector_clear(vector* vector) {
    if (vector == NULL) return;
    delete_doubly_linked_list_all_entries(vector->linked_list);
}

void vector_delete(vector** vector) {
    if (vector == NULL || *vector == NULL) return;
    delete_doubly_linked_list(&(*vector)->linked_list);
    free(*vector);
    *vector = NULL;
}