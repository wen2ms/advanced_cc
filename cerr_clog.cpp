#include <chrono>
#include <iostream>
#include <thread>

int main() {
    // automatic buffered
    // stdout = 1
    std::cout << "This is a standard output" << '\n';
    // Not buffered
    // stderr = 2
    std::cerr << "This is a standard error output" << '\n';
    // Buffered error
    // also stderr
    std::clog << "This is a standard log output" << '\n';

    std::cout << "Start";
    std::cerr << " [cerr]";
    std::clog << " [clog]";
    std::cout << " End" << '\n';

    return 0;
}
