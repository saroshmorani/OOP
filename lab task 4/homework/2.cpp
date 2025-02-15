#include<iostream>
#include<cstdlib>
using namespace std;

class Account{
    private:
    double balance;

    public:
    Account(double balance){
        this-> balance=balance;
    }

    void add_amount(double amount){
        balance+=amount;
        cout << "Updated balance: " << balance << endl;
    }

    void withdraw_amount(double amount) {
        if (amount>balance){
            cout<<"Not enough balance!"<<endl;
        }
        else{
            balance-=amount;
            cout<<"Updated balance: "<<balance<<endl;
        }
    }


    double get_balance(){
        return balance;
    }
};

int main(int argc, char *argv[]){
    if (argc < 2) {
        cout << "Error" << endl;
        return 1;
    }

    double balance = stod(argv[1]);
    balance=stod(argv[1]);
    Account a(balance);
    
    int choice;
    cout<<"Press: "<<endl;
    cout<<"1 to get balance"<<endl;
    cout<<"2 to add amount"<<endl;
    cout<<"3 to withdraw amount"<<endl;
    cin>>choice;

    double amount;

    switch (choice)
    {
    case 1:
        cout<<"Current balance: "<<a.get_balance()<<endl;
        break;
    
    case 2:
        cout<<"Enter amount to add: ";
        cin >> amount;
        a.add_amount(amount);
        break;

    case 3:
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        a.withdraw_amount(amount);
        break;
    
    default:
        break;
    }
}