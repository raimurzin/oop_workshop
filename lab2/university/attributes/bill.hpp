#pragma once
#include <iostream>
#include <string>

class Bill {
public:
    Bill() : count(0), bankName("Unknown") {
        std::cout << "Created empty bill\n";
    }
    
    Bill(double count, const std::string& bankName)
        : count(count), bankName(bankName) {
        std::cout << "Created Bill - " << bankName << " , " << count << " rubs\n";
    }
    
    Bill(const Bill& other) 
        : count(other.count), bankName(other.bankName) {
        std::cout << "Created Bill by copy - " << bankName << " , " << count << " rubs\n";
    }
    
    Bill& operator=(const Bill& other) {
        if (this != &other) {
            Bill temp(other);
            swap(*this, temp);
        }
        return *this;
    }
    
    ~Bill() {
        std::cout << "Removed Bill - " << bankName << " , " << count << " rubs\n";
    }
    
public:
    double getCount() const { return count; }
    std::string getBankName() const { return bankName; }
    
    void setCount(double count) { this->count = count; }
    void setBankName(const std::string& bankName) { this->bankName = bankName; }

public:
    static void swap(Bill& first, Bill& second) noexcept {
        std::swap(first.count, second.count);
        std::swap(first.bankName, second.bankName);
    }
    
private:
    double count;
    std::string bankName;
};