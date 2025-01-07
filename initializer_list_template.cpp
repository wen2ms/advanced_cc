#include <iostream>
#include <vector>
#include <string>

void display(std::initializer_list<int> input_list) {
    for (auto it = input_list.begin(); it != input_list.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

class Dogs {
  public:
    Dogs(std::initializer_list<std::string> input_names) {
        for (auto it = input_names.begin(); it != input_names.end(); ++it) {
            dog_names_.push_back(*it);
            std::cout << *it << ' ';
        }
        std::cout << std::endl;
    } 

  private:
    std::vector<std::string> dog_names_;
};

int main(int argc, char* argv[]) {
    display({1, 2, 3, 4});

    Dogs dogs({"A", "B", "C"});

    return 0;
}