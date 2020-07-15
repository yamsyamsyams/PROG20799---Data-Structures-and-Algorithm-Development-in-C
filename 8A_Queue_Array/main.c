/* 
 * File:   main.c
 * Author: hoangjam
 *
 * Created on July 14, 2020, 10:22 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 6

int queue[MAX_SIZE];

unsigned int size = 0;
unsigned int rear = MAX_SIZE - 1;
unsigned int front = 0;

typedef struct node {
    int data;
} node_t;

node_t* createNode(int val){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = val;
    return newNode;
}

bool isEmpty() {
    return front == rear;
}

bool isFull(){
    return size == MAX_SIZE;
}

void createQueue(){
    node_t* queue = (node_t*)malloc(sizeof(node_t));
    return queue;
}

void enqueue(int value){
    node_t *newNode = (node_t*) malloc(sizeof (node_t));
    queue = createQueue();
    if (newNode == NULL) {
        // no more memory, heap is full
        printf("No more memory\n");
    }
    if(isFull()){
        printf("Thing is full");
    }
    rear = (rear + 1) % MAX_SIZE;
    size++;
    queue[rear] = value;
}

dequeue(){
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    //todo dodo ododoo
}
void printQueue() {
    int i = 0;
    for(i=0; i<MAX_SIZE; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    printQueue();
    
    dequeue();
    printQueue();

    return (EXIT_SUCCESS);
}

