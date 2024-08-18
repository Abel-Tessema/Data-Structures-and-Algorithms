public class BinarySearchTree {
    private static class Node {
        private final int value;
        private Node leftChild;
        private Node rightChild;
        private Node(int value) {
            this.value = value;
            this.leftChild = null;
            this.rightChild = null;
        }
    }

    private Node root;
    public Node getRoot() {
        return root;
    }

    public boolean find(int value) {
        Node current = root;
        while (current != null) {
            if (value == current.value)
                return true;
            if (value < current.value)
                current = current.leftChild;
            else
                current = current.rightChild;
        }
        return false;
    }

    public void insert(int value) {
        Node newNode = new Node(value);
        if (root == null) {
            root = newNode;
            return;
        }
        Node current = root;
        Node parent = current;
        while (current != null) {
            parent = current;
            current = (value < current.value)
                    ? current.leftChild
                    : current.rightChild;
        }
        if (value < parent.value)
            parent.leftChild = newNode;
        else
            parent.rightChild = newNode;
    }

    public void traversePreOrder() {
        System.out.print("Pre-order traversal: ");
        traversePreOrder(root);
        System.out.println();
    }
    private void traversePreOrder(Node root) {
        if (root == null)
            return;

        System.out.print(root.value + " ");
        traversePreOrder(root.leftChild);
        traversePreOrder(root.rightChild);
    }

    public void traverseInOrder() {
        System.out.print("In-order traversal: ");
        traverseInOrder(root);
        System.out.println();
    }
    private void traverseInOrder(Node root) {
        if (root == null)
            return;

        traverseInOrder(root.leftChild);
        System.out.print(root.value + " ");
        traverseInOrder(root.rightChild);
    }

    public void traversePostOrder() {
        System.out.print("Post-order traversal: ");
        traversePostOrder(root);
        System.out.println();
    }
    private void traversePostOrder(Node root) {
        if (root == null)
            return;

        traverseInOrder(root.leftChild);
        traverseInOrder(root.rightChild);
        System.out.print(root.value + " ");
    }

    public int height() {
        return height(root);
    }
    private int height(Node root) {
        if (root == null)
            return -1;

        return 1 + Math.max(height(root.leftChild), height(root.rightChild));
    }

    public int min() {
        return min(root);
    }
    private int min(Node root) {
        if (isLeaf(root))
            return root.value;

        int leftMin = min(root.leftChild);
        int rightMin = min(root.rightChild);

        return Math.min(root.value, Math.min(leftMin, rightMin));
    }

    public int max() {
        return max(root);
    }
    private int max(Node root) {
        if (isLeaf(root))
            return root.value;

        int leftMax = max(root.leftChild);
        int rightMax = max(root.rightChild);

        return Math.max(root.value, Math.max(leftMax, rightMax));
    }

    private boolean isLeaf(Node node) {
        return (node.leftChild == null) && (node.rightChild == null);
    }

    public boolean equals(BinarySearchTree otherTree) {
        /*
        if (root == null && tree.getRoot() == null)
            return true;
        if ((root == null && tree.getRoot() != null)
                || (root != null && tree.getRoot() == null))
            return false;

        return root.value == tree.getRoot().value;

         */
        if (otherTree == null) return false;
        return equals(root, otherTree.getRoot());
    }

    private boolean equals(Node first, Node second) {
        if (first == null && second == null)
            return true;
        if (first != null && second != null)
            return first.value == second.value
                    && equals(first.leftChild, second.leftChild)
                    && equals(first.rightChild, second.rightChild);
        return false;
    }

    public boolean isBinarySearchTree() {
        if (root == null) return true;
        return isBinarySearchTree(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean isBinarySearchTree(Node root, int min, int max) {
        if (!(root.value > min && root.value < max))
            return false;
        if (isLeaf(root))
            return true;
        var left = isBinarySearchTree(root.leftChild, min, root.value);
        var right = isBinarySearchTree(root.rightChild, root.value, max);
        return left && right;
    }

    public void KDistanceNodes(int distance) {
        System.out.print("Nodes at distance " + distance + ": ");
        if (root == null || distance > height() || distance < 0) {
            System.out.println("none");
            return;
        }
        KDistanceNodes(root, distance);
        System.out.println();
    }

    private void KDistanceNodes(Node root, int distance) {
        if (distance == 0) {
            System.out.print(root.value + " ");
            return;
        }
        distance--;
        KDistanceNodes(root.leftChild, distance);
        KDistanceNodes(root.rightChild, distance);
    }

    public void traverseLevelOrder() {
        System.out.print("Level-order traversal: ");
        for (var i = 0; i <= height(); i++)
            KDistanceNodes(root, i);
    }
}
