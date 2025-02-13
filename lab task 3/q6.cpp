#include <iostream>
#include <vector>

class Matrix {
private:
    int rows, cols;
    std::vector<std::vector<int>> mat;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(rows, std::vector<int>(cols, 0));
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            mat[i][j] = value;
        } else {
            std::cout << "Invalid index!" << std::endl;
        }
    }

    int getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return mat[i][j];
        } else {
            std::cout << "Invalid index!" << std::endl;
            return -1;
        }
    }

    void displayMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix add(const Matrix& other) {
        if (this->rows != other.rows || this->cols != other.cols) {
            std::cout << "Matrices cannot be added!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, mat[i][j] + other.mat[i][j]);
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& other) {
        if (this->cols != other.rows) {
            std::cout << "Matrices cannot be multiplied!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += mat[i][k] * other.mat[k][j];
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }
};

int main() {
    Matrix m1(2, 3);
    m1.setElement(0, 0, 1);
    m1.setElement(0, 1, 2);
    m1.setElement(0, 2, 3);
    m1.setElement(1, 0, 4);
    m1.setElement(1, 1, 5);
    m1.setElement(1, 2, 6);

    Matrix m2(2, 3);
    m2.setElement(0, 0, 7);
    m2.setElement(0, 1, 8);
    m2.setElement(0, 2, 9);
    m2.setElement(1, 0, 10);
    m2.setElement(1, 1, 11);
    m2.setElement(1, 2, 12);

    std::cout << "Matrix 1: " << std::endl;
    m1.displayMatrix();

    std::cout << "Matrix 2: " << std::endl;
    m2.displayMatrix();

    Matrix sum = m1.add(m2);
    std::cout << "Sum of Matrices: " << std::endl;
    sum.displayMatrix();

    Matrix m3(3, 2);
    m3.setElement(0, 0, 1);
    m3.setElement(0, 1, 2);
    m3.setElement(1, 0, 3);
    m3.setElement(1, 1, 4);
    m3.setElement(2, 0, 5);
    m3.setElement(2, 1, 6);

    Matrix product = m1.multiply(m3);
    std::cout << "Product of Matrices: " << std::endl;
    product.displayMatrix();

    return 0;
}
