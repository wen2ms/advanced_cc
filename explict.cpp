#include <string>

class Foo {
  public:
    Foo(const char* str) = delete;

    explicit Foo(std::string num) {}
};

int main() {
    // Error
    // Foo foo = "bar";
    // Foo foo("bar");
    // Foo foo = std::string("bar");

    Foo foo(std::string("bar"));

    return 0;
}