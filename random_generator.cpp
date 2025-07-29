// #include <cstdlib>
// #include <ctime>
#include <algorithm>
#include <iostream>
#include <random>

int main() {
    // std::srand(std::time(nullptr));

    // std::cout << std::rand() << std::endl;

    std::random_device random_device;

    // [1, 10]
    // std::uniform_int_distribution<int> distribution(1, 10);

    // [0.0, 1.0)
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    std::cout << distribution(random_device) << std::endl;

    std::vector<int> nums(10);

    std::iota(nums.begin(), nums.end(), 0);

    // std::mt19937 generator(std::time(nullptr));
    std::mt19937 generator(random_device());

    std::shuffle(nums.begin(), nums.end(), generator);

    for (int num : nums) {
        std::cout << num << ' ';
    }
    
    std::cout << std::endl;

    return 0;
}