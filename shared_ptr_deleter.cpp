#include <iostream>
#include <memory>

template <class T>
std::shared_ptr<T> make_shared_array(size_t size) {
    return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

class Dog {
  public:
    Dog() {
        std::cout << "Default constructor called" << std::endl;
    }

    ~Dog() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    std::shared_ptr<Dog> dog(new Dog(), [](Dog* dog) {
        std::cout << "Lambda deleter called" << std::endl;
        delete dog;
    });

    std::shared_ptr<Dog> dogs(new Dog[5], [](Dog* dogs) {
        std::cout << "Dogs deleter called" << std::endl;
        delete[] dogs;
    });

    std::shared_ptr<Dog> another_dogs(new Dog[5], std::default_delete<Dog[]>());

    std::shared_ptr<Dog> last_dogs = make_shared_array<Dog>(3);

    return 0;
}