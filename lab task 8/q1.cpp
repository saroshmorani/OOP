#include<iostream>
using namespace std;

class Account{
	public:
		int AccNumber;
		double balance;
		string AccHolderName;
		string AccType;
		
		Account(int an, double b, string n, string t):  AccNumber(an), balance(b), AccHolderName(n), AccType(t) {};
		
		
		double deposit(double amount){
			balance+=amount;
			return amount;
		}
		double withdraw(double amount){
			if(amount<=balance){
				balance-=amount;
				return amount;
			}
			else{
				cout<<"invalid amount"<<endl;
				return 0;
			}
		}
		
		double calcInterest(double rate){
			double interest= (balance*rate)/100;
			return interest;
		}
		
		void printStatement(double rate){
			cout<<"Interest: "<<calcInterest(rate)<<endl;
			cout<<"Current Balance: "<<balance<<endl;
		}
		
		void getAccInfo(){
			cout<<"Account Number: "<<AccNumber<<endl;
			cout<<"Balance: "<<balance<<endl;
		    cout<<"Account Holder Name: "<<AccHolderName<<endl;
		    cout<<"Account Type: "<<AccType<<endl;
		}
};

class SavingsAccount: public Account{
	public:
		double InterestRate;
		double MinBalance;
		
		SavingsAccount(int an, double b, string n, string t, double rate, double minBal) 
		: Account(an, b, n, t), InterestRate(rate), MinBalance(minBal) {}
		
		void printStatement() {
            cout << "Savings Account Statement" << endl;
            Account::printStatement(InterestRate);
        }
    
};

class CheckingAccount: public Account{
	public:
    CheckingAccount(int an, double b, string n, string t)
        : Account(an, b, n, t) {}

    void printStatement() {
        cout << "Checking Account Statement" << endl;
        Account::printStatement(0);}
};

class FixedDepositAccount: public Account{
	public:
    double fixedInterestRate;
    int maturityDate;

    FixedDepositAccount(int an, double b, string n, string t, double rate, int matDate)
        : Account(an, b, n, t), fixedInterestRate(rate), maturityDate(matDate) {}

    void printStatement() {
        cout << "Fixed Deposit Account Statement" << endl;
        Account::printStatement(fixedInterestRate);
    }
};

int main(){
	SavingsAccount s(100233,5000.00,"Abdullah","Savings Account",0.30, 500.00);
	CheckingAccount c(239448, 23000.00,"Amna", "Current Account");
	FixedDepositAccount f(524556, 67000.00, "Sarim","Fixed Deposit Account", 0.33, 2028);
	
	
    s.getAccInfo();
    s.deposit(2000);
    s.withdraw(500);
    s.printStatement();

    cout<<endl;
    c.getAccInfo();
    c.deposit(3000);
    c.withdraw(1000);
    c.printStatement();

    cout<<endl;
    f.getAccInfo();
    f.printStatement();

    return 0;
}
