#include <iostream>
using namespace std;

class Shape {
public:
    string position;
    string color;
    double borderThickness;

    Shape(string p, string c, double bt)
        : position(p), color(c), borderThickness(bt) {}

    virtual void draw() {
        cout << "Drawing a Shape..." << endl;
    }

    virtual double calculateArea() {
        return 0.0;
    }

    virtual double calculatePerimeter() {
        return 0.0;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    double radius;

    Circle(string p, string c, double bt, double r)
        : Shape(p, c, bt), radius(r) {}

    void draw() override {
        cout << "Drawing a Circle..." << endl;
    }

    double calculateArea() override {
        return 3.14 * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape {
public:
    double length;
    double width;

    Rectangle(string p, string c, double bt, double l, double w)
        : Shape(p, c, bt), length(l), width(w) {}

    void draw() override {
        cout << "Drawing a Rectangle..." << endl;
    }

    double calculateArea() override {
        return length * width;
    }

    double calculatePerimeter() override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
public:
    double height, base, hyp1, hyp2;

    Triangle(string p, string c, double bt, double h, double b, double h1, double h2)
        : Shape(p, c, bt), height(h), base(b), hyp1(h1), hyp2(h2) {}

    void draw() override {
        cout << "Drawing a Triangle..." << endl;
    }

    double calculateArea() override {
        return 0.5 * height * base;
    }

    double calculatePerimeter() override {
        return hyp1 + hyp2 + base;
    }
};

class Polygon : public Shape {
public:
    double length;
    int numOfSides;

    Polygon(string p, string c, double bt, double l, int ns)
        : Shape(p, c, bt), length(l), numOfSides(ns) {}

    void draw() override {
        cout << "Drawing a Polygon..." << endl;
    }

    double calculateArea() override {
        return (numOfSides * length) / 2.0;
    }

    double calculatePerimeter() override {
        return length * numOfSides;
    }
};

int main() {
    Circle c("Center", "Purple", 2, 5);
    c.draw();
    cout<<"Circle"<<endl;
    cout << "Area: " << c.calculateArea() << endl;
    cout << "Perimeter: " << c.calculatePerimeter() << endl;

    cout << endl;

    Rectangle r("TopLeft", "Blue", 1.5, 11.0, 5.0);
    r.draw();
    cout<<"Rectangle"<<endl;
    cout << "Area: " << r.calculateArea() << endl;
    cout << "Perimeter: " << r.calculatePerimeter() << endl;

    cout << endl;

    Triangle t("Vertex", "Orange", 1.0, 6.5, 8.0, 5.4, 7.0);
    t.draw();
    cout<<"Triangle"<<endl;
    cout << "Area: " << t.calculateArea() << endl;
    cout << "Perimeter: " << t.calculatePerimeter() << endl;

    cout << endl;

    Polygon p("Side", "Brown", 1.2, 4.3, 6);
    p.draw();
    cout<<"Polygon"<<endl;
    cout << "Area: " << p.calculateArea() << endl;
    cout << "Perimeter: " << p.calculatePerimeter() << endl;

    return 0;
}

