#include <functional>
#include <iostream>
#include <memory>

class Dog {
  public:
    Dog() {
        std::cout << "Constructor called" << '\n';
    }

    ~Dog() {
        std::cout << "Destructor called" << '\n';
    }
};

int main() {
    using func_ptr = void (*)(Dog*);

    std::unique_ptr<Dog, func_ptr> dog_ptr_1(new Dog(), [](Dog* dog) {
        std::cout << "Lambda1 deleter called" << '\n';
        delete dog;
    });

    std::unique_ptr<Dog, std::function<void(Dog*)>> dog_ptr_2(new Dog(), [=](Dog* dog) {
        std::cout << "Lambda2 deleter called" << '\n';
        delete dog;
    });

    // unique_ptr can automatically manage array
    std::unique_ptr<Dog[]> dogs_unique_ptr(new Dog[3]);

    // shared_ptr can be also automatic after c++11
    // std::shared_ptr<Dog[]> dogs_shared_ptr(new Dog[3]);

    return 0;
}