#pragma once
#include <iostream>
#include <string>
#include "person.hpp"
#include "../attributes/institute.hpp"

class Student : public Person {
public:
    Student() {
        std::cout << "Created Student - Unknown\n";
    }
        
    Student(const std::string& name, uint course, uint group, const Institute& institute)
        : Person(name), course(course), group(group), institute(institute) {
        std::cout << "Created Student " << name << ", Course " << course << ", Group " << group << ", Institute: " << institute.getName() << "\n";
    }
        
    Student(const Student& other) 
        : Person(other), course(other.course), group(other.group), institute(other.institute) {
        std::cout << "Created Student by copy - Course " << course << ", Group " << group << "\n";
    }

    Student& operator=(const Student& p) { 
        if (this != &p) {
            Student temp(p);
            swap(*this, temp);
        }
        return *this;
    }
    virtual ~Student() {
        std::cout << "Removed Student " << Person::name << " - Course " << course << ", Group " << group << "\n";
    }
public:
    virtual std::string whoami() const override;

public:
    static void swap(Student& first, Student& second) noexcept {
        std::swap(first.name, second.name);
        std::swap(first.course, second.course);
        Institute::swap(first.institute, second.institute);
    }
private:
    uint course;
    uint group;
    Institute& institute; 
};

std::string Student::whoami() const override {
    return "I'm Student " << Person::name << " - Course " << course << " of institute " + institute.getName() << "\n";
}