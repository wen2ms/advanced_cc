#include <iostream>
#include <memory>

template <class T>
std::shared_ptr<T> make_shared_array(size_t size) {
    return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

class Dog {
  public:
    Dog() {
        std::cout << "Default constructor called" << '\n';
    }

    ~Dog() {
        std::cout << "Destructor called" << '\n';
    }
};

int main() {
    std::shared_ptr<Dog> dog(new Dog(), [](Dog* dog) {
        std::cout << "Lambda deleter called" << '\n';
        delete dog;
    });

    std::shared_ptr<Dog> dogs(new Dog[5], [](Dog* dogs) {
        std::cout << "Dogs deleter called" << '\n';
        delete[] dogs;
    });

    std::shared_ptr<Dog> another_dogs(new Dog[5], std::default_delete<Dog[]>());

    std::shared_ptr<Dog> last_dogs = make_shared_array<Dog>(3);

    // After c++11
    std::shared_ptr<Dog[]> foo_dogs(new Dog[3]);

    return 0;
}