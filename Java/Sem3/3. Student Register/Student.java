public class Student {
    private String name;
    private String facultyNumber;
    private String major;

    public Student(String name, String facultyNumber, String major) {
        this.name = name;
        this.facultyNumber = facultyNumber;
        this.major = major;
    }

    public String getFacultyNumber() {
        return facultyNumber;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Faculty number: " + facultyNumber + ", Major: " + major;
    }
}
