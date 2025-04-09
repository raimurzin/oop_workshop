#pragma once
#include <iostream>
#include <string>
#include "employee.hpp"
#include "../attributes/institute.hpp"

class Professor : public Employee {
public:
    Professor() : institute(new Institute()) {
        std::cout << "Created Professor - Unknown\n";
    }
        
    Professor(const std::string& name, const std::string& company, const Bill& bill, const std::string& unver_name, const std::string& department) :
        Employee(name, company, bill),
        institute(new Institute(unver_name, department)) {
        std::cout << "Created Professor " << " from Institue " << unver_name << "\n";
    }
        
    Professor(const Professor& other) :
        Employee(other),
        institute(new Institute(*other.institute)) {
        std::cout << "Created Professor " << " by copy from Institue " << institute->getName() << "\n";
    }

    Professor& operator=(const Professor& p) { 
        if (this != &p) {
            Professor temp(p);
            swap(*this, temp);
        }
        return *this;
    }
    
    virtual ~Professor() {
        std::cout << "Removed Professor " << " from " << institute->getName() << " Institute";
        delete institute;
    }

public:
    virtual void whoami() const override;

public:
    static void swap(Professor& first, Professor& second) noexcept {
        Employee::swap(first, second);
        std::swap(first.institute, second.institute);
    }

private:
    Institute* institute = new Institute();
};

void Professor::whoami() const {
    std::cout << "I'm Professor " << " from " << institute->getName() << " Institute\n";
}