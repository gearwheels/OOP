/*       Тимофеев Алексей 207Б
14.	Вариант	5-угольник	6-угольник	8-угольник
Спроектировать простейший «графический» векторный редактор. 
Требование к функционалу редактора:
создание нового документа
импорт документа из файла
экспорт документа в файл
создание графического примитива (согласно варианту задания)
удаление графического примитива
отображение документа на экране (печать перечня графических объектов и их характеристик в std::cout)
реализовать операцию undo, отменяющую последнее сделанное действие. (должно действовать для операций добавления/удаления фигур.)
*/
#include <stack>
#include <execution>
#include <iostream>
#include <algorithm>
#include <memory>
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp" 
#include "figure.hpp"

struct Memento {
    std::vector<std::shared_ptr<Figure>> state;
    Memento() {}
    Memento(const std::vector<std::shared_ptr<Figure>> &other) : state({other}) {}
    ~Memento() {}
};

struct Backup {
    std::stack<Memento> temp;
    void Save(std::vector<std::shared_ptr<Figure>>  fignext) {
        temp.emplace(fignext);
    }
    std::vector<std::shared_ptr<Figure>> Undo() {
        if (!temp.empty()) {
            std::vector<std::shared_ptr<Figure>> res = temp.top().state;
            temp.pop();
            return res;
        } else {
            throw std::logic_error("impossible to return, vector is empty");
        }
    }
};

template<class A, class B, class C>
class Initiate {
    public:
    Initiate() {}
    ~Initiate() {}
    std::shared_ptr<Figure> Pentagon(double x1, double y1, int R) {
        return std::make_shared<A>(x1, y1, R);
    }
    std::shared_ptr<Figure> Hexagon(double x1, double y1, int R) {
        return std::make_shared<B>(x1, y1, R);
    }
    std::shared_ptr<Figure> Octagon(double x1, double y1, int R) {
        return std::make_shared<C>(x1, y1, R);
    }
};

void Print(){
    std::cout << "Enter the coordinates of the center point and the length of the radius of the circumscribed circle, separated by a space: ";
}

int main() {
    Backup doo;
    double x1, y1;
    int R, m;
    std::vector<std::shared_ptr<Figure>> fig;
    Initiate<Pentagon, Hexagon, Octagon> addfigure;
    std::cout << "Enter:\n 1  - creating a new document\n 2  - import document from file\n 3  - export document to file\n";
    std::cout << " 4  - add pentagon\n 5  - add hexagon\n 6  - add octagon\n";
    std::cout << " 7  - delete shape by index \n 8 - print shapes to the screen \n 9 - undo the last action \n 0 - end the program\n";
    FILE * f;
    std::cout << "Enter the command: ";
    while (std::cin >> m && m < 10 && m > 0) {
        switch (m) {
            case 1: {//создание чистого документа(очистка)
                doo.Save(fig);
                fig.clear();
                break;
            }
            case 2: { //импорт документа из файла 
                doo.Save(fig);
                fig.clear();
                int a;
                std::string name;
                std::cout << "Enter file: ";
                std::cin >> name;
                f = fopen(name.c_str(), "r");
                if (f == NULL) {
                    std::cout << "File open error";
                    break;
                }
                while (!feof(f)) {
                    fread(&a, sizeof(int), 1, f);
                    fread(&x1, sizeof(double), 1, f);
                    fread(&y1, sizeof(double), 1, f);
                    fread(&R, sizeof(int), 1, f);
                    switch (a) {
                    case 1: {
                        fig.push_back(addfigure.Pentagon(x1, y1, R));
                        break;
                    }
                    case 2: {
                        fig.push_back(addfigure.Hexagon(x1, y1, R));
                        break;
                    }
                    case 3: {
                        fig.push_back(addfigure.Octagon(x1, y1, R));
                        break;
                    }
                    default:
                        break;
                    }
                    a = -1;
                }
                fclose(f);
                break;
            }
            case 3: {//экспорт документа в файл
                std::string name;
                std::cout << "Enter file:";
                std::cin >> name;
                f = fopen(name.c_str(), "w");
                if (f == NULL) {
                    std::cout << "File open error"<< std::endl;
                    break;
                }
                for (int i = 0; i < fig.size(); ++i) {
                    int a;
                    if (fig[i]->Name() == "Pentagon" ) a = 1;
                    if (fig[i]->Name() == "Hexagon" ) a = 2;
                    if (fig[i]->Name() == "Octagon" ) a = 3;
                    fwrite(&a, sizeof(int), 1, f);
                    std::vector<Pair> temp = fig[i]->Coord();
                    fwrite(&temp[0].x, sizeof(double), 1, f);
                    fwrite(&temp[0].y, sizeof(double), 1, f);
                    int b = fig[i]->Get();
                    fwrite(&b, sizeof(int), 1, f);
                }
                fclose(f);
                break;
            }
            case 4: {
                Print();
                std::cin >> x1 >> y1 >> R;
                if (R < 0) {
                    std::cout << "The entered values are incorrect! Length cannot be negative."<< std::endl;
                    break;
                }
                doo.Save(fig);
                fig.push_back(addfigure.Pentagon(x1, y1, R));
                break;
            }
            case 5: {
                Print();
                std::cin >> x1 >> y1 >> R;
                if (R < 0) {
                    std::cout << "The entered values are incorrect! Length cannot be negative."<< std::endl;
                    break;
                }
                doo.Save(fig);
                fig.push_back(addfigure.Hexagon(x1, y1, R));
                break;
            }
            case 6: {
                Print();
                std::cin >> x1 >> y1 >> R;
                if (R < 0) {
                    std::cout << "The entered values are incorrect! Length cannot be negative." << std::endl;
                    break;
                }
                doo.Save(fig);
                fig.push_back(addfigure.Octagon(x1, y1, R));
                break;
            }
            case 7: {
                int ind;
                std::cout << "Enter index:";
                std::cin >> ind;
                doo.Save(fig);
                if (ind <= 0 || ind >= fig.size() + 1) {
                    std::cout << "The entered values are not correct" << std::endl;
                    break;
                }
                ind--;
                fig.erase(fig.begin() + ind);
                break;
            }
            case 8: {
                std::cout << fig;
                break;
            }
            case 9: {
                fig = doo.Undo();
                std::cout << std::endl;
                break;
            }
            default:
                break;
        }
        std::cout << "Enter the command: ";
    }
}