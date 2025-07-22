#include <iostream>

int main() {
    const auto kValue = 250;

    // kFoo: const int
    const auto kFoo = kValue;

    //  When the variable isn't a pointer or reference, const or volatile is ignored 
    // kBar: int 
    auto kBar = kFoo;

    // kC: const int&
    auto& kC = kFoo; 

    return 0;
}