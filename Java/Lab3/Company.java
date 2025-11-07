import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Company {

    private String companyName;      
    private String domain;            
    private List<Employee> employees; 

    private static final Pattern EMP_ID_PATTERN = Pattern.compile("^EMP-\\d{5}$");

    public Company(String companyName, String domain) {
        this.companyName = companyName;
        this.domain = domain;
        this.employees = new ArrayList<>();
    }

    // Getters & setters
    public String getCompanyName() { return companyName; }
    public void setCompanyName(String companyName) { this.companyName = companyName; }

    public String getDomain() { return domain; }
    public void setDomain(String domain) { this.domain = domain; }

    public List<Employee> getEmployees() { return employees; }
    public void setEmployees(List<Employee> employees) { this.employees = employees; }

    /**
     * Adds an employee after validating:
     * - name must not be empty/blank
     * - employeeId must match ^EMP-\d{5}$
     * - email must belong to this company's domain
     * - experience must be > 1 (insurance eligibility)
     */
    public void addEmployee(Employee e)
            throws InvalidEmailException, EmployeeNotEligibleException {

        if (e == null) {
            throw new IllegalArgumentException("Employee cannot be null.");
        }

        if (e.getName() == null || e.getName().trim().isEmpty()) {
            throw new IllegalArgumentException("Name cannot be empty.");
        }

        if (!isValidEmployeeId(e.getEmployeeId())) {
            throw new IllegalArgumentException("Invalid employee ID. Expected format: EMP-#####");
        }

        if (!validateEmail(e.getEmail())) {
            throw new InvalidEmailException(
                "Invalid e-mail. It must belong to the company domain: @" + domain
            );
        }

        // experience > 1
        checkInsuranceEligibility(e);

        employees.add(e);
    }

    /**
     * Lists all employees in the company.
     */
    public void listEmployees() {
        if (employees.isEmpty()) {
            System.out.println("No employees registered yet.");
            return;
        }
        System.out.println("=== Employees ===");
        for (int i = 0; i < employees.size(); i++) {
            System.out.printf("%d) %s%n", i + 1, employees.get(i));
        }
    }

    /**
     * Finds an employee by their ID.
     * @throws EmployeeNotFoundException if no employee with the given ID exists
     */
    public Employee findById(String id) throws EmployeeNotFoundException {
        for (Employee e : employees) {
            if (e.getEmployeeId() != null && e.getEmployeeId().equals(id)) {
                return e;
            }
        }
        throw new EmployeeNotFoundException("Employee with ID '" + id + "' was not found.");
    }

    /**
     * Validates if the email belongs to the company's domain.
     * Dynamic regex: ^[\w.-]+@<domain>$
     */
    public boolean validateEmail(String email) {
        if (email == null || email.isEmpty() || domain == null || domain.isEmpty()) return false;

        // Build dynamic email pattern: ^[\w.-]+@<escaped-domain>$
        String domainQuoted = Pattern.quote(domain);
        String emailRegex = "^[\\w.-]+@" + domainQuoted + "$";

        return Pattern.compile(emailRegex).matcher(email).matches();
    }

    /**
     * Checks if the employee is eligible for group insurance.
     * Throws EmployeeNotEligibleException if experience <= 1.
     */
    public void checkInsuranceEligibility(Employee e) throws EmployeeNotEligibleException {
        if (e == null) return;
        if (e.getExperience() <= 1) {
            throw new EmployeeNotEligibleException(
                "Employee is not eligible for group insurance (experience must be > 1 year)."
            );
        }
    }

    
    // helpers
    private boolean isValidEmployeeId(String id) {
        if (id == null) return false;
        Matcher m = EMP_ID_PATTERN.matcher(id);
        return m.matches();
    }



    @Override
    public String toString() {
        return String.format(
            "Company name: %s | Domain: %s | Employees: %d",
            companyName, domain, employees.size()
        );
    }
}
