#include <iostream>
#include <memory>

class Cat;

class Dog {
  public:
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }

    // Error: circular reference
    // std::shared_ptr<Cat> cat_ptr;
    std::weak_ptr<Cat> cat_ptr;
};

class Cat {
  public:
    ~Cat() {
        std::cout << "Cat destructor called" << std::endl;
    }

    std::shared_ptr<Dog> dog_ptr;
};

int main() {
    std::shared_ptr<Dog> dog(new Dog);
    std::shared_ptr<Cat> cat(new Cat);

    std::cout << "Dog, use_count: " << dog.use_count() << std::endl;
    std::cout << "Cat, use_count: " << cat.use_count() << std::endl;

    dog->cat_ptr = cat;
    cat->dog_ptr = dog;

    std::cout << "Dog, use_count: " << dog.use_count() << std::endl;
    std::cout << "Cat, use_count: " << cat.use_count() << std::endl;

    return 0;
}