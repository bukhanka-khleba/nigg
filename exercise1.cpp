#include <iostream>
#include <vector>

/// Базовый класс "Геометрическая фигура"
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() = default; 
};

/// Производный класс "Прямоугольник"
class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w = 0, double h = 0) : width(w), height(h) {}
    double area() const override { return width * height; }
    double perimeter() const override { return 2 * (width + height); }
};

/// Производный класс "Квадрат"
class Square : public Rectangle {
public:
    Square(double side = 0) : Rectangle(side, side) {}
};

class Pepe : public Square {
public:
    Pepe(double e = 0) : Square(e) {}
};

int main() {
    std::vector<Shape*> shapes; 
    shapes.push_back(new Rectangle(4, 5)); 
    shapes.push_back(new Square(4));       
    shapes.push_back(new Pepe(2));         

    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << ", Perimeter: " << shape->perimeter() << "\n"; 
    }

    for (const auto& shape : shapes) {
        delete shape; 
    }

    return 0;
}