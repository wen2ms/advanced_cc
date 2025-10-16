#include <iostream>

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Uasge: " << argv[0] << " number" << '\n';
        return 1;
    }

    int input_number = std::stoi(argv[1]);
    int output_number = factorial(input_number);  // computed at run time

    constexpr int regulation = factorial(-1);  // computed at compile time

    std::cout << "The factorial of " << input_number << " is " << output_number << '\n';

    std::cout << "The factorial of -1 is " << regulation << '\n';

    return 0;
}