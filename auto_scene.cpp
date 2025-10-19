#include <iostream>
#include <map>
#include <string>

class Dog {
  public:
    static int calls() {
        return id_;
    }

    static int id_;
};

class Cat {
  public:
    static std::string calls() {
        return name_;
    }

    static std::string name_;
};

int Dog::id_ = 1;
std::string Cat::name_ = "Cat";

template <class T>
void call_member() {
    auto member = T::calls();
    std::cout << "Member is " << member << '\n';
}

int main() {
    call_member<Dog>();
    call_member<Cat>();

    std::map<int, Cat> cats_map;

    cats_map.insert(std::make_pair(0, Cat()));
    cats_map.insert(std::make_pair(1, Cat()));

    for (const std::pair<const int, Cat>& cat : cats_map) {
        std::cout << cat.first << " " << Cat::name_ << '\n';
    }

    return 0;
}
