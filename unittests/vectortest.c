//
// Created by Sriharsha Singam on 1/6/21.
//

#include "../vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TEST_SIZE 10
void* list_of_pointer[TEST_SIZE];

void create_list() {
    char test[15] = "123456789101112";
    for (int i = 0; i < TEST_SIZE; i++) {
        char* new_p = (char*) calloc(1, 50);
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
    vector* vector = vector_init_create_type(50);
//    printf("2\n");
    vector_print(vector);
//    printf("3\n");
    for (int i = 0; i < TEST_SIZE; i++) {
        vector_push_back(vector, list_of_pointer[i]);
    }
    printf("%s\n", (char*)vector_at(vector, 2));
//    printf("4\n");
    vector_print(vector);
//    printf("5\n");
    vector_pop_back(vector);
//    printf("6\n");
    vector_print(vector);
//    printf("7\n");
    vector_pop_front(vector);
    vector_print(vector);
    vector_delete(&vector);
//    printf("8: %p\n", vector);
    vector_print(vector);
//    printf("9\n");

    free_list();
    return 0;
}