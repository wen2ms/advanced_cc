#include <iostream>

class Foo {
  public:
    Foo() = default;
    ~Foo() = default;
    Foo(const Foo& t) = default;
    Foo(Foo&& t) = default;
    Foo& operator=(const Foo& t) = default;
    Foo& operator=(Foo&& t) = default; 
};

class Bar {
  public:
    Bar(Bar&& b);
};
Bar::Bar(Bar&& b) = default;

int main() {

    return 0;
}