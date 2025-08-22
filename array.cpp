#include <array>
#include <iostream>
#include <numeric>

int main() {
    // Not be initialized zeros;
    std::array<int, 5> arr;
    std::iota(arr.begin(), arr.end(), 1);

    for (int num : arr) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    int* iter = arr.begin();
    iter[0] = -1;

    std::cout << "back = " << arr.back() << " front = " << arr.front() << '\n';
    std::cout << "data = " << *arr.data() << '\n';

    arr.fill(100);
    for (int num : arr) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    std::array<int, 5> brr;
    std::cout << "size = " << brr.size() << " capacity = " << brr.max_size() << '\n';

    std::cout << arr.at(6) << '\n';

    return 0;
}