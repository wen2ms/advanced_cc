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

class TVShow {
  public:
    TVShow(const std::function<void()>& func) : callback_(func) {}

    void get_type() {
        callback_();
    }

  private:
    std::function<void()> callback_;
};

int main() {
    std::function<void()> fun1 = Animation::print_type;
    std::function<void()> fun2 = Display();
    std::function<void()> fun3 = Animation();
    
    fun1();
    fun2();
    fun3();

    Display display;
    Animation animation;

    TVShow tvshow1(Animation::print_type);
    TVShow tvshow2(display);
    TVShow tvshow3(animation);

    std::cout << std::endl;
    tvshow1.get_type();
    tvshow2.get_type();
    tvshow3.get_type();

    return 0;
}