#include <iostream>
#include <vector>
#include <cassert>

// Объявления функций сортировки для тестирования
void bubbleSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);
// Другие сортировки...

// Структура для описания результата теста
struct TestResult {
    std::string testName;
    std::string status;
    std::string comment;
};

// Функция для тестирования bubbleSort с пустым массивом
TestResult testBubbleSortEmptyArray() {
    std::vector<int> arr;
    bubbleSort(arr);
    bool passed = arr.empty();
    return { "testBubbleSortEmptyArray", passed ? "passed" : "failed", passed ? "" : "Массив не остался пустым после сортировки" };
}

// Функция для тестирования insertionSort с одним элементом
TestResult testInsertionSortSingleElement() {
    std::vector<int> arr = { 1 };
    insertionSort(arr);
    bool passed = (arr.size() == 1) && (arr[0] == 1);
    return { "testInsertionSortSingleElement", passed ? "passed" : "failed", passed ? "" : "Массив из одного элемента изменился после сортировки" };
}

// Функция для тестирования bubbleSort с обратно отсортированным массивом
TestResult testBubbleSortReversedArray() {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    bubbleSort(arr);
    bool passed = true;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            passed = false;
            break;
        }
    }
    return { "testBubbleSortReversedArray", passed ? "passed" : "failed", passed ? "" : "Массив не был корректно отсортирован" };
}

// Функция для выполнения всех тестов
void runTests() {
    std::vector<TestResult> results = {
        testBubbleSortEmptyArray(),
        testInsertionSortSingleElement(),
        testBubbleSortReversedArray(),
        // Добавьте другие тесты...
    };

    for (const auto& result : results) {
        std::cout << result.testName << ": " << result.status << (result.comment.empty() ? "" : (", комментарий: " + result.comment)) << std::endl;
    }
}

int main() {
    std::cout << "fefefe";
    runTests();
    return 0;
}