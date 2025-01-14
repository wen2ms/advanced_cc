#include <iostream>
#include <string>
#include <memory>

class Dog {
  public:
    Dog() {
        std::cout << "Default constructor called" << std::endl;
    }

    Dog(int age) : age_(age) {
        std::cout << "Constructor called, age: " << age << std::endl;
    }

    Dog(std::string name) : name_(name) {
        std::cout << "Constructor called, name: " << name << std::endl;
    }

    ~Dog() {
        std::cout << "Destructor called" << std::endl;
    }

    std::string& name() {
        return name_;
    }

  private:
    int age_;
    std::string name_;
};

int main() {
    // Constructor initialization
    std::shared_ptr<int> integer_ptr_1(new int(20));
    
    std::cout << "Integer ptr 1, use_count: " << integer_ptr_1.use_count() << std::endl;
    std::cout << std::endl;

    // Move and copy initialization
    std::shared_ptr<int> integer_ptr_2 = std::move(integer_ptr_1);
    std::cout << "Integer ptr 1, use_count: " << integer_ptr_1.use_count() << std::endl;
    std::cout << "Integer ptr 2, use_count: " << integer_ptr_2.use_count() << std::endl;
    std::cout << std::endl;

    std::shared_ptr<int> integer_ptr_3 = integer_ptr_2;
    std::cout << "Integer ptr 1, use_count: " << integer_ptr_1.use_count() << std::endl;
    std::cout << "Integer ptr 2, use_count: " << integer_ptr_2.use_count() << std::endl;
    std::cout << "Integer ptr 3, use_count: " << integer_ptr_3.use_count() << std::endl;
    std::cout << std::endl;

    // std::make_shared initialization
    std::shared_ptr<int> integer_ptr_4 = std::make_shared<int>(20);
    std::shared_ptr<Dog> dog_ptr_1 = std::make_shared<Dog>();
    std::shared_ptr<Dog> dog_ptr_2 = std::make_shared<Dog>(10);
    std::shared_ptr<Dog> dog_ptr_3 = std::make_shared<Dog>("French Bulldog");

    // reset initialization
    dog_ptr_3.reset();
    std::cout << "dog ptr 3, use_count: " << dog_ptr_3.use_count() << std::endl;
    std::cout << std::endl;

    std::shared_ptr<Dog> dog_ptr_4;
    dog_ptr_4.reset(new Dog());

    std::cout << "dog ptr 2, use_count: " << dog_ptr_2.use_count() << std::endl;
    std::cout << "dog ptr 4, use_count: " << dog_ptr_4.use_count() << std::endl;
    std::cout << std::endl;

    std::shared_ptr<Dog> dog_shared_ptr = std::make_shared<Dog>("Doberman");

    Dog* dog = dog_shared_ptr.get();

    dog->name() = "Golden retriver";
    std::cout << "Dog name: " << dog->name() << std::endl;

    dog_shared_ptr->name() = "Labrador";
    std::cout << "Dog name: " << dog_shared_ptr->name() << std::endl;

    return 0;
}