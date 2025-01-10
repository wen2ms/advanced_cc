#include <iostream>
#include <functional>

void foo() {
    using func_ptr = void(*)(int);

    func_ptr print_x = [](int x) {
        std::cout << "x: " << x << std::endl;
    };

    print_x(10);

    // As a functor capturing external variables 
    auto print_y = [=](int y) {
        std::cout << "y: " << y << std::endl; 
    };

    std::function<void(int)> print_y_wrap = print_y;
    auto print_y_bind = std::bind(print_y, std::placeholders::_1);

    print_y_wrap(10);
    print_y_bind(10);
}

int main() {
    foo();

    return 0;
}