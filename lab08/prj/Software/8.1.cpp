#include <cmath> 
#include <iostream> 
#include <windows.h> 


double calculateS(double x, double y, double z) {
    
    double S = (sin(x) / sqrt((y*z) / (x+y))) + 3 * pow(y, 5);
    return S; 
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    double x, y, z; 

    
    std::cout << "Ââåä³òü çíà÷åííÿ x, y, z: ";
    std::cin >> x >> y >> z;

    
    double S = calculateS(x, y, z);

    
    std::cout << "Ðåçóëüòàò: " << S << std::endl;

    return 0; 
}

