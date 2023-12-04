#include "Figure.hpp"
#include <iostream>

class Trapezoid final: public Figure{
    private:
        double _bottom_base;
        double _top_base;
        double _height;

    public:
        Trapezoid() : _top_base(0), _bottom_base(0), _height(0) {}
       
        Trapezoid(const double top_base, const double bottom_base, const double height){
            if (top_base <= 0 || bottom_base <= 0 || height <= 0){
                throw std::invalid_argument("Sides must be more than zero");
            }
            this->_top_base = top_base;
            this->_bottom_base = bottom_base;
            this->_height = height;
        }
        bool operator==(const Trapezoid& other) const 
        {
            return _top_base == other._top_base && _bottom_base == other._bottom_base && _height == other._height;
        }

        explicit operator double() const noexcept override
        {
            return 0.5 * (_top_base + _bottom_base) * _height;
        }
            
        double print_geometric_center() const override{
            double centerX = (_top_base + _bottom_base) / 2;
            double centerY = _height / 2;
            return centerX;
        }
        
        void PrintCoordinates(std::ostream& os) const override {
            os << "Trapezoid: Base1=" << _bottom_base << " Base2=" << _top_base << " Height=" << _height << std::endl;
        }

        void ReadCoordinates(std::istream& is) override {
            is >> _bottom_base >> _top_base >> _height;
        }
};