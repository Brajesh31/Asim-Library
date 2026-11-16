#include "asim_library.h"

#include <algorithm>
#include <iostream>
#include <utility>

// -----------------------------------------------------------------------------
// Stack
// -----------------------------------------------------------------------------

Stack::Stack(int size)
    : elements_(), capacity_(size < 0 ? 0U : static_cast<std::size_t>(size)) {
    if (size < 0) {
        throw std::invalid_argument("Stack capacity cannot be negative.");
    }
    elements_.reserve(capacity_);
}

void Stack::push(int element) {
    if (isFull()) {
        throw std::overflow_error("Cannot push into a full stack.");
    }
    elements_.push_back(element);
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Cannot pop from an empty stack.");
    }
    const int value = elements_.back();
    elements_.pop_back();
    return value;
}

int Stack::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Cannot peek at an empty stack.");
    }
    return elements_.back();
}

bool Stack::isEmpty() const noexcept { return elements_.empty(); }
bool Stack::isFull() const noexcept { return elements_.size() == capacity_; }

void Stack::rotateRight() {
    if (elements_.size() > 1U) {
        std::rotate(elements_.begin(), elements_.end() - 1, elements_.end());
    }
}

void Stack::rotateLeft() {
    if (elements_.size() > 1U) {
        std::rotate(elements_.begin(), elements_.begin() + 1, elements_.end());
    }
}

void Stack::display() const { display(std::cout); }

void Stack::display(std::ostream& output) const {
    for (std::size_t i = 0; i < elements_.size(); ++i) {
        if (i != 0U) output << ' ';
        output << elements_[i];
    }
    output << '\n';
}

bool Stack::search(int element) const {
    return std::find(elements_.begin(), elements_.end(), element) != elements_.end();
}

int Stack::size() const noexcept { return static_cast<int>(elements_.size()); }
int Stack::capacity() const noexcept { return static_cast<int>(capacity_); }
void Stack::clear() noexcept { elements_.clear(); }

// -----------------------------------------------------------------------------
// Binary Search Tree
// -----------------------------------------------------------------------------

BSTNode::BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
BST::BST() noexcept : root_(nullptr), size_(0U) {}
BST::~BST() { clear(); }

BSTNode* BST::clone(const BSTNode* node) {
    if (node == nullptr) return nullptr;
    BSTNode* copy = new BSTNode(node->data);
    try {
        copy->left = clone(node->left);
        copy->right = clone(node->right);
    } catch (...) {
        destroy(copy);
        throw;
    }
    return copy;
}

void BST::destroy(BSTNode* node) noexcept {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

BST::BST(const BST& other) : root_(clone(other.root_)), size_(other.size_) {}

BST& BST::operator=(const BST& other) {
    if (this != &other) {
        BST copy(other);
        std::swap(root_, copy.root_);
        std::swap(size_, copy.size_);
    }
    return *this;
}

BST::BST(BST&& other) noexcept : root_(other.root_), size_(other.size_) {
    other.root_ = nullptr;
    other.size_ = 0U;
}

BST& BST::operator=(BST&& other) noexcept {
    if (this != &other) {
        clear();
        root_ = other.root_;
        size_ = other.size_;
        other.root_ = nullptr;
        other.size_ = 0U;
    }
    return *this;
}

BSTNode* BST::insert(BSTNode* node, int value, bool& inserted) {
    if (node == nullptr) {
        inserted = true;
        return new BSTNode(value);
    }
    if (value < node->data) node->left = insert(node->left, value, inserted);
    else if (value > node->data) node->right = insert(node->right, value, inserted);
    return node;
}

void BST::insert(int value) {
    bool inserted = false;
    root_ = insert(root_, value, inserted);
    if (inserted) ++size_;
}

void BST::inOrder(const BSTNode* node, std::ostream& output) {
    if (node == nullptr) return;
    inOrder(node->left, output);
    output << node->data << ' ';
    inOrder(node->right, output);
}

void BST::inOrderTraversal() const { inOrderTraversal(std::cout); }

void BST::inOrderTraversal(std::ostream& output) const {
    inOrder(root_, output);
    output << '\n';
}

const BSTNode* BST::search(const BSTNode* node, int value) noexcept {
    while (node != nullptr) {
        if (value == node->data) return node;
        node = value < node->data ? node->left : node->right;
    }
    return nullptr;
}

bool BST::search(int value) const { return search(root_, value) != nullptr; }

BSTNode* BST::findMin(BSTNode* node) noexcept {
    while (node != nullptr && node->left != nullptr) node = node->left;
    return node;
}

BSTNode* BST::deleteNode(BSTNode* node, int value, bool& deleted) {
    if (node == nullptr) return nullptr;
    if (value < node->data) {
        node->left = deleteNode(node->left, value, deleted);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value, deleted);
    } else {
        deleted = true;
        if (node->left == nullptr) {
            BSTNode* right = node->right;
            delete node;
            return right;
        }
        if (node->right == nullptr) {
            BSTNode* left = node->left;
            delete node;
            return left;
        }
        BSTNode* successor = findMin(node->right);
        node->data = successor->data;
        bool successorDeleted = false;
        node->right = deleteNode(node->right, successor->data, successorDeleted);
    }
    return node;
}

void BST::deleteNode(int value) {
    bool deleted = false;
    root_ = deleteNode(root_, value, deleted);
    if (deleted) --size_;
}

