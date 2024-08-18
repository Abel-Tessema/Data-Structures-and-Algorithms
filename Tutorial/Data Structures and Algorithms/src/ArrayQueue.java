import java.util.ArrayDeque;

public class ArrayQueue {
    private int[] numbers;
    private int front;
    private int rear = -1;

    public ArrayQueue(int size) {
        numbers = new int[size];
    }

    public void enqueue(int number) {
        if (isFull())
            throw new IllegalStateException();
        if (front != 0) {
            for (int i = 1; i < numbers.length; i++)
                numbers[i - 1] = numbers[i];
            front--;
            rear--;
        }

        numbers[++rear] = number;
    }

    public int dequeue() {
        if (isEmpty())
            throw new IllegalStateException();

        return numbers[front++];
    }

    public int peek() {
        return numbers[front];
    }

    public boolean isEmpty() {
        return front > rear;
    }

    public boolean isFull() {
        return rear - front == numbers.length - 1;
    }

    @Override
    public String toString() {
        if (isEmpty())
            return "[]";
        StringBuilder builder = new StringBuilder();
        for (int i = front; i < rear; i++)
            builder.append(numbers[i]).append(", ");
        return "[" + builder + numbers[rear] + "]";
    }
}
