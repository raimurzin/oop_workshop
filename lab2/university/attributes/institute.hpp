#pragma once
#include <iostream>
#include <string>

class Institute {
public:
    Institute() : name("Unknown"), department("Unknown") {
        std::cout << "Created Institute - Unknown\n";
    }
        
    Institute(const std::string& name, const std::string& department) 
        : name(name), department(department) {
        std::cout << "Created Institute - " << name << ", " << department << "\n";
    }
        
    Institute(const Institute& other) 
        : name(other.name), department(other.department) {
        std::cout << "Created Institute by copy - " << name << ", " << department << "\n";
    }
        
    Institute& operator=(const Institute& other) {
        if (this != &other) {
            Institute temp(other);
            swap(*this, temp);
        }
        return *this;
    }
        
    ~Institute() {
        std::cout << "Removed Institute - " << name << ", " << department << "\n";
    }

public:
    std::string getName() const { return name; }
    std::string getDepartment() const { return department; }
        
    void setName(const std::string& name) { this->name = name; }
    void setDepartment(const std::string& department) { this->department = department; }
    
public:   
    static void swap(Institute& first, Institute& second) noexcept {
        std::swap(first.name, second.name);
        std::swap(first.department, second.department);
    }
        
private:
    std::string name;
    std::string department;
};