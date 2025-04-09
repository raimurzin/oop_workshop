#include <iostream>
#include <memory>

class Base {
public:
    Base() { std::cout << "Created Base\n"; };
    Base(Base *obj) { std::cout << "Created Base by pointer\n"; };
    Base(Base &obj) { std::cout << "Created Base by reference\n"; };
    ~Base() { std::cout << "Destroyed Base\n"; };
};

class Derived : public Base {
public:
    Derived() { std::cout << "Created Derived\n"; };
    Derived(Derived *obj) { std::cout << "Created Derived by pointer\n"; };
    Derived(Derived &obj) { std::cout << "Created Derived by reference\n"; };
    ~Derived() { std::cout << "Destroyed Derived\n"; };
};

Base func1() { 
    Base result;
    return result;
}

// Base* func2() {
//     Base result;
//     return &result;
// }

// Base& func3() { 
//     Base result;
//     return result;
// }

// Base func4() { 
//     Base* result = new Base();
//     return *result;
// }

// std::unique_ptr<Base> func5() {
//     Base* r = new Base();
//     auto result = std::make_unique<Base>{r};
//     return result;
// }

Base& func6() {
    Base* result = new Base();
    return *result;
}

int main() {
    Base res1 = func1();
    // Base* res2 = func2();
    // Base& res3 = func3();
    // Base res4 = func4();
    // auto res5 = func5();
    Base& res6 = func6();
    delete &res6;
}