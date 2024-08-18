#include "BinaryTree.hpp"

int main() {
    BinaryTree<int> tree1;
    tree1.insert(13);
    tree1.insert(7);
    tree1.insert(3);
    tree1.insert(10);
    tree1.insert(8);
    tree1.insert(19);
    tree1.insert(15);
    tree1.insert(23);
    tree1.insert(22);

    BinaryTree<char> tree2;
    tree2.insert('a');
    tree2.insert('d');
    tree2.insert('b');
    tree2.insert('e');
    tree2.insert('f');
    tree2.insert('c');

    BinaryTree<string> tree3;
    tree3.insert("Tessema");
    tree3.insert("Maireg");
    tree3.insert("Bogale");
    tree3.insert("Mulat");

    tree1.inOrderTraversal();
    tree2.inOrderTraversal();
    tree3.inOrderTraversal();

    return 0;
}
