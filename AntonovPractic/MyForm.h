#pragma once
#include <vector>
#include <string>
#include <chrono> // ��� ��������� �������
#include <cassert>

// �������� ���������: ������� ������������ ����������
// ���������� ���������: ������������ ������ ��������� ���������� ���������� � ������������ ������������ �����������
// �����: ������� �.�., ������ 2091, 2 ����
// ���� ��������: 16.02.2024

namespace AntonovPractic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// ������ ��� MyForm
	/// ����� MyForm ������ ��� �������� ������������ ���������� ������������, ����� ������� �������������� ���� ������,
	/// ����� ��������� ���������� � ������������ ����������� ����������.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TextBox^ inputTextBox; // ���� ��� ����� ������� ����� �������������
		System::Windows::Forms::Button^ sortButton; // ������ ��� ������� �������� ����������
		System::Windows::Forms::ComboBox^ sortTypeComboBox; // ���������� ������ ��� ������ ���� ����������
		System::Windows::Forms::TextBox^ outputTextBox; // ���� ��� ������ ���������������� �������
		System::Windows::Forms::Label^ timeLabel; // ����� ��� ����������� ������� ���������� ����������
		System::Windows::Forms::NumericUpDown^ numericUpDownSize; // ������� ��� �������� ������� ������������� �������
		System::Windows::Forms::Button^ generateButton; // ������ ��� ��������� ���������� ������� �����
		System::ComponentModel::Container^ components; // ��������� ��� �������� ����������� �����

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		/// 
		void InitializeComponent(void)
		{
			this->numericUpDownSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->sortButton = (gcnew System::Windows::Forms::Button());
			this->sortTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->outputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSize))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDownSize
			// 
			this->numericUpDownSize->Location = System::Drawing::Point(280, 10);
			this->numericUpDownSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSize->Name = L"numericUpDownSize";
			this->numericUpDownSize->Size = System::Drawing::Size(120, 20);
			this->numericUpDownSize->TabIndex = 5;
			this->numericUpDownSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(280, 40);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(75, 23);
			this->generateButton->TabIndex = 6;
			this->generateButton->Text = L"������������� ������";
			this->generateButton->Click += gcnew System::EventHandler(this, &MyForm::generateButton_Click);
			// 
			// inputTextBox
			// 
			this->inputTextBox->Location = System::Drawing::Point(12, 12);
			this->inputTextBox->Multiline = true;
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(260, 40);
			this->inputTextBox->TabIndex = 4;
			this->inputTextBox->Text = L"������� ������ �����";
			// 
			// sortButton
			// 
			this->sortButton->Location = System::Drawing::Point(12, 108);
			this->sortButton->Name = L"sortButton";
			this->sortButton->Size = System::Drawing::Size(260, 23);
			this->sortButton->TabIndex = 3;
			this->sortButton->Text = L"�����������";
			this->sortButton->Click += gcnew System::EventHandler(this, &MyForm::sortButton_Click);
			// 
			// sortTypeComboBox
			// 
			this->sortTypeComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->sortTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"�����������", L"���������", L"�����������",
					L"������", L"�������"
			});
			this->sortTypeComboBox->Location = System::Drawing::Point(12, 58);
			this->sortTypeComboBox->Name = L"sortTypeComboBox";
			this->sortTypeComboBox->Size = System::Drawing::Size(260, 21);
			this->sortTypeComboBox->TabIndex = 2;
			// 
			// outputTextBox
			// 
			this->outputTextBox->Location = System::Drawing::Point(12, 137);
			this->outputTextBox->Multiline = true;
			this->outputTextBox->Name = L"outputTextBox";
			this->outputTextBox->ReadOnly = true;
			this->outputTextBox->Size = System::Drawing::Size(260, 40);
			this->outputTextBox->TabIndex = 1;
			// 
			// timeLabel
			// 
			this->timeLabel->Location = System::Drawing::Point(12, 180);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(260, 23);
			this->timeLabel->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(408, 261);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->outputTextBox);
			this->Controls->Add(this->sortTypeComboBox);
			this->Controls->Add(this->sortButton);
			this->Controls->Add(this->inputTextBox);
			this->Controls->Add(this->numericUpDownSize);
			this->Controls->Add(this->generateButton);
			this->Name = L"MyForm";
			this->Text = L"����������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSize))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void sortButton_Click(System::Object^ sender, System::EventArgs^ e); // ���������� ������� ����� �� ������ ����������
		void generateButton_Click(System::Object^ sender, System::EventArgs^ e); // ���������� ������� ����� �� ������ ��������� �������

#pragma endregion
	};
}
