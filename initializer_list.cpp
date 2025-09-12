#include <iostream>
#include <string>
#include <utility>

class Dog {
  public:
    Dog(std::string breed, int age) : breed_(std::move(breed)), age_(age) {}

    std::string breed_;
    int age_;
};

int main() {
    Dog dog1{"Golden Retriver", 2};
    Dog dog2 = {"French Bulldog", 1};

    std::array<int, 4> nums{1, 2, 3, 4};

    int* ptr = new int{1};
    int* array = new int[4]{0, 1, 2, 3};

    std::cout << dog1.breed_ << ' ' << dog1.age_ << '\n';
    std::cout << dog2.breed_ << ' ' << dog2.age_ << '\n';

    for (int num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    std::cout << *ptr << '\n';

    for (int i = 0; i < 4; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}