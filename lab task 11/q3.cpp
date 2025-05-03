#include <iostream>
#include <stdexcept>

class ArrayIndexOutOfBounds : public std::exception {
public:
    const char* what() const noexcept override {
        return "ArrayIndexOutOfBounds: Index out of valid range.";
    }
};

template <typename T>
class SafeArray {
private:
    T* arr;
    size_t size;

public:
    SafeArray(size_t n) : size(n) {
        arr = new T[n];
    }

    ~SafeArray() {
        delete[] arr;
    }

    SafeArray(const SafeArray&) = delete;
    SafeArray& operator=(const SafeArray&) = delete;

    T& operator[](int index) {
        if (index < 0 || static_cast<size_t>(index) >= size) {
            throw ArrayIndexOutOfBounds();
        }
        return arr[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || static_cast<size_t>(index) >= size) {
            throw ArrayIndexOutOfBounds();
        }
        return arr[index];
    }

    size_t getSize() const {
        return size;
    }
};
int main() {
    SafeArray<int> arr(5);

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    std::cout << "Array contents:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    try {
        std::cout << "\nAccessing arr[10]:\n";
        std::cout << arr[10] << "\n";
    } catch (const ArrayIndexOutOfBounds& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}

