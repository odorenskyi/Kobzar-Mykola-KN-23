#include <iostream>
#include <cmath>
#include <Windows.h>

double s_calculate(double x, double y, double z) {
    return sin(x) / sqrt(fabs(y * z / (x + y))) + pow(3 * y, 5);
}

void task_9_1() {
    double electricity_consumed;
    const double tariff_1 = 0.3084; // in UAH per kWh for consumption <= 150 kWh
    const double tariff_2 = 0.4194; // in UAH per kWh for consumption > 150 kWh and <= 800 kWh
    const double tariff_3 = 1.3404; // in UAH per kWh for consumption > 800 kWh

    std::cout << "Enter electricity consumed (kWh): ";
    std::cin >> electricity_consumed;

    double total_cost;
    if (electricity_consumed <= 150)
        total_cost = electricity_consumed * tariff_1;
    else if (electricity_consumed <= 800)
        total_cost = electricity_consumed * tariff_2;
    else
        total_cost = electricity_consumed * tariff_3;

    std::cout << "Total cost: " << total_cost << " UAH" << std::endl;
}
// task_9_2 вводить числа через пробіл не через кому типо: 4 5 7 23
void task_9_2() {
    double wind_speeds[6];
    const std::string beaufort_scale[] = {"Calm", "Light air", "Light breeze", "Gentle breeze", "Moderate breeze", "Fresh breeze", "Strong breeze", "Moderate gale", "Fresh gale", "Strong gale", "Whole gale", "Storm", "Violent storm", "Hurricane"};

    std::cout << "Enter wind speeds (m/s) at 00:00, 04:00, 8:00, 12:00, 16:00, 20:00: ";
    for (int i = 0; i < 6; ++i)
        std::cin >> wind_speeds[i];

    double min_speed = wind_speeds[0];
    for (int i = 1; i < 6; ++i)
        if (wind_speeds[i] < min_speed)
            min_speed = wind_speeds[i];

    int beaufort_index = 0;
    while (min_speed >= 0.3) {
        min_speed -= 1.5;
        beaufort_index++;
    }

    std::cout << "Minimum wind speed: " << beaufort_scale[beaufort_index] << std::endl;
}

void task_9_3() {
    unsigned int number;
    std::cout << "Enter a natural number between 0 and 500700: ";
    std::cin >> number;

    int zero_count = 0, one_count = 0;
    while (number) {
        (number & 1) ? one_count++ : zero_count++;
        number >>= 1;
    }

    std::cout << "Number of zeros: " << zero_count << std::endl;
    std::cout << "Number of ones: " << one_count << std::endl;
}

int main() {
    char choice;
    bool exit_flag = false;

    while (!exit_flag) {
        std::cout << "Enter 'd' for s calculation, 'g' for task 9.1, 'h' for task 9.2, 'j' for task 9.3: ";
        std::cin >> choice;

        switch (choice) {
            case 'd':
                double x, y, z;
                std::cout << "Enter the value for x: ";
                std::cin >> x;
                std::cout << "Enter the value for y: ";
                std::cin >> y;
                std::cout << "Enter the value for z: ";
                std::cin >> z;
                std::cout << "Result: " << s_calculate(x, y, z) << std::endl;
                break;
            case 'g':
                task_9_1();
                break;
            case 'h':
                task_9_2();
                break;
            case 'j':
                task_9_3();
                break;
            case 'k':
            case 'K':
            case 'к':
            case 'К':
                exit_flag = true;
                break;
            default:
                Beep(1000, 500); // Produces a beep sound indicating wrong input
                std::cout << "Invalid input! Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
