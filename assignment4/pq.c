/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name:
 * Email:
 */

#include <stdlib.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"

struct node{
	void* val;
	int priority;
};

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */
struct pq{
  struct dynarray* array;
};

void dynarray_print(struct pq* pq){
  int size = dynarray_size(pq->array);
  for(int i = 0; i < size; i++){
    struct node* node = dynarray_get(pq->array, i);
    printf("%d ", node->priority);
  }
  printf("\n");
}

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
	struct pq* temp = malloc(sizeof(struct pq));
  temp->array = dynarray_create();
	return temp;
}

/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
	dynarray_free(pq->array);
  free(pq);
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
	return (dynarray_size(pq->array) == 0) ? 1 : 0;
}

/**
 * @brief This Function swaps places of two nodes in the dynamic array
 * 
 * @param arr dynamic array
 * @param index1 
 * @param index2 
 */
void swap_places(struct dynarray* arr, int index1, int index2){
  struct node* temp = dynarray_get(arr, index1);
  struct node* temp0 = dynarray_get(arr, index2);
  dynarray_replace(arr, index1, temp0);
  dynarray_replace(arr, index2, temp);
}

/**
 * @brief This function checks if the array is in order by checking 3 indexes next
 *        to each other. It will then check if they are order, else it will order then
 *        on a case.
 * @param arr dynamic array
 * @param inx0 
 * @param inx1 
 * @param inx2 
 * @return int it returns 1 if there was a swap of places.
 */
int sorth_heap_array(struct dynarray* arr, int inx0, int inx1, int inx2){
  struct node* node0 = dynarray_get(arr, inx0);
  struct node* node1 = dynarray_get(arr, inx1); 
  struct node* node2 = dynarray_get(arr, inx2); 
  if (node0->priority > node1-> priority || node0->priority > node2->priority){
    if (node0->priority > node1-> priority){
      swap_places(arr, inx0, inx1);
    }
    if (node0->priority > node2-> priority){
      swap_places(arr, inx0, inx2);
    }
    if (node1->priority > node2-> priority){
      swap_places(arr, inx1, inx2);
    }
    return 1;
  }else{
    return 0;
  }
}

/**
 * @brief This function sorths the dynamic array in a recursive way
 * 
 * @param arr dynamic array
 */
void sorth(struct dynarray* arr)
{
  int counter = 0;
  int numsSize = dynarray_size(arr);
  for (int i = 0; i < numsSize; i++){
    if (i+2 < numsSize){
      counter += sorth_heap_array(arr, i, i+1, i+2);
    }else{
      break;
    }
  }if (counter >= 1){
    sorth(arr);
  }
}

/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
  struct node* new_node = malloc(sizeof(struct node));
  new_node->val = value;
  new_node->priority = priority;
  dynarray_insert(pq->array, new_node);
  if (dynarray_size(pq->array) > 2){
    sorth(pq->array);
  }
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
  struct node* temp = dynarray_get(pq->array, 0);
  return temp->val;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
  struct node* temp = dynarray_get(pq->array, 0);
  return temp->priority;
}

/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
  void* temp = pq_first(pq);
	dynarray_remove(pq->array, 0);
}
