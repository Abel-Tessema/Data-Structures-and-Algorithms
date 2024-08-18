#include "./BinaryTree.hpp"

int main() {
    BinaryTree<char> binaryTree('a');

    BinaryTree<char>::Iterator iterator(binaryTree.getRoot());

    iterator.setLeft('b'); iterator.setRight('c');

    iterator.left();
    iterator.setLeft('d'); iterator.setRight('e');

    iterator.parent().right();
    iterator.setLeft('f'); iterator.setRight('g');

    iterator.right();
    iterator.setLeft('h'); iterator.setRight('i');

    iterator.mostParent();
    
// Pre-Order Traversal
    iterator.printPreOrderTraversal();
    write(1, "\n", 1);

// In-Order Traversal    
    iterator.printInOrderTraversal();
    write(1, "\n", 1);

// Post-Order Traversal
    iterator.printPostOrderTraversal();
    write(1, "\n", 1);
}