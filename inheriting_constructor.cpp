#include <iostream>
#include <string>

class Animal {
  public:
    Animal(std::string name, int age) : name_(name), age_(age) {}

    void display(std::string type) {
        std::cout << "This is a " << type << '\n';
    }

  protected:
    std::string name_;
    int age_;
};

class Dog : public Animal {
  public:
    // Inherit all constructors except copy and move.
    //  = Dog(std::string name, int age) : Animal(name, age) {}
    using Animal::Animal;
    using Animal::display;

    void display() {
        std::cout << "Dog name: " << name_ << ", Dog age: " << age_ << '\n';
    }
};

int main() {
    Dog dog("Losus", 10);

    dog.display();
    dog.display("dog");

    return 0;
}