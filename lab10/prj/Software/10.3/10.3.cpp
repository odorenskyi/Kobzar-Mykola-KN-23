#include <iostream>
#include <fstream> // ��� ������ � �������
#include <bitset>
#include "ModulesKobzar.h"

using namespace std; // ������������ �������� ���� std

int main() {
    system("chcp 1251");
    double x, y, z;
    int b;

    // ������� �������� x, y, z �� b � ������
    cout << "������ �������� x: ";
    cin >> x;
    cout << "������ �������� y: ";
    cin >> y;
    cout << "������ �������� z: ";
    cin >> z;
    cout << "������ �������� b: ";
    cin >> b;

    // ��������� ������� s_calculate � ������ ModulesKobzar
    double result = ModulesKobzar::s_calculate(x, y, z);

    // ³�������� ���� "output.txt" ��� ������ ����������
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        // �������� ��������� ��������� � ����
        outputFile << "��������� ���������: " << result << endl;

        // ������������ ����� b � �������� ��� �� �������� ��������� � ����
        outputFile << "����� b � ��������� ���: " << bitset<sizeof(b) * 8>(b) << endl;

        // ��������� ����
        outputFile.close();

        cout << "���������� ���� ������ �������� � ���� 'output.txt'." << endl;
    } else {
        cout << "������� �������� ����� 'output.txt'." << endl;
    }

    return 0;
}
