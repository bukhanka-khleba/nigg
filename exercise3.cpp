#include <iostream>
#include <string>

class Person {
protected:
    std::string name;  
    int age;           

public:
    Person(const std::string& n = "", int a = 0) : name(n), age(a) {}

    virtual void printInfo() const {
        std::cout << "Person: " << name << ", Age: " << age << "\n";
    }

    virtual ~Person() = default;
};


class Student : public virtual Person {
protected:
    std::string university;

public:
    Student(const std::string& n = "", int a = 0, const std::string& u = "")
        : Person(n, a), university(u) {}

    void printInfo() const override {
        std::cout << "Student: " << name << ", Age: " << age
                  << ", University: " << university << "\n";
    }
};

class Worker : public virtual Person {
protected:
    std::string company;  

public:
    Worker(const std::string& n = "", int a = 0, const std::string& c = "")
        : Person(n, a), company(c) {}

    void printInfo() const override {
        std::cout << "Worker: " << name << ", Age: " << age
                  << ", Company: " << company << "\n";
    }
};

class Intern : public Student, public Worker {
public:
    Intern(const std::string& n = "", int a = 0, const std::string& u = "", const std::string& c = "")
        : Person(n, a), Student(n, a, u), Worker(n, a, c) {}

    void printInfo() const override {
        std::cout << "Intern: " << name << ", Age: " << age
                  << ", University: " << university
                  << ", Company: " << company << "\n";
    }
};

int main() {

    Person person("Alice", 30);
    Student student("Bob", 22, "MIT");
    Worker worker("Charlie", 40, "Google");
    Intern intern("David", 25, "Harvard", "Microsoft");

    person.printInfo();
    student.printInfo();
    worker.printInfo();
    intern.printInfo();

    return 0;
}