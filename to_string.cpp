#include <iostream>
#include <string>

int main() {
    long double pi = 3.1415926;
    std::string pi_str = "pi is " + std::to_string(pi);
    std::string love = "love is " + std::to_string(13.14);

    std::cout << pi_str << '\n';
    std::cout << love << '\n';

    std::string decimal = "2022.02.04, Beijing Winter Olympics";
    std::string hex = "10A";
    std::string bin = "-10101";
    std::string any = "0x7f";

    size_t integer;

    int integer_dec = std::stoi(decimal, &integer);
    int integer_hex = std::stoi(hex, nullptr, 16);
    int integer_bin = std::stoi(bin, nullptr, 2);
    int integer_any = std::stoi(any, nullptr, 0);

    std::cout << "integer = " << integer << '\n';
    std::cout << decimal << " => " << integer_dec << '\n';
    std::cout << hex << " => " << integer_hex << '\n';
    std::cout << bin << " => " << integer_bin << '\n';
    std::cout << any << " => " << integer_any << '\n';

    return 0;
}