#include <iostream>
using namespace std;

int main1()
{
    system("chcp 1251");
    setlocale(0, "RU");
    int choose = 0, idz = 0, idzChoose = -1;

    cout << "������� ������� �����! :)" << endl;

    cout << "\n������ �� �� ����� ����������� ������������� ��� ���� �� ���������� ���� ���������? \n 1. ��\n 2. ���\n" << endl;
    cout << "��� �����: ";
    cin >> idz;
    cout << "\n";

    while (choose != -1)
    {


        cout << "\n\n\n��������, ��� �� ������ �������, � ������� �����, �������������� ������ �������, �� ���� ����: \n" \
            "1.�������, ������� ������ (� ������) �� ����� ���������� ��������� ��� ��������� ���� ������ �� ��������������� � ���.\n" \
            "2. ������� �� ����� �������� ������������� � ������ (��� �������) ������ �����, ������� �� �������� ����.\n" \
            "3.������� �� ����� �������� ������������� � ������ (��� �������) ������������� (�� 3,4�-38 �� 3,4�+38) �����, ������� �� �������� ����.\n" \
            "4. ������� �� ����� �������� ������������� � ������ (��� �������) ������������� ����� � ���������� ���������\n" \
            "(�� 3, 4� - 38 �� 3, 4� + 38) �����, ������� �� �������� ����.\n" \
            "0. ��������� ������ ���������. \n\n\n";

        cout << "��� �����: ";
        cin >> choose;
        cout << "\n";

        if (choose != 1 and choose != 2 and choose != 3 and choose != 4 and choose != 0)
            cout << "������ ������ � ���� ��� :(\n";

        else
            switch (choose) {

            case 0: {
                cout << "����-����! :(\n\n";
                choose = -1;
            }
                  break;

            case 1: {
                cout << "��� ������ int �������� " << sizeof(int) << " ����(�).\n" \
                    "��� ������ short int �������� " << sizeof(short int) << " ����(�).\n" \
                    "��� ������ long int �������� " << sizeof(long int) << " ����(�).\n" \
                    "��� ������ float �������� " << sizeof(float) << " ����(�).\n" \
                    "��� ������ double �������� " << sizeof(double) << " ����(�).\n" \
                    "��� ������ long double �������� " << sizeof(long double) << " ����(�).\n" \
                    "��� ������ char �������� " << sizeof(char) << " ����(�).\n" \
                    "��� ������ bool �������� " << sizeof(bool) << " ����(�).\n";
                // int, short int, long int, float, double, long double, char � bool
            }
                  break;

            case 2: {
                int num, order;
                unsigned int mask;

                cout << "������� ����� �����: ";
                cin >> num;
                cout << "\n";

                order = sizeof(num) * 8 - 1;
                mask = 1 << order;

                for (int i = 0; i <= order; i++) {
                    cout << ((mask & num) ? 1 : 0);
                    mask >>= 1;

                    if (!i)
                        cout << " ";
                }

                if (idz == 1) {
                    num = ~num;
                    cout << "\n\n������������� ��� ���� �����?\n 1. ��\n 2. ���\n\n";
                    cout << "��� �����: ";
                    cin >> idzChoose;
                    cout << "\n";

                    if (idzChoose == 1) {

                        mask = 1 << order;

                        for (int i = 0; i <= order; i++) {
                            cout << ((mask & num) ? 1 : 0);
                            mask >>= 1;

                            if (!i)
                                cout << " ";
                        }

                    }

                    while (idzChoose == 1) {

                        cout << "\n\n������������� ��� ���� ����� ��� ���?\n 1. ��\n 2. ���\n\n";
                        cout << "��� �����: ";
                        cin >> idzChoose;
                        cout << "\n";

                        if (idzChoose == 1) {

                            num = ~num;
                            mask = 1 << order;

                            for (int i = 0; i <= order; i++) {
                                cout << ((mask & num) ? 1 : 0);
                                mask >>= 1;

                                if (!i)
                                    cout << " ";
                            }

                        }
                    }

                }

            }
                  break;

            case 3: {
                float numF;
                int orderF;
                unsigned int maskF;

                cout << "������� ������������ �����: ";
                cin >> numF;
                cout << "\n";

                orderF = sizeof(numF) * 8 - 1;
                maskF = 1 << orderF;

                union {
                    int intMemory;
                    float floatMemory;
                };

                floatMemory = numF;

                for (int i = 0; i <= orderF; i++) {
                    cout << ((maskF & intMemory) ? 1 : 0);
                    maskF >>= 1;

                    if (!i or i == 8)
                        cout << " ";
                }

                if (idz == 1) {

                    cout << "\n\n������������� ��� ���� �����?\n 1. ��\n 2.���\n\n";
                    cout << "��� �����: ";
                    cin >> idzChoose;
                    cout << "\n";

                    if (idzChoose == 1) {

                        intMemory = ~intMemory;
                        maskF = 1 << orderF;

                        for (int i = 0; i <= orderF; i++) {
                            cout << ((maskF & intMemory) ? 1 : 0);
                            maskF >>= 1;

                            if (!i or i == 8)
                                cout << " ";
                        }

                    }

                    while (idzChoose == 1) {

                        cout << "\n\n������������� ��� ���� ����� ��� ���?\n 1. ��\n 2. ���\n\n";
                        cout << "��� �����: ";
                        cin >> idzChoose;
                        cout << "\n";

                        if (idzChoose == 1) {

                            intMemory = ~intMemory;
                            maskF = 1 << orderF;

                            for (int i = 0; i <= orderF; i++) {
                                cout << ((maskF & intMemory) ? 1 : 0);
                                maskF >>= 1;

                                if (!i or i == 8)
                                    cout << " ";
                            }

                        }
                    }

                }
            }
                  break;

            case 4: {
                double numD;
                int orderD;
                unsigned int maskD;

                cout << "������� ������������ ����� � ���������� ���������: ";
                cin >> numD;
                cout << "\n";

                orderD = sizeof(numD) * 8 - 1;
                maskD = 1 << orderD;

                union {
                    int intMemory[2];
                    double doubleMemory;
                };

                doubleMemory = numD;

                for (int i = 0; i <= (orderD / 2); i++) {
                    cout << ((maskD & intMemory[1]) ? 1 : 0);
                    maskD >>= 1;

                    if (!i or i == 11)
                        cout << " ";
                }

                maskD = 1 << orderD;

                for (int i = 0; i <= (orderD / 2); i++) {
                    cout << ((maskD & intMemory[0]) ? 1 : 0);
                    maskD >>= 1;
                }

                if (idz == 1) {

                    cout << "\n\n������������� ��� ���� �����?\n 1. ��\n 2.���\n\n";
                    cout << "��� �����: ";
                    cin >> idzChoose;
                    cout << "\n";

                    if (idzChoose == 1) {

                        intMemory[0] = ~intMemory[0];
                        intMemory[1] = ~intMemory[1];
                        maskD = 1 << orderD;

                        for (int i = 0; i <= (orderD / 2); i++) {
                            cout << ((maskD & intMemory[1]) ? 1 : 0);
                            maskD >>= 1;

                            if (!i or i == 11)
                                cout << " ";
                        }

                        maskD = 1 << orderD;

                        for (int i = 0; i <= (orderD / 2); i++) {
                            cout << ((maskD & intMemory[0]) ? 1 : 0);
                            maskD >>= 1;
                        }


                    }

                    while (idzChoose == 1) {

                        cout << "\n\n������������� ��� ���� ����� ��� ���?\n 1. ��\n 2. ���\n\n";
                        cout << "��� �����: ";
                        cin >> idzChoose;
                        cout << "\n";

                        if (idzChoose == 1) {

                            intMemory[0] = ~intMemory[0];
                            intMemory[1] = ~intMemory[1];
                            maskD = 1 << orderD;

                            for (int i = 0; i <= (orderD / 2); i++) {
                                cout << ((maskD & intMemory[1]) ? 1 : 0);
                                maskD >>= 1;

                                if (!i or i == 11)
                                    cout << " ";
                            }

                            maskD = 1 << orderD;

                            for (int i = 0; i <= (orderD / 2); i++) {
                                cout << ((maskD & intMemory[0]) ? 1 : 0);
                                maskD >>= 1;
                            }


                        }
                    }

                }
            }
                  break;
            }
    }


    return 0;
}
