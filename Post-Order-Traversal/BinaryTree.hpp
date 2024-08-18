/**
 * Ensures that this header file is included only once, regardless
 * of how many times it's imported.
 * It is similar to using #ifndef #define #endif directives.
 * The difference is that these are standard, and are present in
 * both C and C++, whereas #pragma is C++ specific, and widely
 * supported instead of being a standard.
 */
#pragma once

// Needed for size_t
#include <cstddef>

/**
 * It specifies that the function is defined elsewhere (extern),
 * and uses the C-language calling convention ("C").
 * It is useful for interfacing with C libraries.
 */
extern "C" {
    /**
     * <p> fileDescriptor = an integer representing a file descriptor
     *                  (usually an open file or socket). </p>
     * <p> memoryBuffer = a pointer to a constant memory buffer (data
     *                to be written). </p>
     * <p> numberOfBytes = the number of bytes to write from the buffer.
     *                     </p>
     * */
	size_t write(int fileDescriptor, const void* memoryBuffer, size_t numberOfBytes);
}

template<typename T>
class Node {
public:
	T* data;
	Node* parent;
	Node* leftChild;
	Node* rightChild;

	explicit Node(T* data = nullptr, Node* parent = nullptr, Node* leftChild = nullptr, Node* rightChild = nullptr)
		: data(data), parent(parent), leftChild(leftChild), rightChild(rightChild)
	{}
};

template<typename T>
class BinaryTree {
private:
    Node<T>* root;

public:
	explicit BinaryTree(T&& data) : root(new Node<T>(&data)) {}

	class Iterator {
	private:
        Node<T>* node;

	public:
		Iterator() : node(root) {}

		explicit Iterator(Node<T>* pointer) : node(pointer) {}

		Iterator(Iterator&& iterator) : node(iterator.node) {}

		bool isRoot() {
			return node->parent == nullptr;
		}

		bool isLeftChild() {
			return !isRoot() && node->parent->leftChild == node;
		}

		bool isRightChild() {
			return !isRoot() && node->parent->rightChild == node;
		}

		bool hasLeftChild() {
			return node->leftChild != nullptr;
		}

		bool hasRightChild() {
			return node->rightChild != nullptr;
		}

		bool hasChild() {
			return hasLeftChild() || hasRightChild();
		}

		bool hasParent() {
			return node->parent != nullptr;
		}

		bool hasLeftSibling() {
			return hasParent() && !isLeftChild() && node->parent->leftChild != nullptr;
		}

		bool hasRightSibling() {
			return hasParent() && !isRightChild() && node->parent->rightChild != nullptr;
		}

		Iterator& parent() {
			if (hasParent())
                node = node->parent;

			return *this;
		}

		Iterator& left() {
			if (hasLeftChild())
                node = node->leftChild;

			return *this;
		}

		Iterator& right() {
			if (hasRightChild())
                node = node->rightChild;

			return *this;
		}

		Iterator& mostParent() {
			while (hasParent()) {
                node = node->parent;
			}

			return *this;
		}

		Iterator& mostLeft() {
			while (hasLeftChild()) {
				left();
			}

			return *this;
		}

		Iterator& mostRight() {
			while (hasRightChild())
			{
				right();
			}

			return *this;
		}

		void setLeft(T&& data) { // set new left node
			if (node->leftChild != nullptr) {
				return;
			}
            auto* newNode = new Node<T>(&data, node);
            node->leftChild = newNode;
		}

		void setRight(T&& data) { // set new right node
			if (node->rightChild != nullptr) {
				return;
			}
            auto* newNode = new Node<T>(&data, node);
            node->rightChild = newNode;
		}

		void log() {
			write(1, node->data, sizeof(T));
		}

		void printPreOrderTraversal() { // Pre-Order Traversal
			log();

			if (hasLeftChild()) {
				Iterator iterator(node);
				iterator.left();
                iterator.printPreOrderTraversal();
			}

			if (hasRightChild()) {
				Iterator iterator(node);
				iterator.right();
                iterator.printPreOrderTraversal();
			}
		}

		void printInOrderTraversal() { // In-Order Traversal
			if (hasLeftChild()) {
				Iterator iterator(node);
				iterator.left();
                iterator.printInOrderTraversal();
			}

			log();

			if (hasRightChild()) {
				Iterator iterator(node);
				iterator.right();
                iterator.printInOrderTraversal();
			}
		}

		void printPostOrderTraversal() { // Post-Order Traversal
			if (hasLeftChild()) {
				Iterator iterator(node);
				iterator.left();
                iterator.printPostOrderTraversal();
			}

			if (hasRightChild()) {
				Iterator iterator(node);
				iterator.right();
                iterator.printPostOrderTraversal();
			}

			log();
		}
	};
	
	Iterator getRoot() {
		return Iterator(root);
	}
};