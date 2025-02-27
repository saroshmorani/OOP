#include <iostream>

class Engine {
public:
    Engine() { std::cout << "Engine created.\n"; }
    ~Engine() { std::cout << "Engine destroyed.\n"; }
};

class Car {
private:
    Engine engine;
    std::string name;
    int id;
public:
    Car(std::string name, int id) : name(name), id(id) { //initializer
        std::cout << "Car " << name << " ID: " << id << " created.\n";
    }
    ~Car() {
        std::cout << "Car " << name << " ID: " << id << " destroyed.\n";
    }
    std::string getName() const { return name; }
    int getId() const { return id; }
};

class Garage {
private:
    Car* cars[10]; 
public:
    Garage() { 
        for (int i = 0; i < 10; ++i) {
            cars[i] = nullptr;
        }
    }

    void parkCar(Car* car) {
        for (int i = 0; i < 10; ++i) {
            if (cars[i] == nullptr) {
                cars[i] = car;
                std::cout << "Car " << car->getName() << " parked in the garage.\n";
                return;
            }
        }
        std::cout << "Garage is full!\n";
    }

    void listCars() const {
        std::cout << "Cars in garage:\n";
        for (int i = 0; i < 10; ++i) {
            if (cars[i] != nullptr) {
                std::cout << "- " << cars[i]->getName() << " ID: " << cars[i]->getId() << "\n";
            }
        }
    }
};

int main() {
    Car rivo("Rivo", 1);
    Car civic("Civic", 2);

    Garage sodhigarage;
    sodhigarage.parkCar(&rivo);
    sodhigarage.parkCar(&civic);
    
    sodhigarage.listCars();

    std::cout << "destruction order!\n";
    return 0;
}

