//
// Created by Sriharsha Singam on 12/13/2020.
//

#include "../basic-structures/doublylinkedlists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TEST_SIZE 10
void* list_of_pointer[TEST_SIZE];
//doubly_linked_list * list_of_ddl_pointer[TEST_SIZE];

void create_list() {
    char test[15] = "123456789101112";
    for (int i = 0; i < TEST_SIZE; i++) {
        char* new_p = (char*) calloc(1, sizeof(50));
//        if (new_p == NULL) {
//            printf("Memory not allocated.\n");
//            exit(0);
//        }
        strncpy(new_p, "Hello World\0", 15);
        list_of_pointer[i] = (void*) new_p;
    }
}

void free_list() {
    for (int i = 0; i < TEST_SIZE; i++) {
        free(list_of_pointer[i]);
    }
}

int main() {

    create_list();

//    printf("1\n");
    doubly_linked_list_metadata* linked_list = doubly_linked_list_init(NULL);
//    printf("2\n");
    print_doubly_linked_list(linked_list);
//    printf("3\n");
    for (int i = 0; i < TEST_SIZE; i++) {
        insert_doubly_linked_list_entry(linked_list, list_of_pointer[i]);
    }
    printf("%s\n", (char*)get_doubly_linked_list_entry(linked_list, 2)->value);
//    printf("4\n");
    print_doubly_linked_list(linked_list);
//    printf("5\n");
    remove_doubly_linked_list_entry(linked_list, linked_list->head);
//    printf("6\n");
    print_doubly_linked_list(linked_list);
//    printf("7\n");
    delete_doubly_linked_list(&linked_list);
//    printf("8\n");
    print_doubly_linked_list(linked_list);
//    printf("9\n");

    free_list();
    return 0;
}