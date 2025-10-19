#include <iostream>

void func(char* p) {
    std::cout << "void func(char* p)" << '\n';
}

void func(int x) {
    std::cout << "void func(int x)" << '\n';
    std::cout << "x is " << x << '\n';
}

void func(long value) {
    std::cout << "void func(long value)" << '\n';
    std::cout << "value is " << value << '\n';
}

int main() {
    char* ptr_char = nullptr;

    func(ptr_char);

    func(nullptr);

    func(NULL);

    return 0;
}