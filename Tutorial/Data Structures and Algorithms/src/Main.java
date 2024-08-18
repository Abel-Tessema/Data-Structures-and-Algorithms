import java.util.*;

public class Main {
    public static void main(String[] args) {
        BinarySearchTree tree1 = new BinarySearchTree();
        tree1.insert(7);
        tree1.insert(4);
        tree1.insert(9);
        tree1.insert(1);
        tree1.insert(6);
        tree1.insert(8);
        tree1.insert(10);
        System.out.println(tree1.find(4));
        tree1.traversePreOrder();
        tree1.traverseInOrder();
        tree1.traversePostOrder();
        System.out.println("Height: " + tree1.height());
        System.out.println("Min: " + tree1.min());
        System.out.println("Max: " + tree1.max());

        System.out.println("Equals (self): " + tree1.equals(tree1));

        BinarySearchTree tree2 = new BinarySearchTree();
        tree2.insert(7);
        tree2.insert(4);
        tree2.insert(9);
        tree2.insert(1);
        tree2.insert(6);
        tree2.insert(8);
//        tree2.insert(10);

        System.out.println("Equals: " + tree1.equals(tree2));
        System.out.println("Equals: " + tree1.equals(null));

//        BinarySearchTree tree3 = null;
//        System.out.println("Equals: " + tree3.equals(null));

        System.out.println("Is binary tree: " + tree1.isBinarySearchTree());

        tree1.KDistanceNodes(-1);
        tree1.KDistanceNodes(0);
        tree1.KDistanceNodes(1);
        tree1.KDistanceNodes(2);
        tree1.KDistanceNodes(3);

        tree1.traverseLevelOrder();
    }
}

/*
Map
        String string = "a green apple";
        var charArray = string.toCharArray();
        charArray.stream().boxed().collec
        Set<Character> set = new HashSet<>(Arrays.asList(charArray));
        Map<Character, Integer> lettersAndCount = new HashMap<>();
        char ch;
        int count;
        for (char character : charArray) {
            count = 0;
            ch = character;
            for (char c : charArray)
                if (c == ch && !lettersAndCount.containsKey(character))
                    count++;
            lettersAndCount.put(ch, count);
        }
        char firstNonRepeatingCharacter = 0;
        for (var character : lettersAndCount.entrySet())
            if (character.getKey() != ' ' && character.getValue() == 1) {
                firstNonRepeatingCharacter = character.getKey();
                break;
            }


        System.out.println(lettersAndCount);
        System.out.println(firstNonRepeatingCharacter);


        Map<Integer, String> map = new HashMap<>();
        map.put(1, "Abel");
        map.put(2, "Besso");
        map.put(3, "Bela");
        System.out.println(map);
        map.put(3, "Gomette");
        System.out.println(map);
*/

/*
Array Queue
        ArrayQueue queue = new ArrayQueue(3);
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        System.out.println(queue);
//        queue.enqueue(40);
        queue.dequeue();
        System.out.println(queue);
        System.out.println(queue.peek());
        queue.dequeue();
        queue.dequeue();
        System.out.println(queue);
//        queue.dequeue();
        queue.enqueue(40);
        queue.enqueue(50);
        queue.enqueue(60);
        queue.enqueue(70);
        System.out.println(queue);
*/



/* Reversing a Queue
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(10);
        queue.add(20);
        queue.add(30);
        System.out.println(queue);
        reverse(queue);
        System.out.println(queue);

    public static void reverse(Queue<Integer> queue) {
        Queue<Integer> temp = new ArrayDeque<>();
        while (!queue.isEmpty())
            temp.add(queue.remove());
        queue = temp;
    }
*/

/* Stack
        Stack stack = new Stack();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.push(60);
        stack.print();
        stack.pop();
        stack.print();
        System.out.println(stack.peek());
        System.out.println(stack.isEmpty());
        for (int i = 0; i < 5; i++)
            stack.pop();
        stack.print();

*/


/* Balanced Expression
        BalancedExpression balancedExpression = new BalancedExpression();
        String string = ")[1] + <2>(";
        boolean isBalanced = balancedExpression.checkBalance(string);
        System.out.println(isBalanced);
*/

/* String Reverser
        String string = "Bogale";
        StringReverser stringReverser = new StringReverser();
        String reverseString = stringReverser.getReverseString(string);
        System.out.println(reverseString);
*/

/* Linked List
        LinkedList linkedList = new LinkedList();
        linkedList.addFirst(10);
        linkedList.addFirst(20);
        linkedList.addFirst(30);
        linkedList.addFirst(40);
        linkedList.addLast(50);
        linkedList.addLast(60);
        linkedList.deleteFirst();
        System.out.println("Size: " + linkedList.size1());
        System.out.println("Size: " + linkedList.size2());
        linkedList.deleteLast();
        linkedList.print();
        System.out.println(linkedList.contains(30));
        System.out.println(linkedList.contains(40));
//        System.out.println(linkedList.indexOf(50));
        System.out.println(linkedList.indexOf(40));
        System.out.println(linkedList.size1());
        System.out.println(linkedList.size2());
        int[] numbers = linkedList.toArray();
        System.out.println(Arrays.toString(numbers));
        linkedList.reverse();
        System.out.println(linkedList.indexOf(30));
        System.out.println(Arrays.toString(linkedList.toArray()));
        linkedList.reverse();
        System.out.println(Arrays.toString(linkedList.toArray()));
        System.out.println(linkedList.getKthFromTheEnd(1));
        System.out.println(linkedList.getKthFromTheEnd(4));
        System.out.println(linkedList.getKthFromTheEnd(5));
*/

/* Array
        Array numbers = new Array(3);
        numbers.insert(10);
        numbers.insert(20);
        numbers.insert(30);
        numbers.insert(40);
        numbers.insert(50);
        numbers.insert(60);
        numbers.removeAt(0);
        numbers.removeAt(3);
        numbers.insert(10);
        System.out.println(numbers.indexOf(20));
        System.out.println(numbers.indexOf(200));
        numbers.print();
*/