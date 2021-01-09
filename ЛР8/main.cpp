/* Тимофеев Алексей 207Б

Создать приложение, которое будет считывать из стандартного ввода данные фигур, согласно варианту задания, выводить их характеристики на экран и записывать в файл. Фигуры могут задаваться как своими вершинами, так и другими характеристиками (например, координата центра, количество точек и радиус).
Программа должна:
1.	Осуществлять ввод из стандартного ввода данных фигур, согласно варианту задания;
2.	Программа должна создавать классы, соответствующие введенным данных фигур;
3.	Программа должна содержать внутренний буфер, в который помещаются фигуры. Для создания буфера допускается использовать стандартные контейнеры STL. Размер буфера задается параметром командной строки. Например, для буфера размером 10 фигур: oop_exercise_08 10
4.	При накоплении буфера они должны запускаться на асинхронную обработку, после чего буфер должен очищаться;
5.	Обработка должна производиться в отдельном потоке;
6.	Реализовать два обработчика, которые должны обрабатывать данные буфера:
a.	Вывод информации о фигурах в буфере на экран;
b.	Вывод информации о фигурах в буфере в файл. Для каждого буфера должен создаваться файл с уникальным именем.
7.	Оба обработчика должны обрабатывать каждый введенный буфер. Т.е. после каждого заполнения буфера его содержимое должно выводиться как на экран, так и в файл.
8.	Обработчики должны быть реализованы в виде лямбда-функций и должны хранится в специальном массиве обработчиков. Откуда и должны последовательно вызываться в потоке – обработчике.
9.	В программе должно быть ровно два потока (thread). Один основной (main) и второй для обработчиков;
10.	В программе должен явно прослеживаться шаблон Publish-Subscribe. Каждый обработчик должен быть реализован как отдельный подписчик.
11.	Реализовать в основном потоке (main) ожидание обработки буфера в потоке-обработчике. Т.е. после отправки буфера на обработку основной поток должен ждать, пока поток обработчик выведет данные на экран и запишет в файл.

14.		5-угольник	6-угольник	8-угольник
*/
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <fstream> 
#include <thread>
#include <unistd.h>
#include "figure.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "server.hpp"

using FigVec = std::vector<std::shared_ptr<Figure>>;

template<class A, class B, class C>
class Initiate {
    public:
    Initiate() {}
    ~Initiate() {}
    std::shared_ptr<Figure> Pentagon(double x1, double y1, int side) {
        return std::make_shared<A>(x1, y1, side);
    }
    std::shared_ptr<Figure> Hexagon(double x1, double y1, int side) {
        return std::make_shared<B>(x1, y1, side);
    }
    std::shared_ptr<Figure> Octagon(double x1, double y1, int side) {
        return std::make_shared<C>(x1, y1, side);
    }
};

void Print(){
    std::cout << "Введите координаты центра описанной окружности и длину радиуса описанной окружности через пробел: ";
}


int main(int argc, char * argv[]) {
    int file = 1;
    Server<FigVec>::get().register_subscriber([] (FigVec &fig) {
        std::cout << fig << std::endl;
        std::cout.flush();
    });
    Server<FigVec>::get().register_subscriber([&file] (FigVec &fig) {
        std::ofstream f;
        std::string name = std::to_string(file);
        name.append(".txt");
        f.open(name.c_str()); 
        f << fig;
        f.close();
        ++file;
        std::cout << "Буфер очищен и сохранен в файл " << (file - 1) << ".txt" << std::endl; 
        std::cout.flush();
    });
    std::thread thread([]() {
        Server<FigVec>::get().run();
    });
    int size_buf = 1;

    if (argc == 2) size_buf = atoi(argv[1]);
    double x1, y1;
    int side, m;
    FigVec fig;
    Initiate<Pentagon, Hexagon, Octagon> Init;
    std::cout << "Введите:\n 1  - добавить пятиугольник\n 2  - добавить шестиугольник\n 3  - добавить восьмиугольник\n";
    std::cout << " 4  - распечатать буфер \n 5  - завершить программу\n";
    std::cout << "Введите команду:";
    while (std::cin >> m && m < 5 && m > 0) {
        switch (m) {
            case 1: {
                Print();
                std::cin >> x1 >> y1 >> side;
                fig.push_back(Init.Pentagon(x1, y1, side));
                break;
            }
            case 2: {
                Print();
                std::cin >> x1 >> y1 >> side;
                fig.push_back(Init.Hexagon(x1, y1, side));
                break;
            }
            case 3: {
                Print();
                std::cin >> x1 >> y1 >> side;
                fig.push_back(Init.Octagon(x1, y1, side));
                break;
            }
            case 4: {
                std::cout << fig;
                break;
            }
            default:
                break;
        }
        if (fig.size() == size_buf) {
            Server<FigVec>::get().publish(fig);
            fig.clear();
            sleep(1);
        }
        std::cout << "Введите команду:";
    }
    fig.clear();
    Server<FigVec>::get().publish(fig);
    thread.join();
}