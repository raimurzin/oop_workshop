#include <iostream>
#include <vector>
#include "university/roles/person.hpp"
#include "university/roles/student.hpp"
#include "university/roles/employee.hpp"
#include "university/roles/professor.hpp"
#include "university/attributes/bill.hpp"
#include "university/attributes/institute.hpp"

void test1() {
    std::cout << "-------------->Check test 1\n\n";
    {
        Person p;
    }
    std::cout << "\n______________________________________\n\n";
    {
        Person p2("Johny B");
    }
    std::cout << "\n______________________________________\n\n";
    {
        Person p2("Johny B");
        Person p3(p2);
    }
    std::cout << "\n______________________________________\n\n";
    {
        Student p;
    }
    std::cout << "\n______________________________________\n\n";
    {
        Institute* iimrt = new Institute("UUST", "IIMRT");
        Student p2("Johny B", 3, 3, iimrt);
        delete iimrt;
    }
    std::cout << "\n______________________________________\n\n";
    {
        Institute* iimrt = new Institute("UUST", "IIMRT");
        Student p2("Johny B", 3, 3, iimrt);
        Student p3(p2);
        delete iimrt;
    }
    std::cout << "\n______________________________________\n\n";
    {
        Employee e;
    }
    std::cout << "\n______________________________________\n\n";
    {
        Bill bill = Bill(70000, "Gazprom");
        Employee e2("Johny B", "MTC", bill);
    }
    std::cout << "\n______________________________________\n\n";
    {
        Bill bill = Bill(70000, "Gazprom");
        Employee e2("Johny B", "MTC", bill);
        Employee e3(e2);
    }
    std::cout << "\n______________________________________\n\n";
    {
        Professor prf;
    }
    std::cout << "\n______________________________________\n\n";
    {
        Institute iimrt = Institute("UUST", "IIMRT");
        Bill bill = Bill(70000, "Gazprom");
        Professor prf2("Johny B", "UUST", bill, &iimrt);
    }
    std::cout << "\n______________________________________\n\n";
    {
        Institute iimrt = Institute("UUST", "IIMRT");
        Bill bill = Bill(70000, "Gazprom");
        Professor prf2("Johny B", "UUST", bill, &iimrt);
        Professor prf3(prf2);
    }
    std::cout << "\n______________________________________\n\n";
}

void test2() {
    std::cout << "-------------->Check test 2\n\n";
    {
        Institute* iimrt = new Institute("UUST", "FIRT");
        Person* person = new Student("Johny B", 3, 3, iimrt);
        person->whoami();
        iimrt->setName("IIMRT");
        delete person;
        delete iimrt;
    }
    std::cout << "\n______________________________________\n\n";
    {
        Institute iimrt = Institute("UUST", "FIRT");
        Bill bill = Bill(70000, "Gazprom");

        std::vector<Person*> v(3);
        v[0] = new Employee("Johny B", "MTC", bill);
        v[1] = new Student("Maria B", 3, 3, &iimrt);
        v[2] = new Professor("Johny B", "UUST", bill, &iimrt);

        v[0]->whoami();
        v[1]->whoami();
        v[2]->whoami();

        for (auto el : v) {
            delete el;
        }
    }
    std::cout << "\n______________________________________\n\n";
    {
        Institute iimrt = Institute("UUST", "FIRT");
        Bill bill = Bill(70000, "Gazprom");

        std::vector<Person> v(3);
        v[0] = Employee("Johny B", "MTC", bill);
        v[1] = Student("Maria B", 3, 3, &iimrt);
        v[2] = Professor("Johny B", "UUST", bill, &iimrt);

        v[0].whoami();
        v[1].whoami();
        v[2].whoami();
    }
}

int main() {
    test1();
    test2();
    return 0;
}