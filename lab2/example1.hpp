#include <iostream>
#include <unordered_map>
#include <string>

enum class Gender {
    Man, // Мужчина
    Woman // Женщина
}

enum class ActivismType {
    Sportsmen, // Спортсмен
    HostelVolunteer // Помощник в общежитии
}

class Person {
public:
    Person() = default;
    Person(uint age, uint gender, std::string name) : age(age), gender(gender), name(name) {}
    Person(const Person& p) : age(p.age), gender(p.gender), name(p.name) {}
    Person& operator=(const Person& p) { 
        auto pCopy = Person(p);
        swap(pCopy, p);
        return &pCopy;
    }
    ~Person() = default;
public:

private:
    uint age;
    uint gender;
    std::string name
};