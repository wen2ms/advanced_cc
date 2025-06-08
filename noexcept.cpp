#include <iostream>

template <class T>
void swap(T& a, T& b, std::integral_constant<bool, true>) noexcept {
    T tmp(std::move(a));

    a = std::move(b);
    b = std::move(tmp);
}

template <class T>
void swap(T& a, T& b, std::integral_constant<bool, false>) {
    T tmp(a);

    a = b;
    b = tmp;
}

template <class T>
void swap(T& a, T& b) noexcept(
    noexcept(swap(a, b, std::integral_constant<bool, noexcept(T(std::move(a))) && noexcept(a.operator=(std::move(b)))>()))) {
    swap(a, b, std::integral_constant<bool, noexcept(T(std::move(a))) && noexcept(a.operator=(std::move(b)))>());
}
