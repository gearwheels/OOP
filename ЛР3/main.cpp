#include <iostream>  // Тимофеев Алексей М8О-207Б-19
#include "figure.hpp" 
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"

std::ostream& operator<<(std::ostream &os, Pair p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

std::ostream& operator<<(std::ostream &os, std::vector<Pair> p) {
    for (int i = 0; i < p.size(); ++i) {
        os << " " << p[i];
    }
    return os;
}

int main() {
    std::string name;
    double x1, y1;
    int length, m;
    std::vector<Figure *> figure;
    std::cout << "Enter:\n 1 - add shape\n 2 - remove element by index\n 3 - print a sequence of shapes\n 4 - display the total area of the figures\n 5 - end the program\n";
    std::cout << "Enter the command:";
    while (std::cin >> m && m < 5) {
        switch (m) {
            case 1: {
                std::cout << "Enter the number of corners in the shape:";
                std::cin >> m;
                switch (m) {
                    case 5: {
                        std::cout << "Enter the coordinates of the top point of the point and the length of the side: ";
                        std::cin >> x1 >> y1 >> length ;
                        if (length <= 0 ) {
                            std::cout << "The entered values are not correct" << std::endl;
                            break;
                        }
                        Figure * pentagon = new Pentagon(x1, y1, length); 
                        figure.push_back(pentagon);
                         break;
                    }
                    case 6: {
                       std::cout << "Enter point coordinates and side length: ";
                        std::cin >> x1 >> y1 >> length;
                        if (length <= 0 ) {
                            std::cout << "The entered values are not correct" << std::endl;
                            break;
                        }
                        Figure * hexagon = new Hexagon(x1, y1, length); 
                        figure.push_back(hexagon);
                        break;
                        }
                    case 8: {
                        std::cout << "Enter point coordinates and side length: ";
                        std::cin >> x1 >> y1 >> length;
                        if (length <= 0 ) {
                            std::cout << "The entered values are not correct" << std::endl;
                            break;
                        }
                        Figure * octagon = new Octagon(x1, y1, length);
                        figure.push_back(octagon);
                        break;
                    }
                    default: {
                        std::cout << "Incorrect number of corners.\n Shapes available: pentagon, hexagon, octagon.\n Try again. \n";
                        break;
                    }
                }
                break;
            }
            case 2: {
                int ind;
                std::cout << "Enter index:";
                std::cin >> ind;
                if (ind <= 0 || ind >= figure.size() + 1) {
                    std::cout << "The entered values are not correct" << std::endl;
                    break;
                }
                ind--;
                figure.erase(figure.begin() + ind);
                break;
            }
            case 3: {
                 for (int i = 0; i < figure.size(); ++i) {
                     std::cout << std::endl;
                     std::cout << figure[i]->GetSize() << "-angle" << std::endl;
                     std::cout << "Coordinates:" << figure[i]->Coord() << std::endl;
                     std::cout << "Center of the figure: " << figure[i]->Center() << std::endl;
                     std::cout << "Square: " << figure[i]->S() << std::endl;
                 }
                break;
            }
            case 4: {
                double s = 0;
                for (int i = 0; i < figure.size(); ++i) {
                     s += figure[i]->S();
                }
                std::cout << std::endl << "total area: " << s << std::endl;
                break;
            }
            default:
                break;
        }
        std::cout << "\n Enter the command:";
    }
}
