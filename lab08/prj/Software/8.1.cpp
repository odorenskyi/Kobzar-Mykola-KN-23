#include <math.h>
#include <stdio.h>
#include <windows.h>

double s_calculate(double x, double y, double z) {
    return sin(x) / sqrt(fabs(y * z / (x + y))) + pow(3 * y, 5);
}

int main() {
    double x, y, z;

    printf("Enter the value for x: ");
    scanf("%lf", &x);

    printf("Enter the value for y: ");
    scanf("%lf", &y);

    printf("Enter the value for z: ");
    scanf("%lf", &z);

    double S = s_calculate(x, y, z);
    printf("Result: %f\n", S);

    return 0;
}
