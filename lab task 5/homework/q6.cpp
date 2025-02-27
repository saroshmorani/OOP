#include <iostream>
using namespace std;

struct MenuItem {
    string name;
    double price;
    string type;
};

class CoffeeShop {
private:
    string name;
    MenuItem menu[10];
    string orders[10];
    int menuSize;
    int orderCount;

public:
    CoffeeShop(string shopName, MenuItem menuItems[], int size)
        : name(shopName), menuSize(size), orderCount(0) {
        for (int i = 0; i < size; i++) {
            menu[i] = menuItems[i];
        }
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                orders[orderCount++] = itemName;
                return "Order added: " + itemName;
            }
        }
        return "This item is currently not available!";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 1; i < orderCount; i++) {
                orders[i - 1] = orders[i];
            }
            orderCount--;
            return "The " + item + " is ready!";
        }
        return "orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders." << endl;
            return;
        }
        for (int i = 0; i < orderCount; i++) {
            cout << orders[i] << " ";
        }
        cout << endl;
    }

    double dueAmount() {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0) return "Menu is empty";
        MenuItem cheapest = menu[0];
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    void drinksOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }

    void foodOnly() {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    MenuItem menu[] = {
        {"Espresso", 3.5, "drink"},
        {"Chai", 4.0, "drink"},
        {"Paratha", 2.5, "food"},
        {"Sandwich", 5.0, "food"}
    };
    
    CoffeeShop myShop("Cafe Imran", menu, 4);
    
    cout << myShop.addOrder("Espresso") << endl;
    cout << myShop.addOrder("Paratha") << endl;
    cout << myShop.fulfillOrder() << endl;
    cout << "Total Due: $" << myShop.dueAmount() << endl;
    cout << "Cheapest Item: " << myShop.cheapestItem() << endl;
    
    cout << "Drinks: ";
    myShop.drinksOnly();
    cout << "Foods: ";
    myShop.foodOnly();
    
    return 0;
}
