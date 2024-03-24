#include <iostream>
#include <bitset>

int countZerosOrOnes(int num, bool countZeros) {
    std::bitset<32> bits(num);

    return countZeros ? bits.count() : (32 - bits.count());
}

int main() {
    system ("chcp 1251");
    int number;
    std::cout << "������ ���������� ����� �� 0 �� 500700: ";
    std::cin >> number;

    if (number < 0 || number > 500700) {
        std::cerr << "���������� �����! ������ ����� �� 0 �� 500700." << std::endl;
        return 1; // ��������� ��� �������
    }

    bool bitD = (number & (1 << 3)) != 0;

    int result = bitD ? countZerosOrOnes(number, true) : countZerosOrOnes(number, false);

    std::cout << "���������: " << result << std::endl;

    return 0;
}

