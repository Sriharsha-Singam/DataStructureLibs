//
// Created by Sriharsha Singam on 11/20/21.
//

#include <stdio.h>
#include "../basic-structures/dynamic_array.h"

int main() {
    dynamic_array* arr = dymanic_array_init(0, dynamic_8bits);
    printf("Size: %lu\n", dynamic_array_size(arr));
    dynamic_64bit_setter(arr, 1, 't');
    dynamic_64bit_setter(arr, 100, 'a');
    char thing[50] = "sriharsha singam";
    for (int i = 0; i < 17; i++) {
        arr->set(arr, i, thing[i]);
    }
//    arr->set(arr, 0, 's');
    printf("New Size: %lu\n", dynamic_array_size(arr));
    printf("0: %c\n", (char)dynamic_64bit_getter(arr, 0));
    printf("1: %c\n", (char)dynamic_64bit_getter(arr, 1));
    printf("100: %c\n", (char)dynamic_64bit_getter(arr, 100));
    return 0;
}