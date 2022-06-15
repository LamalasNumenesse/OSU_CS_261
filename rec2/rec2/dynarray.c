/* CS261 - Reciation 2*/
/* Description: create a array of integers and struct student by giving the size of array, 
                and sort them using sort() and function pointers
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

struct Student{
	int id;
	int score;
};

//helper function to compare students by their scores
int compare_student (void* x, void* y){
    struct Student* a = x;
    struct Student* b = y;
	return a->score > b->score ? 1 : 0;
}

//helper function to compare two ints
int compare_int (void* x, void* y){
    int* a = x;
    int* b = y;
	return *a > *b ? 1 : 0;
}

/* sort the arr array by using a function pointer to 
 * compare its elements
 * Param: 
 *		void** arr                 - array of generic type 
 *      int n                      - array size
 *      int(*cmp)(void* a, void* b)- function pointer to compare two elements in the array 
 */
//void sort(void** arr, int n, int(*cmp)(void* a, void* b))
void sort(void** arr, int n, int (*compare)(void* x, void* y)){
    /*Sort n integers in arr, ascending order*/
	/*
	 * FIXED ME:
	 */
     void* temp = 0;
     for (int i = 0; i < n; i++){
        for (int i = 1; i < n; i++){
            if (!(compare(arr[i], arr[i-1]))){
                temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
            }
        }
     }
}


/* free the memeory allocated by arr
 * Param: 
 *      void** arr                 - array of generic type 
 *      int n                      - array size
 */
void free_arr (void** arr, int n){
	/* free the memory allocated by arr*/
	/*
	 * FIXED ME:
	 */
    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
}

void print_student_array(struct Student** s_a, int size){
    for(int i = 0; i < size; i++){
        printf("\nID: %d", s_a[i]->id);
        printf("\nScore: %d\n", s_a[i]->score);
    }
}

int main(){
    srand(time(NULL));

    /*Declare an integer n and assign 10 to it.*/
    int n = 10;
    /***Step 1: sort an integer array ***/
    /*Allocate memory for n integers using malloc.*/
    int** array = malloc(sizeof(int*) * n);
    /*Generate random ints (0-100, inclusive) for the n integers, using rand().*/

    for (int i = 0; i < n; i++){
        array[i] = malloc(sizeof(int));
        *array[i] = rand() % 101;
    }

    /*Print the contents of the array of n integers.*/
    printf("\nBefore sorting....\n");
    for (int i = 0; i < n; i++){
        printf("%d ", *array[i]);
    }
    
    /*call sort() function to sort*/
    sort((void**)array, n, compare_int);
    /*Print the contents of the array of n integers.*/
    printf("\nAfter sorting....\n");
        for (int i = 0; i < n; i++){
        printf("%d ", *array[i]);
    }

    /***Step 2: After modifying sort() by using function pointer, modify your sort() function call above ****/




    /***Step 3: sort an array of students ***/

    /*Allocate memory for n students using malloc.*/
    
    struct Student** student_array = malloc(sizeof(struct Student)*n);

    for(int i = 0; i < n; i++){
        student_array[i] = malloc(sizeof(struct Student));
        student_array[i]->id = rand() % 101;
        student_array[i]->score = rand() % 11;
    }

    /*Generate random IDs and scores for the n students, using rand().*/
    /*note: 
     *    1. no two students should have the same ids 
     *    2. score and id range: 0-100, inclusive
     */
    

    /*Print the contents of the array of n students.*/
    printf("\nBefore sorting....\n");

    print_student_array(student_array, n);
    /*call sort() function to sort*/
    sort((void**)student_array, n, compare_student);
    /*Print the contents of the array of n students.*/
    printf("\nAfter sorting....\n");
    print_student_array(student_array, n);
    

    

    /***Step 4: free the memory allocated in Step 1-3 by calling free_arr() ***/

    free_arr((void**)student_array, n);
    free_arr((void**)array, n);
    
    return 0;
}
