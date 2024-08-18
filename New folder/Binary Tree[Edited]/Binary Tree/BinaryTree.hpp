//
// Created by Abel XO on 2/11/2024.
// Edited by Pyankie.
//

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <memory>
#include <iostream>

using namespace std;

template <class T>
class BinaryTree {
private:
    struct Node {
        using smartNodePointer = shared_ptr<Node>;  // Modern way of defining aliases in C++.
        T value;
        smartNodePointer leftChild;
        smartNodePointer rightChild;

        explicit Node(T value) : value(value), leftChild(nullptr), rightChild(nullptr) {}
        explicit Node() : leftChild(nullptr), rightChild(nullptr) {} // Default constructor
    };

    /* typedef shared_ptr<Node> smartNodePointer;
       This is the C-style alias definition. */
    using smartNodePointer = shared_ptr<Node>;  // Modern way of defining aliases in C++.
    smartNodePointer root;
    /* In the above statement there is no memory allocation for the variable 'root';
       the actual memory allocation happens during declaration of a 'BinaryTree'--
       instance in the main function within the BinaryTree constructor. */

// ========================== Helper Functions =============================

    void preOrderTraversal(smartNodePointer root) {
        if (root == nullptr)
                return;

        cout << root->value << " ";
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }

    void inOrderTraversal(smartNodePointer root) {
        if (root == nullptr)
            return;

        inOrderTraversal(root->leftChild);
        cout << root->value << " ";
        inOrderTraversal(root->rightChild);
    }

    void postOrderTraversal(smartNodePointer root) {
        if (root == nullptr)
            return;

        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        cout << root->value << " ";
    }

// ============================ Constructor ================================

public:
    /* Here is where the program allocates space for the variable 'root',
       by initializing it to a null pointer. */
    BinaryTree() : root(nullptr) {}

// ======================== Interface Functions =============================

    void preOrderTraversal() {
        cout << "Pre-order traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal() {
        cout << "In-order traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    void postOrderTraversal() {
        cout << "Post-order traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }

    void insert(T value) {
        smartNodePointer newNode = make_shared<Node>(value);    
        /* By using the 'make_shared<Node>()' function,
        we tell the compiler that we want to allocate a memory for the 'newNode' object dynamically. 
        Internally this function uses the 'new' operator to allocate a memory space, 
        but it allows us only to create a smart pointer. In our case a shared one. */
        if (root == nullptr) {
            root = newNode;
            return;
        }
        smartNodePointer current = root;
        smartNodePointer parent = nullptr;

        while (true) {
            parent = current;
            if (current->value < value) {
                current = current->rightChild;
                if (current == nullptr) {
                    parent->rightChild = newNode;
                    return;
                }
            }
            else if (current->value > value) {
                current = current->leftChild;
                if (current == nullptr) {
                    parent->leftChild = newNode;
                    return;
                }
            }
            else {
                cout << "Value already exists, so it won't be added." << endl;
                return;
            }
        } 
    }
};

#endif //BINARYTREE_HPP
