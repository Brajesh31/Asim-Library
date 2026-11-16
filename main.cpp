#include "asim_library.h"

#include <iostream>
#include <stdexcept>
#include <utility>

int main() {
    try {
        std::cout << "=== Asim-Library: data structures demonstration ===\n";

        Stack stack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        std::cout << "Stack (bottom to top): ";
        stack.display();
        stack.rotateRight();
        std::cout << "After rotateRight: ";
        stack.display();
        std::cout << "Top element: " << stack.peek() << '\n';
        std::cout << "Search 20: " << (stack.search(20) ? "found" : "not found") << '\n';
        std::cout << "Popped: " << stack.pop() << '\n';
        std::cout << "Stack size/capacity: " << stack.size() << '/' << stack.capacity() << "\n\n";

        BST bst;
        for (int value : {50, 30, 70, 20, 40, 60, 80, 30}) bst.insert(value);
        std::cout << "BST in-order (sorted): ";
        bst.inOrderTraversal();
        std::cout << "Contains 40: " << (bst.search(40) ? "yes" : "no") << '\n';
        bst.deleteNode(50);
        std::cout << "BST after deleting 50: ";
        bst.inOrderTraversal();
        std::cout << "BST size/height: " << bst.size() << '/' << bst.height() << "\n\n";

        AVLTree avl;
        for (int value : {10, 20, 30, 40, 50, 25, 5, 4, 3}) avl.insert(value);
        std::cout << "AVL in-order (sorted): ";
        avl.inOrderTraversal();
        std::cout << "Contains 25: " << (avl.search(25) ? "yes" : "no") << '\n';
        std::cout << "AVL size/height: " << avl.size() << '/' << avl.height() << '\n';
        std::cout << "AVL balance invariant: " << (avl.isBalanced() ? "valid" : "invalid") << '\n';
        avl.deleteNode(30);
        std::cout << "AVL after deleting 30: ";
        avl.inOrderTraversal();
        std::cout << "AVL balance invariant after deletion: "
                  << (avl.isBalanced() ? "valid" : "invalid") << '\n';

        // Copying trees is a deep copy. Mutating the copy does not mutate the source.
        BST copied = bst;
        copied.insert(999);
        std::cout << "\nDeep-copy check, source contains 999: "
                  << (bst.search(999) ? "yes" : "no") << '\n';
    } catch (const std::exception& error) {
        std::cerr << "Demonstration failed: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
