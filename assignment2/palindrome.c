#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "queue.h"
#include "stack.h"

#define MAX_STR_LEN 256

/*
 * This function prompts the user for input and stores a maximum of `n`
 * characters of the string they enter into `dest`.  Any trailing line ending
 * characters are removed from the input string.  Returns 1 if a string was
 * successfully read from the user or 0 otherwise.
 */
int get_user_str(char* dest, int n) {
  printf("\nEnter a string, and we'll check whether it's a palindrome: ");
  if (fgets(dest, MAX_STR_LEN, stdin) != NULL) {
    /*
     * If a string was successfully read from the user, remove any trailing
     * line ending characters.  Here's some documentation on strcspn() to help
     * understand how this works:
     *
     * https://en.cppreference.com/w/c/string/byte/strcspn
     */
    dest[strcspn(dest, "\r\n")] = '\0';
    return 1;
  } else {
    return 0;
  }
}

int compare_strings(char* s1, char* s2){
  int counter = 0;
  while(s1[counter] != '\0'){
    if (s1[counter] != s2[counter]){
      return 0;
    }
    counter++;
  }
  return 1;
}

void fill_queue(char* str, struct queue* q){
  int counter = 0;
  while(str[counter] != '\0'){
    if (isalpha(str[counter]) != 0){
      str[counter] = tolower(str[counter]);
      queue_enqueue(q, &str[counter]);
    }
    counter++;
  }
}

void fill_stack(char* str, struct stack* s){
  int counter = 0;
  while(str[counter] != '\0'){
    if (isalpha(str[counter]) != 0){
      str[counter] = tolower(str[counter]);
      stack_push(s, &str[counter]);
    }
    counter++;
  }
}

int main(int argc, char const *argv[]) {
  char* in = malloc(MAX_STR_LEN * sizeof(char));

  while (get_user_str(in, MAX_STR_LEN)) {
    /*
     * Inside this loop body, you'll have an input string from the user in `in`.
     * You should use your stack and your queue to test whether that string is
     * a palindrome (i.e. a string that reads the same backward as forward, e.g.
     * "ABCBA" or "Madam, I'm Adam").  For each string input by the user,
     * print a message letting the user know whether or not their string is
     * is a palindrome.
     *
     * When you test whether the user's string is a palindrome, you should
     * ignore any non-letter characters (e.g. spaces, numbers, punctuation,
     * etc.), and you should ignore the case of letters (e.g. the characters
     * 'a' and 'A' should be considered as equal).  The C functions isalpha()
     * and tolower() from ctype.h might help with this.
     */
    struct stack* s = stack_create();
    struct queue* q = queue_create();

    fill_queue(in, q);
    fill_stack(in, s);

    char* queue = malloc(MAX_STR_LEN * sizeof(char));
    char* stack = malloc(MAX_STR_LEN * sizeof(char));
    int counter = 0;

    while(stack_isempty(s) == 0){
      char* temp = stack_pop(s);
      stack[counter] = *temp;
      counter++;
    }

    counter = 0;
    while(queue_isempty(q) == 0){
      char* temp = queue_dequeue(q);
      queue[counter] = *temp;
      counter++;
    }

    if(compare_strings(stack, queue) == 1){
      printf("\nIt is a Palondome!");
      queue_free(q);
      stack_free(s);
      free(stack);
      free(queue);
      break;
    }else{
      printf("\nIt is not a Palondome! Try again.\n");
      queue_free(q);
      stack_free(s);
      free(stack);
      free(queue);
    }

  }

  free(in);
  return 0;
}
