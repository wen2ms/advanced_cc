#include <iomanip>
#include <iostream>

int main() {
    int decimal = 30;
    int hexidecimal = 0x1E;
    int octal = 036;

    std::cout << decimal << ' ' << hexidecimal << ' ' << octal << '\n';
    std::cout << std::uppercase << std::hex << decimal << ' ' << std::oct << hexidecimal << ' ' << std::dec << octal << '\n';

    std::cout << std::setw(5) << "name" << std::setfill('-') << std::setw(6) << "age" << '\n';

    return 0;
}