#include <iostream>

struct Point {
    int x;
    int y;

  protected:
    // Error, there are private members that cannot use initializer list
    // int z;
    static int z;
} point{.x = 0, .y = 0};

int Point::z = 10;

int main() {
    // Aggregation type
    // No custom constructor
    // No private or protected non-static members
    // No base class
    // No virtual functions

    std::cout << point.x << ' ' << point.y << '\n';

    return 0;
}