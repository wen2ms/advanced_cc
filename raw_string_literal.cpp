#include <iostream>
#include <string>

int main() {
    std::string str = R"(This is a "raw" string)";

    std::string windows_path = R"(C:\Program Files\file.txt)";

    std::string multiline = R"(I have a dream
I have a dream that one day every valley shall be exalted,
every hill and mountain shall be made low...)";

    std::cout << "---------------------" << std::endl;

    std::cout << str << std::endl;
    std::cout << "---------------------" << std::endl;

    std::cout << windows_path << std::endl;
    std::cout << "---------------------" << std::endl;

    std::cout << multiline << std::endl;
    std::cout << "---------------------" << std::endl;

    return 0;
}