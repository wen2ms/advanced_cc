#include <iostream>

float my_divide(float a, float b) {
    if (b == 0) {
        throw std::runtime_error("Divided by zero!");
    }

    return a / b;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " number1 number2" << std::endl;
        return 1;
    }

    try {
        float a = std::stof(argv[1]);
        float b = std::stof(argv[2]);

        float result = my_divide(a, b);
        std::cout << a << " / " << b << " is " << result << std::endl;
    }     
    catch (std::invalid_argument& e) {
        std::cout << "Exception: please enter numbers!" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}