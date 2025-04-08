#pragma once
#include <iostream>
#include <string>
#include "person.hpp"
#include "../attributes/bill.hpp"

class Employee : public Person {
public:
    Employee() : company("Unknown") {
        std::cout << "Created Employee - Unknown\n";
    }
        
    Employee(const std::string& name, const std::string& company, const Bill& bill)
        : Person(name), company(company), bill(bill) {
        std::cout << "Created Employee " << name << " from the company " << company << "\n";;
    }
        
    Employee(const Employee& other) 
        : Person(other), company(other.company), bill(other.bill) {
        std::cout << "Created Employee "<< Person::name << " by copy from the company " << company << "\n";
    }

    Employee& operator=(const Employee& e) { 
        if (this != &e) {
            Employee temp(e);
            swap(*this, temp);
        }
        return *this;
    }
    
    virtual ~Employee() {
        std::cout << "Removed Employee " << Person::name << " from the company: " << company << "\n";
    }

public:
    virtual void whoami() const override;
    
public:
    static void swap(Employee& first, Employee& second) noexcept {
        std::swap(first.name, second.name);
        std::swap(first.company, second.company);
        Bill::swap(first.bill, second.bill);
    }
    
private:
    std::string company;
    Bill bill;
};

void Employee::whoami() const {
    std::cout << "I'm Employee " << Person::name << " from the company " << company << "\n";
}