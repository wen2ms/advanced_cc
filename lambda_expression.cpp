#include <iostream>
#include <vector>

void foo(int x) {
    int a = 10;
    [=,  &x]() mutable {
        int b = a;

        // Value copy instead of reference
        a++;
        std::cout << "a: " << a << std::endl;
    }();

    std::cout << "a: " << a << std::endl;
}

int main() {
    foo(1);

    auto func = []() -> std::vector<int> {
        return {1, 2};
    };

    std::vector<int> vec = func();
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}