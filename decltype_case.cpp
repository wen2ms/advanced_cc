#include <iostream>
#include <list>

template <class T>
class MyContainer {
  public:
    void for_each_print(T& t) {
        for (container_it_ = t.begin(); container_it_ != t.end(); ++container_it_) {
            std::cout << "Value: " << *container_it_ << std::endl;
        }
    }

  private:
    decltype(T().begin()) container_it_;
};

int main() {
    std::list<int> age_list{1, 2, 3, 4, 5};
    const std::list<std::string> breeds{"Doberman", "French Bulldog", "Golden Retriver"};

    MyContainer<std::list<int>> my_container;
    MyContainer<const std::list<std::string>> breeds_container;

    my_container.for_each_print(age_list);
    breeds_container.for_each_print(breeds);

    return 0;
}