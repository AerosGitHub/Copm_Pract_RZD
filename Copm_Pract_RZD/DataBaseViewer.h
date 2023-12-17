#pragma once
#include "Class_Train.h"
#include <fstream>

namespace CopmPractRZD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for DataBaseViewer
	/// </summary>
	public ref class DataBaseViewer : public System::Windows::Forms::Form
	{
	public:
		DataBaseViewer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			openFileDialog1->RestoreDirectory = true;
			System::Windows::Forms::DialogResult Status_ShowDialog = openFileDialog1->ShowDialog();
			System::IO::Stream^ FileStream = openFileDialog1->OpenFile();
			String^ FileName = openFileDialog1->FileName;

			table->Columns->Add("From");
			table->Columns->Add("DepartTo");
			table->Columns->Add("Status");
			table->Columns->Add("DateFrom");
			table->Columns->Add("DateDepartTo");
			table->Columns->Add("AvailableSeats");
			table->Columns->Add("TypeOfTrain");


			this->dataGridView1->DataSource = table;

			for (size_t i = 0; i < 100; i++)
			{
				DataRow^ row = table->NewRow();
				row["From"] = FileName;
				table->Rows->Add(row);
			}
		}

		List<Train^>^ TrainsList = gcnew List<Train^>();
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	public:

	public:

		DataTable^ table = gcnew DataTable();
		void ClearData() {
			table->Clear();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DataBaseViewer()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;

	protected:

	protected:

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(9, 116);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(720, 492);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataBaseViewer::dataGridView1_CellContentClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataBaseViewer::dataGridView1_CellDoubleClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(549, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DataBaseViewer::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// DataBaseViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 618);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"DataBaseViewer";
			this->Text = L"DataBaseViewer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ClearData();
	}
};
}
