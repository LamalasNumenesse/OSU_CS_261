/*
 * In this file, you'll implement Dijkstra's algorithm to find the least
 * expensive paths in the graph defined in `airports.dat`.  Don't forget to
 * include your name and @oregonstate.edu email address below.
 *
 * Name: Eliut S. Brenlla Reyes
 * Email: brenllae@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "airports.dat"
#define START_NODE 0
/**
 * @brief This functions prints out a 2d array of the nodes. X and Y axises are the node #
 * 				While the cells represents the edge value between the X and Y node. If the edge
 * 				value is a 0 then there is no edge.
 * 
 * @param arr 2D int array
 * @param size amount of nodes there are
 */
void print_node_arr(int** arr, int size){
	for(int i = 0; i < size; i++){
		for(int ii = 0; ii < size; ii++){
			int val = arr[ii][i];
			printf("%d\t", val);
		}
		printf("\n");
	}
	printf("\n");
}
/**
 * @brief compares weather a is smaller than b
 * 
 * @param a an integer
 * @param b an integer
 * @return int 1 if a is smaller than b else returns 0
 */
int is_smaller(int a, int b){
	return (a < b) ? 1 : 0;
}

/**
 * @brief It skims through an array of numbers to check if we have visited a node in the past
 * 
 * @param arr an array of nodes we have visit before
 * @param size size of the array
 * @param here where we currently at
 * @return int 1 if we are not going to a node we already visited, 0 is we are going to a new node.
 */
int was_I_here(int* arr, int size, int here){
	for(int i = 0; i < size; i++){
		if(arr[i] == here){
			return 0;
		}
	}
	return 1;
}

/**
 * @brief it prints out a path to a node. We grab the smallest path avaliable and transverse the 2D
 * 				array intil we land at the desired node.
 * 
 * @param arr 2D array of nodes
 * @param size Size of the 2D array
 * @param node The node we want to land at
 */
void get_path_to(int** arr, int size, int node){
	int sum = NULL;
	int counter = 0;
	int path = 0;
	int prev_index[size];
	for(int i = 0; i < size; i++){
		prev_index[i] = 0;
	}
	int iter = 0;
	printf("Finding path to %d: ", node);
	while(path != node){
		for(int i = 0; i < size; i++){
			if(was_I_here(prev_index, size, i)){
				if(arr[path][i] != 0){
				// printf("\t\t\tHERE IS I: %d", arr[path][i]);
				// printf("\t\t\tHERE IS SUM: %d\n", sum);
					if(sum == NULL || is_smaller(arr[path][i], sum) == 1){
						sum = arr[path][i];
						prev_index[iter] = path;
						iter++;
						path = i;
						printf("%d ", path);
						counter += sum;
						if(path == node){
							break;
						}
					}
				}
			}
		}
		sum = NULL;
	}
	printf("Here is the SUM: %d\n", counter);
}

int main(int argc, char const *argv[]) {
	/*
	 * Open file and read the first two int: num of nodes, num of edges
	 */
	int n_nodes, n_edges;
	FILE* file = fopen(DATA_FILE, "r");
	fscanf(file, " %d %d ", &n_nodes, &n_edges);
	
	/*
	 * Write your code here to find the
	 * least-cost paths from node 0 to all other nodes in the graph.  Make sure
	 * to print out the least-cost paths you find at the end.
	 *
	 * FIXME: 
 	 */

	// Initialize the 2D array of nodes
	int** arr_nodes = (int**)malloc(sizeof(int*) * n_nodes);
	for (int i = 0; i < n_nodes; i++){
		arr_nodes[i] = (int*)malloc(sizeof(int) * n_nodes);
	}

	for(int i = 0; i < n_nodes; i++){
		for(int ii = 0; ii < n_nodes; ii++){
			arr_nodes[i][ii] = 0; // Initializing the cells
		}
	}

	int from = 0;
	int to = 0;
	int val = 0;
	for (int i = 0; i < n_edges; i++){
		fscanf(file, " %d %d %d ", &from, &to, &val);
		arr_nodes[from][to] = val; // Populating the cells with the corresponding edge vals
	}

	print_node_arr(arr_nodes, n_nodes); // Printing and testing
	get_path_to(arr_nodes, n_nodes, 0);
	get_path_to(arr_nodes, n_nodes, 1);
	get_path_to(arr_nodes, n_nodes, 2);
	get_path_to(arr_nodes, n_nodes, 3);
	get_path_to(arr_nodes, n_nodes, 4);
	get_path_to(arr_nodes, n_nodes, 5);
	get_path_to(arr_nodes, n_nodes, 6);
	// get_path_to(arr_nodes, n_nodes, 7); Doesn't work
	// get_path_to(arr_nodes, n_nodes, 8); Doesn't work
	// get_path_to(arr_nodes, n_nodes, 9); Doesn't work

	// Freeing the 2D array
	for(int i = 0; i < n_nodes; i++){
		free(arr_nodes[i]);
	}
	free(arr_nodes);
	fclose(file);

	 
  return 0;
}
