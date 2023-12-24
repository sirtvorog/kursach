#include <iostream>
#include <fstream>
#include "Windows.h"
#include <cstring>
#include "string.h"
#undef max

using namespace std;
const int sizeArr = 750;

int lox4(int vvod) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cin.clear();
	cin.ignore(1000, '\n');
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	cout << "������ �����. ����������, ������� ����� �����.\n";
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "��� �����: ";
	cin >> vvod;
	return vvod;
}


void clearing() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void countSymbolsInWords(char str[sizeArr]) {
	int count = 0;
	int countWords = 0;
	for (int i = 0; i < strlen(str); i++) {

		if (str[i] == ' ' or i==strlen(str)-1) {
			if (i == strlen(str) - 1) count++;
			countWords++;
			cout << countWords << " �����  �������� " << count << " c�������\n\n";
			count = 0;
			continue;
		}
		
		count++;
	}
}

void deleteSign(int position, char str[sizeArr]) {
	for (int i = position; i < strlen(str); i++) {
		str[i - 1] = str[i];
	}
	str[strlen(str) - 1] = '\0';
}

int isSpase(char sign) {
	if (sign == ' ') return 1;
	else return 0;
}

void editString(char str[sizeArr]) {
	for (int i = 0; i < strlen(str); i++) {
		while (isspace(str[i]) && str[i] == str[i + 1]) {
			deleteSign((i + 1), str);
		}
		if (!islower(str[i])) {
			str[i] = tolower(str[i]);
		}
		while (ispunct(str[i]) && str[i] == str[i + 1]) {
			deleteSign((i + 1), str);
		}
	}
}

void mergeWords(char words[75][10], int count, char* str) {
	str[0] = '\0';

	for (int i = 0; i < count; i++) {
		strcat_s(str, 750, words[i]);

		if (i != count - 1) {
			strcat_s(str, 750, " ");
		}
	}
}

void alphabetSort(char str[sizeArr]) {
	char words[75][10];
	int count = 0;
	char* context = nullptr;
	char* token = nullptr;
	token = strtok_s(str, " ", &context);
	while (token != nullptr && count < 75) {
		strcpy_s(words[count++], token);
		token = strtok_s(nullptr, " ", &context);
	}
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strcmp(words[i], words[j]) > 0) {
				char temp[10];
				strcpy_s(temp, words[i]);
				strcpy_s(words[i], words[j]);
				strcpy_s(words[j], temp);
			}
		}
	}
	mergeWords(words, count, str);
}


int linearSearch(char* str) {
	char pattern[10];
	cout << "\n������� ���������\n\n";
	cout<<"��� ����� : ";
	clearing();
	cin.getline(pattern, 10);
	int n = strlen(str);
	int m = strlen(pattern); 
	int count = 0;

	for (int i = 0; i <= n - m; i++) {
		int j;
		for (j = 0; j < m; j++) {
			if (str[i + j] != pattern[j])
				break;
		}
		if (j == m) {
			count++;
			cout << "\n\n������� ���������� � �������: " << i ;
		}

	}

	if (count == 0) return -1;
	else return count;
}

int main4() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream fout;
	ifstream fin;

	char str[sizeArr];
	int choise=0;
	
	cout << "������� ������� ����� :)\n\n";
	
	cout << "�������� ������ ����������::\n"\
		"1) � ����������\n"\
		"2) �� �����\n\n"\
		"��� �����: ";

	cin >> choise;

	switch (choise) {

		case (!isdigit): {
			lox4(choise);
		}

		case 1: {
			cout << "\n\n������� ���� ������ ����:\n";
			clearing();
			cin.getline(str, sizeArr);
		} break;

		case 2: {
			char c;
			int n = 0;
			char fileName[100];
			cout << "\n\n������� ���� � ����� ����:\n";
			clearing();
			cin.getline(fileName, sizeArr);

			fin.open(fileName);
			while (fin.get(c)) {
				str[n] = c;
				++n;
			}
			str[n] = '\0';
		} break;
	}
	bool exitFlag = false;

	while (exitFlag == false) {
		cout << "\n��� ����� ������ ������? \n" \
			"1) ��������������� ������\n" \
			"2) ������������� ������\n" \
			"3) ���������� ���������� �������� � ������ �����\n" \
			"4) �������� ����� ���������\n" \
			"5) ����� � ������� ����\n"\
			"6) ����� �� ���������\n"\
			"\n\n��� �����: ";

		cin >> choise;
		while (choise > 6 or choise < 1) {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			cout << "������ �����. ���������� ��� ���!\n";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "��� �����: ";
			cin >> choise;
		}
		switch (choise) {

			case (!isdigit): {
				lox4(choise);
			}

			case 1: {
				editString(str);
				cout << "\n����������������� ������:\n";
				cout << str << "\n";
			}break;

			case 2: {
				alphabetSort(str);
				cout << "\n��������������� ������:\n";
				cout << str << "\n";
			}break;

			case 3: {
				countSymbolsInWords(str);
			}break;

			case 4: {
				int result = linearSearch(str);
				if (result == -1)
					cout << "��������� �� �������" << "\n\n";
				else
					cout << "\n\n����� ����������: " << result << "\n\n";
			}break;

			case 5: {
				main4();
			}break;

			case 6: {
				cout << "\n\n���� - ���� :(\n\n";
				exitFlag =true;
				
			}break;
		}
		
	}

	
	return 0;
}