#include "Figure.hpp"
#include <iostream>
#include <cmath>

class Rhombus final: public Figure{
    private:
        double x1_;
        double y1_;
        double x2_;
        double y2_;
        double x3_;
        double y3_;
        double x4_;
        double y4_;

    public:
        Rhombus() : x1_(0), y1_(0), x2_(0), y2_(0), x3_(0), y3_(0), x4_(0), y4_(0) {}

        Rhombus(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const double x4, const double y4){
            this->x1_ = x1;
            this->y1_ = y1;
            this->x2_ = x2;
            this->y2_ = y2;
            this->x3_ = x3;
            this->y3_ = y3;
            this->x4_ = x4;
            this->y4_ = y4;
        }
        bool operator==(const Rhombus& other) const {
            return x1_ == other.x1_ && y1_ == other.y1_ &&
                    x2_ == other.x2_ && y2_ == other.y2_ &&
                    x3_ == other.x3_ && y3_ == other.y3_ &&
                    x4_ == other.x4_ && y4_ == other.y4_;
        }

        explicit virtual operator double() const noexcept{
            double diagonal1 = sqrt(pow(x2_ - x4_, 2) + pow(y2_ - y4_, 2));
            double diagonal2 = sqrt(pow(x1_ - x3_, 2) + pow(y1_ - y3_, 2));
            return 0.5 * diagonal1 * diagonal2;
        }

        double print_geometric_center() const override {
            double centerX = (x1_ + x2_ + x3_ + x4_) / 4;
            double centerY = (y1_ + y2_ + y3_ + y4_) / 4;
            return centerY;
        }        

        void PrintCoordinates(std::ostream& os) const override {
            os << "Rhombus - ";
            os << "Vertices: (" << x1_ << ", " << y1_ << "), (" << x2_ << ", " << y2_ << "), (" << x3_ << ", " << y3_ << "), (" << x4_ << ", " << y4_ << ")" << std::endl;
        }

        void ReadCoordinates(std::istream& is) override{
            is >> x1_ >> y1_ >> x2_ >> y2_ >> x3_ >> y3_ >> x4_ >> y4_;
        }
};