#include <stdlib.h>
#include "ll.h"

// struct node {
// 	int val;
// 	struct node* next;
// };

int node_to_int(struct node* l){
    int i = 0;
    int ii = 1;
    struct node* temp = l;
    while(temp != NULL){
        int iii = temp->val;
        i += iii * ii;
        ii *= 10;
        temp = temp->next;
    }
    return i;
}

int int_len(int n){
    int i = 0;
    while(n != 0){
        n /= 10;
        i++;
    }
    return i;
}

void populate_char(char* c, int n, int size){
    for(int i = size-1; i >= 0; i--){
        c[i] = (n % 10) + '0';
        n = n / 10;
    }
    c[size] = '\0';
}

int verify_input(int n){
    return (n >= 0 && n <= 9) ? n : 0;
}

struct node* add_two_num (struct node* l1, struct node* l2){
    int I = node_to_int(l1);
    int II = node_to_int(l2);
    int i = I + II;
    int ii = int_len(i);
    char iii[ii+1]; 
    populate_char(iii, i, ii);

    struct node* prev = NULL;
    int iv = 0;
    while(1){
        if (iv == 0){
            struct node* new = malloc(sizeof(struct node*));
            new->next = NULL;
            new->val = verify_input((int)iii[iv]-48);
            iv += 1;
            prev = new;
        }else if (iv < ii){
            struct node* new = malloc(sizeof(struct node*));
            new->val = verify_input((int)iii[iv]-48);
            new->next = prev;
            iv += 1;
            prev = new;
        }else{
            break;
        }
    }
    // struct node* new = invert_node(OG);
    return prev;
}