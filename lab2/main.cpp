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
        Student p2("Johny B", 3, 3, "UUST", "IIMRT");
    }
    std::cout << "\n______________________________________\n\n";
    {
        Student p2("Johny B", 3, 3, "UUST", "IIMRT");
        Student p3(p2);
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
        Bill bill = Bill(70000, "Gazprom");
        Professor prf2("Johny B", "UUST", bill, "UUST", "IIMRT");
    }
    std::cout << "\n______________________________________\n\n";
    {
        Bill bill = Bill(70000, "Gazprom");
        Professor prf2("Johny B", "UUST", bill, "UUST", "IIMRT");
        Professor prf3(prf2);
    }
    std::cout << "\n______________________________________\n\n";
}

void test2() {
    std::cout << "-------------->Check test 2\n\n";
    {
        Person* person = new Student("Johny B", 3, 3, "UUST", "IIMRT");
        person->whoami();
        delete person;
    }
    std::cout << "\n______________________________________\n\n";
    {
        Bill bill = Bill(70000, "Gazprom");

        std::vector<Person*> v(3);
        v[0] = new Employee("Johny B", "MTC", bill);
        v[1] = new Student("Maria B", 3, 3, "UUST", "IIMRT");
        v[2] = new Professor("Johny B", "UUST", bill, "UUST", "IIMRT");

        v[0]->whoami();
        v[1]->whoami();
        v[2]->whoami();

        for (auto el : v) {
            delete el;
        }
    }
    std::cout << "\n______________________________________\n\n";
    {
        Bill bill = Bill(70000, "Gazprom");

        std::vector<Person> v(3);
        v[0] = Employee("Johny B", "MTC", bill);
        v[1] = Student("Maria B", 3, 3, "UUST", "IIMRT");
        v[2] = Professor("Johny B", "UUST", bill, "UUST", "IIMRT");

        v[0].whoami();
        v[1].whoami();
        v[2].whoami();
    }
}

int main() {
    //Student prf;
    test1();
    test2();
    //Professor p;
    return 0;
}