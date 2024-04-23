#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <locale> // ��� ������������ ���������� ���������� �����

using namespace std;

int main() {
    system("chcp 1251");
    cout << "----------------------------------\n"
         << "|          Kobzar Mykola �       |\n"
         << "|����,�������������,������, 2024|\n"
         << "----------------------------------\n";

    time_t rawtime;
    time(&rawtime);
    cout << ctime(&rawtime);

    // ������������ ��������� ������
    setlocale(LC_ALL, "uk_UA.utf8");

    ifstream inputFile("input_1.txt");

    if (!inputFile) {
        cerr << "�� ������� ������� ������� ����.\n";
        return 1;
    }

    string inputText;
    string line;
    while (getline(inputFile, line)) {
        inputText += line + "\n";
    }

    inputFile.close();

    int lowercaseCount = 0;
    int uppercaseCount = 0;

    // ����� � ��������� ���� � �����
    for (char c : inputText) {
        if (iswlower(c)) {
            lowercaseCount++;
        } else if (iswupper(c)) {
            uppercaseCount++;
        }
    }

    cout << "ʳ������ ������� �������� �������: " << lowercaseCount << endl;
    cout << "ʳ������ ������� ��������� �������: " << uppercaseCount << endl;

    string poem = "� ������� ��� ������ ���� ������ ����� �� �����... ��� ���� ������ ������� ��� ������� �������.";
    string wordToCheck = "�����";
    if (poem.find(wordToCheck) != string::npos) {
        cout << "����� '" << wordToCheck << "' � � ����.\n";
    } else {
        cout << "����� '" << wordToCheck << "' �� � � ����.\n";
    }

    return 0;
}
