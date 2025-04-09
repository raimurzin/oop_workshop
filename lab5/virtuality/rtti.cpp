#include <iostream>

class A {
public:
    virtual ~A() = default;
    virtual std::string classname() const { 
        return "A"; 
    }
    virtual bool isA(const std::string& className) const {
        return className == "A";
    }
};
class B : virtual public A {
public:
    virtual ~B() = default;
    virtual std::string classname() const override { 
        return "B"; 
    }
    virtual bool isA(const std::string& className) const override {
        return className == "B" || A::isA(className);
    }
};

class C: virtual public A {
public:
    virtual ~C() = default;
    virtual std::string classname() const override { 
        return "C"; 
    }
    virtual bool isA(const std::string& className) const override {
        return className == "C" || A::isA(className);
    }
};

class D: public B, C {
    virtual ~D() = default;
    virtual std::string classname() const override { return "D"; }
    virtual bool isA(const std::string& className) const override {
        return className == "D" ||  B::isA(className) || C::isA(className);
    }
};

void example1(B* b) { // Демонстрация опасного преобразования
    A* a = static_cast<A*>(b);
    std::cout << a->classname() << "\n";
}

void example2(A* t) { // Демонстрация безопасного преобразования
    A* a = dynamic_cast<A*>(t);
    std::cout << (a == nullptr ? "Conversation of " + t->classname() + " to A failed" : "It's okey") << "\n";
    D* d = dynamic_cast<D*>(t);
    std::cout << (d == nullptr ? "Conversation of " + t->classname() + " to D failed" : "It's okey") << "\n";
    C* c = dynamic_cast<C*>(t);
    std::cout << (c == nullptr ? "Conversation of " + t->classname() + " to D failed" : "It's okey") << "\n";
}

void example3(A* a) {
    std::cout << a->classname() << "\n";
}

void example4(A* a) {
    if (a->isA("A") || a->isA("B") || a->isA("C") || a->isA("D")) 
        std::cout << "This object belongs to A hierarchy" << "\n";
}

int main() {
    A* a = new A();
    B* b = new B();
    D* d = new D();
    std::cout << "example1:\n";
    example1(b);  // Безопасно

    std::cout << "example2:\n";
    example2(a);
    example2(b);
    example2(d);

    std::cout << "example3:\n";
    example3(a);
    example3(b);

    std::cout << "example4:\n";
    example4(a);
    example4(b);

    delete a;
    delete b;
}