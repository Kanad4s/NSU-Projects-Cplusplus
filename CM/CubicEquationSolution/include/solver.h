#ifndef SOLVER
#define SOLVER
#include <vector>

namespace solver{
    std::vector<int> solveEquation(float a, float b, float c, float d, float accuracy);
    int calcDiscriminant(float a, float b, float c);
}

#endif