#include <iostream>
#include <string>

class Color {
  public:
    Color(std::string color_name = "tomato") : color_name_(color_name) {}
    
    void modify_color(std::string other_color) {
        color_name_ = other_color;
    }

    std::string color_name_;
};

void modify_const_string(std::string& str) {
    str[0] = 'A';
    std::cout << str << std::endl;
}

void modify_const_string(char* str) {
    // Can't modify const pointer's contents
    // A const std::string means that the string object itself
    // str[0] = 'A';
    std::cout << str << std::endl;
}

int main() {
    const Color color;

    const_cast<Color&>(color).modify_color("red");

    std::cout << "Color is " << color.color_name_ << std::endl;

    const std::string str1 = "Test1";
    // This is a undefined behavior for modify const string
    // modify_const_string(const_cast<std::string&>(str1));

    const char* str2 = "Test2";
    modify_const_string(const_cast<char*>(str2));

    float number = 3.14;
    std::cout << static_cast<int>(number) << std::endl;

    return 0;
}