#ifndef PENTAGON_H
#define PENTAGON_H
#include <algorithm>
#include <cmath>
#include <iostream>
template <class T>
class Pentagon {
    public:
        T R, x, y; // радиус и координаты центра
        Pentagon() : x(0.0), y(0.0), R(0.0){}
        Pentagon(double x1, double y1, double r1) {
            x = x1;
            y = y1;
            R = r1;
        }
        double S();
        void CoordP();
        int countS();
};
template <class T>
void Pentagon<T>::CoordP() {
    double angle,outX,outY;
    for(int i = 2; i < 12; i = i+2) {// расчет точек и вывод
            angle =  360 * 0.2;
            outX = R * cos(i*angle*0.5) + x;
            outY = R * sin(i*angle*0.5) + y;
            std::cout << '(' << outX << ',' << outY << ')'<< '\t';
        }
        std::cout << std::endl;
}
template <class T>
double Pentagon<T>::S() {
    double s = (R * R * 5 * 0.25 * sqrt((5 + sqrt(20))*0.5));
    return s;
}
#endif