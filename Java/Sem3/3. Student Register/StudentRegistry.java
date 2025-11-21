import java.util.ArrayList;

public class StudentRegistry {
    private ArrayList<Student> students = new ArrayList<>();

    public void addStudent(Student student) throws DuplicateFacultyNumberException {
        for (Student s : students) {
            if (s.getFacultyNumber().equals(student.getFacultyNumber())) {
                throw new DuplicateFacultyNumberException("A student with this faculty number already exists.");
            }
        }
        students.add(student);
    }

    public void displayStudents() {
        if (students.isEmpty()) {
            System.out.println("No registered students.");
            return;
        }

        for (Student s : students) {
            System.out.println(s);
        }
    }
}
