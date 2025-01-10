#include <iostream>

void print_value(int& x) {
    std::cout << "lvalue reference" << std::endl;
}

void print_value(int&& x) {
    std::cout << "rvalue reference" << std::endl;
}

void reference_pass(int&& x) {
    print_value(x);
}

int main() {
    // Named rvalue references are treated as lvalues, the unnamed are treated as rvalues

    int x = 50;

    print_value(x);

    print_value(10);

    reference_pass(10);

    return 0;
}