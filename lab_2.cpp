#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const int kDividerFirstTask = 5;

const int kInitialData = 2;
const int kAPositiveTask2Begin = 2;
const int kAPositiveZeroТask2End = 8;
const int kANegativeTask2Begin = 3;
const int kANegativeTask2End = 9;
const int kStepCycleANegativeTask2 = 3;
const int kStepAPositiveTask2 = 2;

const double kStepTask3 = 0.2;
const double accuracy = 1e-6;

const int kColumnWidthArgument = 5;
const int kColumnWidthFunctionValue = 10;

const int kN3Task4 = 3;
const int kN5Task4 = 5;
const int kN10Task4 = 10;
}  // namespace

void Task1() {
    double finishForTask{};
    double divider{};
    double sumNaturalNmb = 0;
    std::cout << "Введите натуральные числа n (число до которого будет идти программа) и m (делитель), притом m < n" << std::endl;
    std::cin >> finishForTask >> divider;
    if (finishForTask <= 0 || divider <= 0 || divider > finishForTask) {
        std::cout << "Введены неверные данные" << std::endl;
        return;
    }
    for (int i = kDividerFirstTask; i <= finishForTask; i += kDividerFirstTask) {
        if ((i % kDividerFirstTask == 0) && (fmod(i, divider) != 0)) {
            sumNaturalNmb += i;
        }
    }
    std::cout << sumNaturalNmb << std::endl;
}

void Task2() {
    double product = 1;
    double a{};
    std::cout << "Введите число а, по которому будет посчитан ответ" << std::endl;
    std::cin >> a;
    if (a >= 0.) {
        for (int i = kAPositiveTask2Begin; i <= kAPositiveZeroТask2End; i += kStepAPositiveTask2) {
            product *= i * i;
        }
        product -= a;
    } else {
        for (int i = kANegativeTask2Begin; i <= kANegativeTask2End; i += kStepCycleANegativeTask2) {
            product *= i - kInitialData;
        }
    }
    std::cout << std::fixed << std::setprecision(3);
    std::cout << product << std::endl;
}

double SearchMember(double x, double lastMember, double n) {
    return lastMember * (-x * x / (n + 1));
}

void Task3() {
    double memberSequence = 1;
    double resultY{};

    std::cout << std::fixed << std::setprecision(kColumnWidthArgument);
    std::cout << std::setw(kColumnWidthArgument) << "X" << " " << std::setw(kColumnWidthFunctionValue) << "Y(X)" << " "
              << std::setw(kColumnWidthFunctionValue) << "S(X)" << " " << std::setw(kColumnWidthArgument) << "N" << std::endl;

    double x = 0.;
    while (x <= 1) {
        double n = 0.;
        double lastMember = 1;
        double resultS = lastMember;
        while ((std::abs(memberSequence) >= accuracy)) {
            memberSequence = SearchMember(x, lastMember, n);
            ++n;
            resultS += memberSequence;
            lastMember = memberSequence;
        }
        memberSequence = 1;
        resultY = std::exp(-(x * x));
        std::cout << std::setw(kColumnWidthArgument) << x << " " << std::setw(kColumnWidthFunctionValue) << resultY << " "
                  << std::setw(kColumnWidthFunctionValue) << resultS << " " << std::setw(kColumnWidthArgument) << n + 1 << std::endl;

        x += kStepTask3;
    }
}

void Task4() {
    int n{};
    double x{};
    std::cout << "Введите значение x: ";
    std::cin >> x;
    std::cout << "Введите натуральное значение n: ";
    std::cin >> n;
    if (n > 0) {
        double resultSum = 1.0;
        double term{};
        for (int i = 1; i <= n; ++i) {
            term = pow(-1, i + 1) * pow(x, i + 1) / (i * pow(2, i));
            resultSum -= term;
            if (i == kN3Task4 || i == kN5Task4 || i == kN10Task4) {
                std::cout << "Частичная сумма при " << i << " слагаемых: " << resultSum << std::endl;
            }
        }
        std::cout << "Результат: " << resultSum << std::endl;
    } else {
        std::cout << "Введены неверные данные";
    }
}

int main() {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        char task{};

        std::cout << "                 Вариант 6                 " << std::endl;
        std::cout << "Чтобы запустить первое задание введите - 1" << std::endl;
        std::cout << "Чтобы запустить второе задание введите - 2" << std::endl;
        std::cout << "Чтобы запустить третье задание введите - 3" << std::endl;
        std::cout << "Чтобы запустить четвертое задание введите - 4" << std::endl;
        std::cin >> task;
        switch (task) {
            case '1':
                std::cout << "Task 1" << std::endl;
                Task1();
                break;
            case '2':
                std::cout << "Task 2" << std::endl;
                Task2();
                break;
            case '3':
                std::cout << "Task 3" << std::endl;
                Task3();
                break;
            case '4':
                std::cout << "Task 4" << std::endl;
                Task4();
                break;
            default:
                std::cout << "Ошибка" << std::endl;
                break;
        }
        std::cout << "Введите y, если хотите продолжить и n, если завершить программу" << std::endl;
        std::cin >> continueExecution;
    }
    return 0;
}
