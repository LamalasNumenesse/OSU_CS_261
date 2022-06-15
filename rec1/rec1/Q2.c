/* CS261- Recitation 1 - Q.2
 * Solution description: call the function foo using "reference" to see the values before and after the function
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return 0;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x = 7, y = 8, z = 9;
    
    /*Print the values of x, y and z*/
    printf("This is the value of x : %d\n", x);    
    printf("This is the value of y : %d\n", y);    
    printf("This is the value of z : %d\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int r = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("This is the values returned by foo: %d\n", r);

    /*Print the values of x, y and z again*/
    printf("This is the value of x : %d\n", x);    
    printf("This is the value of y : %d\n", y);    
    printf("This is the value of z : %d\n", z);

    /*Is the return value different than the value of z?  Why? */
    /****
     * The reason why z didn't change is because we are not passing the address. By passing just z
     * we are only using a copy of the value of z, so whatever happens in foo stays in foo for z.
     ***/

    return 0;
}
    
    
