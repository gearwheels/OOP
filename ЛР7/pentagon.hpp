#pragma once
#include <cmath>
#include "figure.hpp"
class Pentagon: public Figure {
    private:
        int length;
    public:
        Pentagon() : Figure() { length = 0; }
        Pentagon(double x1, double y1, int R) {
            double angle,outX,outY;
            for(int i = 1; i <= 5; i++) {// расчет точек 
                angle =  360 / 5;
                outX = R * cos(i*angle) + x1;
                outY = R * sin(i*angle) + y1;
                points.emplace_back(Pair(outX, outY));
                }
                length = R;
        }
        std::string Name() override {
            return "Pentagon";
        }
        int Get() override {
            return length;
        }
        std::vector<Pair> Coord() override {
            return points;
        }
};
