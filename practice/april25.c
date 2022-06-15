#include <stdio.h>
#include <stdlib.h>
#include "array_iter.h"

// int multiply_by_2(int* p) {
//     *p = *p * 2;
//     return *p;
// }
// int main() {
//     int n = 10, x = 16, y = 32, z = 64;
//     int* p1 = &x;
//     int* a = malloc(n * sizeof(int));
//     int* p2;
//     for (int i = 0; i < n; i++) {
//         a[i] = i;
//     }
//     p2 = a + (n / 2);
//     *p2 = 0;
//     z = multiply_by_2(&x);
//     y = multiply_by_2(p1);

//     printf("Value of x: %d\n", x);
//     printf("Value of y: %d\n", y);
//     printf("Value of z: %d\n", z);
//     printf("Value of p1: %p\n", p1);
//     printf("Value of *p1: %d\n", *p1);
//     printf("Value of p2: %p\n", p2);
//     printf("Value of *p2: %d\n", *p2);
//     printf("Value of a: %p\n", a);
//     printf("Value of a[0]: %d\n", a[0]);
//     printf("Value of a[5]: %d\n", a[5]);
//     free(a);
// }

int main(){
    struct array* array = create_array();
    for (int i = 0; i < 10; i++){
        insert_val(array, i);
    }
    print_array(array);
    printf("\n");
    for (int i = 0; i < 10; i++){
        (i % 2 == 0) ? remove_val(array, i) : i;
    }
    print_array(array);
    printf("\n");
    for (int i = 0; i < 10; i++){
        (i % 2 == 0) ? insert_val(array, i*5) : i;
    }
    print_array(array);
    printf("\n");
    free_array(array);
    

    return 0;
}