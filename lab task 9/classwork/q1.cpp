#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawLimit;
    double depositedToday;
    double withdrawnToday;

public:
    Wallet(double depositLimit = 5000, double withdrawLimit = 3000)
        : balance(0), dailyDepositLimit(depositLimit), dailyWithdrawLimit(withdrawLimit),
          depositedToday(0), withdrawnToday(0) {}

    bool deposit(double amount) {
        if (amount <= 0 || depositedToday + amount > dailyDepositLimit) return false;
        balance += amount;
        depositedToday += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance || withdrawnToday + amount > dailyWithdrawLimit)
            return false;
        balance -= amount;
        withdrawnToday += amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        depositedToday = 0;
        withdrawnToday = 0;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string n) : userID(id), name(n) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    double checkBalance() const {
        return wallet.getBalance();
    }

    void resetDailyLimits() {
        wallet.resetDailyLimits();
    }
};

int main() {
    User user1("U001", "Ali");
    User user2("U002", "Sara");

    cout << "Ali deposits 2000: " << (user1.deposit(2000) ? "Success" : "Failed") << endl;
    cout << "Ali withdraws 1000: " << (user1.withdraw(1000) ? "Success" : "Failed") << endl;
    cout << "Ali tries to withdraw 5000: " << (user1.withdraw(5000) ? "Success" : "Failed") << endl;

    cout << "Sara deposits 6000 (over limit): " << (user2.deposit(6000) ? "Success" : "Failed") << endl;

    cout << "Ali's Balance: " << user1.checkBalance() << endl;
}

