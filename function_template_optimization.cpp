#include <iostream>

template <typename T = long, typename U = char>
void print_two_elements(T t = 'A', U u = 'B') {
    std::cout << t << ' ' << u << std::endl;
}

int main() {
    print_two_elements();

    // Deduction first without explicit type
    print_two_elements('a', 'b');

    print_two_elements<int, int>('a', 'b');

    return 0;
}