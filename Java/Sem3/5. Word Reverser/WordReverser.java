import java.util.Stack;

public class WordReverser {

    public String reverseWords(String sentence) {
        Stack<String> stack = new Stack<>();

        StringBuilder current = new StringBuilder();
        for (int i = 0; i <= sentence.length(); i++) {
            char c = (i < sentence.length()) ? sentence.charAt(i) : ' ';

            if (c != ' ') {
                current.append(c);
            } else {
                if (current.length() > 0) {
                    stack.push(current.toString());
                    current.setLength(0);
                }
            }
        }

        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.append(stack.pop());
            if (!stack.isEmpty()) result.append(" ");
        }

        return result.toString();
    }
}
