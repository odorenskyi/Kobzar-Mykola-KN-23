#include <iostream>
#include "ModulesHorbenko.h"
#include "ModulesKobzar.h"
#include "ModulesChubenko.h"

using namespace std;

extern std::vector<SubjActivity> registry;

int main()
{
    system("chcp 1251");

    int choice;
    do {
        cout << "\n����:\n";
        cout << "1. ������� ���� �����\n";
        cout << "2. ������ ����� �����\n";
        cout << "3. ������ �����\n";
        cout << "4. �������� �����\n";
        cout << "5. ��������� ������ ��������\n";
        cout << "������� �� (1-5): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            displayRegistry("registry.txt");
            break;
        case 2:
            addRecord();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            removeRecord();
            break;
        case 5:
            cout << "���������� ������ � ���� � ���������� ��������..." << endl;
            saveRegistry("registry.txt");
            break;
        default:
            cout << "������� ����. ��������� �� ���." << endl;
        }
    } while (choice != 5);
    return 0;
}
