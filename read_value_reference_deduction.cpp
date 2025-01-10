#include <iostream>

template <class T>
void foo_1(T&& parameter);

// const T&& is a rvalue reference instead of unspecified reference
template <class T>
void foo_2(const T&& parameter);

int main() {
    // Only using rvalue deduction is rvalue reference 

    // rvalue reference
    // foo_1(10);

    int x = 20;

    // lvalue reference
    // foo_1(x);

    // lvalue reference
    auto&& a = x;

    // rvalue reference
    auto&& b = 20;

    // error: decltype(x) is int, int&& c is a rvalue reference
    // decltype(x)&& c = x;

    // const rvalue reference
    const int&& d = 100;

    return 0;
}