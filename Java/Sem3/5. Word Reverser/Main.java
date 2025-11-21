import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        WordReverser reverser = new WordReverser();

        System.out.println("Enter a sentence:");
        String sentence = scanner.nextLine();

        String reversed = reverser.reverseWords(sentence);
        System.out.println(reversed);
    }
}
