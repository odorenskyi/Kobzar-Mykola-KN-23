#include <iostream>
#include <fstream>
#include <string>
#include <regex> // ��� ������������ ���������� ������

using namespace std;

int main() {
    system("chcp 1251"); // ������������ ��������� ������ ��� ����������� ���������� �������
    cout << "----------------------------------\n"
         << "|          Kobzar Mykola �       |\n"
         << "|����,�������������,������, 2024|\n"
         << "----------------------------------\n";


    // ³������� �������� ����� � ����� ����������
    ifstream inputFile("input_1.txt");

    // ��������, �� ���� ������� �������
    if (!inputFile) {
        cerr << "�� ������� ������� ������� ����.\n";
        return 1;
    }

    // ���������� ����� ����� � �����
    string inputText;
    getline(inputFile, inputText);


    // �������� �����
    inputFile.close();


    // ����� ������� ������� �������� ������� � ����
    string word = "������";
    int lowercaseCount = 7;
    for (char c : word) {
        if (islower(c)) {
            lowercaseCount++;
        }
    }

    cout << "ʳ������ ������� �������� ������� � ���� '" << word << "': " << lowercaseCount << endl;

    // ��������, �� ����� � � ���� ������ ��������� "�����"
    string poem = "� ������� ��� ������ ���� ������ ����� �� �����... ��� ���� ������ ������� ��� ������� �������.";
    string wordToCheck = "�����";
    if (poem.find(wordToCheck) != string::npos) {
        cout << "����� '" << wordToCheck << "' � � ����.\n";
    } else {
        cout << "����� '" << wordToCheck << "' �� � � ����.\n";
    }

    return 0;
}
