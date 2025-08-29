#include "asim_library.h"

// -------------------------------------
// Stack Implementation
// -------------------------------------

Stack::Stack(int size) {
    capacity = size;
    arr = new int[size];
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int element) {
    if (isFull()) {
        cout << "Stack overflow!\n";
        return;
    }
    arr[++top] = element;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow!\n";
        return -1;
    }
    return arr[top--];
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}

void Stack::rotateRight() {
    if (isEmpty()) return;
    int last = arr[top];
    for (int i = top; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

void Stack::rotateLeft() {
    if (isEmpty()) return;
    int first = arr[0];
    for (int i = 0; i < top; i++) {
        arr[i] = arr[i + 1];
    }
    arr[top] = first;
}

void Stack::display() {
    for (int i = 0; i <= top; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool Stack::search(int element) {
    for (int i = 0; i <= top; i++) {
        if (arr[i] == element) return true;
    }
    return false;
}

// -------------------------------------
// Binary Search Tree (BST) Implementation
// -------------------------------------

BSTNode::BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

BSTNode* BST::insert(BSTNode* node, int value) {
    if (node == nullptr) return new BSTNode(value);
    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);
    return node;
}

void BST::insert(int value) {
    root = insert(root, value);
}

void BST::inOrder(BSTNode* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void BST::inOrderTraversal() {
    inOrder(root);
    cout << endl;
}

BSTNode* BST::search(BSTNode* node, int value) {
    if (node == nullptr || node->data == value) return node;
    if (value < node->data) return search(node->left, value);
    return search(node->right, value);
}

bool BST::search(int value) {
    return search(root, value) != nullptr;
}

BSTNode* BST::findMin(BSTNode* node) {
    while (node->left) node = node->left;
    return node;
}

BSTNode* BST::deleteNode(BSTNode* node, int value) {
    if (node == nullptr) return node;
    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        BSTNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

void BST::deleteNode(int value) {
    root = deleteNode(root, value);
}

// -------------------------------------
// AVL Tree Implementation
// -------------------------------------

AVLNode::AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* node) {
    return node == nullptr ? 0 : node->height;
}

int AVLTree::balanceFactor(AVLNode* node) {
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, int value) {
    if (node == nullptr) return new AVLNode(value);

    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left (LL) case
    if (balance > 1 && value < node->left->data) {
        return rotateRight(node);
    }

    // Right Right (RR) case
    if (balance < -1 && value > node->right->data) {
        return rotateLeft(node);
    }

    // Left Right (LR) case
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left (RL) case
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

AVLNode* AVLTree::deleteNode(AVLNode* node, int value) {
    if (node == nullptr) return node;

    if (value < node->data) node->left = deleteNode(node->left, value);
    else if (value > node->data) node->right = deleteNode(node->right, value);
    else {
        if (node->left == nullptr || node->right == nullptr) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            AVLNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }

    if (node == nullptr) return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left (LL) case
    if (balance > 1 && balanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }

    // Right Right (RR) case
    if (balance < -1 && balanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }

    // Left Right (LR) case
    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left (RL) case
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::deleteNode(int value) {
    root = deleteNode(root, value);
}

void AVLTree::inOrder(AVLNode* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void AVLTree::inOrderTraversal() {
    inOrder(root);
    cout << endl;
}

bool AVLTree::search(int value) {
    AVLNode* current = root;
    while (current != nullptr) {
        if (current->data == value) return true;
        else if (value < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

AVLNode* AVLTree::findMin(AVLNode* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}
