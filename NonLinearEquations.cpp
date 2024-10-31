#include "NonLinearEquations.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const int kMaxIterations = 1e5;

struct ReadInput {
    double ratio = 0.;
    double acccuacy = 0.;
};

[[nodiscard]] ReadInput InputCofficientAccuracy() {
    double ratio = 0.;
    double accuracy = 0.;

    std::cout << "Введите коэффициент A для уравнения x - A * cos(x) = 0: " << std::endl;
    std::cin >> ratio;
    std::cout << std::endl;
    std::cout << "Введите погрешность(D вормате 1e-n): " << std::endl;
    std::cin >> accuracy;
    std::cout << std::endl;
    return {ratio, accuracy};
}

void PrintResult(double accuracy, double root, int countIterations, bool solved) {
    if (solved) {
        int outputAcc = -static_cast<int>(std::ceil(std::log10(accuracy)));
        std::cout << "X = " << std::setw(outputAcc) << std::setprecision(outputAcc) << std::fixed << root << " - корень уравнения" << std::endl;
        std::cout << "Количество итераций:" << countIterations << std::endl;
    } else {
        std::cout << "Корней не найдено" << std::endl;
    }
}

[[nodiscard]] double CalculateFunction(double root, double ratio) {
    return root - ratio * std::cos(root);
}

[[nodiscard]] double CalculateDerrivative(double root, double ratio) {
    return 1 + ratio * std::sin(root);
}

[[nodiscard]] bool CheckRootSign(double root) {
    if (root >= 0.) {
        return true;
    } else {
        return false;
    }
}
}  // namespace

int TextMenu() {
    std::cout << "Выберите способ решения уранения x - A * cos(x) = 0:" << std::endl;
    std::cout << "1 - Способ методом итераций" << std::endl;
    std::cout << "2 - Методом Ньютона" << std::endl;
    std::cout << "3 - Методом половинного деления" << std::endl;
    int task{};
    std::cin >> task;
    return task;
}

namespace NonLinearEquations {
void ChooseSolution() {
    int task{};
    task = TextMenu();
    switch (static_cast<EquationMethod>(task)) {
        case EquationMethod::Iterative:
            IterationMethod();
            break;
        case EquationMethod::Newton:
            NewtonMethod();
            break;
        case EquationMethod::HalfDivision:
            MethodHalfDivision();
            break;
    }
}

void TaskStart() {
    char continueExecution = 'y';

    while (continueExecution == 'y') {
        ChooseSolution();
        std::cout << "Введите 'y', если хотите продолжить работу, и 'n', если нет" << std::endl;  // func()
        std::cin >> continueExecution;
    }
}

rootCalculationResult SearchRootIterativeMethod(double ratio, double accuracy) {
    double previousRoot = 0.;
    double currentRoot = ratio * std::cos(previousRoot);
    int countIterations = 0;
    ++countIterations;
    bool solved = true;

    while (std::fabs(currentRoot - previousRoot) > accuracy && countIterations < kMaxIterations) {
        previousRoot = currentRoot;
        currentRoot = ratio * std::cos(previousRoot);
        ++countIterations;
    }

    if (CalculateFunction(currentRoot, ratio) > accuracy && kMaxIterations == countIterations) {
        return {.solved = false};
    }
    return {currentRoot, countIterations, solved};
}

void IterationMethod() {
    auto [ratio, accuracy] = InputCofficientAccuracy();
    auto [root, countIterations, solved] = SearchRootIterativeMethod(ratio, accuracy);
    PrintResult(accuracy, root, countIterations, solved);
}

rootCalculationResult SearchRootNewtonMethod(double ratio, double accuracy) {
    int countIterations = 0;
    double previousX = 0.;
    bool solved = true;

    previousX = CalculateFunction(previousX, ratio) / CalculateDerrivative(previousX, ratio);
    ++countIterations;

    while (std::fabs(CalculateFunction(previousX, ratio)) > accuracy && countIterations < kMaxIterations) {
        double derrivative = CalculateDerrivative(previousX, ratio);
        if (derrivative == 0.) {
            break;
        }
        ++countIterations;
        previousX -= CalculateFunction(previousX, ratio) / derrivative;
    }
    if (CalculateFunction(previousX, ratio) > accuracy && kMaxIterations == countIterations) {
        return {.solved = false};
    }
    return {previousX, countIterations, solved};
}

void NewtonMethod() {
    auto [ratio, accuracy] = InputCofficientAccuracy();
    auto [root, countIterations, solved] = SearchRootNewtonMethod(ratio, accuracy);
    PrintResult(accuracy, root, countIterations, solved);
}

rootCalculationResult SearchRootHalfDivisionMethod(double ratio, double accuracy, double leftBoundary, double rightBoundary) {
    if (leftBoundary >= rightBoundary) {
        return {.solved = false};
    }
    int countIterations = 0;
    double middle = 0.;
    bool solved = true;
    while (rightBoundary - leftBoundary > accuracy && countIterations < kMaxIterations) {
        middle = (leftBoundary + rightBoundary) / 2;
        if (CheckRootSign(CalculateFunction(middle, ratio)) == CheckRootSign(CalculateFunction(rightBoundary, ratio))) {
            rightBoundary = middle;
        } else {
            leftBoundary = middle;
        }
        ++countIterations;
    }
    return {((leftBoundary + rightBoundary) / 2), countIterations, solved};
}

void OutputHalfMetod(double ratio, double accuracy) {
    double leftBoundary = 0.;
    double rightBoundary = 0.;
    std::cout << "Введите лувую и правую границу поиска корня(пример: 1 5)" << std::endl;
    std::cin >> leftBoundary >> rightBoundary;
    if (leftBoundary >= rightBoundary) {
        std::cout << "Введены некорректные значения" << std::endl;
        return;
    }
    auto [root, countIterations, solved] = SearchRootHalfDivisionMethod(ratio, accuracy, leftBoundary, rightBoundary);
    PrintResult(accuracy, root, countIterations, solved);
}

void MethodHalfDivision() {
    auto [ratio, accuracy] = InputCofficientAccuracy();
    OutputHalfMetod(ratio, accuracy);
}
}  // namespace NonLinearEquations
