#pragma once
#include <iostream>
#include <string>
#include "employee.hpp"
#include "institute.hpp"

class Professor : public Employee {
public:
    Professor() {
        std::cout << "Created Professor - Unknown\n";
    }
        
    Professor(const std::string& name, const std::string& company, const Bill& bill, Institute& institute)
        : Employee(name, company, bill), institute(&institute) {
        std::cout << "Created Professor " << name << " from Institue " << institute->getName() << "\n";
    }
        
    Professor(const Professor& other) 
        : Employee(other), institute(other.institute) {
        std::cout << "Created Professor " << name << " by copy from Institue " << institute->getName() << "\n";
    }

    Professor& operator=(const Professor& p) { 
        if (this != &p) {
            Professor temp(p);
            swap(*this, temp);
        }
        return *this;
    }
    
    virtual ~Professor() {
        std::cout << "Removed Professor " << name << " from " << Institute << "Institute";
    }

public:
    virtual std::string whoami() const override;

public:
    static void swap(Professor& first, Professor& second) noexcept {
        Employee::swap(first, second);
        std::swap(first.institute, second.institute);
    }

private:
    Institute& institute;
};

std::string Professor::whoami() const override {
    return "I'm Professor " << name << " from " << Institute << "Institute";
}