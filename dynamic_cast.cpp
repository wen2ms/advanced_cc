#include <iostream>
#include <string>

class Animal {
  public:
    void echo() {
        std::cout << "This is a animal" << '\n';
    }
};

class Dog : public Animal {
  public:
    explicit Dog(std::string name = "") : name_(name) {}

    std::string name() {
        return name_;
    }

  private:
    std::string name_;
};

class Mamal {
  public:
    virtual void show_type() {};
};

class Cat : public Mamal {
  public:
    void show_type() override {
        std::cout << "I'm a cat" << '\n';
    }

    void mew() {
        std::cout << "Mew..." << '\n';
    }
};

int main() {
    Dog derived_object("Labrador");
    auto* base_pointer = (Animal*)&derived_object;

    base_pointer->echo();

    // Must require a virtual function
    // Animal animal;
    // Dog* dog = dynamic_cast<Dog*>(&animal);

    Mamal* mamal = new Cat;
    Cat* cat = dynamic_cast<Cat*>(mamal);

    cat->mew();

    Mamal base;
    try {
        Cat derive = dynamic_cast<Cat&>(base);
    } catch (std::bad_cast& e) {
        std::cout << "Can't cast base object to derive" << '\n';
    }

    Cat* derived_ptr = dynamic_cast<Cat*>(&base);
    if (derived_ptr == nullptr) {
        std::cout << "Can't cast base pointer to base" << '\n';
    }

    return 0;
}