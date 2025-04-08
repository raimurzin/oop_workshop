#pragma once
#include <iostream>
#include <string>

class Person {
public:
    Person() : name("Unknown") {
        std::cout << "Created Person - Unknown\n";
    }
    Person(std::string name) : name(name) {
        std::cout << "Created Person - " + name + "\n";
    }
    Person(const Person& p) : name(p.name) {
        std::cout << "Created Person by copy - " + name + "\n";
    }
    Person& operator=(const Person& p) { 
        if (this != &p) {
            Person temp(p);
            swap(*this, temp);
        }
        return *this;
    }
    virtual ~Person() {
        std::cout << "Removed Person - " + name + "\n";
    }
public:
    virtual void whoami() const;

public:
    static void swap(Person& first, Person& second) noexcept {
        std::swap(first.name, second.name);
    }
protected:
    std::string name;
};

void Person::whoami() const {
    std::cout <<  "I`m " << name << "\n";
}