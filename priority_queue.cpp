#include <iostream>
#include <functional>
#include <vector>
#include <queue>

struct Point {
    bool operator< (const Point& other) const {
        return x < other.x;
    }

    int x;
    int y;
};

int main() {
    std::priority_queue<Point, std::vector<Point>> points;

    points.push({1, 2});
    points.push({9, 2});
    points.push({4, 3});
    points.push({0, 2});
    points.push({-1, -1});

    while (!points.empty()) {
        std::cout << points.top().x << ' '; 
        points.pop();
    }
    std::cout << std::endl;

    std::priority_queue<int, std::vector<int>, std::greater<int>> numbers;

    numbers.push(8);
    numbers.push(2);
    numbers.push(1);
    numbers.push(9);
    numbers.push(-1);
    numbers.push(-3);

    while (!numbers.empty()) {
        std::cout << numbers.top() << ' '; 
        numbers.pop();
    }
    std::cout << std::endl;

    return 0;
}