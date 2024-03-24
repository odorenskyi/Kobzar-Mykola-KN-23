#ifndef MODULESKOBZAR_H
#define MODULESKOBZAR_H

#include <cmath>

namespace ModulesKobzar {
 
    double s_calculate(double x, double y, double z) {
        return sin(x) / sqrt(fabs(y * z / (x + y))) + pow(3 * y, 5);
    }
}

#endif // MODULESKOBZAR_H
