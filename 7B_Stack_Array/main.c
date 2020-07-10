/* 
 * File:   main.c
 * Author: hoangjam
 *
 * Created on July 10, 2020, 10:08 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    int size;
    int top;
    int *data;
};

struct stack myStack;

void createStack() {
    // todo: read the size from the user
    myStack.size = 5;
    myStack.top = -1;
    myStack.data = (int *) malloc(myStack.size * sizeof (int));
}

bool isEmpty(){
    return myStack.top == -1;
}

int pop(){
    // 1. make sure the stack is not empty
    if(isEmpty()){
        printf("Stack is empty");
//        return;
        return -1;
    }
    // 2. getting the element to return
    int element = myStack.data[myStack.top];
    
    // 3. update the top
    myStack.top--;
    
    // 4. return the element
    return element;
        
}

bool isFull() {
    return myStack.top == myStack.size - 1;
}

void push(int newValue) {
    // 1. make sure the stack is not full
    if (isFull()) {
        printf("Sorry, stack is full\n");
        return;
    }
    // 2. increment top pointer
    myStack.top++;

    // 3. push the new element to the stack
    myStack.data[myStack.top] = newValue;
}

void printStack() {
    printf("top=%d\n", myStack.top);
    int i = 0;
    for (i = myStack.top; i >= 0; i--) {
        printf("%d ", myStack.data[i]);
    }
    printf("\n");
}

int main() {
    createStack();
    push(1);
    push(2);
    push(3);
    push(4);
    printStack();
    printf("pop %d from the stack\n", pop());
    printStack();

    printStack();

    return (0);
}

