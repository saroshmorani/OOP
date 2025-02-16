#include<iostream>
#include<cstdlib>
using namespace std;

class Invoice{
    private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

    public:
    //constructor
    Invoice(string partNumber, string partDescription, int quantity, double pricePerItem) {
        this->partNumber = partNumber;
        this->partDescription = partDescription;
        this->quantity = (quantity > 0) ? quantity : 0;
        this->pricePerItem = (pricePerItem > 0) ? pricePerItem : 0.0;
    }

    //getters
    double getInvAmount(int quantity, double pricePerItem){
        return quantity*pricePerItem;
    }

    string getPartNumber() {
        return partNumber;
    }

    string getPartDescription() {
        return partDescription;
    }

    int getQuantity() {
        return quantity;
    }

    double getPricePerItem() {
        return pricePerItem;
    }

    //setters
    void setPartNumber(string partNumber) {
        partNumber = partNumber; 
    }
    void setPartDescription(string partDescription) {
        partDescription =partDescription;
    }
    void setQuantity(int quantity) {
        quantity = (quantity > 0) ? quantity : 0;
    }

    void setPricePerItem(double PricePerItem) {
        pricePerItem = (PricePerItem> 0) ? PricePerItem : 0.0;
    }

    //display
    void displayInvoice(){
        cout << "Part Number: " << partNumber << endl;
        cout << "Part Description: " << partDescription << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: $" << pricePerItem << endl;
        cout << "Invoice Amount: $" << getInvAmount(quantity, pricePerItem) << endl;
    }

};

int main(int argc, char* argv[]){

    if(argc != 5){
        return 1;
    }

    string partNumber= argv[1];
    string partDescription= argv[2];
    int quantity= atoi(argv[3]);
    double pricePerItem= atof(argv[4]);

    Invoice i1(partNumber, partDescription, quantity, pricePerItem);

    i1.displayInvoice();
}