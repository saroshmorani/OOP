#include <iostream>
#include <cstdlib>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void reduce() {
        if (denominator == 0) {
            std::cout << "Error: Denominator cannot be zero.\n";
            std::exit(1);
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cout << "Error: Cannot divide by zero fraction.\n";
            std::exit(1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);
};

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    if (f.denominator == 1)
        os << f.numerator;
    else
        os << f.numerator << "/" << f.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    int num, denom;
    char slash;
    is >> num >> slash >> denom;
    if (slash != '/' || denom == 0) {
        std::cout << "Invalid input. Format must be a/b with b != 0.\n";
        std::exit(1);
    }
    f = Fraction(num, denom);
    return is;
}
int main() {
    Fraction f1(2, 4), f2(3, 6);
    std::cout << (f1 + f2) << std::endl;

    Fraction f3;
    std::cout << "Enter a fraction (format: a/b): ";
    std::cin >> f3;
    std::cout << "You entered: " << f3 << std::endl;

    return 0;
}

