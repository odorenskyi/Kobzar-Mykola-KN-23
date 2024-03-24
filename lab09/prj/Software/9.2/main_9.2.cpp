#include <iostream>
#include <cfloat>

using namespace std;
int windSped() {
    system("chcp 1251");
    const int numReadings = 6;
    double windSpeed[numReadings];

    std::cout << "Введіть швидкість вітру (в м/сек) о 00:00, 04:00, 8:00, 12:00, 16:00, 20:00:" << std::endl;
    for (int i = 0; i < numReadings; ++i) {
        std::cout << "Час " << i * 4 << ":00: ";
        std::cin >> windSpeed[i];
    }

    double minWindSpeed = DBL_MAX;
    int minBofort = -1;  // Індикатор для мінімального Бофорта

    const int numRanges = 13;
    const double windSpeedRanges[numRanges][2] = {
        {0.0, 0.5},
        {0.6, 1.5},
        {1.6, 3.3},
        {3.4, 5.4},
        {5.5, 7.9},
        {8.0, 10.7},
        {10.8, 13.8},
        {13.9, 17.1},
        {17.2, 20.7},
        {20.8, 24.4},
        {24.5, 28.4},
        {28.5, 32.6},
        {32.7, DBL_MAX}
    };

    for (int i = 0; i < numReadings; ++i) {
        for (int j = 0; j < numRanges; ++j) {
            if (windSpeed[i] >= windSpeedRanges[j][0] && windSpeed[i] <= windSpeedRanges[j][1]) {
                if (windSpeedRanges[j][0] < minWindSpeed) {
                    minWindSpeed = windSpeedRanges[j][0];
                    minBofort = j;
                }
                break;
            }
        }
    }

    // Виведення результату
    std::cout << "Найменша швидкість вітру протягом доби: " << minWindSpeed << " м/сек" << std::endl;
    std::cout << "Відповідний Бофорт: " << minBofort << std::endl;

    return 0;
}
