#pragma once

#include "Variables.h"
#include "DataBaseViewer.h"

namespace CopmPractRZD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Wizard
	/// </summary>
	public ref class Wizard : public System::Windows::Forms::Form
	{
	public:
		Wizard(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Wizard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ btn_open;
	private: System::Windows::Forms::Label^ lb_login;
	private: System::Windows::Forms::Label^ lb_password;
	private: System::Windows::Forms::TextBox^ textBox_login;
	private: System::Windows::Forms::TextBox^ textBox_password;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_open = (gcnew System::Windows::Forms::Button());
			this->lb_login = (gcnew System::Windows::Forms::Label());
			this->lb_password = (gcnew System::Windows::Forms::Label());
			this->textBox_login = (gcnew System::Windows::Forms::TextBox());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(60, 78);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(346, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"RZD Train Manage System";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Wizard::label1_Click);
			// 
			// btn_open
			// 
			this->btn_open->Location = System::Drawing::Point(171, 266);
			this->btn_open->Margin = System::Windows::Forms::Padding(2);
			this->btn_open->Name = L"btn_open";
			this->btn_open->Size = System::Drawing::Size(100, 41);
			this->btn_open->TabIndex = 2;
			this->btn_open->Text = L"Open";
			this->btn_open->UseVisualStyleBackColor = true;
			this->btn_open->Click += gcnew System::EventHandler(this, &Wizard::btn_open_Click);
			// 
			// lb_login
			// 
			this->lb_login->AutoSize = true;
			this->lb_login->Location = System::Drawing::Point(168, 135);
			this->lb_login->Name = L"lb_login";
			this->lb_login->Size = System::Drawing::Size(41, 13);
			this->lb_login->TabIndex = 3;
			this->lb_login->Text = L"�����:";
			// 
			// lb_password
			// 
			this->lb_password->AutoSize = true;
			this->lb_password->Location = System::Drawing::Point(168, 187);
			this->lb_password->Name = L"lb_password";
			this->lb_password->Size = System::Drawing::Size(48, 13);
			this->lb_password->TabIndex = 4;
			this->lb_password->Text = L"������:";
			// 
			// textBox_login
			// 
			this->textBox_login->Location = System::Drawing::Point(171, 152);
			this->textBox_login->Name = L"textBox_login";
			this->textBox_login->Size = System::Drawing::Size(100, 20);
			this->textBox_login->TabIndex = 5;
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(171, 204);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(100, 20);
			this->textBox_password->TabIndex = 6;
			// 
			// Wizard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(455, 397);
			this->Controls->Add(this->textBox_password);
			this->Controls->Add(this->textBox_login);
			this->Controls->Add(this->lb_password);
			this->Controls->Add(this->lb_login);
			this->Controls->Add(this->btn_open);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Wizard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Wizard";
			this->Load += gcnew System::EventHandler(this, &Wizard::Wizard_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_open_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->textBox_login->Text == "admin" && this->textBox_password->Text == "admin") {
			cheacker = 1;
			MessageBox::Show("You need to have a txt file.\nIf you don't have it, just create it.\n� ��� ������ ���� txt ����.\n���� � ��� ��� ���, �� ������ �������� ���.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		else {
			MessageBox::Show("Login and/or password isn't right.\nPlease write right login and password\n����� �/��� ������ �������.\n����������, ������� ���������� ����� � ������.", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Wizard_Load(System::Object^ sender, System::EventArgs^ e) {
		int a = 10;
	}
};
}
