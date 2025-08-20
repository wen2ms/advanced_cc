#include <iostream>
#include <string>

float my_divide(float dividend, float divisor) {
    if (divisor == 0) {
        throw std::runtime_error("Divided by zero!");
    }
    return dividend / divisor;
}

class MyException {
  public:
    explicit MyException(std::string msg) : msg_(msg) {}

    std::string msg_;
};

void foo() {
    try {
        throw MyException("string exception!");
    } catch (MyException e) {
        std::cout << e.msg_ << '\n';
    }

    std::cout << "over..." << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " number1 number2" << '\n';
        return 1;
    }

    foo();

    try {
        float dividend = std::stof(argv[1]);
        float divisor = std::stof(argv[2]);

        float result = my_divide(dividend, divisor);
        std::cout << dividend << " / " << divisor << " is " << result << '\n';
    } catch (std::invalid_argument& e) {
        std::cerr << "Exception: please enter numbers!" << '\n';
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}