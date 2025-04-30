#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib> // for atoi and atof functions

using namespace std;

struct User {
    int user_id;
    string first_name;
    string last_name;
    string address;
};

struct Product {
    int product_id;
    string product_name;
    double price;
};

struct Order {
    int order_id;
    int user_id;
    int product_ordered;
    double total_paid;
};

void writeDummyData() {
    ofstream userFile("users.txt");
    userFile << "1,John,Doe,123 Main St\n";
    userFile << "2,Linux,Torvalds,456 Open Ave\n";
    userFile << "3,Jane,Smith,789 Oak Blvd\n";
    userFile.close();

    ofstream productFile("products.txt");
    productFile << "1,Laptop,999.99\n";
    productFile << "2,Keyboard,49.99\n";
    productFile << "3,Monitor,199.99\n";
    productFile << "4,Mouse,19.99\n";
    productFile.close();

    ofstream orderFile("orders.txt");
    orderFile << "1,2,1,999.99\n";
    orderFile << "2,1,3,199.99\n";
    orderFile << "3,2,4,19.99\n";
    orderFile << "4,3,2,49.99\n";
    orderFile.close();
}

vector<User> readUsers() {
    vector<User> users;
    ifstream file("users.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        User user;

        getline(ss, token, ',');
        user.user_id = atoi(token.c_str());
        getline(ss, user.first_name, ',');
        getline(ss, user.last_name, ',');
        getline(ss, user.address);

        users.push_back(user);
    }

    return users;
}

vector<Product> readProducts() {
    vector<Product> products;
    ifstream file("products.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Product product;

        getline(ss, token, ',');
        product.product_id = atoi(token.c_str());
        getline(ss, product.product_name, ',');
        getline(ss, token);
        product.price = atof(token.c_str());

        products.push_back(product);
    }

    return products;
}

vector<Order> readOrders() {
    vector<Order> orders;
    ifstream file("orders.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Order order;

        getline(ss, token, ',');
        order.order_id = atoi(token.c_str());
        getline(ss, token, ',');
        order.user_id = atoi(token.c_str());
        getline(ss, token, ',');
        order.product_ordered = atoi(token.c_str());
        getline(ss, token);
        order.total_paid = atof(token.c_str());

        orders.push_back(order);
    }

    return orders;
}

vector<string> getProductsForLinux() {
    vector<string> products;
    vector<User> users = readUsers();
    vector<Product> allProducts = readProducts();
    vector<Order> orders = readOrders();
    
    int linuxId = -1;
    for (const User& user : users) {
        if (user.first_name == "Linux") {
            linuxId = user.user_id;
            break;
        }
    }
    
    if (linuxId == -1) {
        cout << "User 'Linux' not found!" << endl;
        return products;
    }
    
    for (const Order& order : orders) {
        if (order.user_id == linuxId) {
            for (const Product& product : allProducts) {
                if (product.product_id == order.product_ordered) {
                    products.push_back(product.product_name);
                    break;
                }
            }
        }
    }
    
    return products;
}

int main() {
    writeDummyData();
    vector<string> linuxProducts = getProductsForLinux();
    
    cout << "Products associated with user 'Linux':" << endl;
    for (const string& product : linuxProducts) {
        cout << "- " << product << endl;
    }
    
    return 0;
}
