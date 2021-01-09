#pragma once
#include <cmath>
#include "figure.hpp"
class Hexagon: public Figure {
    private:
        int length;
    public:
        Hexagon() : Figure() {length = 0;}
        Hexagon(double x1, double y1, int R) {
            double angle,outX,outY;
            for(int i = 1; i <= 6; i++) {// расчет точек 
                angle =  360 / 6;
                outX = R * cos(i*angle) + x1;
                outY = R * sin(i*angle) + y1;
                points.emplace_back(Pair(outX, outY));
            }
                length = R;
        }
        std::string Name() override {
            return "Hexagon";
        }
        int Get() override {
            return length;
        }
        std::vector<Pair> Coord() override {
            return points;
        }
};