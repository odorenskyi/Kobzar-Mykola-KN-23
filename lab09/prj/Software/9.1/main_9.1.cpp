#include <iostream>

double calculateElectricityBill(double kWh) {
    double totalCost = 0.0;

    if (kWh <= 150) {
        totalCost = kWh * 0.3084;
    } else if (kWh <= 800) {
        totalCost = 150 * 0.3084 + (kWh - 150) * 0.4194;
    } else {
        totalCost = 150 * 0.3084 + 650 * 0.4194 + (kWh - 800) * 1.3404;
    }

    return totalCost;
}

int main() {
    double kWh;

    std::cout << "Enter the amount of electricity consumed in kWh: ";
    std::cin >> kWh;

    if (kWh < 0) {
        std::cerr << "Invalid input. kWh cannot be negative." << std::endl;
        return 1;
    }

    double billAmount = calculateElectricityBill(kWh);

    std::cout << "Total amount to pay: " << billAmount << " UAH" << std::endl;

    return 0;
}
