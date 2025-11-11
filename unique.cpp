#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{2, 2, 2, 2, 1, 3, 3, 5};
    auto iter = std::unique(nums.begin(), nums.end());
    nums.erase(iter, nums.end());

    for (int num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;
}