#include "asim_library.h"

int main() {
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    stack.rotateRight();
    stack.display();

    stack.pop();
    stack.display();

    BST bst;
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.inOrderTraversal();
    cout << "Search 10: " << bst.search(10) << endl;

    AVLTree avl;
    avl.insert(20);
    avl.insert(10);
    avl.insert(30);
    avl.inOrderTraversal();
    cout << "Search 10: " << avl.search(10) << endl;

    avl.deleteNode(10);
    avl.inOrderTraversal();
    
    return 0;
}
