#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> shared_ptr_1, shared_ptr_2;

    shared_ptr_1 = std::make_shared<int>(20);

    std::weak_ptr<int> weak_ptr(shared_ptr_1);

    shared_ptr_2 = weak_ptr.lock();

    std::cout << "Weak ptr, use_count: " << weak_ptr.use_count() << std::endl;

    shared_ptr_1.reset();
    std::cout << "Weak ptr, use_count: " << weak_ptr.use_count() << std::endl;

    shared_ptr_1 = weak_ptr.lock();
    std::cout << "Weak ptr, use_count: " << weak_ptr.use_count() << std::endl;

    std::cout << "Weak ptr, expired: " << weak_ptr.expired() << std::endl;

    weak_ptr.reset();
    std::cout << "Weak ptr, expired: " << weak_ptr.expired() << std::endl;

    return 0;
}