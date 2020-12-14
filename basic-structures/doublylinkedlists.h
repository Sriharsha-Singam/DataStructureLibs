//
// Created by Sriharsha Singam on 7/18/20.
//

#ifndef MEMORYLISTS_DOUBLYLINKEDLISTS_H
#define MEMORYLISTS_DOUBLYLINKEDLISTS_H

#include "linkedlists.h"

typedef struct _doubly_linked_list doubly_linked_list;

struct _doubly_linked_list {
    void* value;
    doubly_linked_list* next;
    doubly_linked_list* previous;
};

typedef struct _doubly_linked_list_metadata doubly_linked_list_metadata;

struct _doubly_linked_list_metadata {
    doubly_linked_list* head;
    doubly_linked_list* last;
    unsigned int overall_size;
    unsigned int overall_data_size;
    linked_list_sorter* sorter;
};


doubly_linked_list_metadata* doubly_linked_list_init(linked_list_sorter* sorter);
doubly_linked_list* insert_config_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value, bool is_front, bool sort);
doubly_linked_list* insert_front_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value);
doubly_linked_list* insert_back_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value);
doubly_linked_list* insert_sort_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value);
doubly_linked_list* insert_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value);
void* remove_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, doubly_linked_list * remove);
void swap_doubly_linked_list(doubly_linked_list_metadata* linked_list_metadata, doubly_linked_list* prev, doubly_linked_list* next);
void sort_doubly_linked_list(doubly_linked_list_metadata * linked_list_metadata);

uint32_t length_of_doubly_linked_list_entries_list(doubly_linked_list_metadata * linked_list_metadata);
doubly_linked_list* get_doubly_linked_list_entry(doubly_linked_list_metadata * linked_list_metadata, uint32_t index);

void delete_doubly_linked_list_entry(doubly_linked_list_metadata * linked_list_metadata, doubly_linked_list* entry);
void delete_doubly_linked_list_all_entries(doubly_linked_list_metadata * linked_list_metadata);
void delete_doubly_linked_list(doubly_linked_list_metadata ** linked_list_metadata);

void print_doubly_linked_list_entry(doubly_linked_list* linked_list_entry);
void print_doubly_linked_list(doubly_linked_list_metadata * linked_list_metadata);

#endif //MEMORYLISTS_DOUBLYLINKEDLISTS_H
