#include <iostream>
#include <vector>

void foo(int x) {
    int a = 10;
    [=, &x]() mutable {
        int b = a;

        // Value copy instead of reference
        ++a;
        std::cout << "a: " << a << '\n';
    }();

    std::cout << "a: " << a << '\n';
}

int main() {
    foo(1);

    auto func = []() -> std::vector<int> { return {1, 2}; };

    std::vector<int> nums = func();
    for (const int& num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    auto bar = [](auto first, auto second) { return first + second; };
    std::cout << bar('a', 3) << '\n';

    return 0;
}