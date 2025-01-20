#include <iostream>
#include <memory>

struct Dog : public std::enable_shared_from_this<Dog> {
    std::shared_ptr<Dog> get_shared_ptr() {
        return shared_from_this();
    }

    ~Dog() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    Dog* dog = new Dog;

    std::shared_ptr<Dog> shared_ptr_1(dog);

    // Error: cannot use the same raw address to initialize multiple shared_ptr
    // std::shared_ptr<Dog> shared_ptr_2(dog);
    std::shared_ptr<Dog> shared_ptr_2 = shared_ptr_1;

    shared_ptr_1.reset(new Dog);

    std::cout << "use_count: " << shared_ptr_1.use_count() << std::endl;

    // Inherit std::enable_shared_from_this to return the std::shared_ptr that manages this
    shared_ptr_2 = shared_ptr_1->get_shared_ptr();

    std::cout << "use_count: " << shared_ptr_2.use_count() << std::endl;

    return 0;
}