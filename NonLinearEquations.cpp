#include "NonLinearEquations.hpp"
#include <cmath>
#include <iostream>

void interface::ChooseSolution() {
    int task{};

    std::cout << "Выберите способ решения уранения x - A * cos(x) = 0:" << std::endl;
    std::cout << "1 - Способ методом итераций" << std::endl;
    std::cout << "2 - Методом Ньютона" << std::endl;
    std::cout << "3 - Методом половинного деления" << std::endl;
    std::cin >> task;

    switch (static_cast<interface::Method>(task)){
        case interface::Method::Iterative:
            IterationMethod();
            break;
        case interface::Method::Newton:
            NewtonMethod();
            break;
        case interface::Method::HalfDivision:
            MethodHalfDivision();
            break;
    }
}

void interface::TaskStart() {
    char continueExecution = 'y';

    while (continueExecution == 'y') {
        ChooseSolution();
        std::cout << "Введите 'y', если хотите продолжить работу, и 'n', если нет" << std::endl;
        std::cin >> continueExecution;
    }
}

[[nodiscard]] double interface::SearchRootIterativeMethod(double ratio, double accuracy, int& countIterations) {
    double previousRoot = 0.;
    double currentRoot = ratio * std::cos(previousRoot);
    ++countIterations;
    int maxIterations = 1e5;

    while (std::fabs(currentRoot - previousRoot) > accuracy && countIterations < maxIterations) {
        previousRoot = currentRoot;
        currentRoot = ratio * std::cos(previousRoot);
        ++countIterations;
    }

    return currentRoot;
}

void interface::IterationMethod() {
    double ratio = 0.;
    double accuracy = 1e-6;
    double root = 0.;
    int countIterations = 0;

    std::cout << "Введите коэффициент А при cos(x)" << std::endl;
    std::cin >> ratio;
    std::cout << std::endl;
    std::cout << "Введите погрешность:" << std::endl;
    std::cin >> accuracy;
    std::cout << std::endl;

    root = SearchRootIterativeMethod(ratio, accuracy, countIterations);

    std::cout << "X = " << root << " - корень уравнения" << std::endl;
    std::cout << "В котором " << countIterations << " итераций" << std::endl;
    std::cout << std::endl;
}

[[nodiscard]] double CalculateFunction(double ratio, double root) {
    return root - ratio * cos(root);
}
[[nodiscard]] double CalculateDerrivative(double ratio, double root) {
    return 1 + ratio * sin(root);
}

[[nodiscard]] double interface::SearchRootNewtonMethod(double ratio, double accuracy, int& countIterations) {
    double xPrevious{};
    double root = 0.;
    int kMaxIterations = 1e5;
    while (std::fabs(root - xPrevious) > accuracy && countIterations < kMaxIterations) {
        ++countIterations;
        xPrevious = root;
        root -= CalculateFunction(ratio, root) / CalculateDerrivative(ratio, root);
    }

    if (std::fabs(CalculateFunction(ratio, root)) > accuracy) {
        root = NAN;
    }

    return root;
}

void interface::NewtonMethod() {
    double a = 0.;
    double accuracy = 0.;
    double root = 0.;
    int countIterations = 0;

    std::cout << "Введите коэффициент А при cos(x)" << std::endl;
    std::cin >> a;
    std::cout << std::endl;
    std::cout << "Введите погрешность:" << std::endl;
    std::cin >> accuracy;
    std::cout << std::endl;

    root = SearchRootIterativeMethod(a, accuracy, countIterations);

    std::cout << "X = " << root << " - корень уравнения" << std::endl;
    std::cout << "В котором " << countIterations << " итераций" << std::endl;
    std::cout << std::endl;
}

[[nodiscard]] double interface::SearchRootHalfDivisionMethod(double ratio, double accuracy, int& countIterations, double leftPointer,
                                                             double rightPointer) {
    double middle = 0.;
    if (((leftPointer - ratio * std::cos(leftPointer) > 0) && (rightPointer - ratio * std::cos(rightPointer) > 0)) ||
        ((leftPointer - ratio * std::cos(leftPointer) < 0) && (rightPointer - ratio * std::cos(rightPointer) < 0))) {
        std::cout << "На заданном интервале функция не меняет знак. Метод половинного деления не применим." << std::endl;
    } else {
        while (fabs(rightPointer - leftPointer) > accuracy) {
            middle = (leftPointer + rightPointer) / 2;
            if (middle - ratio * std::cos(middle) > 0) {
                rightPointer = middle;
            } else {
                leftPointer = middle;
            }
            countIterations++;
        }
    }
    return middle;
}

void interface::MethodHalfDivision() {
    double ratio = 0.;
    double accuracy = 0.;
    double root = 0.;
    int countIterations = 0;
    double rightPointer;
    double leftPointer;

    std::cout << "Введите коэффициент А при cos(x)" << std::endl;
    std::cin >> ratio;

    std::cout << "Введите левую и првую границу через пробел(Пример: -4 4)" << std::endl;
    std::cin >> leftPointer >> rightPointer;
    std::cout << std::endl;

    std::cout << "Введите погрешность:" << std::endl;
    std::cin >> accuracy;
    std::cout << std::endl;

    root = SearchRootHalfDivisionMethod(ratio, accuracy, countIterations, leftPointer, rightPointer);

    std::cout << "X = " << root << " - корень уравнения" << std::endl;
    std::cout << "В котором " << countIterations << " итераций" << std::endl;
    std::cout << std::endl;
}
