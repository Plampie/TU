import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StudentRegistry registry = new StudentRegistry();

        while (true) {
            System.out.println("\n1. Add student");
            System.out.println("2. Display all students");
            System.out.println("3. Exit");

            int choice = scanner.nextInt();
            scanner.nextLine();

            if (choice == 1) {
                System.out.println("Enter name:");
                String name = scanner.nextLine();

                System.out.println("Enter faculty number:");
                String facultyNumber = scanner.nextLine();

                System.out.println("Enter major:");
                String major = scanner.nextLine();

                Student st = new Student(name, facultyNumber, major);

                try {
                    registry.addStudent(st);
                    System.out.println("Student added successfully.");
                } catch (DuplicateFacultyNumberException e) {
                    System.out.println("Error: " + e.getMessage());
                }

            } else if (choice == 2) {
                registry.displayStudents();
            } else if (choice == 3) {
                System.out.println("Exiting...");
                break;
            } else {
                System.out.println("Invalid option.");
            }
        }
    }
}
