#include "pch.h"
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "../AntonovPractic/MyForm.cpp"

// Название программы: Unit тестирование
// Назначение программы: Проверка корректности выполнения функций
// Автор: Антонов С.С., группа 2091, 2 курс
// Дата создания: 16.02.2024

using namespace System;

// Структура для хранения информации о тесте
struct TestResult {
	std::string testName;
	std::string status;
	std::string comment;
};

// Функция для выполнения и вывода результатов теста
TestResult runTest(bool(*testFunc)(), const std::string& testName) {
    bool result = testFunc();
    TestResult testResult;
    testResult.testName = testName;
    if (result) {
        testResult.status = "passed";
    }
    else {
        testResult.status = "failed";
        testResult.comment = "Поведение не соответствует ожиданию.";
    }
    return testResult;
}

// Функция тестирования quickSort
bool testQuickSort() {
    // Тест с одним элементом
    std::vector<int> singleElementArray = { 1 };
    quickSort(singleElementArray, 0, singleElementArray.size() - 1);
    if (singleElementArray.size() != 1 || singleElementArray[0] != 1) return false;
    // Тест с обратно отсортированным массивом
    std::vector<int> reversedArray = { 5, 4, 3, 2, 1 };
    quickSort(reversedArray, 0, reversedArray.size() - 1);
    for (size_t i = 0; i < reversedArray.size() - 1; ++i) {
        if (reversedArray[i] > reversedArray[i + 1]) {
            return false;
        }
    }
    return true;
}
// Функция тестирования insertionSort
bool testInsertionSort() {
    // Тест с одним элементом
    std::vector<int> singleElementArray = { 1 };
    insertionSort(singleElementArray);
    if (singleElementArray.size() != 1 || singleElementArray[0] != 1) return false;

    // Тест с обратно отсортированным массивом
    std::vector<int> reversedArray = { 5, 4, 3, 2, 1 };
    insertionSort(reversedArray);
    for (size_t i = 0; i < reversedArray.size() - 1; ++i) {
        if (reversedArray[i] > reversedArray[i + 1]) {
            return false;
        }
    }
    return true;
}
// Функция тестирования bubbleSort
bool testBubbleSort() {
    // Тест с одним элементом
    std::vector<int> singleElementArray = { 1 };
    bubbleSort(singleElementArray);
    if (singleElementArray.size() != 1 || singleElementArray[0] != 1) return false;

    // Тест с обратно отсортированным массивом
    std::vector<int> reversedArray = { 5, 4, 3, 2, 1 };
    bubbleSort(reversedArray);
    for (size_t i = 0; i < reversedArray.size() - 1; ++i) {
        if (reversedArray[i] > reversedArray[i + 1]) {
            return false;
        }
    }
    return true;
}

int Testing(cli::array<String^>^ args)
{
    std::vector<TestResult> testResults;
    testResults.push_back(runTest(testQuickSort, "QuickSort Test"));
    testResults.push_back(runTest(testInsertionSort, "InsertionSort Test"));
    testResults.push_back(runTest(testBubbleSort, "BubbleSort Test"));
    // Вывод результатов теста
    for (const auto& result : testResults) {
        std::cout << result.testName << ": " << result.status;
        if (!result.comment.empty()) {
            std::cout << ", комментарий: " << result.comment;
        }
        std::cout << std::endl;
    }
    system("pause");
	return 0;
}