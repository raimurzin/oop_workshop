#include <iostream>

class Animal {
public:
    virtual void makeSound() {} 
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bark" << std::endl;
    }
    void L() const {
        std::cout << "L" << std::endl;
    }
};
    
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow" << std::endl;
    }
    void M() const {
        std::cout << "M" << std::endl;
    }
};
    
void playSound(Animal* animal) {
    // animal->M(); // Не сработает
    Cat* m = dynamic_cast<Cat*>(animal);
    if (m != nullptr) m->M();

    Dog* d = dynamic_cast<Dog*>(m);
    if (d == nullptr) std::cout << "Cannot execute conversation\n";
}

int main() {
    Cat* cat = new Cat();
    playSound(cat);
}