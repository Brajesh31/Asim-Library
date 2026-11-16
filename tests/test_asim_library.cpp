#include "asim_library.h"

#include <cassert>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace {
std::string traversal(const BST& tree) {
    std::ostringstream out;
    tree.inOrderTraversal(out);
    return out.str();
}

std::string traversal(const AVLTree& tree) {
    std::ostringstream out;
    tree.inOrderTraversal(out);
    return out.str();
}

void testStack() {
    Stack stack(3);
    assert(stack.isEmpty());
    assert(stack.size() == 0);
    assert(stack.capacity() == 3);
    bool underflow = false;
    try { (void)stack.pop(); } catch (const std::underflow_error&) { underflow = true; }
    assert(underflow);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.isFull());
    assert(stack.peek() == 3);
    assert(stack.search(2));
    assert(!stack.search(9));

    bool overflow = false;
    try { stack.push(4); } catch (const std::overflow_error&) { overflow = true; }
    assert(overflow);

    stack.rotateRight();
    std::ostringstream out;
    stack.display(out);
    assert(out.str() == "3 1 2\n");
    stack.rotateLeft();
    out.str("");
    out.clear();
    stack.display(out);
    assert(out.str() == "1 2 3\n");
    assert(stack.pop() == 3);
    stack.clear();
    assert(stack.isEmpty());

    bool invalidCapacity = false;
    try { Stack invalid(-1); } catch (const std::invalid_argument&) { invalidCapacity = true; }
    assert(invalidCapacity);
}

void testBST() {
    BST tree;
    for (int value : {50, 30, 70, 20, 40, 60, 80, 30}) tree.insert(value);
    assert(tree.size() == 7);
    assert(tree.search(50));
    assert(!tree.search(999));
    assert(traversal(tree) == "20 30 40 50 60 70 80 \n");

    tree.deleteNode(20); // leaf
    assert(!tree.search(20));
    tree.deleteNode(30); // one child in this updated topology
    assert(!tree.search(30));
    tree.deleteNode(70); // two children
    assert(!tree.search(70));
    tree.deleteNode(999); // absent value is harmless
    assert(tree.size() == 4);

    BST copy = tree;
    copy.insert(999);
    assert(copy.search(999));
    assert(!tree.search(999));
    BST assigned;
    assigned = tree;
    assert(traversal(assigned) == traversal(tree));
    BST moved = std::move(copy);
    assert(moved.search(999));
    assert(copy.empty());
    tree.clear();
    assert(tree.empty());
    assert(tree.size() == 0);
}

void testAVL() {
    for (const std::vector<int>& values : {
             std::vector<int>{30, 20, 10}, // LL
             std::vector<int>{10, 20, 30}, // RR
             std::vector<int>{30, 10, 20}, // LR
             std::vector<int>{10, 30, 20}  // RL
         }) {
        AVLTree tree;
        for (int value : values) {
            tree.insert(value);
            assert(tree.isBalanced());
        }
        assert(traversal(tree) == "10 20 30 \n");
        assert(tree.height() == 2);
    }

    AVLTree tree;
    for (int value : {9, 5, 10, 0, 6, 11, -1, 1, 2, 7, 8, 12, 14, 13, 3, 4}) {
        tree.insert(value);
        assert(tree.isBalanced());
    }
    assert(tree.size() == 16);
    assert(tree.search(14));
    tree.deleteNode(9);
    tree.deleteNode(0);
    tree.deleteNode(5);
    tree.deleteNode(999);
    assert(tree.isBalanced());
    assert(tree.size() == 13);

    AVLTree copy = tree;
    copy.insert(1000);
    assert(copy.search(1000));
    assert(!tree.search(1000));
    AVLTree assigned;
    assigned = tree;
    assert(traversal(assigned) == traversal(tree));
    AVLTree moved = std::move(copy);
    assert(moved.search(1000));
    assert(copy.empty());
    tree.clear();
    assert(tree.empty());
}

} // namespace

int main() {
    testStack();
    testBST();
    testAVL();
    return 0;
}
