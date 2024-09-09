#include <inputParser.h>
#include <solver.h>
#include <outputParser.h>
#include <iostream>

// фаза тока опережает фазу напряжения
// в синусоидальной фаза тока отстает от напряжения
// если эдс направлена в сторону узла k, то берется со знаком плюс и с минусом иначе

int main(int argc, char* argv[]) {
    float a, b, c, d;
    double accuracy, step;
    if (inputParser::parseInput(argc, argv, &a, &b, &c, &d, &accuracy, &step)) {
        std::vector<int> solution = solver::solveEquation(a, b, c, d, accuracy, step);
        outputParser::showResults(solution);
    } else {
        std::cout << "not valid input" << std::endl;
        return 0;
    }
}