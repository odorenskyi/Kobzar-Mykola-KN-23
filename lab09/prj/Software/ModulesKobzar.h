#ifndef S_CALCULATOR_H
#define S_CALCULATOR_H

class SCalculator {
public:
    static double calculate(double x, double y, double z);
};

#endif //

#include <bitset>

// ������� ��� ��������� ������� �������� ���� ��� ������� � ����
int countZerosOrOnes(int num, bool countZeros) {
    std::bitset<32> bits(num); // ������������ ����� � ������� ������

    // ������������� ��������� �������� ��� ��������� ���� ��� �������
    return countZeros ? bits.count() : (32 - bits.count());
}


