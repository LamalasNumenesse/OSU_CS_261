/* CS261- Recitation 1 - Q. 1*
 * Solution description: check the properties, like value and address, of pointer
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("This is the value adopted by iptr: %d\n", *iptr);

     /*Print the address pointed to by iptr*/
     printf("This is the address pointed by iptr: %p\n", iptr);

     /*Print the address of iptr itself*/
     printf("This is the address of iptr: %p\n", &iptr);

}

int main(){
    
    /*declare an integer x and initialize it with 0*/
    int x = 0;

    /*print the address of x*/
    printf("This is the address of x: %p\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("This is the value of x: %d\n", x);
    return 0;
}
