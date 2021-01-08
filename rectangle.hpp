#include "figure.hpp"

class Rectangle: public Figure{
private:
    double h,l;

public:
    Rectangle(){}

    Rectangle(std::pair<double, double> center, double h, double l){
        this->center = center;
        this->h = h;
        this->l = l;
    }

    double Area() override {
        return h*l;
    }

    void Print() override {
        std::cout << "Rectangle: ";
        std::cout << *this;
        auto center = Center();
        std::cout << " Center: {" << center.first << "; " << center.second << "} ";
        std::cout << "Area: " << Area() << "\n";
    }

    void Printf(std::ofstream& out) override {
        out << "Rectangle: ";
        out << *this;
        auto center = Center();
        out << " Center: {" << center.first << "; " << center.second << "} ";
        out << "Area: " << Area() << "\n";
    }

    friend std::ostream& operator<<(std::ostream& cout, const Rectangle& t){
        cout << "(" << t.center.first - t.l/2 << ", " << t.center.second - t.h/2 << ")";
        cout << "(" << t.center.first - t.l/2 << ", " << t.center.second + t.h/2 << ")";
        cout << "(" << t.center.first + t.l/2 << ", " << t.center.second + t.h/2 << ")";
        cout << "(" << t.center.first + t.l/2 << ", " << t.center.second - t.h/2 << ")";
        return cout;
    }
};