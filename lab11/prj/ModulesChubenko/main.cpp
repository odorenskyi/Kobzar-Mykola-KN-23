#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "ModulesChubenko.h"

using namespace std;

extern std::vector<SubjActivity> registry;
const string defaultFilename = "registry.txt";

void addRecord() {
    // Завантаження реєстру з файлу перед додаванням нового запису
    ifstream fileIn(defaultFilename);
    if (fileIn.is_open()) {
        registry.clear(); // Очищуємо вектор перед завантаженням
        SubjActivity subj;
        while (getline(fileIn, subj.region, ',')) {
            getline(fileIn, subj.name, ',');
            getline(fileIn, subj.manager, ',');
            getline(fileIn, subj.address, ',');
            getline(fileIn, subj.certificate, ',');
            getline(fileIn, subj.activities);
            registry.push_back(subj);
        }
        fileIn.close();
    } else {
        cerr << "Файл не знайдено: " << defaultFilename << endl;
        return;
    }

    // Додавання нового запису до реєстру
    SubjActivity newSubj;
    cout << "Введіть область: ";
    getline(cin, newSubj.region);
    cout << "Введіть назву: ";
    getline(cin, newSubj.name);

    // Переконайтеся, що назва унікальна
    auto it = find_if(registry.begin(), registry.end(), [&](const SubjActivity& s) {
        return s.name == newSubj.name;
    });

    if (it != registry.end()) {
        cout << "Запис з такою назвою вже існує!" << endl;
        return;
    }

    cout << "Введіть керівника: ";
    getline(cin, newSubj.manager);
    cout << "Введіть юридичну адресу: ";
    getline(cin, newSubj.address);
    cout << "Введіть сертифікат: ";
    getline(cin, newSubj.certificate);
    cout << "Введіть напрямки діяльності: ";
    getline(cin, newSubj.activities);

    registry.push_back(newSubj);
    cout << "Запис успішно додано!" << endl;

    // Збереження оновленого реєстру у файл після додавання нового запису
    ofstream fileOut(defaultFilename);
    if (!fileOut.is_open()) {
        cerr << "Помилка при відкритті файлу для запису: " << defaultFilename << endl;
        return;
    }
    // Запис даних у файл
    for (const auto& subj : registry) {
        fileOut << subj.region << ","
               << subj.name << ","
               << subj.manager << ","
               << subj.address << ","
               << subj.certificate << ","
               << subj.activities << "\n";
    }
    fileOut.close();
}


void removeRecord() {
    std::string name;
    std::cout << "Введіть назву юридичної особи для видалення: ";
    std::getline(std::cin, name);

    auto it = std::find_if(registry.begin(), registry.end(), [&](const SubjActivity& subj) {
        return subj.name == name;
    });

    if (it != registry.end()) {
        registry.erase(it);
        std::cout << "Запис успішно видалено!" << std::endl;
        saveRegistry("registry.txt");
    } else {
        std::cout << "Запис не знайдено." << std::endl;
    }
}
