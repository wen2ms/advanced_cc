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
    Bar();

    Bar(const Bar& other) = delete;
    Bar& operator=(const Bar& other) = delete;

    void print_bar(int number) {
        std::cout << static_cast<char>(number) << '\n';
    }

    void print_bar(char letter) = delete;
};

Bar::Bar() = default;

int main() {
    Bar bar1;

    // Error: Copy constructor and opartor are a deleted function
    // Bar bar2(bar1);
    // Bar bar3 = bar1;

    bar1.print_bar(65);

    // Error
    // bar1.print_bar('a');

    return 0;
}