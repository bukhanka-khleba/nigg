#include <iostream>
#include <vector>
#include <string>


class Employee {
protected:
    std::string name; 
    double salary;    

public:
    Employee(const std::string& n = "", double s = 0.0) : name(n), salary(s) {}

    virtual void printInfo() const {
        std::cout << "Employee: " << name << ", Salary: " << salary << "\n";
    }

    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    double bonus;  

public:
    Manager(const std::string& n = "", double s = 0.0, double b = 0.0)
        : Employee(n, s), bonus(b) {}

    void printInfo() const override {
        std::cout << "Manager: " << name << ", Salary: " << salary
                  << ", Bonus: " << bonus << ", Total: " << (salary + bonus) << "\n";
    }
};

int main() {
    std::vector<Employee*> employees;

    employees.push_back(new Employee("Alice", 50000));
    employees.push_back(new Manager("Bob", 70000, 15000));
    employees.push_back(new Manager("Charlie", 80000, 20000));

    for (const auto& emp : employees) {
        emp->printInfo();
    }

    for (const auto& emp : employees) {
        delete emp;
    }

    return 0;
}