#include <iostream>
#include <memory>
#include <new>

int main() {
    try {
        std::unique_ptr<int[]> arr(new int[1000000000000000]);
    } catch (const std::bad_alloc& err) {
        std::cerr << err.what() << '\n';
    }

    std::unique_ptr<int[]> nums(new(std::nothrow) int[1000000000000000]);
    if (nums == nullptr) {
        std::cerr << "Allocation failed" << '\n';
    }

    return 0;
}