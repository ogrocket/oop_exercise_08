#include "figure.hpp"

class Square: public Figure{
private:
    double side;

public:
    Square(){}

    Square(std::pair<double, double> center, double side){
        this->center = center;
        this->side = side;
    }

    double Area() override {
        return side * side;
    }

    void Print() override {
        std::cout << "Square: ";
        std::cout << *this;
        auto center = Center();
        std::cout << " Center: {" << center.first << "; " << center.second << "} ";
        std::cout << "Area: " << Area() << "\n";
    }

    void Printf(std::ofstream& out) override {
        out << "Square: ";
        out << *this;
        auto center = Center();
        out << " Center: {" << center.first << "; " << center.second << "} ";
        out << "Area: " << Area() << "\n";
    }

    friend std::ostream& operator<<(std::ostream& cout, const Square& t){
        cout << "(" << t.center.first - t.side/2 << ", " << t.center.second - t.side/2 << ")";
        cout << "(" << t.center.first - t.side/2 << ", " << t.center.second + t.side/2 << ")";
        cout << "(" << t.center.first + t.side/2 << ", " << t.center.first + t.side/2 << ")";
        cout << "(" << t.center.first + t.side/2 << ", " << t.center.second - t.side/2 << ")";
        return cout;
    }
};