#include <array>
#include <cstdlib>
#include <iostream>
#include <new>

class Foo {
  public:
    Foo() {
        std::cout << "Foo()" << '\n';
    }

    ~Foo() {
        std::cout << "~Foo()" << '\n';
    }

    void say() {}
};

void my_new_handler() {
    std::cerr << "new handler called" << '\n';
    throw std::bad_alloc();
}

int main() {
    // new is a operator, but operator new is a function
    void* foo = operator new(sizeof(Foo));
    Foo* foo_cast = static_cast<Foo*>(operator new(sizeof(Foo)));

    operator delete(foo);
    operator delete(foo_cast);

    std::new_handler old_handler = std::set_new_handler(my_new_handler);

    try {
        void* ptr = operator new(10000000000000000);
    } catch (std::bad_alloc& e) {
        std::cerr << e.what() << '\n';
    }

    foo = operator new(sizeof(Foo));
    // placement new also is a operator, and call operator new like new, but this operator new does not allocate memory
    foo_cast = new (foo) Foo;

    foo_cast->~Foo();
    operator delete(foo);

    std::array<char, 8> array{};
    foo_cast = new (array.data()) Foo;

    foo_cast->~Foo();

    return 0;
}