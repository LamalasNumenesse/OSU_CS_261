/*
 * This file contains the definition of the interface for the hash table
 * you'll implement.  You can find descriptions of the hash table functions,
 * including their parameters and their return values, in hash_table.c.
 *
 * You should not modify this file.
 */

#ifndef __HASH_TABLE_H
#define __HASH_TABLE_H 

/*
 * Structure used to represent a hash table.
 */
struct ht{
  struct hd** Hash_Array;
  int Size;
  int Capacity;
};

/**
 * @brief Struct used to represent a node in the hash table
 * 
 */
struct hd{
    void* Data;
    int Key;
    struct hd* Next;
};

/*
 * Hash table interface function prototypes.  Refer to hash_table.c for
 * documentation about each of these functions.
 */
struct ht* ht_create();
void print_hash(struct ht* ht); // Prints Hash Array
int ht_isempty(struct ht* ht);
int ht_size(struct ht* ht);
void ht_free(struct ht* ht);
int ht_hash_func(struct ht* ht, void* key, int (*convert)(void*));
void ht_insert(struct ht* ht, void* key, void* value, int (*convert)(void*));
void* ht_lookup(struct ht* ht, void* key, int (*convert)(void*));
void ht_remove(struct ht* ht, void* key, int (*convert)(void*));


#endif
