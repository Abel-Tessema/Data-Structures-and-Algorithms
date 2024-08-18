public class LinkedList {
    private Node first;
    private Node last;
    private int size = 0;

    public LinkedList() {
        first = new Node();
        last = new Node();
        first.setNext(last);
        last.setNext(first);
    }

    public void print() {
        Node node = first.getNext();
        if (first.getNext() == last)
            System.out.println("The list is empty. There's nothing to print.");
        else {
            while (node != null) {
                System.out.println(node.getValue());
                node = node.getNext();
            }
        }
    }

    // addFirst
    public void addFirst(int value) {
        Node newNode = new Node(value);
        if (first.getNext() == last) {
            first.setNext(newNode);
            last.setNext(newNode);
            newNode.setNext(null);
        } else {
            newNode.setNext(first.getNext());
            first.setNext(newNode);
        }
        size++;
    }

    // addLast
    public void addLast(int value) {
        Node newNode = new Node(value);
        if (first.getNext() == last && last.getNext() == first) {
            first.setNext(newNode);
        } else {
            last.getNext().setNext(newNode);
        }
        last.setNext(newNode);
        newNode.setNext(null);
        size++;
    }

    // deleteFirst
    public void deleteFirst() {
        if (first.getNext() == last) {
            System.out.println("The list is empty. There's nothing to delete.");
        } else if (first.getNext() == last.getNext()) {
            first.setNext(last);
            last.setNext(first);
        } else {
            Node temp = first.getNext().getNext();
            first.getNext().setNext(null);
            first.setNext(temp);
        }
        size--;
    }


    // deleteLast
    public void deleteLast() {
        if (first.getNext() == last) {
            System.out.println("The list is empty. There's nothing to delete.");
        } else if (first.getNext() == last.getNext()) {
            first.setNext(last);
            last.setNext(first);
        } else {
            Node temp = first.getNext();
            while (temp.getNext().getNext() != null)
                temp = temp.getNext();
            temp.setNext(null);
            last.setNext(temp);
        }
        size--;
    }

    // contains
    public boolean contains(int value) {
        if (first.getNext() == last)
            return false;
        Node temp = first.getNext();
        while (temp != null) {
            if (temp.getValue() == value)
                return true;
            temp = temp.getNext();
        }
        return false;
    }

    // indexOf
    public int indexOf(int value) {
        if (first.getNext() == last)
            return -1;
        else {
            Node temp = first.getNext();
            int count = 0;
            while (temp != null) {
                if (temp.getValue() == value)
                    return count;
                count++;
                temp = temp.getNext();
            }
        }
        return -1;
    }

    // O(n)
    public int size1() {
        Node temp = first.getNext();
        if (first.getNext() == last)
            return 0;
        int size = 0;
        while(temp != null) {
            size++;
            temp = temp.getNext();
        }
        return size;
    }

    // O(1)
    public int size2() {
        return size;
    }

    public int[] toArray() {
        if (first.getNext() == last)
            return new int[0];
        int[] numbers = new int[size];
        int index = 0;
        Node temp = first.getNext();
        while (temp != null) {
            numbers[index++] = temp.getValue();
            temp = temp.getNext();
        }
        return numbers;
    }

    public void reverse() {
        if (first.getNext() == last)
            System.out.println("The list is empty. There's nothing to reverse.");
        else {
            Node[] nodes = new Node[size];
            Node temp = first.getNext();
            for (int i = 0; i < size; i++) {
                nodes[i] = temp;
                temp = temp.getNext();
            }
            for (int i = 0; i < size - 1; i++)
                nodes[i + 1].setNext(nodes[i]);
            nodes[0].setNext(null);
            first.setNext(nodes[size - 1]);
            last.setNext(nodes[0]);
        }
    }

    public int getKthFromTheEnd(int k) {

        if (k <= 0 || k > size || first.getNext() == last) return Integer.MIN_VALUE;

        Node temp1 = first.getNext();
        Node temp2 = first.getNext();
        for (int i = 0; i < k - 1; i++)
            temp2 = temp2.getNext();
        while (temp2.getNext() != null) {
            temp1 = temp1.getNext();
            temp2 = temp2.getNext();
        }
        return temp1.getValue();
    }

//    public void reverse() {
//        // a -> b -> c -> d
//
//        // temp1 = first.getNext().getNext() = b;
//        // first.getNext().setNext(first);
//        // temp1.setNext(
//        // if (temp1 == first.getNext()) temp1.setNext(null)
//        // else
//        // Swap first and last ==> tempX = first, first = last, last = temp1
//        LinkedList linkedList = new LinkedList();
//        Node temp = first.getNext();
//        while (temp != null) {
//            linkedList.addFirst(temp.getValue());
//            temp = temp.getNext();
//        }
//        this = linkedList;
//    }
}
