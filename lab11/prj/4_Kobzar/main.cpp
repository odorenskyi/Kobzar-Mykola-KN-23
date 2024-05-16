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
        cout << "\nМеню:\n";
        cout << "1. Вивести весь реєстр\n";
        cout << "2. Додати новий запис\n";
        cout << "3. Шукати запис\n";
        cout << "4. Видалити запис\n";
        cout << "5. Завершити роботу програми\n";
        cout << "Виберіть дію (1-5): ";
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
            cout << "Збереження реєстру у файл і завершення програми..." << endl;
            saveRegistry("registry.txt");
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 5);
    return 0;
}
