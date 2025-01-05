#include <iostream>

class Rectangle {
  public:
    Rectangle(int width, int height) : width_(width), height_(height) {}

    Rectangle(std::pair<int, int> size) : Rectangle(size.first, size.second) {}

    Rectangle(int side) : Rectangle(side, side) {}

    void display() const {
        std::cout << "Width: " << width_ << ", Height: " << height_ << std::endl;
    }
  
  private:
    int width_;
    int height_;
};  

int main() {
    Rectangle rect1(10), rect2(std::make_pair(1, 3)), rect3(2, 5);

    rect1.display();
    rect2.display();
    rect3.display();

    return 0;
}