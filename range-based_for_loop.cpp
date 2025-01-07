#include <iostream>
#include <set>
#include <vector>

std::vector<int> vec{1, 2, 3, 4};

std::vector<int>& get_vec() {
    std::cout << "Get vector..." << std::endl;
    return vec;
}

int main() {
    std::set<int> input_numbers{3, 2, 1, 5, 7};

    for (auto& number : input_numbers) {
        // Error, in range-based for loop, the items in set and keys in map are const deduced with auto 
        // number++;

        std::cout << number << ' ';
    }
    std::cout << std::endl;

    // The container will only be accessed once, and the range has been determined
    for (const auto& item : get_vec()) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    return 0;
}