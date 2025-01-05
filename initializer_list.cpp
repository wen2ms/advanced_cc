#include <iostream>
#include <string>

class Dog {
  public:
    Dog(std::string breed, int age) : breed_(breed), age_(age) {} 

    std::string breed_;
    int age_;
};

int main() {
    Dog dog1{"Golden Retriver", 2};
    Dog dog2 = {"French Bulldog", 1};

    int arr[] = {1, 2, 3, 4};

    int* p = new int{1};
    int* array = new int[4]{0, 1, 2, 3};

    std::cout << dog1.breed_ << ' ' << dog1.age_ << std::endl;
    std::cout << dog2.breed_ << ' ' << dog2.age_ << std::endl;

    for (int i = 0; i < 4; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << *p << std::endl;

    for (int i = 0; i < 4; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}