#pragma once
#include <cmath>
#include "figure.hpp"
class Octagon: public Figure {
    private:
        int length;
    public:
        Octagon() : Figure() { length = 0; }
        Octagon(double x1, double y1, int R) {
            double angle,outX,outY;
            for(int i = 1; i <= 8; i++) {// расчет точек 
                angle =  360 / 8;
                outX = R * cos(i*angle) + x1;
                outY = R * sin(i*angle) + y1;
                points.emplace_back(Pair(outX, outY));
            }
                length = R;
        }
        std::string Name() override {
            return "Octagon";
        }
        int Get() override {
            return length;
        }
        std::vector<Pair> Coord() override {
            return points;
        }
};