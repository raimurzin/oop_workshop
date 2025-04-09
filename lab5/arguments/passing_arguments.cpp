#include <iostream>

class Base {
public:
    Base() { std::cout << "Created Base\n\n"; };
    Base(Base *obj) { std::cout << "Created Base by pointer\n"; };
    Base(Base &obj) { std::cout << "Created Base by reference\n"; };
    ~Base() { std::cout << "Destroyed Base\n"; };
};

class Derived : public Base {
public:
    Derived() { std::cout << "Created Derived\n\n"; };
    Derived(Derived *obj) { std::cout << "Created Derived by pointer\n"; };
    Derived(Derived &obj) { std::cout << "Created Derived by reference\n"; };
    ~Derived() { std::cout << "Destroyed Derived\n"; };
};

void func1(Base obj) { 
    std::cout << "Get by value\n";
}

void func2(Base *obj) {
    std::cout << "Get by pointer\n";
}

void func3(Base &obj) {
    std::cout << "Get by reference\n";
}

int main() {
    {
        std::cout << "\nTEST 1: Base\n";
        Base* b = new Base();
        func1(*b);
        func2(b);
        func3(*b);
        delete b;
    }
    {
        std::cout << "\nTEST 2: Derived\n";
        Derived* d = new Derived();
        func1(*d);
        func2(d);
        func3(*d);
        delete d;
    }
}