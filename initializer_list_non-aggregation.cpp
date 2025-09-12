#include <iostream>
#include <string>
#include <utility>

class Dog {
  public:
    Dog() : age_(-1) {}

    Dog(std::string name, int age) : name_(std::move(name)), age_(age) {}

    void display() {
        std::cout << name_ << ' ' << age_ << '\n';
    }

  private:
    std::string name_;
    int age_;
};

Dog create_dog(std::string name, int age) {
    return {name, age};
}

// It's aggregation-type
struct Student {
    Dog dog;
    int age;
};

int main() {
    create_dog("Six", 6).display();

    Student student{.dog = {}, .age = 13};
    student.dog.display();

    return 0;
}