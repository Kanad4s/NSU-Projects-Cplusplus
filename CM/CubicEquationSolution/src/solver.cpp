#include "solver.h"
#include <iostream>
#include <cmath>

std::vector<double> solver::solveEquation(double a, double b, double c, double d, double accuracy, double step) {
    std::vector<double> derivativeRoots;
    std::vector<double> solutions;
    bool isNegative = false;
    discriminantState discriminantState = researchDerivative(a, b, c, derivativeRoots, &isNegative);
    int res = calcRoots(discriminantState, a, b, c, d, accuracy, step, solutions);
    return std::vector<double>();
}

int solver::calcDiscriminant(double a, double b, double c, std::vector<double> roots) {
    return b * b - 4 * a * c;
}

void solver::calcSquareRoots(double a, double b, double discriminant, std::vector<double> roots) {
    roots.push_back((-1 * b + std::sqrt(discriminant)) / (2 * a));
    roots.push_back((-1 * b - std::sqrt(discriminant)) / (2 * a));
}

solver::discriminantState solver::researchDerivative(double a, double b, double c, std::vector<double> derivativeRoots, bool* isNegative) {
    a *= 3;
    b *= 2;
    int discriminant = calcDiscriminant(a, b, c, derivativeRoots);
    if (discriminant > 0) {
        calcSquareRoots(a, b, discriminant, derivativeRoots);
        return discriminantState::positive;
    } else if (discriminant == 0) {
        derivativeRoots.push_back(-1 * b / (2 * a));
        return discriminantState::zero;
    } else if (discriminant < 0) {
        return discriminantState::negative;
    }  
}

int solver::calcRoots(discriminantState discriminantState, double a, double b, double c, double d, double accuracy, double step, std::vector<double> roots) {
    if (discriminantState == discriminantState::negative) {
        double root;
        // функция убывает, т.к. D < 0 и в 3ax^2 + 2bx + c, c < 0.
        if (c < 0) {
            if (d > 0) {
                root = bisectionMethod(0, solver::maxValue, accuracy, step, true);
            } else {
                root = bisectionMethod(solver::minValue, 0, accuracy, step, false);
            }
        // функция возрастает.
        } else if (c > 0) {
            if (d > 0) {
                root = bisectionMethod(solver::minValue, 0, accuracy, step, false);
            } else {
                root = bisectionMethod(0, solver::maxValue, accuracy, step, true);
            }
        } else {
            root = 0;
        }
        roots.push_back(root);
    }
}

double solver::findSegmentLeftBorder(double startPoint, bool rightDirection) {
    double leftBorder = startPoint;
    if (rightDirection) {
        while (leftBorder <= solver::maxValue && calcFunction(leftBorder + solver::STEP) >= 0) {
            leftBorder += solver::STEP;
        }
    } else {
        while (leftBorder >= solver::minValue && calcFunction(leftBorder - solver::STEP) <= 0) {
            leftBorder -= solver::STEP;
        }
        leftBorder -= solver::STEP;
    }
    return leftBorder;
}

double solver::bisectionMethod(double a, double b, double accuracy, double step, bool rightDirection) {
    if (a * b > 0) {
        std::cout << "worng [ " << a << ", " << b << "], sign is same" << std::endl;
        return 0;
    }
    bool isLeftMinus = false;
    if (a < 0) {
        isLeftMinus = true;
    }
    double nextValue = (a + b) / 2;
    while (!isRoot()) {
        if (isRoot()) {

        }
    }
}

bool solver::isRoot(double value, double accuracy) {
    return std::abs(calcFunction(value)) <= accuracy;
}

double solver::calcFunction(double x) {
    return A * x * x * x + B * x * x + C * x + D;
}
