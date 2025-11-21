import java.util.Scanner;

public class TextProcessor {

    public void run() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a sentence:");
        String input = scanner.nextLine();

        int wordCount = countWords(input);
        System.out.println("Word count: " + wordCount);

        String longest = findLongestWord(input);
        System.out.println("Longest word: " + longest);

        String reversedWords = reverseWords(input);
        System.out.println("Words reversed: " + reversedWords);
    }

    private int countWords(String text) {
        int count = 0;
        boolean insideWord = false;

        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);

            if (c != ' ' && !insideWord) {
                insideWord = true;
                count++;
            } else if (c == ' ') {
                insideWord = false;
            }
        }

        return count;
    }

    private String findLongestWord(String text) {
        StringBuilder current = new StringBuilder();
        String longest = "";

        for (int i = 0; i <= text.length(); i++) {
            char c = (i < text.length()) ? text.charAt(i) : ' ';

            if (c != ' ') {
                current.append(c);
            } else {
                if (current.length() > longest.length()) {
                    longest = current.toString();
                }
                current.setLength(0);
            }
        }

        return longest;
    }

    private String reverseWords(String text) {
        StringBuilder result = new StringBuilder();
        StringBuilder current = new StringBuilder();

        for (int i = 0; i <= text.length(); i++) {
            char c = (i < text.length()) ? text.charAt(i) : ' ';

            if (c != ' ') {
                current.append(c);
            } else {
                result.append(reverseString(current.toString()));
                if (i < text.length()) {
                    result.append(" ");
                }
                current.setLength(0);
            }
        }

        return result.toString();
    }

    private String reverseString(String s) {
        StringBuilder reversed = new StringBuilder();

        for (int i = s.length() - 1; i >= 0; i--) {
            reversed.append(s.charAt(i));
        }

        return reversed.toString();
    }
}
