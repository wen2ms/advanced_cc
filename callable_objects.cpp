#include <iostream>
#include <string>

class Dog {
  public:
    void print_breed() {
        std::cout << "print_breed, breed is " << breed_ << std::endl;
    }

    static void print_type() {
        std::cout << "print_type, this is a dog" << std::endl;
    }
    
  std::string breed_;
};

using print_func_ptr = void(*)();

class PrintDog {
  public:
    void operator()(const Dog& dog) {
        std::cout << "Functor, breed is " << dog.breed_ << std::endl;
    }

    operator print_func_ptr() {
        // Cannot return Dog::print_breed that is non-static member function
        return Dog::print_type;
    }
};

void print_dog(const Dog& dog) {
    std::cout << "print_dog, breed is " << dog.breed_ << std::endl;
}

int main() {
    // Callable objects
    // 1. Function pointer
    // 2. Functor
    // 3. A object that can convert to a function pointer
    // 4  Class member pointer

    Dog dog{"Golden Retirver"};

    void(*print_dog_func)(const Dog&) = print_dog;
    (*print_dog_func)(dog);

    PrintDog()(dog);

    PrintDog()();

    print_func_ptr print_type_ptr = Dog::print_type;
    print_type_ptr();

    void(Dog::*print_breed_ptr)() = &Dog::print_breed;
    std::string Dog::*breed_ptr = &Dog::breed_;

    (dog.*print_breed_ptr)();
    std::cout << dog.*breed_ptr << std::endl;

    return 0;
}