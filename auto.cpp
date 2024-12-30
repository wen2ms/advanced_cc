#include <iostream>

int main() {
    const auto kValue = 250;

    // kA: const int
    const auto kA = kValue;

    //  When the variable isn't a pointer or reference, const or volatile is ignored 
    // kB: int 
    auto kB = kA;

    // kC: const int&
    auto& kC = kA; 

    return 0;
}