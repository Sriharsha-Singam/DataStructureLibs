//
// Created by Sriharsha Singam on 7/18/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "singlelinkedlists.h"

single_linked_list_metadata* single_linked_list_init(linked_list_sorter* sorter) {

    single_linked_list_metadata* linked_list_metadata = (single_linked_list_metadata*) calloc(1, sizeof(single_linked_list_metadata));

    linked_list_metadata->overall_size = 0 + sizeof(single_linked_list_metadata);
    linked_list_metadata->overall_data_size = 0;
    linked_list_metadata->sorter = sorter;
    linked_list_metadata->head = NULL;
    linked_list_metadata->last = NULL;

    return linked_list_metadata;
}

// TODO: Specify where to add the new entry.
// TODO: Apply different method for sorting.
single_linked_list* insert_single_linked_list_entry(single_linked_list_metadata* linked_list_metadata, void* value) {

    if (!linked_list_metadata) return NULL;

    single_linked_list* new_entry = (single_linked_list*) malloc(sizeof(single_linked_list));
    new_entry->value = value;

    if (!linked_list_metadata->head) {
        new_entry->next = NULL;
        linked_list_metadata->head = new_entry;
        linked_list_metadata->last = new_entry;
    } else {
        linked_list_metadata->last->next = new_entry;
        linked_list_metadata->last = new_entry;
    }

    linked_list_metadata->overall_data_size += sizeof(*value);
    linked_list_metadata->overall_size += sizeof(void*) + sizeof(single_linked_list);

    sort_single_linked_list(linked_list_metadata);

    return new_entry;
}

void* remove_single_linked_list_entry(single_linked_list_metadata* linked_list_metadata, single_linked_list* entry) {

    void* value = entry->value;
    single_linked_list* prev = linked_list_metadata->head;

    while (prev && (prev->next != entry)) {
        prev = prev->next;
    }

    if (linked_list_metadata->head == entry && linked_list_metadata->last == entry) {
        linked_list_metadata->head = NULL;
        linked_list_metadata->last = NULL;
    } else if (linked_list_metadata->last == entry) {
        linked_list_metadata->last = prev;
        linked_list_metadata->last->next = NULL;
    } else if (linked_list_metadata->head == entry) {
        linked_list_metadata->head = entry->next;
    }

    linked_list_metadata->overall_data_size -= sizeof(*value);
    linked_list_metadata->overall_size -= sizeof(void*) + sizeof(single_linked_list);

    free(entry);
    return value;
}

void swap_single_linked_list(single_linked_list_metadata* linked_list_metadata, single_linked_list* prev, single_linked_list* next) {

    if (!linked_list_metadata) return;

    if (prev == linked_list_metadata->head) {
        linked_list_metadata->head = next;
        prev->next = next->next;
        next->next = prev;
        return;
    }

    single_linked_list* entry = linked_list_metadata->head;

    while (entry->next && (entry->next != prev)) {
        entry = entry->next;
    }

    entry->next = next;
    prev->next = next->next;
    next->next = prev;
}

void sort_single_linked_list(single_linked_list_metadata* linked_list_metadata) {

    if (!linked_list_metadata || !linked_list_metadata->sorter) return;

    single_linked_list* linked_list = linked_list_metadata->head;

    while (linked_list) {

        if ((linked_list->next != NULL)
            && ((*(linked_list_metadata->sorter))(linked_list->value, linked_list->next->value))) {

            swap_single_linked_list(linked_list_metadata, linked_list, linked_list->next);

            linked_list = linked_list_metadata->head;

        } else {
            linked_list = linked_list->next;
        }
    }
}