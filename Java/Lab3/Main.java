import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        Company company = null;

        while (true) {
            printMenu();

            String choice = prompt("Choose an option (1-5): ");
            switch (choice) {
                case "1":
                    company = createCompany();
                    break;

                case "2":
                    if (company == null) {
                        System.out.println("Please create a company first (option 1).");
                        break;
                    }
                    handleAddEmployee(company);
                    break;

                case "3":
                    if (company == null) {
                        System.out.println("Please create a company first (option 1).");
                        break;
                    }
                    company.listEmployees();
                    break;

                case "4":
                    if (company == null) {
                        System.out.println("Please create a company first (option 1).");
                        break;
                    }
                    handleFindEmployee(company);
                    break;

                case "5":
                    System.out.println("Exiting. Goodbye!");
                    return;

                default:
                    System.out.println("Invalid choice. Please select 1-5.");
            }
            System.out.println();
        }
    }

// main menu
    private static Company createCompany() {
        System.out.println("=== Enter Company Information ===");
        String name;
        while (true) {
            name = prompt("Company name: ");
            if (!name.trim().isEmpty()) break;
            System.out.println("Company name cannot be empty. Please try again.");
        }

        String domain;
        while (true) {
            domain = prompt("Company e-mail domain (e.g., example.com): ");
            if (!domain.trim().isEmpty()) break;
            System.out.println("Domain cannot be empty. Please try again.");
        }

        Company company = new Company(name.trim(), domain.trim());
        System.out.println("Company created: " + company);
        return company;
    }

    private static void handleAddEmployee(Company company) {
        System.out.println("=== Add Employee ===");

        while (true) {
            try {
                String name = prompt("Name: ").trim();
                String id = prompt("Employee ID (format EMP-#####): ").trim();
                int exp = readIntWithRetry();
                String email = prompt("E-mail (must be in @" + company.getDomain() + "): ").trim();

                Employee e = new Employee(name, id, exp, email);
                company.addEmployee(e);

                System.out.println("Employee added successfully.");
                break;

            } catch (InvalidEmailException | EmployeeNotEligibleException | IllegalArgumentException ex) {
                System.out.println("Error: " + ex.getMessage());
                System.out.println("Please try again.\n");

            } catch (Exception ex) {
                System.out.println("Unexpected error: " + ex.getMessage());
                System.out.println("Please try again.\n");
            }
        }
    }

    private static void handleFindEmployee(Company company) {
        System.out.println("=== Find Employee by ID ===");
        String id = prompt("Enter employee ID (format EMP-#####): ").trim();
        try {
            Employee found = company.findById(id);
            System.out.println("Found: " + found);
        } catch (EmployeeNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

  
// helpers
    private static void printMenu() {
        System.out.println("==== Group Insurance Registration ====");
        System.out.println("1. Enter company");
        System.out.println("2. Add employee");
        System.out.println("3. List all employees");
        System.out.println("4. Find employee by ID");
        System.out.println("5. Exit");
    }

    private static String prompt(String label) {
        System.out.print(label);
        return scanner.nextLine();
    }

    private static int readIntWithRetry() {
        while (true) {
            String s = prompt("Years of experience (number): ");
            try {
                return Integer.parseInt(s.trim());
            } catch (NumberFormatException nfe) {
                System.out.println("Invalid number. Please enter a valid integer.");
            }
        }
    }
}
