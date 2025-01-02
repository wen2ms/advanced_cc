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

int main() {
    Stu student;

    print_name func_1 = &Student::get_name;
    display_name func_2 = print_student;

    (student.*func_1)();
    func_2(student);

    return 0;
}