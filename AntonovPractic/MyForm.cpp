#include "MyForm.h"

// Название программы: Система демонстрации сортировок
// Назначение программы: Демонстрация работы различных алгоритмов сортировки с возможностью визуализации результатов
// Автор: Антонов С.С., группа 2091, 2 курс
// Дата создания: 16.02.2024

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    AntonovPractic::MyForm form;
    Application::Run(%form);
}
// Сортировки
void quickSort(std::vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
void insertionSort(std::vector<int>& arr) {
    int i, key, j;
    for (i = 1; i < arr.size(); i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void bubbleSort(std::vector<int>& arr) {
    int i, j;
    bool swapped;
    for (i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}
void cocktailShakerSort(std::vector<int>& arr) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}
void countSort(std::vector<int>& arr, int exp) {
    std::vector<int> output(arr.size());
    int i, count[10] = { 0 };

    for (i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}
void radixSort(std::vector<int>& arr) {
    int m = *max_element(arr.begin(), arr.end());

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

void AntonovPractic::MyForm::sortButton_Click(System::Object^ sender, System::EventArgs^ e) {
    // Проверка выбора сортировки
    if (sortTypeComboBox->SelectedItem == nullptr) {
        MessageBox::Show("Пожалуйста, выберите метод сортировки.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Проверка ввода массива
    String^ input = this->inputTextBox->Text->Trim();
    if (String::IsNullOrWhiteSpace(input)) {
        MessageBox::Show("Пожалуйста, введите массив чисел или символов для сортировки.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Попытка определить, является ли ввод числами или символами
    bool isNumericInput = true; // Предполагаем, что ввод - числа
    cli::array<Char>^ separators = gcnew cli::array<Char>{',', ' '};
    cli::array<String^>^ strNumbers = input->Split(separators, StringSplitOptions::RemoveEmptyEntries);
    System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("^[0-9]+$");

    for each (String ^ str in strNumbers) {
        if (!regex->IsMatch(str->Trim())) {
            isNumericInput = false;
            break;
        }
    }

    std::vector<int> values; // Используем для хранения ASCII значений символов или чисел
    if (isNumericInput) {
        // Преобразование чисел
        for each (String ^ str in strNumbers) {
            values.push_back(Convert::ToInt32(str->Trim()));
        }
    }
    else {
        // Преобразование символов в ASCII значения
        for each (Char c in input) {
            if (c != ',' && !Char::IsWhiteSpace(c)) // Пропускаем запятые и пробелы
                values.push_back(static_cast<int>(c));
        }
    }

    // Замер времени и выбор сортировки
    auto start = std::chrono::high_resolution_clock::now();
    if (sortTypeComboBox->SelectedItem->ToString() == "Быстрая") {
        quickSort(values, 0, values.size() - 1);
    }
    else if (sortTypeComboBox->SelectedItem->ToString() == "Вставками") {
        insertionSort(values);
    }
    else if (sortTypeComboBox->SelectedItem->ToString() == "Пузырьковая") {
        bubbleSort(values);
    }
    else if (sortTypeComboBox->SelectedItem->ToString() == "Шейкер") {
        cocktailShakerSort(values);
    }
    else if (sortTypeComboBox->SelectedItem->ToString() == "Поразрядная") {
        radixSort(values);
    }
    else {
        MessageBox::Show("Выбранный метод сортировки не поддерживается.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    this->timeLabel->Text = "Время выполнения: " + elapsed.count().ToString() + " сек.";

    // Вывод отсортированного массива
    System::String^ output = "";
    if (isNumericInput) {
        for (size_t i = 0; i < values.size(); i++) {
            output += values[i].ToString() + (i < values.size() - 1 ? ", " : "");
        }
    }
    else {
        for (size_t i = 0; i < values.size(); i++) {
            output += Convert::ToChar(values[i]).ToString() + (i < values.size() - 1 ? ", " : "");
        }
    }
    this->outputTextBox->Text = output;
}
void AntonovPractic::MyForm::generateButton_Click(System::Object^ sender, System::EventArgs^ e) {
    int size = (int)this->numericUpDownSize->Value; // Получаем размер массива
    System::Random^ rand = gcnew System::Random();
    String^ randomArray = "";
    for (int i = 0; i < size; i++) {
        randomArray += rand->Next(0, 100).ToString(); // Генерация числа от 0 до 99
        if (i < size - 1) {
            randomArray += ", ";
        }
    }
    this->inputTextBox->Text = randomArray; // Заполнение текстового поля сгенерированным массивом
}