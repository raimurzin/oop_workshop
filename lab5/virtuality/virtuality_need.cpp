#include <iostream>

namespace overlapping {
    struct Base {
        Base() { std::cout << "Created Base and allocated sources\n"; }
        ~Base() { std::cout << "Destroyed Base and deallocated sources\n"; }
        
        void write_smth() const {
            std::cout << "It's base\n";
        }
    };

    struct Derived : public Base {
        Derived() { std::cout << "Created Derived and allocated sources\n"; }
        ~Derived() { std::cout << "Destroyed Derived and deallocated sources\n"; }
        
        void write_smth() const {
            std::cout << "It's derived\n";
        }
        // using Base::write_smth()
    };
}

namespace virtuality {
    struct Base {
        Base() { std::cout << "Created Base and allocated sources\n"; }
        virtual ~Base() { std::cout << "Destroyed Base and deallocated sources\n"; }

        virtual void write_smth() const {
            std::cout << "It's base\n";
        }
    };

    struct Derived : public Base {
        Derived() { std::cout << "Created Derived and allocated sources\n"; }
        virtual ~Derived() { std::cout << "Destroyed Derived and deallocated sources\n"; }

        virtual void write_smth() const override {
            std::cout << "It's derived\n";
        }
    };
}

int main() {
    std::cout << "Without using virtuality:\n";
    overlapping::Base* b1 = new overlapping::Derived();
    b1->write_smth();
    delete b1;

    std::cout << "\nWith using virtuality:\n";
    virtuality::Base* b2 = new virtuality::Derived();
    b2->write_smth();
    delete b2;
}