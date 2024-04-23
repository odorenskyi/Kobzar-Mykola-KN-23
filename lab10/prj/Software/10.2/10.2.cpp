#include <iostream>
#include <fstream>
#include <ctime>
#include <locale>
#include <cctype>

using namespace std;

// ������� ��� ���� ������� �������
string reverseCase(const string& str) {
    string result;
    for (char c : str) {
        if (isupper(c))
            result += tolower(c);
        else if (islower(c))
            result += toupper(c);
        else
            result += c;
    }
    return result;
}

int main() {
    system("chcp 1251");
    cout << "----------------------------------\n"
         << "|          Kobzar Mykola �       |\n"
         << "|����,�������������,������, 2024|\n"
         << "----------------------------------\n";

    // ��������� ��������� ����
    time_t rawtime;
    time(&rawtime);

    // ��������� ��������� ����
    cout << ctime(&rawtime);

    // ������� �������� �����
    ifstream input("input_2.txt");
    if (!input.is_open()) {
        cerr << "������� �������� �����!" << endl;
        return 1;
    }

    // ����� �� ����� ����� "Chandelier"
    string word;
    while (input >> word) {
        if (word == "Chandelier") {
            int upperCount = 0, lowerCount = 0;
            for (char c : word) {
                if (isupper(c))
                    upperCount++;
                else if (islower(c))
                    lowerCount++;
            }
            // ��������� ���������� � �������
            cout << "�����: " << word << endl;
            cout << "ʳ������ ������� ��������� �������: " << upperCount << endl;
            cout << "ʳ������ ������� �������� �������: " << lowerCount << endl;

            // ������������ ������� � ��������� ����������
            string reversedWord = reverseCase(word);
            cout << "����� � ������� ��������: " << reversedWord << endl;
            int reversedUpperCount = 0, reversedLowerCount = 0;
            for (char c : reversedWord) {
                if (isupper(c))
                    reversedUpperCount++;
                else if (islower(c))
                    reversedLowerCount++;
            }
            cout << "ʳ������ ������� ��������� ������� ���� ����: " << reversedUpperCount << endl;
            cout << "ʳ������ ������� �������� ������� ���� ����: " << reversedLowerCount << endl;
            break; // ���� ����� ��������, ����� ��������� ������� �����
        }
    }

    // �������� �����
    input.close();

    return 0;
}
