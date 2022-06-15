/*
 * In this file, you will write the structures and functions needed to
 * implement a hash table.  Feel free to implement any helper functions
 * you need in this file to implement a hash table.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Eliut S. Brenlla Reyes
 * Email: brenllae@oregonstate.edu
 */

#include <stdlib.h>

#include <stdio.h>

#include "dynarray.h"
#include "list.h"
#include "hash_table.h"

int ITER = 0;

/**
 * @brief This is a struct that acts as the hash data. It will store data
 *        as a void*, it will store it's key, and it will have a pointer
 *        to a next hash data in case of collition.
 */

struct hd;

/*
 * This is the structure that represents a hash table.  You must define
 * this struct to contain the data needed to implement a hash table.
 */
struct ht;

/**
 * @brief Prints the hash table, You can call this o the test_hash_table
 *        so long that ht is not NULL;
 * 
 * @param ht 
 */
void print_hash(struct ht* ht){
    for(int i = 0; i < ht->Capacity; i++){
        struct hd* temp = ht->Hash_Array[i];
        if (temp == NULL){
            printf("\t[%d] Key: NULL", i);
        }
        while(temp != NULL){
            printf("\t[%d] Key: %d", i, temp->Key);
            temp = temp->Next;
        }
        printf("\n");
    }
}

/*
 * This function should allocate and initialize an empty hash table and
 * return a pointer to it.
 */
struct ht* ht_create(){
    struct ht* temp = malloc(sizeof(struct ht));
    temp->Hash_Array = malloc(sizeof(struct hd) * 2);
    for (int i = 0; i < 2; i++){
        temp->Hash_Array[i] = NULL;
    }
    temp->Size = 0;
    temp->Capacity = 2;
    return temp;
}

/*
 * This function should free the memory allocated to a given hash table.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the hash table.  That is the responsibility of the caller.
 *
 * Params:
 *   ht - the hash table to be destroyed.  May not be NULL.
 */
void ht_free(struct ht* ht){
    for(int i = 0; i < ht->Capacity; i++){
        struct hd* temp = ht->Hash_Array[i];
        struct hd* next = NULL;
        while(temp != NULL){
            next = temp->Next;
            free(temp);
            temp = next;
        }
    }
    free(ht->Hash_Array);
    free(ht);
}

/*
 * This function should return 1 if the specified hash table is empty and
 * 0 otherwise.
 *
 * Params:
 *   ht - the hash table whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if ht is empty and 0 otherwise.
 */
int ht_isempty(struct ht* ht){
    return ht->Size > 0 ? 0 : 1;
}


/*
 * This function returns the size of a given hash table (i.e. the number of
 * elements stored in it, not the capacity).
 */
int ht_size(struct ht* ht){
    return ht->Size;
}

/*
 * This function takes a key, maps it to an integer index value in the hash table,
 * and returns it. The hash algorithm is totally up to you. Make sure to consider
 * Determinism, Uniformity, and Speed when design the hash algorithm
 *
 * Params:
 *   ht - the hash table into which to store the element.  May not be NULL.
 *   key - the key of the element to be stored
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode // Decided to delete this since it would be too tedius
 */
int ht_hash_func(struct ht* ht, void* key, int (*convert)(void*)){
    int key_int = convert(key);
    // return ((key_int % 2 != 0) ? ((key_int + 1) * 2^2) : ((key_int + 2 * 2^2)-1)) % ht->Capacity;
    return (key_int) % ht->Capacity;
    // if will check if key is even
    // Even: it will add key_init + 1 and it will multiply by 4;
    // Odd: it will add key_init +2 and multiply by 4 then subtract 1
}

/**
 * @brief Checks if there is a value that is the same key as the one
 *        we are trying to insert.
 * 
 * @param ht 
 * @return true 
 * @return false 
 */

