/*
Создать программу, которая:
Создает набор фигур согласно варианту задания (как минимум по одной фигуре каждого типа с координатами типа int и координатами типа double).
Сохраняет фигуры в std::tuple
Печатает на экран содержимое std::tuple с помощью шаблонной функции print.
Вычисляет суммарную площадь фигур в std::tuple и выводит значение на экран.
Необходимо реализовать две шаблонных функции:
Функция print печати фигур на экран std::cout  (печататься должны координаты вершин фигур). Функция должна принимать на вход std::tuple с фигурами, согласно варианту задания (минимум по одной каждого класса).
Функция square вычисления суммарной площади фигур. Функция должна принимать на вход std::tuple с фигурами, согласно варианту задания (минимум по одной каждого класса).
Фигуры по варианту:  5-угольник, 6-угольник, 8-угольник.
*/
#include <iostream>
#include <typeinfo>// Тимофеев Алексей М8О-207Б-19
#include <tuple>
#include <string>
#include <cmath>
#include <vector>

template<class T>
struct Pentagon {
    std::vector<std::pair<T, T>> points;
};
template<class T>
struct Hexagon {
    std::vector<std::pair<T, T>> points;
};
template<class T>
struct Octagon {
    std::vector<std::pair<T, T>> points;
};
template<class T> 
std::ostream &operator<<(std::ostream &os, const std::pair<T, T> &t) {
    os << " (" << t.first << ',' << t.second << ") ";
    return os;
}
template<size_t ind = 0, class T>
void print(const T &t) {
    if constexpr(ind < std::tuple_size<T>::value) {
        std::string s = typeid(std::get<ind>(t)).name();
        s.erase(0, 1);
        s.erase(s.length() - 3, 3);
        std::cout << s << ": ";
        for (int i = 0; i < std::get<ind>(t).points.size(); ++i){
            std::cout << std::get<ind>(t).points[i];
            if ((i + 1) % 4 == 0 && i != std::get<ind>(t).points.size() - 1) {
                std::cout << std::endl << "\t ";
            }
        }
        std::cout << std::endl << std::endl;
        print<ind + 1, T>(t);
    }
    return;
}
template<class T>
long double SFig(const std::vector<std::pair<T, T>> &fig, std::string nametype) {
    long double S = 0;
    long double side = sqrt(pow(fig[0].first - fig[1].first, 2) + pow(fig[0].second - fig[1].second, 2));
    if(nametype == "Pentagon") {
        S = (side * side * sqrt(5) * sqrt(5 + sqrt(20)));
    }
    if(nametype == "Hexagon") {
        S = 3 * sqrt(3) * side * side / 2;
    }
    if(nametype == "Octagon") { 
        S = 2 * side * side * (1 + sqrt(2));
    }
    return S;
}
template<size_t ind = 0, class T>
long double square(const T &t) {
    long double S = 0;
    if constexpr(ind < std::tuple_size<T>::value) {
        std::string name = typeid(std::get<ind>(t)).name();
        name.erase(0, 1);
        name.erase(name.length() - 3, 3);
        S = SFig(std::get<ind>(t).points, name);
        S += square<ind + 1, T>(t);
    } 
    return S;
}
int main() {
    std::cout << "double or int" << std::endl;
    std::string data;
    std::cin >> data;
    if (data == "double"){
        using pair_double = std::pair<double, double>;
        double points[16];// массив точек 
        double x1, y1, R, angle; // коорд ц х, коорд центра у, радиус, угол
        std::cout << "Octagon" << std::endl;
        std::cout << "Coordinates of center point :" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Radius :" << std::endl;
        std::cin >> R;
        if (R <= 0.0) {
            std::cout << "The entered values are not correct" << std::endl;
            return 0;
        }
        for(int i = 0; i < 16; i = i = i+2) { // расчет точек 
            angle =  360 / 8;
            points[i] = R * cos(i*angle) + x1;
            points[i+1] = R * sin(i*angle) + y1;;
        }
        Octagon<double> oct1 = {{pair_double(points[1],points[2]), pair_double(points[3],points[4]), pair_double(points[5],points[6]), pair_double(points[7],points[8]), pair_double(points[9],points[10]), pair_double(points[11],points[12]), pair_double(points[13],points[14]), pair_double(points[15],points[16])}};
        std::cout << "Hexagon" << std::endl;
        std::cout << "Coordinates of center point :" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Radius :" << std::endl;
        std::cin >> R;
        if (R <= 0.0) {
             std::cout << "The entered values are not correct" << std::endl;
            return 0;
        }
        for(int i = 0; i < 12; i = i+2) {// расчет точек 
            angle =  360 / 6;
            points[i] = R * cos(i*angle) + x1;
            points[i+1] = R * sin(i*angle) + y1;;
        }
        Hexagon<double> hex1 = {{pair_double(points[1],points[2]), pair_double(points[3],points[4]), pair_double(points[5],points[6]), pair_double(points[7],points[8]), pair_double(points[9],points[10]), pair_double(points[11],points[12])}};
        std::cout << "Pentagon" << std::endl;
        std::cout << "Coordinates of center point :" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Radius :" << std::endl;
        std::cin >> R;
        if (R <= 0.0) {
            std::cout << "The entered values are not correct" << std::endl;
            return 0;
        }
        for(int i = 0; i < 10; i = i+2) {// расчет точек 
           angle =  360 / 5;
            points[i] = R * cos(i*angle) + x1;
            points[i+1] = R * sin(i*angle) + y1;;
        }
        Pentagon<double> pen1 = {{pair_double(points[1],points[2]), pair_double(points[3],points[4]), pair_double(points[5],points[6]), pair_double(points[7],points[8]), pair_double(points[9],points[10])}};
        std::tuple<Pentagon<double>, Hexagon<double>, Octagon<double>> t1(pen1, hex1, oct1);
        print(t1);
        std:: cout << "Square: " << square(t1) << std::endl;;
    }else if (data == "int"){
        using pair_int = std::pair<int, int>;
        int x1, y1, R, angle;// коорд ц х, коорд центра у, радиус, угол
        int points[16];// массив точек 
        std::cout << "Octagon" << std::endl;
        std::cout << "Coordinates of center point :" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Radius :" << std::endl;
        std::cin >> R;
        if (R <= 0) {
            std::cout << "The entered values are not correct" << std::endl;
            return 0;
        }
        for(int i = 0; i < 16; i = i+2) {// расчет точек 
            angle =  360 / 8;
            points[i] = R * cos(i*angle) + x1;
            points[i+1] = R * sin(i*angle) + y1;
        }
        Octagon<int> oct2 = {{pair_int(points[1],points[2]), pair_int(points[3],points[4]), pair_int(points[5],points[6]), pair_int(points[7],points[8]), pair_int(points[9],points[10]), pair_int(points[11],points[12]), pair_int(points[13],points[14]), pair_int(points[15],points[16])}};
        std::cout << "Hexagon" << std::endl;
        std::cout << "Coordinates of center point :" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Radius :" << std::endl;
        std::cin >> R;
        if (R <= 0) {
            std::cout << "The entered values are not correct" << std::endl;
            return 0;
        }
        for(int i = 0; i < 12; i = i+2) {// расчет точек 
            angle =  360 / 6;
            points[i] = R * cos(i*angle) + x1;
            points[i+1] = R * sin(i*angle) + y1;
        }
        Hexagon<int> hex2 = {{pair_int(points[1],points[2]), pair_int(points[3],points[4]), pair_int(points[5],points[6]), pair_int(points[7],points[8]), pair_int(points[9],points[10]), pair_int(points[11],points[12])}};
        std::cout << "Pentagon" << std::endl;
        std::cout << "Coordinates of center point :" << std::endl;
        std::cin >> x1 >> y1;
        std::cout << "Radius :" << std::endl;
        std::cin >> R;
        if (R <= 0) {
            std::cout << "The entered values are not correct" << std::endl;
            return 0;
        }
        for(int i = 0; i < 10; i = i+2) {// расчет точек 
            angle =  360 / 5;
            points[i] = R * cos(i*angle) + x1;
            points[i+1] = R * sin(i*angle) + y1;
        }
        Pentagon<int> pen2 = {{pair_int(points[1],points[2]), pair_int(points[3],points[4]), pair_int(points[5],points[6]), pair_int(points[7],points[8]), pair_int(points[9],points[10])}};
        std::tuple<Pentagon<int>, Hexagon<int>, Octagon<int>> t1(pen2, hex2, oct2);
        print(t1);
        std:: cout << "Square: " << square(t1) << std::endl;
    }else{
         std:: cout << "Wrong type " << std::endl;
        return 0;
    }
}