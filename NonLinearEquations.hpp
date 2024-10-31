#pragma once

namespace NonLinearEquations {
enum class EquationMethod : int {
    Iterative = 1,
    Newton,
    HalfDivision,
};

struct rootCalculationResult {
    double root = 0.;
    int countIterations = 0;
    bool solved = true;
};
void ChooseSolution();
void TaskStart();

[[nodiscard]] rootCalculationResult SearchRootIterativeMethod(double ratio, double accuracy);
void IterationMethod();

[[nodiscard]] rootCalculationResult SearchRootNewtonMethod(double ratio, double accuracy);
void NewtonMethod();

[[nodiscard]] rootCalculationResult SearchRootHalfDivisionMethod(double ratio, double accuracy, double leftPointer, double rightPointer);
void MethodHalfDivision();

}  // namespace NonLinearEquations
