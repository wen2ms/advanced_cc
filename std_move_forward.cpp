#include <iostream>
#include <list>

template <class T>
void print_value(T& t) {
    std::cout << "lvalue" << '\n';
}

template <class T>
void print_value(T&& t) {
    std::cout << "rvalue" << '\n';
}

template <class T>
void test_forward(T&& t) {
    print_value(t);

    print_value(std::move(t));

    // t will be convert lvalue only if T is lvalue reference
    print_value(std::forward<T>(t));

    std::cout << '\n';
}

int main() {
    int&& x = 10;
    int y = 20;

    int&& rvalue_reference_1 = std::move(x);
    int&& rvalue_reference_2 = std::move(y);

    std::list<std::string> list_1 = {"1", "2", "3"};

    std::list<std::string> list_2 = std::move(list_1);

    test_forward(1);

    test_forward(y);

    test_forward(x);

    test_forward(std::forward<int&>(y));

    return 0;
}