#include <iostream>
// #include <cassert>

int main() {
    // int size = -1;

    // assert(size > 0);

    // char* str = new char[size];

    // error: static assertion
    // static_assert(sizeof(long) == 4, "32 bits platform");

    static_assert(sizeof(long) == 8, "64 bits platform");

    return 0;
}