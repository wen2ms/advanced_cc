#include <iostream>
#include <functional>
#include <string>

void call_func(int x, int y, const std::function<void(int, int)>& func) {
    if (x % 2 == 0 && y % 2 == 0) {
        func(x, y);
    }
}

void my_add(int x, int y) {
    std::cout << "x: " << x << ", y: " << y << ", x + y: " << x + y << std::endl;
}

class Animation {
  public:
    void title() {
        std::cout << "Title is " << title_ << std::endl;
    }

    std::string title_;
};

int main() {
    for (int i = 0; i < 10; ++i) {
        // auto_func doesn't work in call_func, std::placeholders::_<x> must be used 
        // auto func = std::bind(my_add, i + 1, i + 2);
        // call_func(i, i, func);

        auto func = std::bind(my_add, std::placeholders::_1, std::placeholders::_2);
        call_func(i, i, func);
    }

    Animation animation{"Frieren"};
    auto title_bind = std::bind(&Animation::title, &animation);
    title_bind();

    auto title_variable = std::bind(&Animation::title_, &animation);
    std::cout << "Title: " << title_variable() << std::endl;;
    title_variable() = "Arcane";
    std::cout << "Title: " << title_variable() << std::endl;;

    std::function<void()> title_func = title_bind;
    title_func();

    std::function<std::string&()> title_variable_func = title_variable;
    std::cout << "Title: " << title_variable_func() << std::endl;;    

    return 0;
}