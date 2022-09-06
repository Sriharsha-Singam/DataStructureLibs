//
// Created by Sriharsha Singam on 10/22/21.
//

#ifndef MEMORYLISTS_DYNAMIC_ARRAY_H
#define MEMORYLISTS_DYNAMIC_ARRAY_H

typedef struct _dynamic_array dynamic_array;
typedef unsigned long dymanic_array_size;
typedef unsigned long static_data_size;

typedef unsigned char dynamic_8bits_type;
typedef unsigned short dynamic_16bits_type;
typedef unsigned long dynamic_32bits_type;
typedef unsigned long long dynamic_64bits_type;

typedef enum {
    dynamic_8bits = 1,
    dynamic_16bits = 2,
    dynamic_32bits = 4,
    dynamic_64bits = 8
} dynamic_types;

typedef enum {
    INDEX_NOT_FOUND,
    NEGATIVE_INDEX,
    NONE
} possible_errors;

struct _dynamic_array {
    void* start_pointer;
    dynamic_types data_type;
#ifdef DEBUG
    dymanic_array_size overall_size;
    dymanic_array_size overall_data_size;
#endif
    dymanic_array_size number_of_elements;
    dynamic_64bits_type (*at)(dynamic_array*, dymanic_array_size);
    dymanic_array_size (*size)();
    possible_errors last_error;
    int (*set)(dynamic_array*, dymanic_array_size, dynamic_64bits_type);
};

__inline__ dynamic_8bits_type unsafe_dynamic_8bit_getter(dynamic_array* dynamic_arr, dymanic_array_size index);
__inline__ dynamic_16bits_type unsafe_dynamic_16bit_getter(dynamic_array* dynamic_arr, dymanic_array_size index);
__inline__ dynamic_32bits_type unsafe_dynamic_32bit_getter(dynamic_array* dynamic_arr, dymanic_array_size index);
__inline__ dynamic_64bits_type unsafe_dynamic_64bit_getter(dynamic_array* dynamic_arr, dymanic_array_size index);
dynamic_64bits_type dynamic_getter(dynamic_array* dynamic_arr, dymanic_array_size index)
int dynamic_64bit_setter(dynamic_array* dynamic_arr, dymanic_array_size index, dynamic_64bits_type value);
dymanic_array_size dynamic_array_size(dynamic_array* dynamic_arr);

dynamic_array* dymanic_array_init(dymanic_array_size number_of_elements, dynamic_types data_type);
void dymanic_array_free(dynamic_array* dynamic_arr);

#endif //MEMORYLISTS_DYNAMIC_ARRAY_H
