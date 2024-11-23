#include "sortingMethods.hpp"

#include <iostream>
#include <random>
namespace {
const int kStaticArrSize = 10;

void PrintArray(int* array, std::size_t len, int permutations, int comparisons) {
    for (std::size_t i = 0; i < len; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "Кол-во перестановок: " << permutations << " Кол-во сравнений: " << comparisons << std::endl;
}

void CopyArray(int* source, int* destination, int size) {
    for (int i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}

void RandomElm(int* array, std::size_t size) {
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution distribution(0, 99);
    for (std::size_t i = 0; i < size; ++i) {
        array[i] = distribution(randomEngine);
    }
}
}  // namespace

namespace sortingMethods {
void ExecuteApp() {
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        SelectMethod();
        std::cout << "Продолжить выполнение программы [y/n]?" << std::endl;
        std::cin >> continueExecution;
    }
}

void SelectMethod() {
    int method = 0;
    std::cout << "Выберите вектор?\n"
              << "1 - Статический массив\n"
              << "2 - Динамический массив" << std::endl;

    std::cin >> method;

    switch (static_cast<Method>(method)) {
        case Method::sortingByChoice:
            std::cout << "Статический массив:" << std::endl;
            CreateStaticArr();
            break;
        case Method::bubbleSorting:
            std::cout << "Динамический массив:" << std::endl;
            CreateDynamicArr();
            break;
        default:
            std::cout << "Неверный ввод" << std::endl;
            break;
    }
}

void ExecuteSelectionSort(int* array, std::size_t arraySize, int& permutations, int& comparisons, bool ascending) {
    if (!array) {
        return;
    }

    permutations = 0;
    comparisons = 0;

    int selectionElement = 0;
    std::size_t selectionIndex = 0;

    for (std::size_t i = 0; i < arraySize - 1; ++i) {
        selectionElement = array[i];
        selectionIndex = i;

        for (std::size_t j = i + 1; j < arraySize; ++j) {
            if ((ascending) ? array[j] < selectionElement : array[j] > selectionElement) {
                selectionElement = array[j];
                selectionIndex = j;
            }

            ++comparisons;
        }

        if (i != selectionIndex) {
            std::swap(array[i], array[selectionIndex]);
            ++permutations;
        }
    }
}

void CreateStaticArr() {
    int StaticMinMaxArray[kStaticArrSize] = {};
    RandomElm(StaticMinMaxArray, kStaticArrSize);
    std::cout << std::endl;
    int StaticBubbleArray[kStaticArrSize] = {};
    CopyArray(StaticMinMaxArray, StaticBubbleArray, kStaticArrSize);
    Static(StaticMinMaxArray, StaticBubbleArray);
}

void CreateDynamicArr() {
    std::size_t size{};
    std::cout << "Введите длинну массива" << std::endl;
    std::cin >> size;
    std::cout << std::endl;
    int* DinamicMinMaxArray = new int[size];
    RandomElm(DinamicMinMaxArray, size);
    int* DinamicBubbleArray = new int[size]{};
    CopyArray(DinamicMinMaxArray, DinamicBubbleArray, size);
    Dinamic(DinamicMinMaxArray, DinamicBubbleArray, size);
    delete[] DinamicMinMaxArray;
    delete[] DinamicBubbleArray;
}
void Static(int* StaticMinMaxArray, int* StaticBubbleArray) {
    int permutations = 0;
    int comparisons = 0;
    for (std::size_t i = 0; i < 6; ++i) {
        bool ascending = true;
        if (i == 2 || i == 5) {
            ascending = false;
        }
        (i < 3) ? (ExecuteSelectionSort(StaticMinMaxArray, kStaticArrSize, permutations, comparisons, ascending),
                   std::cout << "Сортировка MIN/MAX: ", PrintArray(StaticMinMaxArray, kStaticArrSize, permutations, comparisons))
                : (ExecuteBubleSort(StaticBubbleArray, kStaticArrSize, permutations, comparisons, ascending),
                   std::cout << "Сортировка пузырьком: ", PrintArray(StaticBubbleArray, kStaticArrSize, permutations, comparisons));
    }
}

void ExecuteBubleSort(int* array, std::size_t arraySize, int& permutations, int& comparisons, bool ascending) {
    if (!array) {
        return;
    }

    permutations = 0;
    comparisons = 0;

    bool sorted = false;

    for (std::size_t i = 0; i < arraySize - 1 && !sorted; ++i) {
        sorted = true;

        for (std::size_t j = 0; j < arraySize - i - 1; ++j) {
            if ((ascending) ? array[j + 1] < array[j] : array[j + 1] > array[j]) {
                sorted = false;
                std::swap(array[j], array[j + 1]);
                ++permutations;
            }

            ++comparisons;
        }
    }
}

void Dinamic(int* DinamicMinMaxArray, int* DinamicBubbleArray, std::size_t len) {
    int permutations = 0;
    int comparisons = 0;
    bool ascending = true;
    ExecuteSelectionSort(DinamicMinMaxArray, len, permutations, comparisons, ascending);
    std::cout << "Сортировка MIN/MAX: ";
    PrintArray(DinamicMinMaxArray, len, permutations, comparisons);
    ExecuteBubleSort(DinamicBubbleArray, len, permutations, comparisons, ascending);
    std::cout << "Сортировка пузырьком: ";
    PrintArray(DinamicBubbleArray, len, permutations, comparisons);
}  //
}  // namespace sortingMethods
