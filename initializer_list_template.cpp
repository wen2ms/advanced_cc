#include <iostream>
#include <string>
#include <vector>

void display(std::initializer_list<int> input_list) {
    for (int num : input_list) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

class Dogs {
  public:
    Dogs(std::initializer_list<std::string> input_names) {
        for (const auto& input_name : input_names) {
            dog_names_.push_back(input_name);
            std::cout << input_name << ' ';
        }
        std::cout << '\n';
    }

  private:
    std::vector<std::string> dog_names_;
};

int main(int argc, char* argv[]) {
    display({1, 2, 3, 4});

    Dogs dogs({"A", "B", "C"});

    return 0;
}