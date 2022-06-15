#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "array_iter.h"

struct array{
    int* vals;
    int size;
    int capacity; 
    int iterator;
};

void re_size(struct array* array){
    assert(array);
    int* new_vals = malloc(sizeof(int) * (array->capacity * 2));
    for (int i = 0; i < array->capacity; i++){
        new_vals[i] = array->vals[i];
    }
    free(array->vals);
    array->vals = new_vals;
    array->capacity = array->capacity * 2;
}

struct array* create_array() {
    struct array* new_array = malloc(sizeof(struct array));
    new_array->vals = malloc(sizeof(int) * 2); 
    new_array->size = 0; 
    new_array->capacity = 2; 
    new_array->iterator = 0; 
    return new_array;
}

void free_array(struct array* array){
    assert(array);
    free(array->vals);
    free(array);
}

void insert_val(struct array* array, int val){
    assert(array);
    if (array->capacity == array->size){
        re_size(array);
    }
    array->vals[array->size] = val;
    array->size = array->size + 1;
}

int remove_val(struct array* array, int index){
    assert(array);
    if(index <= array->size){
        array->vals[array->size] = 0;
        array->size = array->size - 1;
        return 1;
    }else{
        return 0;
    }
}

int get_val(struct array* array, int index){
    assert(array);
    return (index <= array->size) ? array->vals[index] : -1;
}

void print_array(struct array* array){
    assert(array);
    for (int i = 0; i < array->size; i++){
        printf("Index %d: %d\n", i, array->vals[i]);       
    }
}