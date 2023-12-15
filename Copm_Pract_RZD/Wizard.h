#pragma once

#include "Variables.h"

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
	private: System::Windows::Forms::Button^ btn_create;
	private: System::Windows::Forms::Button^ btn_open;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_create = (gcnew System::Windows::Forms::Button());
			this->btn_open = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(88, 158);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(346, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"RZD Train Manage System";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_create
			// 
			this->btn_create->Location = System::Drawing::Point(250, 242);
			this->btn_create->Name = L"btn_create";
			this->btn_create->Size = System::Drawing::Size(100, 50);
			this->btn_create->TabIndex = 1;
			this->btn_create->Text = L"Create";
			this->btn_create->UseVisualStyleBackColor = true;
			// 
			// btn_open
			// 
			this->btn_open->Location = System::Drawing::Point(250, 298);
			this->btn_open->Name = L"btn_open";
			this->btn_open->Size = System::Drawing::Size(100, 50);
			this->btn_open->TabIndex = 2;
			this->btn_open->Text = L"Open";
			this->btn_open->UseVisualStyleBackColor = true;
			this->btn_open->Click += gcnew System::EventHandler(this, &Wizard::btn_open_Click);
			// 
			// Wizard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(607, 489);
			this->Controls->Add(this->btn_open);
			this->Controls->Add(this->btn_create);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Wizard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Wizard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_open_Click(System::Object^ sender, System::EventArgs^ e) {
		cheacker = 1;
		this->Close();
	}
	};
}
