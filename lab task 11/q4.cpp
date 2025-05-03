#include <iostream>

template <typename T>
class Base {
protected:
    T a, b;

public:
    Base(T x, T y) : a(x), b(y) {}

    T multiplyBase() const {
        return a * b;
    }

    void printBase() const {
        std::cout << "Base multiplication (a * b): " << multiplyBase() << std::endl;
    }
};

template <typename T>
class Derived : public Base<T> {
private:
    T c, d;

public:
    Derived(T x, T y, T z, T w) : Base<T>(x, y), c(z), d(w) {}

    T multiplyDerived() const {
        return c * d;
    }

    void printDerived() const {
        this->printBase();
        std::cout << "Derived multiplication (c * d): " << multiplyDerived() << std::endl;
    }
};

int main() {
    Derived<int> obj(2, 9, 3, 5);

    obj.printDerived();

    return 0;
}


