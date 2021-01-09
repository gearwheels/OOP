#pragma once
#include "figure.hpp"
#include <cmath>

class Pentagon: public Figure {
    private:
        int length;
    public:
        Pentagon() : Figure() { length = 0; }
        Pentagon(double x1, double y1, int c);
        double S() override;
        Pair Center() override;
        std::vector<Pair> Coord() override;
};

Pentagon::Pentagon(double x1, double y1, int c) {
    double R = (sqrt(10)*sqrt(5 + sqrt(5))*c) / 10;// найти радиус 
    Pair O;// найти центр
    O.x = x1;
    O.y = y1 - R;
    points.emplace_back(Pair(x1, y1));
    points.emplace_back(Pair(O.x - (double)R * sqrt(3) / 2, O.y - (double)R / 2));
    points.emplace_back(Pair(O.x + (double)R * sqrt(3) / 2, O.y - (double)R / 2));
    points.emplace_back(Pair(O.x - (double)R / 2, O.y - (double)R * sqrt(3) / 2 - R));
    points.emplace_back(Pair(O.x + (double)R / 2, O.y - (double)R * sqrt(3) / 2 - R));
    length = c;
}
Pair Pentagon::Center() { 
    Pair out(0,0);
    for (int i = 0; i < 5; ++i){
        out.x += points[i].x;
        out.y += points[i].y;
    }
    out.x /= 5;
    out.y /= 5;
    return out;
}

std::vector<Pair> Pentagon::Coord() {
    return points;
}

double Pentagon::S() {
    double s = (length * length * sqrt(5) * sqrt(5 + sqrt(20)));
    return s;
}