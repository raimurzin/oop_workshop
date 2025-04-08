#include <iostream>
#include "university/roles/person.hpp"
#include "university/roles/student.hpp"
#include "university/roles/employee.hpp"
#include "university/roles/professor.hpp"
#include "university/attributes/bill.hpp"
#include "university/attributes/institute.hpp"

void test1() {
    // Тест на статическое создание объектов
    std::cout << "\nСоздание объекта класса Person\n";
    {
        Person p2;
        Person p("Johny B");
    }
    std::cout << "\n______________________________________\n";
    {
        Person p("Alice");
    }
    std::cout << "\n______________________________________\n";
    {
        Person p("Alice");
    }
    std::cout << "\n______________________________________\n";
    {
        Person p("Alice");
    }
    std::cout << "\n______________________________________\n";
    {
        Person p("Alice");
    }
    std::cout << "\n______________________________________\n";
}

void test2() {
    // Тест на динамическое создание объектов
}

void test3() {
    // Тест на композицию и агрегацию
}


int main() {
    Person p;
    return 0;
}