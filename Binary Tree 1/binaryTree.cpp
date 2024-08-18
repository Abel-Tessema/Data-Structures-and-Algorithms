#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

class BinaryTree {
private:
    struct Node {
        int value;
        Node *leftChild = nullptr;
        Node *rightChild = nullptr;
    };

    Node* root = nullptr;

    bool isBinarySearchTree(Node* root, int min, int max) {
        if (root == nullptr)
            return true;

        if (root->value < min || root->value > max)
            return false;

        return isBinarySearchTree(root->leftChild, min, root->value - 1) &&
               isBinarySearchTree(root->rightChild, root->value + 1, max);
    }


    void inOrderTraversal(Node *Root) {
        if (Root == nullptr)
            return;
        inOrderTraversal(Root->leftChild);
        cout << Root->value << endl;
        inOrderTraversal(Root->rightChild);
    }

    void preOrderTraversal(Node *Root) {
        if (Root == nullptr)
            return;

        cout << Root->value << endl;
        preOrderTraversal(Root->leftChild);
        preOrderTraversal(Root->rightChild);
    }

    void postOrderTraversal(Node *Root) {
        if (Root == nullptr)
            return;

        postOrderTraversal(Root->leftChild);
        postOrderTraversal(Root->rightChild);
        cout << Root->value << endl;
    }


    int height(Node *r) {
        if (r == nullptr) {
            return -1;
        }
        return 1 + max(height(r->leftChild), height(r->rightChild));
    }


    bool equals(Node *first, Node *second) {
        if (first == nullptr && second == nullptr) {
            return true;
        }
        if (first != nullptr && second != nullptr) {
            return first->value == second->value && equals(first->leftChild, second->leftChild) &&
                   equals(first->rightChild, second->rightChild);
        }
        return false;
    }

    int minValue(Node *r) {
        if (r == nullptr) {
            int max = numeric_limits<int>::max();
            return max;
        }

        return min(r->value, min(minValue(r->leftChild), minValue(r->rightChild)));
    }

    Node *deleteNode(Node *root, int value) {
        // base case
        if (root == nullptr) return root;

        // If the value to be deleted is smaller than the root's value,
        // then it lies in left subtree
        if (value < root->value) {
            root->leftChild = deleteNode(root->leftChild, value);
        }
            // If the value to be deleted is greater than the root's value,
            // then it lies in right subtree
        else if (value > root->value) {
            root->rightChild = deleteNode(root->rightChild, value);
        }
            // if value is same as root's value, then this is the node
            // to be deleted
        else {
            // node with only one child or no child
            if (root->leftChild == nullptr) {
                Node *temp = root->rightChild;
                delete root;
                return temp;
            } else if (root->rightChild == nullptr) {
                Node *temp = root->leftChild;
                delete root;
                return temp;
            }
//DELETION BY COPYING:
            // node with two children: get the inorder successor (smallest
            // in the right subtree)
            Node *temp = minValueNode(root->rightChild);

            // copy the inorder successor's content to this node
            root->value = temp->value;

            // delete the inorder successor
            root->rightChild = deleteNode(root->rightChild, temp->value);
//DELETION BY MERGING:

            // // get the minimum value of the right sub-tree.
            // Node *temp = minValueNode(root->rightChild);
            // // link the left sub-tree with the left child of the right sub-tree
            // temp->leftChild = root->leftChild;
            // // delete the link of the root to the root of the left sub-tree
            // root->leftChild = nullptr;
            // // store the value of the new node of the tree
            // Node *newSubTree = root->rightChild;
            // // delete the link of the root to the root of the right sub-tree
            // root->rightChild = nullptr;
            // // delete the root
            // delete root;
            // // set the root of the tree.
            // root = newSubTree;



        }
        return root;
    }

    void printNodesAtDistanceK(Node *r, int k) {
        if (r == nullptr) {
            return;
        }

        // if(k!=0&&!isLeft){

        //         cout<<"  ";

        // }
        if (k == 0) {
            cout << r->value;
            return;
        }
        printNodesAtDistanceK(r->leftChild, k - 1);
        cout << "  ";
        printNodesAtDistanceK(r->rightChild, k - 1);
    }

