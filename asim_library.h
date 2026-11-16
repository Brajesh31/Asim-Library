#ifndef ASIM_LIBRARY_H
#define ASIM_LIBRARY_H

#include <cstddef>
#include <iosfwd>
#include <memory>
#include <stdexcept>
#include <vector>

/**
 * @file asim_library.h
 * @brief Educational integer data structures: Stack, BST, and AVLTree.
 *
 * The containers own their storage and are safely copyable/movable. Tree
 * traversals write to an explicitly supplied stream; the no-argument overloads
 * preserve the original console-oriented API.
 */

/**
 * @brief Fixed-capacity LIFO stack of integers.
 *
 * rotateRight/rotateLeft rotate the occupied sequence, not the unused
 * capacity. The display order is bottom-to-top. Empty pop/peek operations
 * throw std::underflow_error, and pushing into a full stack throws
 * std::overflow_error.
 */
class Stack {
public:
    explicit Stack(int size);
    ~Stack() = default;

    Stack(const Stack&) = default;
    Stack& operator=(const Stack&) = default;
    Stack(Stack&&) noexcept = default;
    Stack& operator=(Stack&&) noexcept = default;

    void push(int element);
    int pop();
    int peek() const;
    bool isEmpty() const noexcept;
    bool isFull() const noexcept;
    void rotateRight();
    void rotateLeft();
    void display() const;
    void display(std::ostream& output) const;
    bool search(int element) const;
    int size() const noexcept;
    int capacity() const noexcept;
    void clear() noexcept;

private:
    std::vector<int> elements_;
    std::size_t capacity_;
};

/** @brief Node type exposed for educational inspection of a binary search tree. */
class BSTNode {
public:
    explicit BSTNode(int value);
    int data;
    BSTNode* left;
    BSTNode* right;
};

/**
 * @brief Unbalanced binary search tree of unique integer keys.
 *
 * Duplicate insertions are ignored. All nodes are owned by the BST instance.
 * Copying performs a deep copy; moving transfers ownership.
 */
class BST {
public:
    BST() noexcept;
    ~BST();

    BST(const BST& other);
    BST& operator=(const BST& other);
    BST(BST&& other) noexcept;
    BST& operator=(BST&& other) noexcept;

    void insert(int value);
    void inOrderTraversal() const;
    void inOrderTraversal(std::ostream& output) const;
    bool search(int value) const;
    void deleteNode(int value);
    bool empty() const noexcept;
    std::size_t size() const noexcept;
    int height() const noexcept;
    void clear() noexcept;

private:
    BSTNode* root_;
    std::size_t size_;

    static BSTNode* clone(const BSTNode* node);
    static void destroy(BSTNode* node) noexcept;
    static BSTNode* insert(BSTNode* node, int value, bool& inserted);
    static void inOrder(const BSTNode* node, std::ostream& output);
    static const BSTNode* search(const BSTNode* node, int value) noexcept;
    static BSTNode* deleteNode(BSTNode* node, int value, bool& deleted);
    static BSTNode* findMin(BSTNode* node) noexcept;
    static int height(const BSTNode* node) noexcept;
};

/** @brief Node type used by AVLTree. Height of a leaf is one. */
class AVLNode {
public:
    explicit AVLNode(int value);
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

/**
 * @brief Self-balancing AVL tree of unique integer keys.
 *
 * Duplicate insertions are ignored. Insertions and deletions restore the AVL
 * balance invariant. All nodes are owned by the AVLTree instance.
 */
class AVLTree {
public:
    AVLTree() noexcept;
    ~AVLTree();

    AVLTree(const AVLTree& other);
    AVLTree& operator=(const AVLTree& other);
    AVLTree(AVLTree&& other) noexcept;
    AVLTree& operator=(AVLTree&& other) noexcept;

    void insert(int value);
    void deleteNode(int value);
    void inOrderTraversal() const;
    void inOrderTraversal(std::ostream& output) const;
    bool search(int value) const noexcept;
    bool empty() const noexcept;
    std::size_t size() const noexcept;
    int height() const noexcept;
    bool isBalanced() const noexcept;
    void clear() noexcept;

private:
    AVLNode* root_;
    std::size_t size_;

    static AVLNode* clone(const AVLNode* node);
    static void destroy(AVLNode* node) noexcept;
    static int height(const AVLNode* node) noexcept;
    static int balanceFactor(const AVLNode* node) noexcept;
    static void updateHeight(AVLNode* node) noexcept;
    static AVLNode* rotateRight(AVLNode* node) noexcept;
    static AVLNode* rotateLeft(AVLNode* node) noexcept;
    static AVLNode* rebalance(AVLNode* node) noexcept;
    static AVLNode* insert(AVLNode* node, int value, bool& inserted);
    static AVLNode* deleteNode(AVLNode* node, int value, bool& deleted);
    static AVLNode* findMin(AVLNode* node) noexcept;
    static void inOrder(const AVLNode* node, std::ostream& output);
    static bool isBalanced(const AVLNode* node) noexcept;
};

#endif // ASIM_LIBRARY_H
