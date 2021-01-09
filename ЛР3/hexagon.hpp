#pragma once
#include "figure.hpp"
#include <cmath>

class Hexagon: public Figure {
    private:
        int length;
    public:
        Hexagon() : Figure() { length = 0; }
        Hexagon(double x1, double y1, int length);
        double S() override;
        Pair Center() override;
        std::vector<Pair> Coord() override;
};

Hexagon::Hexagon(double x1, double y1, int c) {
    points.push_back(Pair(x1, y1));
    points.push_back(Pair(x1 - (double)c * sqrt(3) / 2, y1 - (double) c / 2));
    points.push_back(Pair(x1 + (double)c * sqrt(3) / 2, y1 - (double) c / 2));
    points.push_back(Pair(x1 - (double)c * sqrt(3) / 2, y1 - (double) c / 2 - c));
    points.push_back(Pair(x1 + (double)c * sqrt(3) / 2, y1 - (double) c / 2 - c));
    points.push_back(Pair(x1, y1 - 2 * c));
    length = c;
}

double Hexagon::S() {
    double s = 3 * sqrt(3) * length * length / 2;
    return s;
}

Pair Hexagon::Center() {
    Pair out(0,0);
    out.x = points[0].x;
    out.y = points[0].y - (double)length;
    return out;
}

std::vector<Pair> Hexagon::Coord() {
    return points;
}
