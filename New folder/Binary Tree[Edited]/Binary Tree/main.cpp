#include "BinaryTree.hpp"

int main() {
    BinaryTree<int> tree;
    tree.insert(13);
    tree.insert(7);
    tree.insert(3);
    tree.insert(10);
    tree.insert(8);
    tree.insert(19);
    tree.insert(15);
    tree.insert(23);
    tree.insert(22);

    tree.inOrderTraversal();
    tree.postOrderTraversal();
    tree.preOrderTraversal();

    return 0;
}
