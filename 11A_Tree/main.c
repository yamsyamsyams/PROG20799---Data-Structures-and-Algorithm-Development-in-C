/* 
 * File:   main.c
 * Author: hoangjam
 *
 * this is a tree, not a binary tree
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int number;
} node_data_t;

typedef struct node {
    node_data_t data;
    struct node *left;
    struct node *right;
} tree_node_t;

tree_node_t *newNode(int newData) {
    tree_node_t *node = (tree_node_t*) malloc(sizeof (tree_node_t));
    node->data.number = newData;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void visit(tree_node_t *node) {
    printf("%d ", node->data.number);
}

void preorder(tree_node_t *node) {
    if (node != NULL) {
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
}

void inOrder(tree_node_t *node){
    if(node !=NULL){
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
}

void postOrder(tree_node_t *node){
    if(node !=NULL){
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
}

int nodesCount(tree_node_t *node){
    if(node == NULL){
        return 0;
    }
    return 1 + nodesCount(node->left) + nodesCount(node->right);
}

int main() {
    tree_node_t *root = newNode(8);
    root->left = newNode(3);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    
    printf("Inorder: ");
    inOrder(root);
    printf("\n");
    
    printf("Postorder: ");
    postOrder(root);
    printf("\n");
    
    printf("Tree has %d nodes", nodesCount(root));

    return 0;
}