#pragma once

#include <iostream>

namespace sortingMethods {
enum class Method : int {
    sortingByChoice = 1,
    bubbleSorting
};

void ExecuteApp();
void SelectMethod();

void CreateStaticArr();
void CreateDynamicArr();

void ExecuteSelectionSort(int*, std::size_t, int&, int&, bool);
void ExecuteBubleSort(int*, std::size_t, int&, int&, bool);

void Dinamic(int*, int*, std::size_t);
void Static(int*, int*);

}  // namespace sortingMethods
