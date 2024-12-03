#include <iostream>
#include <string>

using std::stoi;

namespace print_functions {
namespace print_letters {
void print_letters(const std::string& input_string) {
    for (int i = 0; i < input_string.length(); i++) {
        std::cout << input_string.at(i) << ' ';
    }
    std::cout << std::endl;
}
}  // namespace print_letters
}  // namespace print_functions

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " LetterNumber" << std::endl;
        return 1;
    }

    const int kLetterNumber = std::stoi(argv[1]);

    std::string input_string;
    for (int i = 0; i < kLetterNumber; i++) {
        input_string.append(1, 'A' + i);
    }

    namespace display_letters = print_functions::print_letters;

    display_letters::print_letters(input_string);

    return 0;
}