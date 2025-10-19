#include <iostream>
#include <memory>

std::unique_ptr<int> foo() {
    return {};
}

int main() {
    // Constructor initialization
    std::unique_ptr<int> ptr_1(new int(10));

    // Move initialization, cannot use copy initialization
    std::unique_ptr<int> ptr_2 = std::move(ptr_1);

    std::unique_ptr<int> ptr_3 = foo();

    // Reset initialization
    ptr_3.reset(new int(20));

    int* integer = ptr_3.get();
    std::cout << "Integer: " << *integer << '\n';

    std::cout << "Integer: " << *ptr_3 << '\n';

    return 0;
}