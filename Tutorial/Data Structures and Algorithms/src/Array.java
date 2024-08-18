public class Array {
    private int[] numbers;
    private int length;
    private int size = 0;

    public Array(int size) {
        this.length = size;
        numbers = new int[size];
    }

    public void insert(int number) {
        if (size < length) {
            numbers[size] = number;
            size++;
        } else {
            length++;
            int[] temp = numbers;
            numbers = new int[length];
            for (int i = 0; i < size; i++)
                numbers[i] = temp[i];
            numbers[size] = number;
            size++;
        }
    }

    public int removeAt(int index) {
        int removedNumber = numbers[index];
        int[] temp = new int[length];
        for (int i = index; i < length - 1; i++)
            numbers[i] = numbers[i + 1];
        size--;
        temp = numbers;
        numbers = new int[--length];
        for (int i = 0; i < length; i++)
            numbers[i] = temp[i];
        return removedNumber;
    }

    public int indexOf(int number) {
        for (int i = 0; i < length; i++)
            if (numbers[i] == number)
                return i;
        return -1;
    }

    public int length() {
        return length;
    }
    public void print() {
        for (int number : numbers)
            System.out.println(number);
    }
}
