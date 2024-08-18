//
// Created by Abel XO on 2/11/2024.
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
        T value;
        Node* leftChild = nullptr;
        Node* rightChild = nullptr;

        explicit Node(T value) {
            this->value = value;
        }
    };

    Node* root = nullptr;

    void preOrderTraversal(Node* root) {
        if (root == nullptr)
                return;

        cout << root->value << " ";
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }

    void inOrderTraversal(Node* root) {
        if (root == nullptr)
            return;

        inOrderTraversal(root->leftChild);
        cout << root->value << " ";
        inOrderTraversal(root->rightChild);
    }

    void postOrderTraversal(Node* root) {
        if (root == nullptr)
            return;

        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        cout << root->value << " ";
    }

public:
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
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;

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
