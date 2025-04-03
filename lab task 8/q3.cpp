#include <iostream>
using namespace std;

class Currency {
protected:
    string currencyCode, currencySymbol;
    double amount, exchangeRate;

public:
    Currency(string code, string symbol, double amt, double rate)
        : currencyCode(code), currencySymbol(symbol), amount(amt), exchangeRate(rate) {}

    virtual double convertToBase() = 0; 
    virtual double convertTo(string targetCurrency) = 0; 
    virtual void displayCurrency() = 0;
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency("USD", "$", amt, 1.0) {} 

    double convertToBase() override { return amount; } 
    double convertTo(string targetCurrency) override {
        if (targetCurrency == "Euro") return amount * 0.91;
        if (targetCurrency == "Rupee") return amount * 280.0;
        return amount;
    }
    void displayCurrency() override { cout << currencySymbol << amount << " (" << currencyCode << ")\n"; }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency("EUR", "€", amt, 1.1) {}

    double convertToBase() override { return amount * 1.1; } 
    double convertTo(string targetCurrency) override {
        if (targetCurrency == "USD") return amount * 1.1;
        if (targetCurrency == "Rupee") return amount * 310.0;
        return amount;
    }
    void displayCurrency() override { cout << currencySymbol << amount << " (" << currencyCode << ")\n"; }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency("PKR", "Rs", amt, 0.0036) {}

    double convertToBase() override { return amount * 0.0036; } 
    double convertTo(string targetCurrency) override {
        if (targetCurrency == "USD") return amount * 0.0036;
        if (targetCurrency == "Euro") return amount * 0.0032;
        return amount;
    }
    void displayCurrency() override { cout << currencySymbol << amount << " (" << currencyCode << ")\n"; }
};

int main() {
    Dollar usd(300);
    Euro eur(109);
    Rupee pkr(10300);

    cout << "Currency Conversions:\n";
    usd.displayCurrency();
    cout << "Converted to Euro: " << usd.convertTo("Euro") << " EUR\n";
    cout << "Converted to Rupee: " << usd.convertTo("Rupee") << " PKR\n\n";

    eur.displayCurrency();
    cout << "Converted to USD: " << eur.convertTo("USD") << " USD\n";
    cout << "Converted to Rupee: " << eur.convertTo("Rupee") << " PKR\n\n";

    pkr.displayCurrency();
    cout << "Converted to USD: " << pkr.convertTo("USD") << " USD\n";
    cout << "Converted to Euro: " << pkr.convertTo("Euro") << " EUR\n";

    return 0;
}

