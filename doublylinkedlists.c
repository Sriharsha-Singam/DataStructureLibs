//
// Created by Sriharsha Singam on 7/18/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlists.h"

doubly_linked_list_metadata* doubly_linked_list_init(linked_list_sorter* sorter) {

    doubly_linked_list_metadata* linked_list_metadata = (doubly_linked_list_metadata*) malloc(sizeof(doubly_linked_list_metadata));

    linked_list_metadata->overall_size = sizeof(doubly_linked_list_metadata);
    linked_list_metadata->overall_data_size = 0;
    linked_list_metadata->sorter = sorter;
    linked_list_metadata->head = NULL;
    linked_list_metadata->last = NULL;

    return linked_list_metadata;
}

doubly_linked_list* insert_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value) {

    if (!linked_list_metadata) return NULL;

    doubly_linked_list* new_entry = (doubly_linked_list*) malloc(sizeof(doubly_linked_list));
    new_entry->value = value;

    if (!linked_list_metadata->head) {
        linked_list_metadata->head = new_entry;
        new_entry->previous = NULL;
        new_entry->next = NULL;
        linked_list_metadata->head = new_entry;
    }  else {
        doubly_linked_list* linked_list_copy = linked_list_metadata->last;

        linked_list_copy->next = new_entry;
        new_entry->next = NULL;
        new_entry->previous = linked_list_copy;

        linked_list_metadata->last = new_entry;
    }

    linked_list_metadata->overall_data_size += sizeof(*value);
    linked_list_metadata->overall_size += sizeof(void*) + sizeof(doubly_linked_list);

    sort_doubly_linked_list(linked_list_metadata);

    return new_entry;
}

void* remove_single_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, doubly_linked_list * remove) {

    void* value = remove->value;

    doubly_linked_list* prev = remove->previous;
    doubly_linked_list* next = remove->next;

    if (prev != NULL) prev->next = next;
    else linked_list_metadata->head = next;

    if (next != NULL) next->previous = prev;
    else linked_list_metadata->last = prev;

    linked_list_metadata->overall_data_size -= sizeof(*value);
    linked_list_metadata->overall_size -= sizeof(void*) + sizeof(doubly_linked_list);

    free(remove);
    return value;
}

void swap_doubly_linked_list(doubly_linked_list_metadata* linked_list_metadata, doubly_linked_list* prev, doubly_linked_list* next) {

    if (!linked_list_metadata) return;

    doubly_linked_list* prev_prev = prev->previous;
    doubly_linked_list* next_next = next->next;

    if (prev_prev != NULL) {
        prev_prev->next = next;
    } else {
        linked_list_metadata->head = next;
    }

    if (next_next != NULL) {
        next_next->previous = prev;
    } else {
        linked_list_metadata->last = prev;
    }

    prev->next = next_next;
    prev->previous = next;

    next->next = prev;
    next->previous = prev_prev;
}

void sort_doubly_linked_list(doubly_linked_list_metadata * linked_list_metadata) {

    if (!linked_list_metadata || !linked_list_metadata->sorter) return;

    doubly_linked_list* linked_list = linked_list_metadata->head;

    while (linked_list) {

        if ((linked_list->next != NULL)
            && ((*(linked_list_metadata->sorter))(linked_list->value, linked_list->next->value))) {

            swap_doubly_linked_list(linked_list_metadata, linked_list, linked_list->next);

            linked_list = linked_list_metadata->head;

        } else {
            linked_list = linked_list->next;
        }
    }
}