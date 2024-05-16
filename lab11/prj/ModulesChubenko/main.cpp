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
    // ������������ ������ � ����� ����� ���������� ������ ������
    ifstream fileIn(defaultFilename);
    if (fileIn.is_open()) {
        registry.clear(); // ������� ������ ����� �������������
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
        cerr << "���� �� ��������: " << defaultFilename << endl;
        return;
    }

    // ��������� ������ ������ �� ������
    SubjActivity newSubj;
    cout << "������ �������: ";
    getline(cin, newSubj.region);
    cout << "������ �����: ";
    getline(cin, newSubj.name);

    // �������������, �� ����� ��������
    auto it = find_if(registry.begin(), registry.end(), [&](const SubjActivity& s) {
        return s.name == newSubj.name;
    });

    if (it != registry.end()) {
        cout << "����� � ����� ������ ��� ����!" << endl;
        return;
    }

    cout << "������ ��������: ";
    getline(cin, newSubj.manager);
    cout << "������ �������� ������: ";
    getline(cin, newSubj.address);
    cout << "������ ����������: ";
    getline(cin, newSubj.certificate);
    cout << "������ �������� ��������: ";
    getline(cin, newSubj.activities);

    registry.push_back(newSubj);
    cout << "����� ������ ������!" << endl;

    // ���������� ���������� ������ � ���� ���� ��������� ������ ������
    ofstream fileOut(defaultFilename);
    if (!fileOut.is_open()) {
        cerr << "������� ��� ������� ����� ��� ������: " << defaultFilename << endl;
        return;
    }
    // ����� ����� � ����
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
    std::cout << "������ ����� �������� ����� ��� ���������: ";
    std::getline(std::cin, name);

    auto it = std::find_if(registry.begin(), registry.end(), [&](const SubjActivity& subj) {
        return subj.name == name;
    });

    if (it != registry.end()) {
        registry.erase(it);
        std::cout << "����� ������ ��������!" << std::endl;
        saveRegistry("registry.txt");
    } else {
        std::cout << "����� �� ��������." << std::endl;
    }
}
