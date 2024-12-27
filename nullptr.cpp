#include <iostream>

void func(char* p) {
    std::cout << "void func(char* p)" << std::endl;
}

void func(int x) {
    std::cout << "void func(int x)" << std::endl;
    std::cout << "x is " << x << std::endl;
}

void func(long value) {
    std::cout << "void func(long value)" << std::endl;
    std::cout << "value is " << value << std::endl;
}

int main() {
    char* ptr_char = nullptr;

    func(ptr_char);

    func(nullptr);

    func(NULL);

    return 0;
}