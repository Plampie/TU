class Person:
    def __init__(self, name, family, age, nationality):
        self.name = name
        self.family = family
        self.age = age
        self.nationality = nationality
        
    def print(self):
        print(f"Name: {self.name} {self.family}")
        print(f"Nationality: {self.nationality}")
        
class Student(Person):
    def __init__(self, name, family, age, nationality, university, yearofstudy):
        super().__init__(name, family, age, nationality)
        self.university = university
        self.yearofstudy = yearofstudy
    
    def print(self):
        super().print()
        print(f"University: {self.university} ")
        print(f"Year of Study: {self.yearofstudy}")
        
class Lecturer(Person):
    def __init__(self, name, family, age, nationality, university, experience):
        super().__init__(name, family, age, nationality)
        self.university = university
        self.experience = experience
        
    def print(self):
        super().print()
        print(f"Universsity: {self.university}")
        print(f"Experience: {self.experience}")
    
p1 = Person('Plamena', 'Georgieva', 25, 'Bulgarian')
p1.print()

s1 = Student('Georgi', 'Stemenov', 19, 'Bulgarian', 'TU', 2024)
s1.print()

l1 = Lecturer('Kamen', 'Illiev', 36, 'Bulgarian', 'TU', 7)
l1.print()