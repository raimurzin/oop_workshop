#include <iostream>
#include <unordered_map>

enum class Gender {
    Man,
    Woman
}

enum class ActivismType {
    Sportsmen, // Спортсмен
    HostelVolunteer // Помощник в общежитии
}

class Person {
public:
    Person() = default;
    Person(uing age, uint gender) : age(age), gender(gender) {}
    Person(const Person& p) : age(p.age), gender(p.gender) {}
    Person& operator=(const Person& p) { return Person(p); }
    ~Person() = default;
private:
    uint age;
    uint gender; 
};

class Employee : public Person {
public:

private:
    uint salary;
    std::string company; // Название компании
    std::string position; // Должность в компании
};

class Student : public Person {
public:

private:
    uint grade; // Курс стеднта
    uint grant; // Размер стипендии студента
    std::string speciality; // Специальность студента
};

class Activist : public Person {
public:

private:
    uint activismType;
};

class WorkingStudent : public Employee, Student {

};

class Superman : public Employee, Student, Activist {

};