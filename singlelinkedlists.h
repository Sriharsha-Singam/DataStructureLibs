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

single_linked_list_metadata* single_linked_list_init(linked_list_sorter* sorter);
single_linked_list* insert_single_linked_list_entry(single_linked_list_metadata* linked_list_metadata, void* value);
void* remove_single_linked_list_entry(single_linked_list_metadata* linked_list_metadata, single_linked_list* entry);
void swap_single_linked_list(single_linked_list_metadata* linked_list_metadata, single_linked_list* prev, single_linked_list* next);
void sort_single_linked_list(single_linked_list_metadata* linked_list_metadata);

#endif //MEMORYLISTS_SINGLELINKEDLISTS_H
