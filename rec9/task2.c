#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array{
	int* Data;
	int Array_Size;
	int Capacity;
};

void printArray(struct Array* arr){
	for(int i = 0; i < arr->Array_Size; i++){
		printf("%d ", arr->Data[i]);
	}
	printf("\n");
}

void print_array(int* arr, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

struct Array* start_array(){
	struct Array* temp = malloc(sizeof(struct Array));
	temp->Data = malloc(sizeof(int)*5);
	temp->Array_Size = 0;
	temp->Capacity = 5;
	for(int i = 0; i < 5; i++){
		temp->Data[i] = -1;
	}
	return temp;
}

void re_size(struct Array* arr){
	arr->Capacity = (arr->Capacity * 2);
	int* temp = malloc(sizeof(int) * (arr->Capacity));
	for(int i = 0; i < arr->Capacity; i++){
		if(i >= arr->Array_Size){
			temp[i] = -1;
		}else{
			temp[i] = arr->Data[i];
		}
	}
	free(arr->Data);
	arr->Data = temp;
}

int getSize(int n){
	int counter = 0;
	while(n != 0){
		n = (n/10);
		counter++;
	}
	return counter;
}

int get_sum(int* map, int size){
	int sum = 0;
	for(int i = 0; i < size; i++){
		int temp = map[i];
		sum += (temp * temp);
	}
	return sum;
}

bool isHappy_helper(int n, struct Array* counter, int* result){
	int size = getSize(n);
	int map[size];
	int sum = 0;
	for(int i = size-1; i >= 0; i--){
		map[i] = n%10;
		n = n/10;
	}
	//print_array(map, size);
	sum = get_sum(map, size);
	if(counter->Array_Size != 0){
		for(int i = 0; i < counter->Array_Size; i++){
			if(counter->Data[i] == sum){
				*result = 0;
				return 0;
			}
		}
	}
	if(sum == 1){
		*result = 1;
		return 1;
	}else{
		if(counter->Array_Size == counter->Capacity){
			re_size(counter);
		}else{
			counter->Data[counter->Array_Size] = sum;
			counter->Array_Size += 1;
			//printArray(counter);
		}
		isHappy_helper(sum, counter, result);
	}
}

/*
 * return true (1) if n is happy, false (0) otherwise
 */
bool isHappy(int n){
	struct Array* counter = start_array();
	int result = 0;
	isHappy_helper(n, counter, &result);
	free(counter->Data);
	free(counter);
	return result;
}

/*
 * Below are testing functions... DO NOT MODIFY!!!
 */

void show_result(int e, int r){
	printf("Expected: %d\nActual: %d...", e, r);
	if (r != e) 
        printf("FAIL\n\n\n");
    else 
        printf("OK\n\n\n");
}



int main()
{
	printf("\nTEST 1...19\n");
	show_result(1, isHappy(19));

	printf("\nTEST 2...2\n");
	show_result(0, isHappy(2));

	printf("\nTEST 3...7\n");
	show_result(1, isHappy(7));

	printf("\nTEST 4...176\n");
	show_result(1, isHappy(176));

	printf("\nTEST 5...36\n");
	show_result(0, isHappy(36));

	

	return 0;
}
