#include "Figure.hpp"
#include <iostream>
#include <cmath>
class Pentagon final: public Figure{
    private:
        double side_;
    public:
        Pentagon() : side_(0){}

        Pentagon(const double side){
            if (side <= 0){
                throw std::invalid_argument("Side must be more than zero");
            }
            this->side_ = side;
        }
        bool operator==(const Pentagon& other) const {
            return side_ == other.side_;
        }

        explicit virtual operator double() const noexcept {
            double area = (side_ * side_) / 4 * sqrt(25 + 10 * sqrt(5));
            return abs(area);
        }

        double print_geometric_center() const override {
            double area = (side_ * side_) / 4 * sqrt(25 + 10 * sqrt(5));
            double pp = side_ * 5 / 2;
            double centerXY = area / pp;
            return centerXY;
        }

        void ReadCoordinates(std::istream& is) override {
            is >> side_;
        }

        void PrintCoordinates(std::ostream& os) const override {
            os << "Pentagon - ";
            os << "side: " << side_ << std::endl;
        }

};