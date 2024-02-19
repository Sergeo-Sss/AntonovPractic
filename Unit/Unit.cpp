#include "pch.h"
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "../AntonovPractic/MyForm.cpp"

// �������� ���������: Unit ������������
// ���������� ���������: �������� ������������ ���������� �������
// �����: ������� �.�., ������ 2091, 2 ����
// ���� ��������: 16.02.2024

using namespace System;

// ��������� ��� �������� ���������� � �����
struct TestResult {
	std::string testName;
	std::string status;
	std::string comment;
};

// ������� ��� ���������� � ������ ����������� �����
TestResult runTest(bool(*testFunc)(), const std::string& testName) {
    bool result = testFunc();
    TestResult testResult;
    testResult.testName = testName;
    if (result) {
        testResult.status = "passed";
    }
    else {
        testResult.status = "failed";
        testResult.comment = "��������� �� ������������� ��������.";
    }
    return testResult;
}

// ������� ������������ quickSort
bool testQuickSort() {
    // ���� � ����� ���������
    std::vector<int> singleElementArray = { 1 };
    quickSort(singleElementArray, 0, singleElementArray.size() - 1);
    if (singleElementArray.size() != 1 || singleElementArray[0] != 1) return false;
    // ���� � ������� ��������������� ��������
    std::vector<int> reversedArray = { 5, 4, 3, 2, 1 };
    quickSort(reversedArray, 0, reversedArray.size() - 1);
    for (size_t i = 0; i < reversedArray.size() - 1; ++i) {
        if (reversedArray[i] > reversedArray[i + 1]) {
            return false;
        }
    }
    return true;
}
// ������� ������������ insertionSort
bool testInsertionSort() {
    // ���� � ����� ���������
    std::vector<int> singleElementArray = { 1 };
    insertionSort(singleElementArray);
    if (singleElementArray.size() != 1 || singleElementArray[0] != 1) return false;

    // ���� � ������� ��������������� ��������
    std::vector<int> reversedArray = { 5, 4, 3, 2, 1 };
    insertionSort(reversedArray);
    for (size_t i = 0; i < reversedArray.size() - 1; ++i) {
        if (reversedArray[i] > reversedArray[i + 1]) {
            return false;
        }
    }
    return true;
}
// ������� ������������ bubbleSort
bool testBubbleSort() {
    // ���� � ����� ���������
    std::vector<int> singleElementArray = { 1 };
    bubbleSort(singleElementArray);
    if (singleElementArray.size() != 1 || singleElementArray[0] != 1) return false;

    // ���� � ������� ��������������� ��������
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
    // ����� ����������� �����
    for (const auto& result : testResults) {
        std::cout << result.testName << ": " << result.status;
        if (!result.comment.empty()) {
            std::cout << ", �����������: " << result.comment;
        }
        std::cout << std::endl;
    }
    system("pause");
	return 0;
}