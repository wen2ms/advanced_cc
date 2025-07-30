#include <iostream>
#include <optional>
#include <string>

class User {
  public:
    User(const std::string& name, std::optional<std::string> nick_name, std::optional<int> age)
        : name_(name), nick_name_(nick_name), age_(age) {}

    friend std::ostream& operator<<(std::ostream& out, const User& user) {
        out << user.name_ << ' ';
        if (user.nick_name_.has_value()) {
            out << user.nick_name_.value() << ' ';
        }
        if (user.age_ == std::nullopt) {
            out << *user.age_ << ' ';
        }

        return out;
    }

  private:
    std::string name_;
    std::optional<std::string> nick_name_;
    std::optional<int> age_;
};

int main() {
    User peter("Peter", "Tree", 23);
    User catty("Catty", std::nullopt, std::nullopt);

    std::cout << peter << std::endl;

    std::cout << catty << std::endl;

    return 0;
}