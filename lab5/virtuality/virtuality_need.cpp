#include <iostream>

namespace overlapping {
    struct Base {
        void write_smth() const {
            std::cout << "It's base\n";
        }
    };

    struct Derived : public Base {
        void write_smth() const {
            std::cout << "It's derived\n";
        }
    };
}

namespace virtuality {
    struct Base {
        virtual void write_smth() const {
            std::cout << "It's base\n";
        }
    };

    struct Derived : public Base {
        virtual void write_smth() const {
            std::cout << "It's derived\n";
        }
    };
}

int main() {
    {
        overlapping::Base* b = new overlapping::Derived();
        b->write_smth();
        delete b;
    }
    {
        virtuality::Base* b = new virtuality::Derived();
        b->write_smth();
        delete b;
    }
}