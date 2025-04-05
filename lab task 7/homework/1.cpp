#include <iostream>

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};
int main() {
    Number n(8);

    std::cout << "Original: ";
    n.display();

    --n; 
	std::cout << "After Prefix -- : ";
    n.display();

    n--;
    std::cout << "After Postfix -- : ";
    n.display();

    return 0;
}

