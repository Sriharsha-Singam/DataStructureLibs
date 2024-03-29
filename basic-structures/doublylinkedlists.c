//
// Created by Sriharsha Singam on 7/18/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlists.h"

doubly_linked_list_metadata* doubly_linked_list_init(linked_list_sorter* sorter) {

    doubly_linked_list_metadata* linked_list_metadata = (doubly_linked_list_metadata*) calloc(1, sizeof(doubly_linked_list_metadata));

    linked_list_metadata->overall_size = sizeof(doubly_linked_list_metadata);
    linked_list_metadata->overall_data_size = 0;
    linked_list_metadata->sorter = sorter;
    linked_list_metadata->head = NULL;
    linked_list_metadata->last = NULL;

    // TODO: Must include debug statements.
//#ifdef DEBUG
//    printf("DEBUG: Creating a new doubly linked list. Metadata=0x%x\n", linked_list_metadata);
//#endif

    return linked_list_metadata;
}

doubly_linked_list* insert_config_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value, bool is_front, bool sort) {

    if (!linked_list_metadata) return NULL;

    doubly_linked_list* new_entry = (doubly_linked_list*) calloc(1, sizeof(doubly_linked_list));
    new_entry->value = value;

    if (!linked_list_metadata->head) {
        new_entry->previous = NULL;
        new_entry->next = NULL;
        linked_list_metadata->head = new_entry;
        linked_list_metadata->last = new_entry;
    }  else {
        if (is_front == FALSE) {
            doubly_linked_list* linked_list_copy = linked_list_metadata->last;

            linked_list_copy->next = new_entry;
            new_entry->next = NULL;
            new_entry->previous = linked_list_copy;

            linked_list_metadata->last = new_entry;
        } else {
            new_entry->next = linked_list_metadata->head;
            new_entry->previous = NULL;

            linked_list_metadata->head->previous = new_entry;

            linked_list_metadata->head = new_entry;
        }
    }

    //linked_list_metadata->overall_data_size += sizeof(*value);
    linked_list_metadata->overall_size += sizeof(void*) + sizeof(doubly_linked_list);

    if (sort) sort_doubly_linked_list(linked_list_metadata);

    return new_entry;
}

doubly_linked_list* insert_front_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value) {
    return insert_config_doubly_linked_list_entry(linked_list_metadata, value, TRUE, FALSE);
}

doubly_linked_list* insert_back_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value) {
    return insert_config_doubly_linked_list_entry(linked_list_metadata, value, FALSE, FALSE);
}

doubly_linked_list* insert_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value) {
    return insert_config_doubly_linked_list_entry(linked_list_metadata, value, FALSE, FALSE);
}

doubly_linked_list* insert_sort_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, void* value) {
    return insert_config_doubly_linked_list_entry(linked_list_metadata, value, FALSE, TRUE);
}

void* remove_doubly_linked_list_entry(doubly_linked_list_metadata* linked_list_metadata, doubly_linked_list * remove) {

    void* value = remove->value;

    doubly_linked_list* prev = remove->previous;
    doubly_linked_list* next = remove->next;

    if (prev != NULL) prev->next = next;
    else linked_list_metadata->head = next;

    if (next != NULL) next->previous = prev;
    else linked_list_metadata->last = prev;

    //linked_list_metadata->overall_data_size -= sizeof(*value);
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

uint32_t length_of_doubly_linked_list_entries_list(doubly_linked_list_metadata * linked_list_metadata) {

    doubly_linked_list* linked_list = linked_list_metadata->head;

    uint32_t counter = 0;

    while(linked_list) {
        counter++;
        linked_list = linked_list->next;
    }

    return counter;
}

doubly_linked_list* get_doubly_linked_list_entry(doubly_linked_list_metadata * linked_list_metadata, uint32_t index) {

    if (index >= length_of_doubly_linked_list_entries_list(linked_list_metadata)) return NULL;

    doubly_linked_list* linked_list = linked_list_metadata->head;

    while(index) {
        linked_list = linked_list->next;
        index--;
    }

    return linked_list;
}

void delete_doubly_linked_list_entry(doubly_linked_list_metadata * linked_list_metadata, doubly_linked_list* entry) {
    remove_doubly_linked_list_entry(linked_list_metadata, entry);
}

void delete_doubly_linked_list_all_entries(doubly_linked_list_metadata * linked_list_metadata) {
    doubly_linked_list* linked_list = linked_list_metadata->head;
    while(linked_list) {
        linked_list = linked_list->next;
        delete_doubly_linked_list_entry(linked_list_metadata, linked_list_metadata->head);
    }
}

void delete_doubly_linked_list(doubly_linked_list_metadata ** linked_list_metadata) {
    delete_doubly_linked_list_all_entries(*linked_list_metadata);
    free(*linked_list_metadata);
    *linked_list_metadata = NULL;
}

void print_doubly_linked_list_entry(doubly_linked_list* linked_list_entry) {
    printf("Doubly Linked List Entry [%p] {\n", linked_list_entry);
    printf("\t\tvalue = %p,\n", linked_list_entry->value);
    printf("\t\tnext = %p,\n", linked_list_entry->next);
    printf("\t\tprevious = %p,\n", linked_list_entry->previous);
    printf("}\n");
}

void print_doubly_linked_list(doubly_linked_list_metadata * linked_list_metadata) {

    if (!linked_list_metadata) return;

    printf("Doubly Linked List Metadata [%p] {\n", linked_list_metadata);

    if (linked_list_metadata->head) {
        doubly_linked_list* linked_list = linked_list_metadata->head;

        while (linked_list) {
            print_doubly_linked_list_entry(linked_list);
            linked_list = linked_list->next;
        }
    }

    printf("}\n");
}