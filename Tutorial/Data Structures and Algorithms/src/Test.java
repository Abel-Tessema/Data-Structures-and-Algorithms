import java.util.ArrayList;

public class Test {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(0);
        list.add(4);
        list.removeIf(n -> n == 0);
        System.out.println(list);
    }
}
