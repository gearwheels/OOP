#include <iostream>      							//Тимофеев Алексей М8О-207Б-19
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

class LongInt{
    private:
    unsigned int head;
	unsigned int tail;
	public: 
	void SumLongInt(LongInt inVar2)  {
		long long int ohead1 = head;
		long long int ohead2 = inVar2.head;
		long long int otail1 = tail;
		long long int otail2 = inVar2.tail;
		otail1 += otail2;
		ohead1 += ohead2;
		ohead1 += otail1;
		if (ohead1 > 8589934590){
			std::cout << "Ошибка переполнеия " << ".\n" << endl;
			return;
		}
		std::cout << "Сумма равна " << ohead1 << ".\n" << endl;
	}
	void DiffLongInt(LongInt inVar1, LongInt inVar2){
		long long int otail1 = inVar1.tail;
		long long int ohead1 = inVar1.head;
		long long int otail2 = inVar2.tail;
		long long int ohead2 = inVar2.head; 
		otail1 -= otail2;
		ohead1 -= ohead2;
		ohead1 += otail1;
		if (ohead1 < 0){
			std::cout << "Разность этих чисел не может быть отрицательным " << ".\n" << endl;
			return;
		}
		std::cout << "Разность равна " << ohead1 << ".\n" << endl;
	}
	int check1 (int a, int m, int m1){ 
			int n;								// Ф-ия проверяет элемент массива Data на переполнение; проверяет может ли m1 (предшествующий эл-т числа) дать + 1 к0 m
			if (a <= ((m*2) % 10)){ return n = 2; } 
			else if ((m1*2) >9){
				if (a <= ((m*2) % 10 + 1)){ return n = 1; }
				else{ return n = 0;}
			}else{ return n = 0;}  
	}
	bool minus = false;

