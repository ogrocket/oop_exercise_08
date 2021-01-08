#include "figure.hpp"

class Triangle: public Figure{
private:
    double h;
    double l;

public:
    Triangle(){}

    Triangle(std::pair<double, double> center, double h, double l){
        this->center = center;
        this->h = h;
        this->l = l;
    }

    double Area() override {
        return h * l / 2;
    }

    void Print() override {
        std::cout << "Triangle: ";
        std::cout << *this;
        auto center = Center();
        std::cout << " Center: {" << center.first << "; " << center.second << "} ";
        std::cout << "Area: " << Area() << "\n";
    }

    void Printf(std::ofstream& out) override {
        out << "Triangle: ";
        out << *this;
        auto center = Center();
        out << " Center: {" << center.first << "; " << center.second << "} ";
        out << "Area: " << Area() << "\n";
    }

    friend std::ostream& operator<<(std::ostream& cout, const Triangle& t){
        cout << "(" << t.center.first - t.l/2 << ", " << t.center.second - t.h/2 << ")";
        cout << "(" << t.center.first + t.l/2 << ", " << t.center.second - t.h/2 << ")";
        cout << "(" << t.center.first << ", " << t.center.second + t.h/2 << ")";
        return cout;
    }

};