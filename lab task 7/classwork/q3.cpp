#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class BigInteger {
private:
    std::vector<int> digits;
    bool isNegative;

    void normalize() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

    static BigInteger add(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        result.digits.clear();
        
        int carry = 0;
        size_t max_len = a.digits.size() > b.digits.size() ? a.digits.size() : b.digits.size();
        
        for (size_t i = 0; i < max_len || carry; ++i) {
            int digit_a = (i < a.digits.size()) ? a.digits[i] : 0;
            int digit_b = (i < b.digits.size()) ? b.digits[i] : 0;
            
            int sum = digit_a + digit_b + carry;
            carry = sum / 10;
            result.digits.push_back(sum % 10);
        }
        
        return result;
    }

    static BigInteger subtract(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        result.digits.clear();
        
        int borrow = 0;
        for (size_t i = 0; i < a.digits.size(); ++i) {
            int digit_a = a.digits[i];
            int digit_b = (i < b.digits.size()) ? b.digits[i] : 0;
            
            digit_a -= borrow;
            borrow = 0;
            
            if (digit_a < digit_b) {
                digit_a += 10;
                borrow = 1;
            }
            
            result.digits.push_back(digit_a - digit_b);
        }
        
        result.normalize();
        return result;
    }

    static bool absLess(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) {
            return a.digits.size() < b.digits.size();
        }
        
        for (int i = static_cast<int>(a.digits.size()) - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] < b.digits[i];
            }
        }
        
        return false;
    }

public:
    BigInteger() : isNegative(false) {
        digits.push_back(0);
    }

    BigInteger(long long num) {
        if (num < 0) {
            isNegative = true;
            num = -num;
        } else {
            isNegative = false;
        }
        
        if (num == 0) {
            digits.push_back(0);
        } else {
            while (num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }
        }
    }

    BigInteger(const std::string& s) {
        if (s.empty()) {
            digits.push_back(0);
            isNegative = false;
            return;
        }
        
        size_t start = 0;
        if (s[0] == '-') {
            isNegative = true;
            start = 1;
        } else {
            isNegative = false;
        }
        
        for (int i = static_cast<int>(s.size()) - 1; i >= static_cast<int>(start); --i) {
            if (!isdigit(s[i])) {
                throw std::invalid_argument("Invalid character in BigInteger string");
            }
            digits.push_back(s[i] - '0');
        }
        
        normalize();
    }

    BigInteger operator-() const {
        BigInteger result(*this);
        if (result != BigInteger(0)) {
            result.isNegative = !result.isNegative;
        }
        return result;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = add(*this, other);
            result.isNegative = isNegative;
            return result;
        } else {
            if (absLess(*this, other)) {
                BigInteger result = subtract(other, *this);
                result.isNegative = other.isNegative;
                return result;
            } else {
                BigInteger result = subtract(*this, other);
                result.isNegative = isNegative;
                return result;
            }
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        return *this + (-other);
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);
        
        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                long long current = result.digits[i + j] + 
                                  digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + 
                                  carry;
                result.digits[i + j] = current % 10;
                carry = current / 10;
            }
        }
        
        result.isNegative = isNegative != other.isNegative;
        result.normalize();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        
        if (isNegative) {
            return absLess(other, *this);
        } else {
            return absLess(*this, other);
        }
    }

    bool operator<=(const BigInteger& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const BigInteger& other) const {
        return !(*this <= other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        if (num.isNegative) {
            os << '-';
        }
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        std::string s;
        is >> s;
        num = BigInteger(s);
        return is;
    }
};
int main() {
    BigInteger num1("12345678901234567890");
    BigInteger num2("98765432109876543210");
    
    BigInteger num3 = -12345;
    
    BigInteger num4;
    std::cout << "Enter a big integer: ";
    std::cin >> num4;
    
    BigInteger sum = num1 + num2;
    BigInteger diff = num2 - num1;
    BigInteger product = num1 * num3;
    BigInteger negation = -num1;
    
    std::cout << "\nnum1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    std::cout << "num3 = " << num3 << std::endl;
    std::cout << "num4 = " << num4 << std::endl;
    std::cout << "\nSum (num1 + num2) = " << sum << std::endl;
    std::cout << "Difference (num2 - num1) = " << diff << std::endl;
    std::cout << "Product (num1 * num3) = " << product << std::endl;
    std::cout << "Negation (-num1) = " << negation << std::endl;
    
    std::cout << "\nComparison results:" << std::endl;
    std::cout << "num1 == num2: " << (num1 == num2 ? "true" : "false") << std::endl;
    std::cout << "num1 != num2: " << (num1 != num2 ? "true" : "false") << std::endl;
    std::cout << "num1 < num2: " << (num1 < num2 ? "true" : "false") << std::endl;
    std::cout << "num1 > num2: " << (num1 > num2 ? "true" : "false") << std::endl;
    std::cout << "num1 <= num2: " << (num1 <= num2 ? "true" : "false") << std::endl;
    std::cout << "num1 >= num2: " << (num1 >= num2 ? "true" : "false") << std::endl;
    
    BigInteger zero;
    BigInteger large("9999999999999999999999999999999999999999");
    std::cout << "\nEdge cases:" << std::endl;
    std::cout << "Zero: " << zero << std::endl;
    std::cout << "Very large number: " << large << std::endl;
    std::cout << "Large + Negative: " << large + BigInteger("-1000000000000000000000") << std::endl;
    
    return 0;
}