	LongInt(unsigned int h, unsigned int t ){ 
		head = h;
		tail = t;  
	}
	void SetLongInt(string Data){  
		int arr[10] = {4, 2, 9, 4, 9, 6, 7, 2, 9, 5};   //4294967295   8589934590
		int a, n, b = 0;
		int i1 = 0;
		char st[2];
		st[0] = Data[0];
		 n = Data.length(); 
		bool f = true;
		head = 0;
		tail = 0;
		minus = false;
		if ((n < 10)||((n == 10) && (atoi(st) < 4))){
			f = false;
		}
		for (int i = 0; i < n; ++i){
			st[0] = Data[i];   
			a = atoi(st); 
			//std::cout << i << " i " << endl;
			//std::cout << n << endl;
			if ((a > arr[i]) && (f == true)){
				//std::cout << "0.1" << endl;
				if ((i == 9) && (a > arr[i]) && (tail <= 4294967290) ){
				//	std::cout << "искл" << endl;
					tail += ((a + b) / 2)* pow(10,(n - i - 1));
					head += ((a + b) / 2)* pow(10,(n - i - 1));
					tail += (a % 2)* pow(10,(n - i - 1));
					/*std::cout << head << "!!!!" << endl;
					std::cout << tail << "!!!!" << endl;*/
					return;
				}
				i1 = i;
				if (check1(a, arr[i], arr[++i1]) == 1){
					//std::cout << "1" << endl; // получаем что можно разложить по 2-м unsigned. 
					tail += (((a - 1) + b) / 2)* pow(10,(n - i - 1)); 
					head += (((a - 1) + b) / 2)* pow(10,(n - i - 1));	
					//std::cout << head << "!!!!" << endl;
					//std::cout << tail << "!!!!" << endl;
					b = 10;	  
				}else if (check1(a, arr[i], arr[++i1]) == 2){
					//std::cout << "2" << endl;
					tail += ((a + b) / 2)* pow(10,(n - i - 1));
					head += ((a + b) / 2)* pow(10,(n - i - 1));
					if (b == 0){
						tail += (a % 2)* pow(10,(n - i - 1));
					}
				//	std::cout << head << "!!!!" << endl;
				//	std::cout << tail << "!!!!" << endl;
					b = 0;
				}else if (check1(a, arr[i], arr[++i1]) == 0){ 
				//	std::cout << "0" << endl;
					head = 0;
					tail = 0;
					return;
				}
			}else if (a < arr[i]){ 
				//std::cout << "0.2" <<endl;
				if (f){
					tail += ((a + b) / 2)* pow(10,(n - i - 1));
					head += ((a + b) / 2)* pow(10,(n - i - 1));
					if (b == 0){
						tail += (a % 2)* pow(10,(n - i - 1));
					}
				}else{
					tail += (a + b)* pow(10,(n - i - 1));
				}
				//std::cout << head << "!!!!" << endl;
				//std::cout << tail << "!!!!" <<endl;	
				i1 = i + 1;
				int a1;
				st[0] = Data[i1];   
				a1 = atoi(st);
				if ((a < arr[i]) && (a1 > arr[i1]) && (f)){
					f = true;
				}else{
					f = false;
				}
				b = 0;
			}else if (a == arr[i]){ 
				//std::cout << "0.3" <<endl;
				if (f){
					tail += ((a + b) / 2)* pow(10,(n - i - 1));
					head += ((a + b) / 2)* pow(10,(n - i - 1));
					if (b == 0){
						tail += (a % 2)* pow(10,(n - i - 1));
					}
				}else{
					tail += (a + b)* pow(10,(n - i - 1));
				}
				//std::cout << head << "!!!!" << endl;
				//std::cout << tail << "!!!!" <<endl;
				b = 0;
			}else if (f == false){
				//std::cout << "0.4" <<endl;
				tail += (a + b)* pow(10,(n - i - 1));
				//std::cout << head << "!!!!" << endl;
				//std::cout << tail << "!!!!" <<endl;	
			}
			
		}
	}
	void MultLongInt (LongInt inVar2){
		long long int otail1 = tail;
		long long int ohead1 = head;
		long long int otail2 = inVar2.tail;
		long long int ohead2 = inVar2.head; 
		ohead1 += otail1;
		ohead2 += otail2;
		ohead1 *= ohead2;
		if ((minus || inVar2.minus) && ((minus && inVar2.minus) == false)){
			std::cout << "Произведение этих чисел не может быть отрицательным " << ".\n" << endl;
			return;
		}
		if (ohead1 > 8589934590){
			std::cout << "Ошибка переполнеия " << ".\n" << endl;
			return;
		}
		std::cout << "Произведение равно " << ohead1 << ".\n" << endl;
	}
	void DivILongInt (LongInt inVar2){
		long long int otail1 = tail;
		long long int ohead1 = head;
		long long int otail2 = inVar2.tail;
		long long int ohead2 = inVar2.head; 
		ohead1 += otail1;
		ohead2 += otail2;
		if ((ohead1 == 0) && (ohead2 == 0)){
			std::cout << "Частное равно 0." << endl;
		}else{
			ohead1 /= ohead2;
			if ((minus || inVar2.minus) && ((minus && inVar2.minus) == false)){
				std::cout << "Частное этих чисел не может быть отрицательным " << ".\n" << endl;
				return;
			}
			std::cout << "Частное равно " << ohead1 << ". \n" << endl;
		}
	}
	void DivMLongInt (LongInt inVar2){
		long long int otail1 = tail;
		long long int ohead1 = head;
		long long int otail2 = inVar2.tail;
		long long int ohead2 = inVar2.head; 
		ohead1 += otail1;
		ohead2 += otail2;
		if ((ohead1 == 0) && (ohead2 == 0)){
			std::cout << "Остаток равен 0." << endl;
		}else{
			if ((minus || inVar2.minus) && ((minus && inVar2.minus) == false)){
				std::cout << "Остаток этих чисел не может быть отрицательным " << ".\n" << endl;
				return;
			}
			ohead1 %= ohead2;
			std::cout << "Остаток равен " << ohead1 << ". \n" << endl;
		} 
	}
	void ompLongInt (LongInt inVar2){
		long long int otail1 = tail;
		long long int ohead1 = head;
		long long int otail2 = inVar2.tail;
		long long int ohead2 = inVar2.head; 
		ohead1 += otail1;
		ohead2 += otail2;
		if (minus){
			ohead1 *= -1;
		}
		if (inVar2.minus){
			ohead2 *= -1;
		}
		if (ohead1 < ohead2){
			std::cout << ohead1 << " < " << ohead2 << endl;
		} else if (ohead1 > ohead2){
			std::cout << ohead1 << " > " << ohead2 << endl;
		} else if (ohead1 == ohead2){
			std::cout << ohead1 << " = " << ohead2 << endl;
		}
	}
	void GetLongInt(){
		long long o1 = head;
		long long o2 = tail;
		o1 = o1 + o2;
		std::cout << "Первое поле: "<< head << "   Второе поле: " << tail << ".\n"<<endl;
		if (minus){
			o1 *= -1;
		}
		std::cout << "Число: "<< o1 << ".\n" <<endl;
	}
};
void CheckZn(LongInt inVar1, LongInt inVar2){
		if ((inVar1.minus) && (inVar2.minus)){
			std::cout << "Сумма этих чисел не может быть отрицательным " << ".\n" << endl;
			return;
		}else if (inVar1.minus){
			inVar1.DiffLongInt (inVar2, inVar1);
			return;
		}else if (inVar2.minus){
			inVar1.DiffLongInt (inVar1, inVar2);
			return;
		}else{
			inVar1.SumLongInt (inVar2);
			return ;
		}
	}

