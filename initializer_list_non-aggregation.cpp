#include <iostream>
#include <string>

class Dog {
  public:
    Dog() : name_(""), age_(-1) {}

    Dog(std::string name, int age) : name_(name), age_(age) {}

    void display() {
        std::cout << name_ << ' ' << age_ << std::endl;
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

    Student student{{}, 13};
    student.dog.display();

    return 0;
}