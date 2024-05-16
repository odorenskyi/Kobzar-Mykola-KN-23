#include "ModulesHorbenko.h"
#include <fstream>
#include <iostream>

std::vector<SubjActivity> registry;

void searchRecord() {
    std::string name;
    std::cout << "������ ����� �������� ����� ��� ������: ";
    std::getline(std::cin, name);

    auto it = std::find_if(registry.begin(), registry.end(), [&](const SubjActivity& subj) {
        return subj.name == name;
    });

    if (it != registry.end()) {
        std::cout << "�������: " << it->region << std::endl;
        std::cout << "�������: " << it->manager << std::endl;
        std::cout << "�������� ������: " << it->address << std::endl;
        std::cout << "����������: " << it->certificate << std::endl;
        std::cout << "�������� ��������: " << it->activities << std::endl;
    }
    else {
        std::cout << "����� �� ��������." << std::endl;
    }
}

void saveRegistry(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "������� ��� ������� ����� ��� ������: " << filename << std::endl;
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

