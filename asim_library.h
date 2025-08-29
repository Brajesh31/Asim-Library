#ifndef ASIM_LIBRARY_H
#define ASIM_LIBRARY_H

#include <iostream>
#include <algorithm>
using namespace std;

// Stack Class
class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size);
    ~Stack();
    void push(int element);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void rotateRight();
    void rotateLeft();
    void display();
    bool search(int element);
};

// Binary Search Tree (BST) Node and Class
class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value);
};

class BST {
private:
    BSTNode* root;
    BSTNode* insert(BSTNode* node, int value);
    void inOrder(BSTNode* node);
    BSTNode* search(BSTNode* node, int value);
    BSTNode* deleteNode(BSTNode* node, int value);
    BSTNode* findMin(BSTNode* node);

public:
    BST();
    void insert(int value);
    void inOrderTraversal();
    bool search(int value);
    void deleteNode(int value);
};

// AVL Tree Node and Class
class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value);
};

class AVLTree {
private:
    AVLNode* root;
    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insert(AVLNode* node, int value);
    AVLNode* deleteNode(AVLNode* node, int value);
    AVLNode* findMin(AVLNode* node);
    void inOrder(AVLNode* node);

public:
    AVLTree();
    void insert(int value);
    void deleteNode(int value);
    void inOrderTraversal();
    bool search(int value);
};

#endif
