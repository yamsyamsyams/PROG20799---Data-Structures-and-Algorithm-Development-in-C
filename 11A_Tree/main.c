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

void inOrder(tree_node_t *node) {
    if (node != NULL) {
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
}

void postOrder(tree_node_t *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
}

int nodesCount(tree_node_t *node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + nodesCount(node->left) + nodesCount(node->right);
}

tree_node_t *insert(tree_node_t *node, int number) {
    //todo: deal with doublicates

    if (node == NULL) {
        return newNode(number);
    }

    if (number < node->data.number)
        node->left = insert(node->left, number);
    else
        node->right = insert(node->right, number);
    return node;
}

// either returns null if number doesn't exist in tree, otherwise return pointer to node
tree_node_t* search(tree_node_t *root, int number) {

    if (root == NULL || number == root->data.number)
        return root;

    if (number > root->data.number) {
        search(root->right, number);
    } else {
        search(root->left, number);
    }
}

int main() {
    tree_node_t *root = newNode(8);
    insert(root, 2);
    insert(root, 5);
    insert(root, 6);
    insert(root, 8);
    insert(root, 10);

    tree_node_t* searchNode = search(root, 10);
    if(searchNode != NULL){
        printf("number found\n");
    }
    else{
        printf("number not found\n");
    }

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



    /*
        root->left = newNode(3);
        root->left->left = newNode(1);
        root->left->right = newNode(6);
        root->left->right->left = newNode(4);
        root->left->right->right = newNode(7);

        root->right = newNode(10);
        root->right->right = newNode(14);
        root->right->right->left = newNode(13);
     */



    return 0;
}