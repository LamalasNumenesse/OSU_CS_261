/*
 * This program should sort a linked by increasing value using bubble sort,
 * but it's currently broken.  Use GDB and Valgrind to help debug it.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * This link structure is used below to implement a simple singly-linked list.
 */
struct link {
  int val;
  struct link* next;
};

/*
 * This function swaps the values of two integers, using their memory addresses
 * (i.e. using pointers to those integers).
 */
void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
} 

/*
 * This function implements bubble sort:
 *
 *   https://en.wikipedia.org/wiki/Bubble_sort
 *
 * Here, we specifically sort a linked list of integers by increasing value
 * (i.e. the smallest value should be at the front of the array after it's
 * sorted).
 */
void bubble_sort(struct link* head) {
  int swapped = 0;
  struct link* curr = head;
  do {
    swapped = 0;
    while (curr != NULL) {
      if ((curr->next != NULL) && (curr->val > curr->next->val)) {
        swap(&curr->val, &curr->next->val);
        swapped = 1;
      }
      curr = curr->next;
    }
    if (swapped != 0 && curr == NULL){
      curr = head;
    }
  } while (swapped);
}

int main(int argc, char const *argv[]) {
  /*
   * Generate a linkd list containing 16 random values between 0 and 100.
   */
  struct link* head = NULL;
  for (int i = 0; i < 16; i++) {
    struct link* newlink = malloc(sizeof(struct link));
    newlink->val = rand() % 100;
    newlink->next = head;
    head = newlink;
  }

  /*
   * Print the entire list.
   */
  printf("The unsorted list values are:\n");
  for (struct link* curr = head; curr != NULL; curr = curr->next) {
    printf("  %d", curr->val);
  }
  printf("\n\n");

  /*
   * Sort the list, then print it again.
   */
  printf("The sorted list values are:\n");
  bubble_sort(head);
  for (struct link* curr = head; curr != NULL; curr = curr->next) {
    printf("  %d", curr->val);
  }
  printf("\n");

  struct link* next = NULL;
  struct link* curr = head;
  while (curr != NULL){
    next = curr->next;
    free(curr);
    curr = next;
  }

  return 0;
}
