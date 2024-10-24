#include <iostream>
namespace interface{

enum class Method : int{Iterative = 1,Newton, HalfDivision};

double SearchRootIterativeMethod(double ratio, double accuracy, int& countIterations);
double SearchRootNewtonMethod(double ratio, double accuracy, int& countIterations);
double SearchRootHalfDivisionMethod(double ratio, double accuracy, int& countIterations, double leftPointer, double rightPointer);

void IterationMethod();
void NewtonMethod();
void MethodHalfDivision();

void ChooseSolution();
void TaskStart();
}
