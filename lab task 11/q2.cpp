#include <iostream>
#include <vector>
#include <stdexcept>

class DimensionMismatchException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimension mismatch.";
    }
};

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c, const T& initial = T()) : rows(r), cols(c), data(r, std::vector<T>(c, initial)) {}

    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols)
            throw std::out_of_range("Matrix index out of bounds");
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols)
            throw std::out_of_range("Matrix index out of bounds");
        return data[r][c];
    }

    size_t numRows() const { return rows; }
    size_t numCols() const { return cols; }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.at(i, j) = this->at(i, j) + other.at(i, j);

        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw DimensionMismatchException();

        Matrix<T> result(rows, other.cols, T());
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
                }
            }
        }

        return result;
    }

    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                std::cout << val << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    A.at(0, 0) = 1; A.at(0, 1) = 2;
    A.at(1, 0) = 3; A.at(1, 1) = 4;

    B.at(0, 0) = 5; B.at(0, 1) = 6;
    B.at(1, 0) = 7; B.at(1, 1) = 8;

    try {
        Matrix<int> C = A + B;
        std::cout << "A + B:\n";
        C.print();

        Matrix<int> D = A * B;
        std::cout << "\nA * B:\n";
        D.print();

    } catch (const DimensionMismatchException& e) {
        std::cerr << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}

