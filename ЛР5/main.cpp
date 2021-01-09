#include <iostream>
#include <algorithm>
#include <memory>
#include "pentagon.h"
#include "TIterator.h"
#include "TListItem.h"
#include "TList.h"

void menu(){
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1) Add pentagon" << std::endl;
    std::cout << "2) Delete figure from list" << std::endl;
    std::cout << "3) Print list"  << std::endl;
    std::cout << "4) Find the number of objects which set area less than the established one"  << std::endl;
    std::cout << "0) Exit" << std::endl;
}
int main(){
    int32_t act = 1;
    TList<Pentagon<double>> list;
    std::shared_ptr<Pentagon<double>> ptr;
    while (act != 0) {
        menu();
        std::cin >> act;
        switch(act) {
            case 1:
                double xO, yO, R;
                std::cout << "Enter coord to center: ";
                std::cin >> xO >> yO;
                std::cout << "\nEnter radius: ";
                std::cin >> R;
                if (R <= 0.0){
                    std::cout << "The entered values are not correct" << std::endl;
                    return 0;
                }
                ptr = std::make_shared<Pentagon<double>>(xO,yO,R); 
                list.Push(ptr);
                break;
            case 2:
                list.Pop();
                break;
            case 3:
                std::cout << list << std::endl;
                break;
            case 4:
                double s;
                std::cout << "Enter square" << std::endl;
                std::cin >> s;
	            if(s<=0){
		            std::cout << "Invalid data entered" << std::endl;
	            }else{
                    int k = 0, out = 0;
                    if(!list.IsEmpty()) {
                        for(auto i : list) {
                            std::cout << k << " Square " << i->S() << std::endl;
                            if (i->S()<s){
                                ++out;
                            }
                            ++k;
                        } 
                    } else {
                        std::cout << "List is empty." << std::endl;
                    }
                    std::cout << "The number of objects which set area less than the established one: " << out << std::endl;}
                break;
            case 0:
                list.Del();
                break;
            default:
                std::cout << "Incorrect command" << std::endl;;
                break;
        }
    }
    return 0;
}