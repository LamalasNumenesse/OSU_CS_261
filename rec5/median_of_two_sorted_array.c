#include <stdio.h>
#include <stdlib.h>

//  First Implementation

void sorth(int* array, int size){
    for(int i = 1; i < size; i++){
        for(int ii = 0; ii < size; ii++){
            if (array[ii] > array[i]){
                int temp = array[ii];
                array[ii] = array[i];
                array[i] = temp;
            }
        }
    }
}

double findMedian(int* int_array, int size){
    return (size % 2 == 0) ? ((double)(int_array[size / 2] + int_array[(size / 2) - 1]) / 2) : (int_array[size / 2]);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int* new_array = malloc(sizeof(int) * (nums1Size + nums2Size));
    int itterator = 0;
    for(int i = 0; i < nums1Size; i++){
        new_array[i] = nums1[i];
        itterator++;
    }
    for(int i = 0; i < nums2Size; i++){
        new_array[itterator] = nums2[i];
        itterator++;
    }
    sorth(new_array, itterator);
    double val = findMedian(new_array, itterator);
    free(new_array);
    return val;
}

int main(int argc, char **argv){
    int a1[] = {1};
    int a2[] = {2};
 
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int n2 = sizeof(a2)/sizeof(a2[0]);

    printf("Median is 1.5 = %f\n", findMedianSortedArrays(a1, n1, a2, n2));

    int a3[] = {1, 12, 15, 26, 38};
    int a4[] = {2, 13, 17, 30, 45, 50};
 
    n1 = sizeof(a3)/sizeof(a3[0]);
    n2 = sizeof(a4)/sizeof(a4[0]);

    printf("Median is 17 = %f\n", findMedianSortedArrays(a3, n1, a4, n2));

    int a5[] = {1, 12, 15, 26, 38};
    int a6[] = {2, 13, 17, 30, 45 };
 
    n1 = sizeof(a5)/sizeof(a5[0]);
    n2 = sizeof(a6)/sizeof(a6[0]);

    printf("Median is 16 = %f\n", findMedianSortedArrays(a5, n1, a6, n2));

    int a7[] = {1, 2, 5, 6, 8 };
    int a8[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a7)/sizeof(a7[0]);
    n2 = sizeof(a8)/sizeof(a8[0]);

    printf("Median is 10.5 = %f\n", findMedianSortedArrays(a7, n1, a8, n2));

    int a9[] = {1, 2, 5, 6, 8, 9, 10 };
    int a10[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a9)/sizeof(a9[0]);
    n2 = sizeof(a10)/sizeof(a10[0]);

    printf("Median is 9.5 = %f\n", findMedianSortedArrays(a9, n1, a10, n2));

    int a11[] = {1, 2, 5, 6, 8, 9 };
    int a12[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a11)/sizeof(a11[0]);
    n2 = sizeof(a12)/sizeof(a12[0]);

    printf("Median is 9 = %f\n", findMedianSortedArrays(a11, n1, a12, n2));

    int a13[] = {1, 2, 5, 6, 8 };
    int a14[] = {11, 13, 17, 30, 45, 50};
    
    n1 = sizeof(a13)/sizeof(a13[0]);
    n2 = sizeof(a14)/sizeof(a14[0]);

    printf("Median is 11 = %f\n", findMedianSortedArrays(a13, n1, a14, n2));


    return 0;
}
