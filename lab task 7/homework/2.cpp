#include <iostream>

class Shape {
private:
    float length;
    float width;

public:
    Shape(float l = 0, float w = 0) : length(l), width(w) {}

    float Area() const {
        return length * width;
    }

    float operator+(const Shape& other) const {
        return this->Area() + other.Area();
    }

    void display() const {
        std::cout << "Length: " << length << ", Width: " << width << ", Area: " << Area() << std::endl;
    }
};
int main() {
    Shape shape1(5, 4);
    Shape shape2(3, 2);

    shape1.display();
    shape2.display();

    float totalArea = shape1 + shape2;
    std::cout << "Total Area (shape1 + shape2): " << totalArea << std::endl;

    return 0;
}

