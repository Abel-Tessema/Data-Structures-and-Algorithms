import java.util.EmptyStackException;
import java.util.Stack;

public class BalancedExpression {
    public boolean checkBalance(String string) {
        if (string == null)
            throw new IllegalArgumentException();

        try {
            Stack<Character> stack = new Stack<>();
            for (char ch : string.toCharArray()) {
                if (ch == '(' || ch == '[' || ch == '{' || ch == '<')
                    stack.push(ch);
                else if (ch == ')') {
                    if (stack.pop() != '(')
                        return false;
                } else if (ch == ']') {
                    if (stack.pop() != '[')
                        return false;
                } else if (ch == '}') {
                    if (stack.pop() != '{')
                        return false;
                } else if (ch == '>') {
                    if (stack.pop() != '<')
                        return false;
                }
            }
            return stack.empty();
        } catch (EmptyStackException e) {
            return false;
        }
    }
}
