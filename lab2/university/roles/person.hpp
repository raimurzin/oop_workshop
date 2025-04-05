#pragma once
#include <iostream>

enum class Gender {
    Man, // Мужчина
    Woman // Женщина
};

enum class ActivismType {
    Sportsmen, // Спортсмен
    HostelVolunteer // Помощник в общежитии
};

class Person {
public:
    Person() {
        std::cout << "Created Unknown Person\n";
    }
    Person(uint age, uint gender, std::string name) : age(age), gender(gender), name(name) {}
    Person(const Person& p) : age(p.age), gender(p.gender), name(p.name) {}
    Person& operator=(const Person& p) { 
        if (this != &p) {
            Person temp(p);
            swap(*this, temp);
        }
        return *this;
    }
    virtual ~Person() {
        std::cout << "Removed " + (name.empty() ? "Unknown Person" : name) + "\n";
    }
public:
    virtual std::string whoami() const;
private:
    void swap(Person& first, Person& second) noexcept {
        using std::swap;
        swap(first.age, second.age);
        swap(first.gender, second.gender);
        swap(first.name, second.name);
    }
private:
    uint age;
    uint gender;
    std::string name;
};

std::string Person::whoami() const {
    std::cout << "I`m " + (name.empty() ? "Unknown Person" : name) + "\n";
    return {};
}