#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>

int main() {
    std::list<int> nums(10);

    std::iota(nums.begin(), nums.end(), 1);

    auto is_even = [](int num) { return num % 2 == 0; };

    std::cout << "all even? : " << std::all_of(nums.cbegin(), nums.cend(), is_even) << '\n';
    std::cout << "any even? : " << std::any_of(nums.cbegin(), nums.cend(), is_even) << '\n';
    std::cout << "none even? : " << std::none_of(nums.cbegin(), nums.cend(), is_even) << '\n';

    return 0;
}