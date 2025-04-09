#include <iostream>
#include <memory>

class A {
public:
    A() { std::cout << "Created A\n"; }
    ~A() { std::cout << "Destroyed A\n"; }
};


void f_in1(std::shared_ptr<A> ptr) {
    std::cout << ptr.use_count() << "\n";
}

void f_in2(std::unique_ptr<A> ptr) {
    return;
}

std::shared_ptr<A> f_out1() {
    return std::shared_ptr<A>{new A()};
}

std::unique_ptr<A> f_out2() {
    return std::unique_ptr<A>{new A()};;
}

int main() {
    auto unq_ptr = std::make_unique<A>();
    auto shr_ptr = std::make_shared<A>();

    auto p1 = std::move(unq_ptr); // move ptr to p1
    auto p2 = shr_ptr;
    auto p3 = shr_ptr;
    std::cout << p3.use_count() << "\n";

    auto p4 = std::shared_ptr<A>{new A()};
    std::cout << p4.use_count() << "\n";

    // Передача умных указателей в качестве параметров
    f_in1(p4);
    f_in2(std::move(unq_ptr));

    // Прием умных указателей
    auto o1 = f_out1();
    std::cout << o1.use_count() << "\n";
    auto o2 = f_out2();
}