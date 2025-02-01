#include <iostream>

#include "foo.h"

int bar1();
int bar2();

int main() {
    int sum = bar1() + bar2();
    
    std::cout << sum << std::endl;

    return 0;
}