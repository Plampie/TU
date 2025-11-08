public class Employee {
    private String name;        
    private String employeeId;  
    private int experience;     
    private String email;       

    public Employee(String name, String employeeId, int experience, String email) {
        this.name = name;
        this.employeeId = employeeId;
        this.experience = experience;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public String getEmployeeId() {
        return employeeId;
    }

    public int getExperience() {
        return experience;
    }

    public String getEmail() {
        return email;
    }

    @Override
    public String toString() {
        return String.format(
            "Name: %s | Employee ID: %s | Experience: %d years | E-mail: %s",
            name, employeeId, experience, email
        );
    }
}

