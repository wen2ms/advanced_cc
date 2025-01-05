#include <iostream>
#include <string>

class Animal {
  public:
    Animal(std::string name, int age) : name_(name), age_(age) {}

    void display(std::string type) {
        std::cout << "This is a " << type << std::endl;
    }  

  protected:
    std::string name_;
    int age_;
};

class Dog : public Animal {
  public:   
    using Animal::Animal;
    using Animal::display;

    void display() {
        std::cout << "Dog name: " << name_ << ", Dog age: " << age_ << std::endl;
    }
};

int main() {
    Dog dog("Losus", 10);

    dog.display();
    dog.display("dog");

    return 0;
}