bool CheckDig (string Data){
	bool flag=true ;
	int i = Data.length();
	for (int l = 0; l <= i-1; ++l) {
		if (isdigit(Data[l])){
			flag = true;
		}else{
			return flag = false;
		}
	}
	return flag;
}


main(){
	LongInt inVar1 (0,0);
	LongInt inVar2 (0,0); 
	LongInt outVar (0,0); 
	std::string Data;
	

    for(;;){
		int a;
		std::cout << "Выберите действие, которое нужно выполнить.\n" << endl;
		std::cout <<"Чтобы закончить программу, введите 0.\n Чтобы создать переменные, введите 1.\n Чтобы вывести переменные, введите 2.\n Чтобы сложить числа, введите 3.\n Чтобы получить разность чисел введите 4.\n Чтобы перемножить числа, введите 5.\n Чтобы получить частное числа, введите 6.\n Чтобы получить остаток от деления чисел, введите 7.\n Чтобы сравнить числа, введите 8.\n" << endl;
		std::cin >> a;
		std::cin.ignore(32767, '\n');
		
		if (a == 0){
			std::cout <<"Конец работы программы\n." << endl;
			break;
		} else if(a == 1){
			for(int ii = 0; ii < 2; ++ii){
				std::cout <<"Введите число.\t" << endl;
				getline(cin, Data);
				if (Data.length() != 0){ // проверка пустая ли строка
			 		if (Data[0] == '-'){
						 std::cout <<"Введите безнаковые числа.\n" << endl;
						}
					if(CheckDig(Data)){
						if (Data.length() <= 10){  // предпроверка на переполнение
							//std::cout << "Data.length() <= 10    " << Data <<endl;
							if (ii == 0){
						 		inVar1.SetLongInt (Data);
							}else{
								inVar2.SetLongInt(Data);
							}
						}else{
							--ii;
							std::cout <<"Ошибка переполнения.\n." << endl;
						}
					}else{ --ii;
						std::cout <<"Введите строку из чисел.\n" << endl;
					}

				}else{
					--ii;
					std::cout <<"Пустая строка.\n" << endl;
				}
			}
		} else if (a == 2){
			inVar1.GetLongInt();
			inVar2.GetLongInt();
		}else if (a == 3){
			CheckZn(inVar1, inVar2);
		}else if (a == 4){
			if (inVar2.minus){
				inVar2.minus = false;
			}else{
				inVar2.minus = true;
			}
			CheckZn(inVar1, inVar2);
			if (inVar2.minus){
				inVar2.minus = false;
			}else{
				inVar2.minus = true;
			}
		}else if (a == 5){
			inVar1.MultLongInt (inVar2);
		}else if (a == 6){
			inVar1.DivILongInt (inVar2);
		}else if (a == 7){
			inVar1.DivMLongInt (inVar2);
		}else if (a == 8){
			inVar1.ompLongInt (inVar2);
		}
	}
	return 0;
}
