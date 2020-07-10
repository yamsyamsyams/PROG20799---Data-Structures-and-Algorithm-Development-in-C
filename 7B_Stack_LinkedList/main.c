/* 
 * File:   main.c
 * Author: hoangjam
 *
 * Created on July 10, 2020, 11:26 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct node *next;
} node_t;

node_t *top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(int newValue) {
    node_t * n;
    n = (node_t*) malloc(sizeof (node_t));

    if (!n) {
        printf("\nHeap Overflow");
        exit(1);
    }

    n->data = newValue;
    n->next = top;
    top = n;
}

int pop() {
    node_t * n;
    
    n = top;
    top = top->next;
    n->next = NULL;
}

int main() {


    return (0);
}
