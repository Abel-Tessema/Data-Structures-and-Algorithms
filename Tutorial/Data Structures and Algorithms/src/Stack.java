import java.util.EmptyStackException;

public class Stack {
    private int[] numbers;
    private int size = 0;
    private int last;
    public Stack () {
        numbers = new int[5];
    }

    public void push(int number) {
        if (size == numbers.length) {
            int[] temp = new int[size * 2];
            for (int i = 0; i < size; i++)
                temp[i] = numbers[i];
            numbers = temp;
        }
        numbers[size++] = number;
    }

    public int pop() {
        if (isEmpty())
            throw new EmptyStackException();
        size--;
        return numbers[size];
    }

    public int peek() {
        return numbers[size - 1];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("[]");
            return;
        }
        System.out.print("[");
        for (int i = 0; i < size - 1; i++)
            System.out.print(numbers[i] + ", ");
        System.out.println(numbers[size - 1] + "]");
    }
}
