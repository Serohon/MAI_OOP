#include <iostream>
#include <vector>
#include <cmath>

class Figure {
public:
    virtual ~Figure() {}

    virtual double CalculateArea() const = 0;
    virtual double CalculateGeometricCenter() const = 0;
    virtual void PrintCoordinates(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.PrintCoordinates(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure) {
        figure.ReadCoordinates(is);
        return is;
    }

    virtual void ReadCoordinates(std::istream& is) = 0;
};

class Trapezoid : public Figure {
private:
    double base1, base2, height;

public:
    Trapezoid() : base1(0), base2(0), height(0) {}

    double CalculateArea() const override {
        return 0.5 * (base1 + base2) * height;
    }

    double CalculateGeometricCenter() const override {
        return (base1 + base2) / 2.0;
    }

    void PrintCoordinates(std::ostream& os) const override {
        os << "Trapezoid: Base1=" << base1 << " Base2=" << base2 << " Height=" << height << std::endl;
    }

    void ReadCoordinates(std::istream& is) override {
        is >> base1 >> base2 >> height;
    }
};

class Rhombus : public Figure {
private:
    double side, diagonal1, diagonal2;

public:
    Rhombus() : side(0), diagonal1(0), diagonal2(0) {}

    double CalculateArea() const override {
        return 0.5 * diagonal1 * diagonal2;
    }

    double CalculateGeometricCenter() const override {
        return 0;  // Рассчитайте геометрический центр ромба
    }

    void PrintCoordinates(std::ostream& os) const override {
        os << "Rhombus: Side=" << side << " Diagonal1=" << diagonal1 << " Diagonal2=" << diagonal2 << std::endl;
    }

    void ReadCoordinates(std::istream& is) override {
        is >> side >> diagonal1 >> diagonal2;
    }
};


int main() {
    std::vector<Figure*> figures; // Динамический массив указателей на фигуры

    // Ввод фигур и добавление их в вектор figures
    while (true) {
        int choice;
        std::cout << "Enter the type of figure (1 - Trapezoid, 2 - Rhombus, 3 - Pentagon, 0 - Exit): ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }
        Figure* figure = nullptr; 
        if (choice == 1) {
            Figure* figure = new Trapezoid;
        } else if (choice == 2) {
            Figure* figure = new Rhombus;
        } else {
            std::cout << "Invalid choice." << std::endl;
            continue;
        }

        std::cin >> *figure;
        figures.push_back(figure);
    }

    // Вывод геометрического центра и площади для каждой фигуры
    for (const auto& figure : figures) {
        std::cout << "Geometric Center: " << figure->CalculateGeometricCenter() << std::endl;
        std::cout << "Area: " << figure->CalculateArea() << std::endl;
    }

    // Удаление фигуры по индексу (пример для удаления первой фигуры)
    size_t index_to_remove = 0;
    if (index_to_remove < figures.size()) {
        delete figures[index_to_remove];
        figures.erase(figures.begin() + index_to_remove);
    }

    // Освобождение памяти
    for (auto figure : figures) {
        delete figure;
    }

    return 0;
}