int does_it_exist(struct ht* ht, void* key, int (*convert)(void*)){
    int key_int = convert(key);
    int idx = ht_hash_func(ht, key, convert);
    struct hd* temp = ht->Hash_Array[idx];
    if(temp == NULL){
        return 0;
    }
    while(key_int != temp->Key){
        temp = temp->Next;
        if(temp == NULL){
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Creates a new hash array that is 2 times the size of the current one
 *        it will copy the values of the old array in a new index depending on
 *        the new capacity.
 * 
 * @param ht 
 * @param convert 
 */
void ht_re_size(struct ht* ht, int (*convert)(void*)){
    ht->Capacity = (ht->Capacity * 2);
    struct hd** new_hash_arr = malloc(sizeof(struct hd) * (ht->Capacity));
    for (int i = 0; i < (ht->Capacity); i++){
        new_hash_arr[i] = NULL;
    }
    for (int i = 0; i < (ht->Capacity / 2); i++){
        struct hd* temp0 = ht->Hash_Array[i];
        struct hd* next = NULL;
        while(temp0 != NULL){
            int idx = ht_hash_func(ht, temp0->Data, convert);
            next = temp0->Next;
            temp0->Next = NULL;
            if(new_hash_arr[idx] == NULL){
                new_hash_arr[idx] = temp0;
            }else{
                struct hd* curr = new_hash_arr[idx];
                while(1){
                    if(curr->Next == NULL){
                        curr->Next = temp0;
                        break;
                    }else{
                        curr = curr->Next;
                    }
                }
            }
            temp0 = next;
        }
    }
    free(ht->Hash_Array);
    ht->Hash_Array = new_hash_arr;
}

/*
 * This function should insert a given element into a hash table with a
 * specified key.  Note that you cannot have two same keys in one hash table.
 * If the key already exists, update the value associated with the key.  
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * Resolution of collisions is requried, use either chaining or open addressing.
 * If using chaining, double the number of buckets when the load factor is >= 4
 * If using open addressing, double the array capacity when the load factor is >= 0.75
 * load factor = (number of elements) / (hash table capacity)
 *
 * Params:
 *   ht - the hash table into which to insert an element.  May not be NULL.
 *   key - the key of the element
 *   value - the value to be inserted into ht.
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */

void ht_insert(struct ht* ht, void* key, void* value, int (*convert)(void*)){
    if(ht->Capacity == ht->Size){
        ht_re_size(ht, convert);
    }if (does_it_exist(ht, key, convert) == 0){
        struct hd* temp = malloc(sizeof(struct hd));
        int idx = ht_hash_func(ht, key, convert);
        temp->Data = value;
        temp->Key = convert(key);
        temp->Next = NULL;
        if(ht->Hash_Array[idx] == NULL){
            ht->Hash_Array[idx] = temp;
        }else{
            struct hd* curr = ht->Hash_Array[idx];
            while(1){
                if(curr->Next == NULL){
                    curr->Next = temp;
                    break;
                }else{
                    curr = curr->Next;
                }
            }
        }
        ht->Size += 1;
    }else{
        ht_remove(ht, key, convert);
        ht_insert(ht, key, value, convert);
    }
}


/*
 * This function should search for a given element in a hash table with a
 * specified key provided.   
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * If the key is found, return the corresponding value (void*) of the element,
 * otherwise, return NULL
 *
 * Params:
 *   ht - the hash table into which to loop up for an element.  May not be NULL.
 *   key - the key of the element to search for
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */
void* ht_lookup(struct ht* ht, void* key, int (*convert)(void*)){
    int key_int = convert(key);
    int idx = ht_hash_func(ht, key, convert);
    struct hd* temp = ht->Hash_Array[idx];
    if(temp == NULL){
        return NULL;
    }
    while(key_int != temp->Key){
        temp = temp->Next;
        if(temp == NULL){
            return NULL;
        }
    }
    return temp->Data;
}


/*
 * This function should remove a given element in a hash table with a
 * specified key provided.   
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * If the key is found, remove the element and return, otherwise, do nothing and return 
 *
 * Params:
 *   ht - the hash table into which to remove an element.  May not be NULL.
 *   key - the key of the element to remove
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */
void ht_remove(struct ht* ht, void* key, int (*convert)(void*)){
    int key_int = convert(key);
    int idx = ht_hash_func(ht, key, convert);
    struct hd* curr = ht->Hash_Array[idx];
    struct hd* prev = NULL;
    struct hd* next = NULL;
    if(curr->Next == NULL){
        free(curr);
        ht->Hash_Array[idx] = NULL;
    }else{
        int idx_list = 0;
        while(key_int != curr->Key){
            prev = curr;
            curr = curr->Next;
            idx_list += 1;
        }
        if(idx_list == 0){
            ht->Hash_Array[idx] = curr->Next;
            free(curr);
        }else{
            prev->Next = curr->Next;
            free(curr);
        }
    }
    ht->Size -= 1;
} 
