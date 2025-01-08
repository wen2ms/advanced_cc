#include <iostream>
#include <string>
#include <functional>

using func_ptr = void(*)();

class Animation {
  public:
    void title() {
        std::cout << "Title is " << title_ << std::endl;
    }

    static void print_type() {
        std::cout << "Animation..." << std::endl;
    }

    operator func_ptr() {
        return print_type;
    }

    std::string title_;
};

class Display {
  public:
    void operator()() {
        std::cout << "Functor..." << std::endl;
    }
};

int main() {
    std::function<void()> fun1 = Animation::print_type;
    std::function<void()> fun2 = Display();
    std::function<void()> fun3 = Animation();
    
    fun1();
    fun2();
    fun3();

    return 0;
}