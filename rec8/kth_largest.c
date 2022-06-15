#include <stdio.h>
#include <stdlib.h>

// void print_array(int* nums, int size){
//     for(int i = 0; i < size; i++){
//         printf("%d ", nums[i]);
//     }
//     printf("\n");
// }

void swap_places(int* num_array, int index1, int index2){
    int temp = num_array[index1];
    num_array[index1] = num_array[index2];
    num_array[index2] = temp;
}

int sorth_heap_array(int* nums, int inx0, int inx1, int inx2){
    if (nums[inx0] > nums[inx1] || nums[inx0] > nums[inx2]){
        if (nums[inx0] > nums[inx1]){
            swap_places(nums, inx0, inx1);
        }
        if (nums[inx0] > nums[inx2]){
            swap_places(nums, inx0, inx2);
        }
        if (nums[inx1] > nums[inx2]){
            swap_places(nums, inx1, inx2);
        }
        return 1;
    }else{
        return 0;
    }
}

int findKthLargest(int* nums, int numsSize, int k)
{
    int counter = 0;
    for (int i = 0; i < numsSize; i++){
        if (i+2 < numsSize){
            counter += sorth_heap_array(nums, i, i+1, i+2);
        }else{
            break;
        }
    }if (counter >= 1){
        findKthLargest(nums, numsSize, k);
    }
    return nums[numsSize-k];
}


int main(int argc, char **argv)
{
    
    printf("\nTest 1...\n");
    int num1[6] = {3,2,1,5,6,4};
    printf("2nd largest in [3 2 1 5 6 4]\n");
    printf("Expected: 5\n");
    printf("Actual: %d\n", findKthLargest(num1, 6, 2));

    printf("\nTest 2...\n");
    int num2[9] = {3,2,3,1,2,4,5,5,6};
    printf("4th largest in [3 2 3 1 2 4 5 5 6]\n");
    printf("Expected: 4\n");
    printf("Actual: %d\n", findKthLargest(num2, 9, 4));

    printf("\nTest 3...\n");
    int num3[5] = {10,10,10,10,10};
    printf("5th largest in [10 10 10 10 10]\n");
    printf("Expected: 10\n");
    printf("Actual: %d\n", findKthLargest(num3, 5, 5));

    printf("\nTest 4...\n");
    int num4[7] = {-10,10,-10,10,-10,10,0};
    printf("4th largest in [-10 10 -10 10 -10 10 0]\n");
    printf("Expected: 0\n");
    printf("Actual: %d\n", findKthLargest(num4, 7, 4));

    printf("\nTest 5...\n");
    int num5[10] = {10,9,8,7,6,5,4,3,2,1};
    printf("1st largest in [10 9 8 7 6 5 4 3 2 1]\n");
    printf("Expected: 10\n");
    printf("Actual: %d\n", findKthLargest(num5, 10, 1));
    
    return 0;
}