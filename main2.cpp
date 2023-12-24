
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <conio.h>
#include <windows.h>

using namespace std;
using namespace chrono;

const int N = 100;
int arr[N];
int unsortArr[N];
bool flag = false, sortFlag = false;




void fullArr2() {
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		arr[i] = -99 + rand() % (99 + 99 + 1);
	}
}

int lox2(int vvod) {
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

void printArr2(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

void bubbleSort(int* arr) {
	int count = 0;

	for (int i = 0; i < (N - 1 - i); i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
			else count++;
		}
		if (count == N - 1)
			break;
		else count = 0;

	}
}

void shakerSort(int* arr) {
	for (int i = 0; i < (N / 2 + 1); i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
		for (int k = N - 1 - i; k > i + 1; k--) {
			if (arr[k] < arr[k - 1]) {
				swap(arr[k], arr[k - 1]);
			}
		}
	}
}

void combSort(int* arr) {
	double  k = 1.247;
	int length = N - 1, count = 0;

	while (length >= 1) {
		for (int i = 0; i + length < N; i++) {

			if (arr[i] > arr[i + length])
				swap(arr[i], arr[i + length]);
		}
		length /= k;
	}

	while (true) {
		for (int j = 0; j < N - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
			else count++;
		}
		if (count == N - 1)
			break;
		else count = 0;
	}
}

void insertSort(int* arr) {
	int key, j;
	for (int i = 1; i < N; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

void quickSort(int* arr, int size) {
	int begin = 0;
	int end = size - 1;
	int midArr = arr[size / 2];
	do {
		while (arr[begin] < midArr) begin++;
		while (arr[end] > midArr) end--;
		if (begin <= end) {
			swap(arr[begin], arr[end]);
			begin++;
			end--;
		}
	} while (begin < end);
	if (begin < size) quickSort(&arr[begin], size - begin);
	if (end > 0) quickSort(arr, end + 1);
}






int binSearch(int arr[], int key, int begin, int end) {
	if (end >= begin) {
		int mid = begin + (end - begin) / 2;

		if (arr[mid] == key) {
			return mid;
		}

		if (arr[mid] > key) {
			return binSearch(arr, key, begin, mid - 1);
		}

		return binSearch(arr, key, mid + 1, end);
	}

	return -1;
}





int main2()
{

	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;

	system("chcp 1251");
	setlocale(0, "");
	int choose = -1;
	int count = 0;

	cout << "������� ������� �����! :)" << endl;

	while (choose != 0)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);

		cout << "\n\n\n��������, ��� �� ������ �������, � ������� �����, �������������� ������ �������, �� ���� ����: \n" \
			"1. C������ � ������� ������������� ������, �������� �������� ��������� ��������� ��������, � ����������� ���������.\n" \
			"2. ������������� ��������� � ������ 1 ������ (����������� �� �������� � ��������), � ����� ���������� ����� ����������� �� ����������.\n" \
			"3. ����� ����������� � ������������ ������� �������, � ����� ���������� ����� ����������� �� ����� � ��������������� ������� � �����������������.\n" \
			"4. ����� ������� �������������� ������������ � ������������� �������� � �������, � ����� ����� ���������� � ������� ���������, ������� ����� ����� ��������." \
			"���������� ����� ����������� �� ����� � ��������������� � ����������������� �������.\n" \
			"\n5. ���������� ���������� ��������� � �������, ������� ������, ��� ��������, ������� �� ��������.\n" \
			"6. ���������� ���������� ��������� � �������, ������� ������, ��� ��������, ������� �� ��������.\n" \
			"7. ������ ���� �� �������, �������� �������� ����� ���������� ���� �����, � ����� ���������� ����� ����������� �� �����.\n" \
			"8. �������� ������� �������� ������� ��� ���������, ������� �� �������. ���������� ����������� �����.\n" \
			"9. ��������� ����������������� ������ �� ���, �������� ������� �������� � ������������ � �������� ��� 3. (��� ���� ������, ����� �����������, ��������)\n" \
			"-1. ��������� ������ � ���������� :(\n\n\n";

		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "��� �����: ";
		cin >> choose;
		cout << "\n\n";

		count += 1;
		if (count == 3) {
			cout << "���������� :)\n\n";
			cout << "�������������� ������:\n";
			printArr2(unsortArr, N);
			cout << "\n\n��������������� ������:\n";
			printArr2(arr, N);
			cout << "\n\n";
			count = 0;
		}



		switch (choose) {

		case (!isdigit): {
			cin.clear();
			cin.ignore(1000, '\n');
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			cout << "������ �����. ����������, ������� ����� �����.\n";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			continue;
		} break;

		case -1: {
			cout << "����-���� :(";
			choose = 0;
		} break;

		case 1: {											//full arr

			fullArr2();

			for (int i = 0; i < N; i++) {
				unsortArr[i] = arr[i];
			}

			printArr2(arr, N);

			flag = true;
		}
			  break;

		case 2: {												//sort choose

			if (flag == false) {
				cout << "�������������� ������:\n";
				fullArr2();

				for (int i = 0; i < N; i++) {
					unsortArr[i] = arr[i];
				}

				printArr2(arr, N);
			}

			sortFlag = true;
			cout << "\n\n";
			cout << "����� ���������� �� ������ ������������?\n 1. ���������� ��������� \n 2. ������-���������� \n 3. ���������� ���������� \n 4. ���������� ��������� \n 5. ������� ���������� \n\n";
			cout << "��� �����: ";
			int sortChoose;
			cin >> sortChoose;
			if (sortChoose > 5 or sortChoose < 1 or !isdigit) sortChoose = lox2(sortChoose);
			cout << "\n\n";

			cout << "��������������� ������:\n";

			start = steady_clock::now();

			switch (sortChoose) {

			case 1: {
				bubbleSort(arr);
			}
				  break;


			case 2: {
				shakerSort(arr);
			}
				  break;


			case 3: {
				combSort(arr);
			} break;


			case 4: {
				insertSort(arr);
			}break;


			case 5: {
				quickSort(arr, N);
			}
			}

			end = steady_clock::now();

			printArr2(arr, N);

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ :  " << duration_cast<nanoseconds>(end - start).count() << " ����������\n";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
			  break;

		case 3: {															// max and min
			if (flag == false) {
				cout << "�������������� ������:\n";
				fullArr2();

				for (int i = 0; i < N; i++) {
					unsortArr[i] = arr[i];
				}

				printArr2(unsortArr, N);
			}
			if (sortFlag == false) {
				cout << "\n\n��������������� ������:\n";
				shakerSort(arr);
				printArr2(arr, N);
			}

			//unsorted
			int max = unsortArr[0], min = unsortArr[0];

			start = steady_clock::now();

			for (int i = 1; i < N; i++) {
				if (unsortArr[i] > max)  max = unsortArr[i];
				if (unsortArr[i] < min)  min = unsortArr[i];
			}

			end = steady_clock::now();

			cout << "\n\n������������ �������: " << max << "\n����������� �������: " << min;

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ����������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			//sorted
			start = steady_clock::now();

			max = arr[N - 1];
			min = arr[0];

			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ��������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
			  break;

		case 4: {													//midlle and quantity

			if (flag == false) {
				cout << "�������������� ������:\n";
				fullArr2();

				for (int i = 0; i < N; i++) {
					unsortArr[i] = arr[i];
				}

				printArr2(unsortArr, N);
			}
			if (sortFlag == false) {
				cout << "\n\n��������������� ������:\n";
				shakerSort(arr);
				printArr2(arr, N);
			}

			int midArr = (arr[0] + arr[N - 1]) / 2;
			int quantity = 0, ID = -1;

			//unsorted


			start = steady_clock::now();

			for (int i = 0; i < N; i++) {
				if (unsortArr[i] == midArr) {
					quantity++;
					ID = i;
				}

				if (ID != -1) {
					cout << "\n\n������ ���������� �������� � ����������������� �������: " << ID;
					ID = -1;
				}
			}

			cout << "\n\n������� �������������� ������������� � ������������ ��������:"\
				" " << midArr << "\n���������� ��������� � �������, ������ ����� ��������: " << quantity;

			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ����������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			//sorted

			start = steady_clock::now();

			int search = binSearch(arr, midArr, 0, N - 1);
			quantity = 0;
			if (search != -1) {
				cout << "\n\n������ ���������� �������� � ��������������� �������: " << search;
				quantity++;
				for (int i = search + 1; i < N; i++) {
					if (arr[i] == midArr) {
						quantity++;
						cout << "\n������ ���������� �������� � ��������������� �������: " << i;
					}
					else break;
				}

				for (int i = search - 1; i < N; i--) {
					if (arr[i] == midArr) {
						quantity++;
						cout << "\n������ ���������� �������� � ��������������� �������: " << i;
					}
					else break;
				}

			}

			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ��������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);


		} break;

		case 5: {

			if (flag == false) {
				cout << "�������������� ������:\n";
				fullArr2();

				for (int i = 0; i < N; i++) {
					unsortArr[i] = arr[i];
				}

				printArr2(unsortArr, N);
			}
			if (sortFlag == false) {
				cout << "\n\n��������������� ������:\n";
				shakerSort(arr);
				printArr2(arr, N);
			}

			int num, quantityLess = 0;
			cout << "\n\n������� ����� :)\n\n���� �����: \n";
			cin >> num;

			//unsorted

			start = steady_clock::now();

			for (int i = 0; i < N; i++) {
				if (unsortArr[i] < num) quantityLess++;
			}
			cout << "\n\n���������� ���������, �������� ������� ������ ����������: " << quantityLess;

			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ����������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			//sorted
			int moreID = 0;

			start = steady_clock::now();

			for (int i = 0; i <= N; i++) {
				if (arr[i] > num) {
					moreID = i;
					break;
				}
			}
			//cout << "\n\n���������� ���������, �������� ������� ������ ����������: " ;

			//cout << moreID;
			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ��������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		} break;

		case 6: {

			if (flag == false) {
				cout << "�������������� ������:\n";
				fullArr2();

				for (int i = 0; i < N; i++) {
					unsortArr[i] = arr[i];
				}

				printArr2(unsortArr, N);
			}
			if (sortFlag == false) {
				cout << "\n\n��������������� ������:\n";
				shakerSort(arr);
				printArr2(arr, N);
			}

			int num, quantityMore = 0;
			cout << "\n\n������� ����� :)\n\n���� �����:\n";
			cin >> num;

			//unsorted

			start = steady_clock::now();

			for (int i = 0; i < N; i++) {
				if (unsortArr[i] > num) quantityMore++;
			}
			cout << "\n\n���������� ���������, �������� ������� ������ ����������: " << quantityMore;

			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ����������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			//sorted
			int moreID = 0;

			start = steady_clock::now();

			int i;

			for (i = 0; i <= N && arr[i] > num; i++);

			//cout << "\n\n���������� ���������, �������� ������� ������ ����������: ";

			//cout << N-moreID;

			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ��������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		} break;

		case 7: {

			if (flag == false) {
				cout << "�������������� ������:\n";
				fullArr2();

				for (int i = 0; i < N; i++) {
					unsortArr[i] = arr[i];
				}

				printArr2(unsortArr, N);
			}
			if (sortFlag == false) {
				cout << "\n\n��������������� ������:\n";
				shakerSort(arr);
				printArr2(arr, N);
			}

			int num, ID = -1;
			cout << "������� ����� :)\n\n���� �����\n";
			cin >> num;

			//unsorted

			start = steady_clock::now();

			for (int i = 0; i < N; i++) {
				if (unsortArr[i] == num) {
					ID = i;
					break;
				}
			}
			if (ID != -1) cout << "\n\n������� � ����� ��������� ��������� � ����������������� ������� ��� �������� " << ID;
			else cout << "\n\n�������� � ����� ��������� ��� � ������� :(";

			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ����������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			//sorted

			start = steady_clock::now();

			int sortID = binSearch(arr, num, 0, N);
			if (sortID != -1) cout << "\n\n������� � ����� ��������� ��������� � ��������������� ������� ��� �������� " << sortID;
			end = steady_clock::now();

			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\n\n�����, ������� ������������� �� ���������� ������ � ��������������� �������:"\
				" " << duration_cast<nanoseconds>(end - start).count() << " ����������";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		} break;

		case 8: {
			if (flag == false) {
				cout << "�������������� ������:\n";
				fullArr2();

				for (int i = 0; i < N; i++) {
					unsortArr[i] = arr[i];
				}

				printArr2(unsortArr, N);
			}
			if (sortFlag == false) {
				cout << "\n\n��������������� ������:\n";
				shakerSort(arr);
				printArr2(arr, N);
			}

			int firstID, secondID, changeVar;
			cout << "\n\n������� ������� ���������, ������� �� ������ �������� ������� ����� ������:\n";
			cin >> firstID >> secondID;

			while ((firstID < 0 or firstID > N - 1) or (secondID < 0 or secondID > N - 1) or !isdigit) {
				cout << "\n������� ������ ������ ��������!!!\n";
				firstID = lox2(firstID);
				cout << "\n������� ������ ������ ��������!!!\n";
				secondID = lox2(secondID);
			}

			changeVar = arr[firstID];
			arr[firstID] = arr[secondID];
			arr[secondID] = changeVar;
			cout << "\n";
			printArr2(arr, N);

		} break;

		case 9: {

			if (flag == false) {
				cout << "�������������� ������:\n";
				fullArr2();

				for (int i = 0; i < N; i++) {
					unsortArr[i] = arr[i];
				}

				printArr2(unsortArr, N);
			}

			int leftHalfArr[N / 2], rightHalfArr[N / 2];

			for (int i = 0; i < N / 2; i++) {
				leftHalfArr[i] = unsortArr[i];
			}
			cout << "\n\n������ ������������ ������: \n\n";
			printArr2(leftHalfArr, N / 2);


			for (int i = 0; i < N / 2; i++) {
				rightHalfArr[i] = unsortArr[i + N / 2];
			}
			cout << "\n\n������ ������������ ������: \n\n";
			printArr2(rightHalfArr, N / 2);
			int memory;

			for (int i = 0; i < (N / 2) - 1; i += 2) {
				memory = leftHalfArr[i];
				leftHalfArr[i] = rightHalfArr[i + 1];
				rightHalfArr[i + 1] = memory;
			}

			cout << "\n\n�� �������� �������� �������� ��������� 1-�� ������� � ������� ���������� 2-�� �������. \n\n";

			cout << "\n\n������ ������������ ������: \n\n";
			printArr2(leftHalfArr, N / 2);

			cout << "\n\n������ ������������ ������: \n\n";
			printArr2(rightHalfArr, N / 2);

			for (int i = 0; i < N / 2; i++) {
				if (rightHalfArr[i] % 2 != 0)  rightHalfArr[i] += 1;
			}

			cout << "\n\n������ ������������ ������ ������ ��������� ������!! : \n\n";
			printArr2(rightHalfArr, N / 2);

			int sravnenie = 0;
			for (int i = 0; i < N / 2; i++) {
				if (leftHalfArr[i] > rightHalfArr[i]) sravnenie++;
			}
			cout << "\n\n";
			cout << "�� ������ ������� ���� " << sravnenie << " ���������, ������� ������, ��� � ������ ��� ��� �� ��������.\n\n";
		}break;
		}
	}
	return 0;
}
