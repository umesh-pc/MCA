
class Person:
    def __init__(self, name, roll):
        self.name = name
        self.roll = roll


class Marks:
    def __init__(self, maths, computer):
        self.maths = maths
        self.computer = computer


class Student(Person, Marks):
    def __init__(self, name, roll, maths, computer):
        Person.__init__(self, name, roll)
        Marks.__init__(self, maths, computer)

    def calculate_percentage(self):
        total_marks = self.maths + self.computer
        percentage = (total_marks / 100) * 100  
        return percentage

    def display(self):
        print(f"Name: {self.name}")
        print(f"Roll: {self.roll}")
        print(f"Maths Marks: {self.maths}/50")
        print(f"Computer Marks: {self.computer}/50")
        percentage = self.calculate_percentage()
        result = "Pass" if percentage >= 50 else "Fail"
        print(f"Percentage: {percentage:.2f}% - Result: {result}")



def compare_students(student1, student2):
    p1 = student1.calculate_percentage()
    p2 = student2.calculate_percentage()

    if p1 > p2:
        print(f"\n{student1.name} has a higher percentage ({p1:.2f}%) than {student2.name} ({p2:.2f}%).")
    elif p2 > p1:
        print(f"\n{student2.name} has a higher percentage ({p2:.2f}%) than {student1.name} ({p1:.2f}%).")
    else:
        print(f"\nBoth {student1.name} and {student2.name} have the same percentage ({p1:.2f}%).")



print("Enter details for Student 1:")
name1 = input("Name: ")
roll1 = input("Roll number: ")
maths1 = float(input("Maths marks (out of 50): "))
computer1 = float(input("Computer marks (out of 50): "))
student1 = Student(name1, roll1, maths1, computer1)

print("\nEnter details for Student 2:")
name2 = input("Name: ")
roll2 = input("Roll number: ")
maths2 = float(input("Maths marks (out of 50): "))
computer2 = float(input("Computer marks (out of 50): "))
student2 = Student(name2, roll2, maths2, computer2)


print("\nStudent 1 Details:")
student1.display()

print("\nStudent 2 Details:")
student2.display()


compare_students(student1, student2)
