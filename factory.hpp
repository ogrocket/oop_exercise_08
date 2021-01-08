#pragma once

#include "triangle.hpp"
#include "rectangle.hpp"
#include "square.hpp"

#include <memory>

struct Factory{
    static std::shared_ptr<Figure> Create(int id){      //console factory
        switch(id){
            case 1:{    //triangle
                std::pair<double, double> center;
                double h, l;
                std::cout << "Input center coordinates, height and base of triangle:";
                std::cin >> center.first >> center.second >> h >> l;
                return std::make_shared<Triangle>(center, h, l);
            }

            case 2:{    //rectangle
                std::pair<double, double> center;
                double h, l;
                std::cout << "Input center coordinates, height and base of rectangle:";
                std::cin >> center.first >> center.second >> h >> l;
                return std::make_shared<Rectangle>(center, h, l);
            }

            case 3:{    //square
                std::pair<double, double> center;
                double side;
                std::cout << "Input center coordinates and side of square:";
                std::cin >> center.first >> center.second >> side;
                return std::make_shared<Square>(center, side);
            }
        default:
            throw std::runtime_error ("Wrong ID");
        }
    }
};