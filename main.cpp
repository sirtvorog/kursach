#include <iostream>
#include "main.h"
using namespace std;

int main(){
	system("chcp 1251");
	setlocale(0, "");
	int choise=0;
	while (choise != -1) {
			cout << "С чем будем работать?\n"\
				"1. Типы данных\n"\
				"2. Одномерный массив\n"\
				"3. Многомерный массив\n"\
				"4. Массив символов\n"\
				"0. Ввыйти из программы\n"\
				"\nВаш выбор: ";
			cin >> choise;
			switch (choise) {
				case 0: {
					choise = -1;
					break;
				}
				case 1: {
					system("cls");
					main1();
					system("cls");
					break;
				}

				case 2: {
					system("cls");
					main2();
					system("cls");
					break;
				}

				case 3: {
					system("cls");
					main3();
					system("cls");
					break;
				}

				case 4: {
					system("cls");
					main4();
					system("cls");
					break;
				}
			}
	}
return 0;
}