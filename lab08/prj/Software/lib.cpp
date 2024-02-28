#include "ModulesKobzar.h"
#include <cmath>

double SCalculator::calculate(double x, double y, double z) {
    return sin(x) / sqrt(fabs(y * z / (x + y))) + pow(3 * y, 5);
}
