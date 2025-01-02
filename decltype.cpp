#include <iostream>

class Dog {
  public:
    int age_ = 0;
    std::string name_;
    static const std::string kBreed;
};

const std::string Dog::kBreed = "Dog";

int&& eat() {}
const int drink() {}

int main() {
    decltype(Dog::kBreed) breed;

    decltype(eat()) eating = 0;

    decltype(drink()) drinking;

    const Dog dog;
    
    decltype(dog.age_) age;

    decltype((dog.age_)) age_with_parentheses = 0;

    int n = 0, m = 0;
    decltype(n = n + m) x = n;

    return 0;
}
