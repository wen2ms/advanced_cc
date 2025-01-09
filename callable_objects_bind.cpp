#include <iostream>
#include <functional>

void call_func(int x, int y, const std::function<void(int, int)>& func) {
    if (x % 2 == 0 && y % 2 == 0) {
        func(x, y);
    }
}

void my_add(int x, int y) {
    std::cout << "x: " << x << ", y: " << y << ", x + y: " << x + y << std::endl;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        // auto_func doesn't work in call_func, std::placeholders::_<x> must be used 
        // auto func = std::bind(my_add, i + 1, i + 2);
        // call_func(i, i, func);

        auto func = std::bind(my_add, std::placeholders::_1, std::placeholders::_2);
        call_func(i, i, func);
    }

    return 0;
}