int BST::height(const BSTNode* node) noexcept {
    if (node == nullptr) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

int BST::height() const noexcept { return height(root_); }
bool BST::empty() const noexcept { return root_ == nullptr; }
std::size_t BST::size() const noexcept { return size_; }

void BST::clear() noexcept {
    destroy(root_);
    root_ = nullptr;
    size_ = 0U;
}

// -----------------------------------------------------------------------------
// AVL Tree
// -----------------------------------------------------------------------------

AVLNode::AVLNode(int value)
    : data(value), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() noexcept : root_(nullptr), size_(0U) {}
AVLTree::~AVLTree() { clear(); }

AVLNode* AVLTree::clone(const AVLNode* node) {
    if (node == nullptr) return nullptr;
    AVLNode* copy = new AVLNode(node->data);
    copy->height = node->height;
    try {
        copy->left = clone(node->left);
        copy->right = clone(node->right);
    } catch (...) {
        destroy(copy);
        throw;
    }
    return copy;
}

void AVLTree::destroy(AVLNode* node) noexcept {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

AVLTree::AVLTree(const AVLTree& other)
    : root_(clone(other.root_)), size_(other.size_) {}

AVLTree& AVLTree::operator=(const AVLTree& other) {
    if (this != &other) {
        AVLTree copy(other);
        std::swap(root_, copy.root_);
        std::swap(size_, copy.size_);
    }
    return *this;
}

AVLTree::AVLTree(AVLTree&& other) noexcept : root_(other.root_), size_(other.size_) {
    other.root_ = nullptr;
    other.size_ = 0U;
}

AVLTree& AVLTree::operator=(AVLTree&& other) noexcept {
    if (this != &other) {
        clear();
        root_ = other.root_;
        size_ = other.size_;
        other.root_ = nullptr;
        other.size_ = 0U;
    }
    return *this;
}

int AVLTree::height(const AVLNode* node) noexcept {
    return node == nullptr ? 0 : node->height;
}

int AVLTree::balanceFactor(const AVLNode* node) noexcept {
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

void AVLTree::updateHeight(AVLNode* node) noexcept {
    if (node != nullptr) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }
}

AVLNode* AVLTree::rotateRight(AVLNode* y) noexcept {
    AVLNode* x = y->left;
    AVLNode* middle = x->right;
    x->right = y;
    y->left = middle;
    updateHeight(y);
    updateHeight(x);
    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) noexcept {
    AVLNode* y = x->right;
    AVLNode* middle = y->left;
    y->left = x;
    x->right = middle;
    updateHeight(x);
    updateHeight(y);
    return y;
}

AVLNode* AVLTree::rebalance(AVLNode* node) noexcept {
    if (node == nullptr) return nullptr;
    updateHeight(node);
    const int balance = balanceFactor(node);
    if (balance > 1) {
        if (balanceFactor(node->left) < 0) node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1) {
        if (balanceFactor(node->right) > 0) node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

AVLNode* AVLTree::insert(AVLNode* node, int value, bool& inserted) {
    if (node == nullptr) {
        inserted = true;
        return new AVLNode(value);
    }
    if (value < node->data) node->left = insert(node->left, value, inserted);
    else if (value > node->data) node->right = insert(node->right, value, inserted);
    return inserted ? rebalance(node) : node;
}

void AVLTree::insert(int value) {
    bool inserted = false;
    root_ = insert(root_, value, inserted);
    if (inserted) ++size_;
}

AVLNode* AVLTree::findMin(AVLNode* node) noexcept {
    while (node != nullptr && node->left != nullptr) node = node->left;
    return node;
}

AVLNode* AVLTree::deleteNode(AVLNode* node, int value, bool& deleted) {
    if (node == nullptr) return nullptr;
    if (value < node->data) {
        node->left = deleteNode(node->left, value, deleted);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value, deleted);
    } else {
        deleted = true;
        if (node->left == nullptr || node->right == nullptr) {
            AVLNode* child = node->left != nullptr ? node->left : node->right;
            delete node;
            return child;
        }
        AVLNode* successor = findMin(node->right);
        node->data = successor->data;
        bool successorDeleted = false;
        node->right = deleteNode(node->right, successor->data, successorDeleted);
    }
    return deleted ? rebalance(node) : node;
}

void AVLTree::deleteNode(int value) {
    bool deleted = false;
    root_ = deleteNode(root_, value, deleted);
    if (deleted) --size_;
}

void AVLTree::inOrder(const AVLNode* node, std::ostream& output) {
    if (node == nullptr) return;
    inOrder(node->left, output);
    output << node->data << ' ';
    inOrder(node->right, output);
}

void AVLTree::inOrderTraversal() const { inOrderTraversal(std::cout); }

void AVLTree::inOrderTraversal(std::ostream& output) const {
    inOrder(root_, output);
    output << '\n';
}

bool AVLTree::search(int value) const noexcept {
    const AVLNode* current = root_;
    while (current != nullptr) {
        if (value == current->data) return true;
        current = value < current->data ? current->left : current->right;
    }
    return false;
}

bool AVLTree::isBalanced(const AVLNode* node) noexcept {
    if (node == nullptr) return true;
    const int balance = balanceFactor(node);
    return balance >= -1 && balance <= 1 &&
           std::abs(height(node->left) - height(node->right)) <= 1 &&
           isBalanced(node->left) && isBalanced(node->right);
}

bool AVLTree::isBalanced() const noexcept { return isBalanced(root_); }
bool AVLTree::empty() const noexcept { return root_ == nullptr; }
std::size_t AVLTree::size() const noexcept { return size_; }
int AVLTree::height() const noexcept { return height(root_); }

void AVLTree::clear() noexcept {
    destroy(root_);
    root_ = nullptr;
    size_ = 0U;
}
