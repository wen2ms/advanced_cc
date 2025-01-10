#include <iostream>

int main() {
    int number = 10;

    int& l_reference = number;
    
    int&& r_reference = 20;

    const int& const_l_reference_1 = 10;
    const int& const_l_reference_2 = number;
    const int& const_l_reference_3 = l_reference;
    const int& const_l_reference_4 = r_reference;

    // Error
    // constexpr int& constexpr_l_reference = 10; 

    const int&& const_r_reference_1 = 10;

    // Error
    // const int&& const_r_reference_2 = r_reference;

    return 0;
}