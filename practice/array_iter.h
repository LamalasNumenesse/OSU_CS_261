#ifndef __ARRAY_ITER_H
#define __ARRAY_ITER_H

struct array;

struct array* create_array();
void free_array(struct array* array);
void insert_val(struct array* array, int val);
int remove_val(struct array* array, int index);
int get_val(struct array* array, int index);
void print_array(struct array* array);

#endif