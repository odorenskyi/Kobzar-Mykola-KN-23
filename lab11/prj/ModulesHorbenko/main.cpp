#include "ModulesHorbenko.h"
#include <fstream>
#include <iostream>

std::vector<SubjActivity> registry;

void searchRecord() {
    std::string name;
    std::cout << "Введіть назву юридичної особи для пошуку: ";
    std::getline(std::cin, name);

    auto it = std::find_if(registry.begin(), registry.end(), [&](const SubjActivity& subj) {
        return subj.name == name;
    });

    if (it != registry.end()) {
        std::cout << "Область: " << it->region << std::endl;
        std::cout << "Керівник: " << it->manager << std::endl;
        std::cout << "Юридична адреса: " << it->address << std::endl;
        std::cout << "Сертифікат: " << it->certificate << std::endl;
        std::cout << "Напрямки діяльності: " << it->activities << std::endl;
    }
    else {
        std::cout << "Запис не знайдено." << std::endl;
    }
}

void saveRegistry(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Помилка при відкритті файлу для запису: " << filename << std::endl;
        return;
    }
    for (const auto& subj : registry) {
        file << subj.region << ","
             << subj.name << ","
             << subj.manager << ","
             << subj.address << ","
             << subj.certificate << ","
             << subj.activities << "\n";
    }
    file.close();
}

