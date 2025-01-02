#include <iostream>

template <class T, class U>
auto my_add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main(int argc, char* argv[]) {
    int x = 1;
    float y = 1.414;

    std::cout << x << " + " << y << " is " << my_add(x, y) << std::endl;

    return 0;
}