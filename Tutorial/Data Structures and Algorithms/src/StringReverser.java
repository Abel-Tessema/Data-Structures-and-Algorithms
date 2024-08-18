import java.util.Stack;

public class StringReverser {
    public String getReverseString(String string) {
        String reverseString = "";
        Stack<Character> characters = new Stack<>();
        for (int i = 0; i < string.length(); i++)
            characters.push(string.charAt(i));
        for (int i = 0; i < string.length(); i++)
            reverseString = reverseString.concat(String.valueOf(characters.pop()));
        return reverseString;
    }
}
