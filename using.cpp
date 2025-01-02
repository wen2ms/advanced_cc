#include <iostream>
#include <string>

typedef struct Student {
    void get_name() {
        std::cout << "Student name: " << name << std::endl;
    }

    std::string name = "student";
} Stu;

void print_student(const Student& student) {
    std::cout << "Student name: " << student.name << std::endl;
}

typedef void (Stu::*print_name)();
using display_name = void (*)(const Student& student);

template <typename T>
struct MyType {
    typedef std::pair<int, T> my_pair; 
};

template <typename T>
using custom_pair = std::pair<int, T>;

int main() {
    MyType<double>::my_pair pair_1{1, 2};
    custom_pair<double> pair_2(1, 2);

    std::cout << pair_1.first << ' ' << pair_1.second << std::endl;
    std::cout << pair_1.first << ' ' << pair_1.second << std::endl;

    Stu student;

    print_name func_1 = &Student::get_name;
    display_name func_2 = print_student;

    std::cout << std::endl;
    (student.*func_1)();
    func_2(student);

    return 0;
}