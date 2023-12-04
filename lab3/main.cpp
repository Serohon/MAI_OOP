#include <iostream>
#include <vector>
#include "Trapezoid.cpp"
#include "Rhombus.cpp"
#include "Pentagon.cpp"

int main()
{
    std::vector<Figure*> figures;
    Figure* Trapezoid_ = new Trapezoid;
    Figure* Rhombus_ = new Rhombus;
    Figure* Pentagon_ = new Pentagon;
    std::cout << "Enter coordinates for Trapezoid:" << std::endl;
    std::cin >> *Trapezoid_;
    std::cout << "Enter coordinates for Rhombus:" << std::endl;
    std::cin >> *Rhombus_;
    std::cout << "Enter coordinates for Pentagon:" << std::endl;
    std::cin >> *Pentagon_;
    std::cout << std::endl;
    std::cout << *Trapezoid_ << std::endl;
    std::cout << *Rhombus_ << std::endl;
    std::cout << *Pentagon_ << std::endl;
    figures.push_back(Trapezoid_);
    figures.push_back(Rhombus_);
    figures.push_back(Pentagon_);

    for (const auto& figure : figures) {
        std::cout << "CenterX is: " << figure->print_geometric_center() << std::endl;
        std::cout << "Area: " << figure->operator double() << std::endl;
    }

    double totalArea = 0.0;
    for (const auto& figure : figures) {
        totalArea += figure->operator double();
    }
    std::cout << "Total Area: " << totalArea << std::endl;

    int indexToDelete = 0;
    if (indexToDelete >= 0 && indexToDelete < figures.size()) {
        delete figures[indexToDelete];
        figures.erase(figures.begin() + indexToDelete);
    }

    for (const auto& figure : figures) {
        delete figure;
    }

    return 0;
}