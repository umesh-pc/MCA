class Person:
    def __init__(self, name, phno):
        self.name = name
        self.phno = phno


class Dept:
    def __init__(self, dept_name, location):
        self.dept_name = dept_name
        self.location = location


class Employee(Person, Dept):
    def __init__(self, name, phno, dept_name, location, designation, salary):
        Person.__init__(self, name, phno)
        Dept.__init__(self, dept_name, location)
        self.designation = designation
        self.salary = salary

    def display_details(self):
        incremented_salary = self.salary + (self.salary * 0.10)

        print("\n----- Employee Details -----")
        print(f"Name: {self.name}")
        print(f"Phone Number: {self.phno}")
        print(f"Department: {self.dept_name}")
        print(f"Location: {self.location}")
        print(f"Designation: {self.designation}")
        print(f"Original Salary: {self.salary}")
        print(f"Salary after 10% increment: {incremented_salary:.2f}")


# ----- Taking input from user -----
name = input("Enter employee name: ")
phno = input("Enter phone number: ")
dept_name = input("Enter department name: ")
location = input("Enter department location: ")
designation = input("Enter designation: ")
salary = float(input("Enter salary: "))

# Create Employee object
emp = Employee(name, phno, dept_name, location, designation, salary)

# Display employee details
emp.display_details()
