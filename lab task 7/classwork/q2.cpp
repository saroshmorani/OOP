#include <iostream>
#include <vector>
#include <string>

class PolynomialUtils;

class Polynomial {
private:
    std::vector<int> coeffs;

    void trim() {
        while (!coeffs.empty() && coeffs.back() == 0)
            coeffs.pop_back();
    }

public:
    Polynomial() {}

    Polynomial(const std::vector<int>& c) : coeffs(c) {
        trim();
    }

    Polynomial operator+(const Polynomial& other) const {
        std::vector<int> result(std::max(coeffs.size(), other.coeffs.size()), 0);
        for (size_t i = 0; i < coeffs.size(); ++i)
            result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i)
            result[i] += other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        std::vector<int> result(std::max(coeffs.size(), other.coeffs.size()), 0);
        for (size_t i = 0; i < coeffs.size(); ++i)
            result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i)
            result[i] -= other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
        for (size_t i = 0; i < coeffs.size(); ++i)
            for (size_t j = 0; j < other.coeffs.size(); ++j)
                result[i + j] += coeffs[i] * other.coeffs[j];
        return Polynomial(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
    friend class PolynomialUtils;
};

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    if (p.coeffs.empty()) {
        os << "0";
        return os;
    }

    bool first = true;
    for (int i = p.coeffs.size() - 1; i >= 0; --i) {
        int coef = p.coeffs[i];
        if (coef == 0) continue;

        if (!first) {
            os << (coef > 0 ? " + " : " - ");
        } else {
            if (coef < 0)
                os << "-";
            first = false;
        }

        int absCoef = std::abs(coef);
        if (absCoef != 1 || i == 0)
            os << absCoef;
        if (i > 0) {
            os << "x";
            if (i > 1)
                os << "^" << i;
        }
    }

    return os;
}

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power = 1;
        for (int coef : p.coeffs) {
            result += coef * power;
            power *= x;
        }
        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        if (p.coeffs.size() <= 1)
            return Polynomial({0});
        std::vector<int> deriv(p.coeffs.size() - 1);
        for (size_t i = 1; i < p.coeffs.size(); ++i)
            deriv[i - 1] = p.coeffs[i] * i;
        return Polynomial(deriv);
    }
};
int main() {
    Polynomial p1({-1, 0, 5, 2});
    Polynomial p2({0, 1, 3}); 

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    std::cout << "P1: " << p1 << std::endl;
    std::cout << "P2: " << p2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Diff: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;

    std::cout << "P1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << std::endl;
    std::cout << "Derivative of P1: " << PolynomialUtils::derivative(p1) << std::endl;

    return 0;
}

