#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{1, 2, 3, 3, 3, 4, 5};
    std::cout << std::lower_bound(nums.begin(), nums.end(), 3) - nums.begin() << '\n';
    std::cout << std::upper_bound(nums.begin(), nums.end(), 3) - nums.begin() << '\n';

    auto iter = std::lower_bound(nums.begin(), nums.end(), 10);
    if (iter == nums.end()) {
        std::cout << "Not found" << '\n';
    }

    return 0;
}