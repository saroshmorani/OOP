#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct MenuItem {
    string name;
    string type;
    double price;
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> shopMenu) {
        name = shopName;
        menu = shopMenu;
    }

    string addOrder(string itemName) {
        for (const auto &item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string fulfilledItem = orders.front();
            orders.erase(orders.begin());
            return "The " + fulfilledItem + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto &order : orders) {
            for (const auto &item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items in the menu";
        
        MenuItem cheapest = menu[0];
        for (const auto &item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto &item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (const auto &item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main(int argc, char* argv[]) {
    vector<MenuItem> menu = {
        {"Espresso", "drink", 3.0},
        {"Cappuccino", "drink", 4.5},
        {"Latte", "drink", 4.0},
        {"Croissant", "food", 2.5},
        {"Bagel", "food", 3.5}
    };

    CoffeeShop shop("StarCaffeine", menu);
    
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <command> [item_name]" << endl;
        return 1;
    }
    
    string command = argv[1];
    
    if (command == "addOrder" && argc == 3) {
        cout << shop.addOrder(argv[2]) << endl;
    } else if (command == "fulfillOrder") {
        cout << shop.fulfillOrder() << endl;
    } else if (command == "listOrders") {
        vector<string> orders = shop.listOrders();
        if (orders.empty()) {
            cout << "No orders." << endl;
        } else {
            cout << "Orders: ";
            for (const auto &order : orders) {
                cout << order << " ";
            }
            cout << endl;
        }
    } else if (command == "dueAmount") {
        cout << "Total Due Amount: $" << shop.dueAmount() << endl;
    } else if (command == "cheapestItem") {
        cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    } else if (command == "drinksOnly") {
        vector<string> drinks = shop.drinksOnly();
        cout << "Drinks: ";
        for (const auto &drink : drinks) {
            cout << drink << " ";
        }
        cout << endl;
    } else if (command == "foodOnly") {
        vector<string> foods = shop.foodOnly();
        cout << "Foods: ";
        for (const auto &food : foods) {
            cout << food << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid command or arguments." << endl;
    }
    
    return 0;
}
