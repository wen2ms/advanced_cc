#include <bitset>
#include <iostream>

int main() {
    // 00000101
    unsigned int a = 5;
    // 00000011
    unsigned int b = 3;

    unsigned int res_and = a & b;
    unsigned int res_or = a | b;
    unsigned int res_not = ~a;
    unsigned int res_xor = a ^ b;
    unsigned int res_l_shift = a << 1;
    unsigned int res_r_shift = a >> 1;

    std::cout << "AND: " << res_and << std::endl;
    std::cout << "OR : " << res_or << std::endl;
    std::cout << "NOT: " << std::bitset<8>(res_not) << std::endl;
    std::cout << "XOR: " << res_xor << std::endl;
    std::cout << "<< : " << std::bitset<8>(res_l_shift) << std::endl;
    std::cout << ">> : " << res_r_shift << std::endl;

    return 0;
}