//
// Created by Sriharsha Singam on 10/22/21.
//

#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

__inline__ dynamic_8bits_type unsafe_dynamic_8bit_getter(dynamic_array* dynamic_arr, dymanic_array_size index) {
    dynamic_8bits_type value = *(((dynamic_8bits_type*)dynamic_arr->start_pointer) + index);
    return value;
}

__inline__ dynamic_16bits_type unsafe_dynamic_16bit_getter(dynamic_array* dynamic_arr, dymanic_array_size index) {
    dynamic_16bits_type value = *(((dynamic_16bits_type*)dynamic_arr->start_pointer) + index);
    return value;
}

__inline__ dynamic_32bits_type unsafe_dynamic_32bit_getter(dynamic_array* dynamic_arr, dymanic_array_size index) {
    dynamic_32bits_type value = *(((dynamic_32bits_type*)dynamic_arr->start_pointer) + index);
    return value;
}

__inline__ dynamic_64bits_type unsafe_dynamic_64bit_getter(dynamic_array* dynamic_arr, dymanic_array_size index) {
    dynamic_64bits_type value = *(((dynamic_64bits_type*)dynamic_arr->start_pointer) + index);
    return value;
}

dynamic_64bits_type dynamic_getter(dynamic_array* dynamic_arr, dymanic_array_size index) {
    if (index >= 0 && index < dynamic_arr->number_of_elements) {
        dynamic_64bits_type value = 0x0;
        if (dynamic_arr->data_type == dynamic_8bits) {
            dynamic_8bits_type value_8bits = unsafe_dynamic_8bit_getter(dynamic_arr, index);
            value |= (dynamic_64bits_type)value_8bits;
        } else if (dynamic_arr->data_type == dynamic_16bits) {
            dynamic_16bits_type value_16bits = unsafe_dynamic_16bit_getter(dynamic_arr, index);
            value |= (dynamic_64bits_type)value_16bits;
        } else if (dynamic_arr->data_type == dynamic_32bits) {
            dynamic_32bits_type value_32bits = unsafe_dynamic_32bit_getter(dynamic_arr, index);
            value |= (dynamic_64bits_type)value_32bits;
        } else {
            dynamic_64bits_type value_64bits = unsafe_dynamic_64bit_getter(dynamic_arr, index);
            value |= (dynamic_64bits_type)value_64bits;
        }
        dynamic_arr->last_error = NONE;
        return value;
    }
    dynamic_arr->last_error = INDEX_NOT_FOUND;
    return -1;
}

int dynamic_64bit_setter(dynamic_array* dynamic_arr, dymanic_array_size index, dynamic_64bits_type value) {
    if (index < 0) {
        dynamic_arr->last_error = NEGATIVE_INDEX;
        return -1;
    }

    dynamic_arr->last_error = NONE;

    if (index >= dynamic_arr->number_of_elements) {
        dymanic_array_size new_number_of_elements = index + 1;
        void* new_buffer = (void*) calloc(new_number_of_elements, (unsigned)dynamic_arr->data_type);
        memcpy(new_buffer, dynamic_arr->start_pointer, ((dymanic_array_size)dynamic_arr->data_type * dynamic_arr->number_of_elements));
        free(dynamic_arr->start_pointer);
        dynamic_arr->start_pointer = new_buffer;
        dynamic_arr->number_of_elements = new_number_of_elements;
    }

    if (dynamic_arr->data_type == dynamic_8bits) {
        *(((dynamic_8bits_type*)dynamic_arr->start_pointer) + index) = (dynamic_8bits_type)value;
    } else if (dynamic_arr->data_type == dynamic_16bits) {
        *(((dynamic_16bits_type*)dynamic_arr->start_pointer) + index) = (dynamic_16bits_type)value;
    } else if (dynamic_arr->data_type == dynamic_32bits) {
        *(((dynamic_32bits_type*)dynamic_arr->start_pointer) + index) = (dynamic_32bits_type)value;
    } else {
        *(((dynamic_64bits_type*)dynamic_arr->start_pointer) + index) = (dynamic_64bits_type)value;
    }

    return 0;
}

dymanic_array_size dynamic_array_size(dynamic_array* dynamic_arr) {
    return dynamic_arr->number_of_elements;
}

void dymanic_array_free(dynamic_array* dynamic_arr) {
    free(dynamic_arr->start_pointer);
    free(dynamic_arr);
}

dynamic_array* dymanic_array_init(dymanic_array_size number_of_elements, dynamic_types data_type) {
    dynamic_array* allocating_dyn_arr = (dynamic_array*) calloc(1, sizeof(dynamic_array));
    void* starting_pointer = (void*) calloc(number_of_elements, (unsigned)data_type);
//    if (data_type == dynamic_8bits) {
//        starting_pointer = (void*) calloc(1, number_of_elements * 1);
//    } else if (data_type == dynamic_16bits) {
//        starting_pointer = (void*) calloc(1, number_of_elements * 2);
//    } else if (data_type == dynamic_32bits) {
//        starting_pointer = (void*) calloc(1, number_of_elements * 4);
//    } else {
//        starting_pointer = (void*) calloc(1, number_of_elements * 8);
//    }
    allocating_dyn_arr->start_pointer = starting_pointer;
    allocating_dyn_arr->at = &dynamic_getter;
    allocating_dyn_arr->set = &dynamic_64bit_setter;
    allocating_dyn_arr->size = &dynamic_array_size;
    allocating_dyn_arr->data_type = data_type;
    allocating_dyn_arr->number_of_elements = number_of_elements;
    allocating_dyn_arr->last_error = NONE;
#ifdef DEBUG
    allocating_dyn_arr->overall_data_size = number_of_elements * ((dymanic_array_size)data_type);
    allocating_dyn_arr->overall_size = sizeof(dynamic_array) + allocating_dyn_arr->overall_data_size;
#endif
    return allocating_dyn_arr;
}