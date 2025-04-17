#include <iostream>

enum Color : char {
    kRed = 'a',
    kGreen,
    kBlue
};

// Error: Unscoped enum is globally visible
// enum {kRed, kGreen, kBlue};

enum class ColorA {
    kRed,
    kGreen,
    kBlue
};

enum struct ColorB {
    kRed,
    kGreen,
    kBlue
};


int main() {
    std::cout << Color::kRed << kRed << std::endl;

    // Must to explicitly convert
    std::cout << static_cast<int>(ColorA::kRed) << static_cast<int>(ColorB::kRed) << std::endl;

    return 0;
}