#pragma once
#include <iostream>
#include <string>
#include "employee.hpp"
#include "../attributes/institute.hpp"

class Professor : public Employee {
public:
    Professor() {
        std::cout << "Created Professor - Unknown\n";
    }
        
    Professor(const std::string& name, const std::string& company, const Bill& bill, Institute* institute)
        : Employee(name, company, bill), institute(institute) {
        std::cout << "Created Professor " << 5 << " from Institue " << institute->getName() << "\n";
    }
        
    Professor(const Professor& other) 
        : Employee(other), institute(other.institute) {
        std::cout << "Created Professor " << 5 << " by copy from Institue " << institute->getName() << "\n";
    }

    Professor& operator=(const Professor& p) { 
        if (this != &p) {
            Professor temp(p);
            swap(*this, temp);
        }
        return *this;
    }
    
    virtual ~Professor() {
        std::cout << "Removed Professor " << 5 << " from " << institute->getName() << " Institute";
    }

public:
    virtual void whoami() const override;

public:
    static void swap(Professor& first, Professor& second) noexcept {
        Employee::swap(first, second);
        std::swap(first.institute, second.institute);
    }

private:
    Institute* institute;
};

void Professor::whoami() const {
    std::cout << "I'm Professor " << "5" << " from " << institute->getName() << " Institute\n";
}