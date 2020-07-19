//
// Created by Sriharsha Singam on 7/18/20.
//

#ifndef MEMORYLISTS_SINGLELINKEDLISTS_H
#define MEMORYLISTS_SINGLELINKEDLISTS_H

#include "linkedlists.h"

typedef struct _single_linked_list single_linked_list;

struct _single_linked_list {
    void* value;
    single_linked_list* next;
};

typedef struct _single_linked_list_metadata single_linked_list_metadata;

struct _single_linked_list_metadata {
    single_linked_list* head;
    single_linked_list* last;
    unsigned long overall_size;
    unsigned long overall_data_size;
    linked_list_sorter* sorter;
};

single_linked_list_metadata* get_single_linked_list_metadata();
single_linked_list_metadata* single_linked_list_init(linked_list_sorter* sorter);
single_linked_list* insert_single_linked_list(void* value);
void sort_single_linked_list();

#endif //MEMORYLISTS_SINGLELINKEDLISTS_H
