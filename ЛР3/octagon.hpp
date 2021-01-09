#pragma once
#include "figure.hpp"
#include <cmath>

class Octagon: public Figure {
    private:
        int length;
    public:
        Octagon() : Figure() { length = 0; }
        Octagon(double x1, double y1, int c);
        double S() override;
        Pair Center() override;
        std::vector<Pair> Coord() override;
};

Octagon::Octagon(double x1, double y1, int c) {
    points.push_back(Pair(x1, y1));
    points.push_back(Pair(x1 + (double)c * cos(M_PI / 8), y1 -  (double)c * sin(M_PI / 8)));
    points.push_back(Pair(x1 - (double)c * cos(M_PI / 8), y1 -  (double)c * sin(M_PI / 8)));
    points.push_back(Pair(x1 + (double)c * sqrt(1 / sqrt(2) + 1), y1 - (double)c * sqrt(1 / sqrt(2) + 1)));
    points.push_back(Pair(x1 - (double)c * sqrt(1 / sqrt(2) + 1), y1 - (double)c * sqrt(1 / sqrt(2) + 1)));
    points.push_back(Pair(x1 + (double)c * cos(M_PI / 8), y1 - 2 * (double)c * cos(M_PI / 8)));
    points.push_back(Pair(x1 - (double)c * cos(M_PI / 8), y1 - 2 * (double)c * cos(M_PI / 8)));
    points.push_back(Pair(x1, y1 - 2 * (double)c ));
    length = c;
}
std::vector<Pair> Octagon::Coord() {
    return points;
}

Pair Octagon::Center() {
    Pair out(0,0);
    out.x = points[0].x;
    out.y = points[0].y - (double)length;
    return out;
}

double Octagon::S() {
    double s = 2 * length * length * (1 + sqrt(2));
    return s;
}