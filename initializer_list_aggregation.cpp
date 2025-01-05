#include <iostream>

struct Point {
    int x;
    int y;

  protected:
    // Error, there are private members that cannot use initializer list
    // int z;
    static int z;
}  point{0, 0};

int Point::z = 10;

int main() {
    // Aggregation type
    // No custom constructor
    // No private or protected non-static members 
    // No base class
    // No virtual functions 

    std::cout << point.x << ' ' << point.y << std::endl;

    return 0;
}