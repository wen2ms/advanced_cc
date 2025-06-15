#include <iostream>
#include <string>

int main() {
    long double pi = 3.1415926;
    std::string pi_str = "pi is " + std::to_string(pi);
    std::string love = "love is " + std::to_string(13.14);

    std::cout << pi_str << std::endl;
    std::cout << love << std::endl;

    std::string decimal = "2022.02.04, Beijing Winter Olympics";
    std::string hex = "10A";
    std::string bin = "-10101";
    std::string any = "0x7f";

    size_t sz;

    int integer_dec = std::stoi(decimal, &sz);
    int integer_hex = std::stoi(hex, nullptr, 16);
    int integer_bin = std::stoi(bin, nullptr, 2);
    int integer_any = std::stoi(any, nullptr, 0);

    std::cout << "sz = " << sz << std::endl;
    std::cout << decimal << " => " << integer_dec << std::endl;
    std::cout << hex << " => " << integer_hex << std::endl;
    std::cout << bin << " => " << integer_bin << std::endl;
    std::cout << any << " => " << integer_any << std::endl;

    return 0;
}