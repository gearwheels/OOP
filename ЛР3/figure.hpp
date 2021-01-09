#pragma once
#include <iostream>
#include <vector>
#include <string>

struct Pair {
    double x;
    double y;
    Pair() {
        x = 0;
        y = 0;
    }
    Pair(double a, double b) {
        x = a;
        y = b;
    }
};

 class Figure {
    protected:
        std::vector<Pair> points;
    public:
        Figure();
        Figure(double x1, double y1, int c);
        virtual double S();
        virtual Pair Center();
        virtual std::vector<Pair> Coord();
        int GetSize(){
            return points.size();
        }
 };

Figure::Figure() {
}

Figure::Figure(double x1, double y1, int c) {
    points.emplace_back(Pair(x1,y1));
}

double Figure::S() {
    return 0;
}

Pair Figure::Center() {
}

std::vector<Pair> Figure::Coord() {
    return points;
}