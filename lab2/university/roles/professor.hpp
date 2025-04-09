#pragma once
#include <iostream>
#include <string>
#include "employee.hpp"
#include "../attributes/institute.hpp"

class Professor : public Employee {
public:
    Professor() : institute(nullptr) {
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
        if (institute != nullptr) {
            std::cout << "Removed Professor " << 5 << " from " << institute->getName() << " Institute";
        } else {
            std::cout << "Removed Unknown Professor\n";
        }
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
    if (institute != nullptr) {
        std::cout << "I'm Professor " << "5" << " from " << institute->getName() << " Institute\n";
    } else {
        std::cout << "I'm Unknown Professor\n";
    }
}