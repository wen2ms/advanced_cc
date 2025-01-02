#include <iostream>

class Animal {
  public:
    virtual void eat() = 0;
};

class Dog : public Animal{
  public:
    virtual void barking() {}

    void eat() override final{
        std::cout << "Eating..."  << std::endl;
    }
};

class BullDog final : public Dog {
  public:
    void barking() override {
        std::cout << "This is a bull dog" << std::endl;
    }
};

int main() {
    Dog dog;
    BullDog bull_dog;

    dog.eat();
    bull_dog.barking();
    bull_dog.eat();

    return 0;
}

