#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> shared_ptr_1;
    std::shared_ptr<int> shared_ptr_2;

    shared_ptr_1 = std::make_shared<int>(20);

    std::weak_ptr<int> weak_ptr(shared_ptr_1);

    shared_ptr_2 = weak_ptr.lock();

    std::cout << "Weak ptr, use_count: " << weak_ptr.use_count() << '\n';

    shared_ptr_1.reset();
    std::cout << "Weak ptr, use_count: " << weak_ptr.use_count() << '\n';

    shared_ptr_1 = weak_ptr.lock();
    std::cout << "Weak ptr, use_count: " << weak_ptr.use_count() << '\n';

    std::cout << "Weak ptr, expired: " << weak_ptr.expired() << '\n';

    weak_ptr.reset();
    std::cout << "Weak ptr, expired: " << weak_ptr.expired() << '\n';

    // 
    std::shared_ptr<int[]> shared_ptr_3(new int[3]);
    std::weak_ptr<int[]> weak_ptr_2 = shared_ptr_3;

    return 0;
}