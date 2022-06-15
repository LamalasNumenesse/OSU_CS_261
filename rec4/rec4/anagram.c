/* CS 261 Recitation 4: Anagram Detector
 */

#include <stdio.h>

/*
  The Function checks two given strings (a, b) and return
  1 if they are anagram, and 0 otherwise
  Assuming:
  1. a and b are of the same length
  2. a and b are made up of symbols from the set of 26 lowercase characters
 */

int get_len(char* str){
  int counter = 0;
  while(str[counter] != "\0"){
    counter++;
  }
  return counter;
}

int check_anagram(char *a, char *b)
{
  int length_a = get_len(a);
  int length_b = get_len(b);
  int counter = 0;

  for (int i = 0; i < length_a; i++){
    for (int ii = 0; ii < length_b; ii++){
      if (a[i] == b[ii]){
        counter++;
        ii = length_b;
      }
    }
  }
  counter -= 1;
  printf("counter: %d\n", counter);
  printf("length_a: %d\n", length_a);
  printf("length_b: %d\n", length_b);
  return (counter == length_a || counter == length_b) ? 1 : 0;
}


int main()
{
  
  printf("Test 1.....\n");
  printf("\"heart\", \"earth\"\n");
  printf("Expected: 1 \n");
  printf("Acutal: %d\n\n", check_anagram("heart", "earth"));


  printf("Test 2.....\n");
  printf("\"python\", \"typhon\"\n");
  printf("Expected: 1 \n");
  printf("Acutal: %d\n\n", check_anagram("python", "typhon"));

  printf("Test 3.....\n");
  printf("\"race\", \"care\"\n");
  printf("Expected: 1 \n");
  printf("Acutal: %d\n\n", check_anagram("race", "care"));

  printf("Test 4.....\n");
  printf("\"listen\", \"silent\"\n");
  printf("Expected: 1 \n");
  printf("Acutal: %d\n\n", check_anagram("listen", "silent"));

  printf("Test 5.....\n");
  printf("\"seal\", \"leaf\"\n");
  printf("Expected: 0 \n");
  printf("Acutal: %d\n\n", check_anagram("seal", "leaf"));

  printf("Test 6.....\n");
  printf("\"asdfghjkl\", \"aasdfghjk\"\n");
  printf("Expected: 0 \n");
  printf("Acutal: %d\n\n", check_anagram("asdfghjkl", "aasdfghjk"));

  

  return 0;
}

