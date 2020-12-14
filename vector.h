//
// Created by INT_ACC on 12/12/2020.
//

#ifndef MEMORYLISTS_VECTOR_H
#define MEMORYLISTS_VECTOR_H

#include "basic-structures/doublylinkedlists.h"

typedef struct _vector vector;

struct _vector {
    doubly_linked_list_metadata* linked_list;
    uint32_t data_size;
};

vector* vector_init();
vector* vector_init_create_type(uint32_t size);
void vector_push_back(vector* vector, void* value);
void vector_push_back_type(vector* vector, void* value);
void vector_push_back_create_type(vector* vector, void* value, uint32_t size);
void vector_push_front(vector* vector, void* value);
void vector_push_front_type(vector* vector, void* value);
void vector_push_front_create_type(vector* vector, void* value, uint32_t size);
void* vector_pop_back(vector* vector);
void* vector_pop_front(vector* vector);
void* vector_at(vector* vector, uint32_t index);
uint32_t vector_size(vector* vector);

#endif //MEMORYLISTS_VECTOR_H
