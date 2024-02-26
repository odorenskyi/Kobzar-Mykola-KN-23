#include <cmath> // ϳ�������� �������� cmath ��� ������������ ������������ �������
#include <iostream> // ϳ�������� �������� iostream ��� �����/������
#include <windows.h> // ϳ������ ����

// ������� ��� ���������� ������
double calculateS(double x, double y, double z) {
    // ���������� ����� �� ��������
    double S = (sin(x) / sqrt((y*z) / (x+y))) + 3 * pow(y, 5);
    return S; // ��������� ���������
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //���������� ����������
    double x, y, z; // ��������� ���� x, y, z

    // �������� � ����������� ������ �������� x, y, z
    std::cout << "������ �������� x, y, z: ";
    std::cin >> x >> y >> z;

    // ���������� S �� ��������� ������� calculateS
    double S = calculateS(x, y, z);

    // �������� ���������
    std::cout << "���������: " << S << std::endl;

    return 0; // ��������� ��������
}

