import java.util.LinkedList;

public class CommandProcessor {
    private LinkedList<Integer> numbers = new LinkedList<>();

    public void process(String input) throws InvalidCommandException {
        String[] parts = split(input);
        if (parts.length == 0) {
            throw new InvalidCommandException("Invalid command!");
        }

        String cmd = parts[0];

        if (cmd.equals("add")) {
            if (parts.length != 2 || !isNumber(parts[1])) {
                throw new InvalidCommandException("Invalid command!");
            }
            numbers.add(Integer.parseInt(parts[1]));

        } else if (cmd.equals("remove")) {
            if (parts.length != 2 || !isNumber(parts[1])) {
                throw new InvalidCommandException("Invalid command!");
            }
            Integer value = Integer.parseInt(parts[1]);
            numbers.remove(value);

        } else if (cmd.equals("print")) {
            if (parts.length != 1) {
                throw new InvalidCommandException("Invalid command!");
            }
            if (numbers.isEmpty()) {
                System.out.println("The list is empty.");
            } else {
                for (Integer num : numbers) {
                    System.out.print(num + " ");
                }
                System.out.println();
            }

        } else if (cmd.equals("exit")) {
            if (parts.length != 1) {
                throw new InvalidCommandException("Invalid command!");
            }
            System.exit(0);

        } else {
            throw new InvalidCommandException("Invalid command!");
        }
    }

    private String[] split(String input) {
        int countSpaces = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == ' ') countSpaces++;
        }
        String[] result = new String[countSpaces + 1];

        StringBuilder current = new StringBuilder();
        int index = 0;

        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);

            if (c == ' ') {
                result[index] = current.toString();
                current.setLength(0);
                index++;
            } else {
                current.append(c);
            }
        }
        result[index] = current.toString();

        return result;
    }

    private boolean isNumber(String s) {
        if (s.length() == 0) return false;
        for (int i = 0; i < s.length(); i++) {
            if (!Character.isDigit(s.charAt(i)) && !(i == 0 && s.charAt(i) == '-')) {
                return false;
            }
        }
        return true;
    }
}