    void breadthFirstTraversal(Node *root) {
        int h = height(root);
        for (int i = 0; i <= h; i++) {
            // cout<<"Level "<<i<<":";
            // // Print spaces before each level
            // for(int j = 0; j < h - i; j++) {
            //     cout << "  ";
            // }
            printNodesAtDistanceK(root, i);
            // cout<<endl;
            // cout<<endl;
        }
    }


public:

    void printNodesAtDistanceK(int distance) {
        printNodesAtDistanceK(root, distance);
    }

    void breadthFirstTraversal() {
        breadthFirstTraversal(root);
    }


    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void insert(int value) {
        Node *newNode = new Node;
        newNode->value = value;
        if (root == nullptr) {
            root = newNode;
        } else {
            Node *current = root;
            Node *parent = nullptr;

            while (true) {
                parent = current;
                if (current->value < value) {
                    current = current->rightChild;
                    if (current == nullptr) {
                        parent->rightChild = newNode;
                        return;
                    }
                } else if (value < current->value) {
                    current = current->leftChild;
                    if (current == nullptr) {
                        parent->leftChild = newNode;
                        return;
                    }
                } else {
                    cout << "Value already exists" << endl;
                    return;
                }
            }
        }
    }

    bool equals(BinaryTree other) {
        return equals(root, other.root);
    }

    bool find(int value) {
        Node *current = root;
        while (current != nullptr) {
            if (current->value > value) {
                current = current->leftChild;
            } else if (current->value < value) {
                current = current->rightChild;
            } else {
                return true;
            }
        }
        return false;
    }

    void printInOrder() {
        inOrderTraversal(root);
    }

    int getHeight() {
        return height(root);
    }

    int getMinValue() {
        return minValue(root);
    }

    bool isBinarySearchTree() {
        int max = numeric_limits<int>::max();
        int min = numeric_limits<int>::min();
        return isBinarySearchTree(root, min, max);
    }

    void printGivenLevel(Node *root, int level) {
        if (root == nullptr)
            return;
        if (level == 1)
            cout << root->value << " ";
        else if (level > 1) {
            printGivenLevel(root->leftChild, level - 1);
            printGivenLevel(root->rightChild, level - 1);
        }
    }


    void printLevelOrder() {
        int h = height(root);
        for (int i = 1; i <= h; i++)
            printGivenLevel(root, i);
    }


    Node *minValueNode(Node *node) {
        Node *current = node;

        // loop down to find the leftmost leaf
        while (current && current->leftChild != nullptr)
            current = current->leftChild;

        return current;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(13);
    tree.insert(7);
    tree.insert(3);
    tree.insert(10);
    tree.insert(8);
    tree.insert(19);
    tree.insert(15);
    tree.insert(23);
    tree.insert(22);



    // BinaryTree tree2;
    // tree2.insert(7);
    // tree2.insert(10);
    // tree2.insert(8);
    // tree2.insert(19);
    // tree2.insert(6);
    // bool found = tree.find(19);
    // cout << "found? " << found << endl;
    // tree.printInOrder();
    // cout << "Height: " << tree.getHeight() << endl;
    // cout << "min: " << tree.getMinValue() << endl;
    // cout << "equal? " << tree.equals(tree2) << endl;
    // cout << "is binary search tree: " << tree.isBinarySearchTree() << endl;
    // tree2.printInOrder();
    //  cout << "Deleting 19: ";
    // tree.root = tree.deleteNode(tree.root, 19);
    cout << "before deletion: " << endl;
    tree.printInOrder();
    tree.deleteNode(13);
    cout << "after deletion: " << endl;
    tree.printInOrder();
    cout << endl;
    tree.insert(24);
    tree.breadthFirstTraversal();
    tree.deleteNode(15);
    tree.breadthFirstTraversal();
    return 0;
}
// 3, 7, 8, 10, 15, 19, 22, 23
// 