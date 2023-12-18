#pragma once
#include "Class_Train.h"


namespace CopmPractRZD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::IO;

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

			FillTable();
		}

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ btn_openNewFile;
	private: System::Windows::Forms::Button^ btn_search;
	private: System::Windows::Forms::TextBox^ textBox_cityFrom;
	private: System::Windows::Forms::Label^ lb_cityFrom;
	private: System::Windows::Forms::Label^ lb_cityDepartTo;
	private: System::Windows::Forms::TextBox^ textBox_cityDepartTo;
	private: System::Windows::Forms::Label^ lb_dateFrom;
	private: System::Windows::Forms::TextBox^ textBox_dateFrom;



	private: System::Windows::Forms::Label^ lb_dateDepart;
	private: System::Windows::Forms::TextBox^ textBox_dateDepart;


	private: System::Windows::Forms::Button^ btn_safe;

	public:
		List<Train^>^ TrainsList = gcnew List<Train^>();

		String^ FileName = "";
	private: System::Windows::Forms::Label^ lb_Status;
	private: System::Windows::Forms::TextBox^ textBox_Status;
	private: System::Windows::Forms::CheckBox^ checkBox_Kupe;
	private: System::Windows::Forms::CheckBox^ checkBox_Sleep;
	private: System::Windows::Forms::CheckBox^ checkBox_Platscart;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;

	public:

	public:

		DataTable^ table = gcnew DataTable();

		void FillTable() {

			if (FileName == "") {
				//Windows Dialog window to choose file (Explorer)

				openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				openFileDialog1->RestoreDirectory = true;
				System::Windows::Forms::DialogResult Status_ShowDialog = openFileDialog1->ShowDialog();
				System::IO::Stream^ myFileStream = openFileDialog1->OpenFile();

				FileName = openFileDialog1->FileName;
			}

			StreamReader^ TxtFileStream = File::OpenText(FileName);


			//Filling TrainList from txt file stream

			while (!TxtFileStream->EndOfStream) {

				String^ Line = TxtFileStream->ReadLine();
				array<String^>^ SplittedLine = Line->Split(' ');
				String^ From = SplittedLine[0];
				String^ DepartTo = SplittedLine[1];
				Int32 Status = Convert::ToInt32(SplittedLine[2]);
				String^ DateF = SplittedLine[3];
				String^ DateD = SplittedLine[4];
				Int32 Kupe = Convert::ToInt32(SplittedLine[5]);
				Int32 Sleep = Convert::ToInt32(SplittedLine[6]);
				Int32 Platscart = Convert::ToInt32(SplittedLine[7]);

				TrainsList->Add(gcnew Train(From, DepartTo, Status, DateF, DateD, Kupe, Sleep, Platscart));
			}

			TxtFileStream->Close();

			AddColumns();

			this->dataGridView1->DataSource = table;

			for (int i = 0; i < this->TrainsList->Count; i++)
			{
				DataRow^ row = table->NewRow();
				for (int j = 0; j < table->Columns->Count; j++)
				{
					String^ columnName = table->Columns[j]->Caption;
					row[columnName] = TrainsList[i]->AllData[columnName];
				}
				table->Rows->Add(row);
			}

		}

		static array<String^>^ ColumnsNames = gcnew array<String^>(9) {
			"From",
			"DepartTo",
			"Status",
			"DateFrom",
			"DateDepartTo",
			"AvailableSeats",
			"SeatsKupe",
			"SeatsSleep",
			"SeatsPlatscart"
		};

		void AddColumns() {

			if (table->Columns->Count == 0) {
				for each (String^ ColumnName in ColumnsNames)
				{
					table->Columns->Add(ColumnName);
				}
			}
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
	private: System::Windows::Forms::Button^ btn_clear;


	protected:

	protected:

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btn_clear = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btn_openNewFile = (gcnew System::Windows::Forms::Button());
			this->btn_search = (gcnew System::Windows::Forms::Button());
			this->textBox_cityFrom = (gcnew System::Windows::Forms::TextBox());
			this->lb_cityFrom = (gcnew System::Windows::Forms::Label());
			this->lb_cityDepartTo = (gcnew System::Windows::Forms::Label());
			this->textBox_cityDepartTo = (gcnew System::Windows::Forms::TextBox());
			this->lb_dateFrom = (gcnew System::Windows::Forms::Label());
			this->textBox_dateFrom = (gcnew System::Windows::Forms::TextBox());
			this->lb_dateDepart = (gcnew System::Windows::Forms::Label());
			this->textBox_dateDepart = (gcnew System::Windows::Forms::TextBox());
			this->btn_safe = (gcnew System::Windows::Forms::Button());
			this->lb_Status = (gcnew System::Windows::Forms::Label());
			this->textBox_Status = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_Kupe = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Sleep = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_Platscart = (gcnew System::Windows::Forms::CheckBox());
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
			this->dataGridView1->Size = System::Drawing::Size(940, 506);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &DataBaseViewer::dataGridView1_CellBeginEdit);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataBaseViewer::dataGridView1_CellContentClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataBaseViewer::dataGridView1_CellDoubleClick);
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataBaseViewer::dataGridView1_CellEndEdit);
			// 
			// btn_clear
			// 
			this->btn_clear->Location = System::Drawing::Point(794, 91);
			this->btn_clear->Name = L"btn_clear";
			this->btn_clear->Size = System::Drawing::Size(154, 23);
			this->btn_clear->TabIndex = 2;
			this->btn_clear->Text = L"Clear";
			this->btn_clear->UseVisualStyleBackColor = true;
			this->btn_clear->Click += gcnew System::EventHandler(this, &DataBaseViewer::btn_clear_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// btn_openNewFile
			// 
			this->btn_openNewFile->Location = System::Drawing::Point(794, 62);
			this->btn_openNewFile->Name = L"btn_openNewFile";
			this->btn_openNewFile->Size = System::Drawing::Size(154, 23);
			this->btn_openNewFile->TabIndex = 3;
			this->btn_openNewFile->Text = L"Open";
			this->btn_openNewFile->UseVisualStyleBackColor = true;
			this->btn_openNewFile->Click += gcnew System::EventHandler(this, &DataBaseViewer::btn_openNewFile_Click);
			// 
			// btn_search
			// 
			this->btn_search->Location = System::Drawing::Point(794, 33);
			this->btn_search->Name = L"btn_search";
			this->btn_search->Size = System::Drawing::Size(154, 23);
			this->btn_search->TabIndex = 4;
			this->btn_search->Text = L"Search";
			this->btn_search->UseVisualStyleBackColor = true;
			// 
			// textBox_cityFrom
			// 
			this->textBox_cityFrom->Location = System::Drawing::Point(15, 30);
			this->textBox_cityFrom->Name = L"textBox_cityFrom";
			this->textBox_cityFrom->Size = System::Drawing::Size(102, 20);
			this->textBox_cityFrom->TabIndex = 5;
			this->textBox_cityFrom->TextChanged += gcnew System::EventHandler(this, &DataBaseViewer::textBox_cityFrom_TextChanged);
			// 
			// lb_cityFrom
			// 
			this->lb_cityFrom->AutoSize = true;
			this->lb_cityFrom->Location = System::Drawing::Point(12, 14);
			this->lb_cityFrom->Name = L"lb_cityFrom";
			this->lb_cityFrom->Size = System::Drawing::Size(105, 13);
			this->lb_cityFrom->TabIndex = 6;
			this->lb_cityFrom->Text = L"Город отправления";
			// 
			// lb_cityDepartTo
			// 
			this->lb_cityDepartTo->AutoSize = true;
			this->lb_cityDepartTo->Location = System::Drawing::Point(123, 14);
			this->lb_cityDepartTo->Name = L"lb_cityDepartTo";
			this->lb_cityDepartTo->Size = System::Drawing::Size(102, 13);
			this->lb_cityDepartTo->TabIndex = 7;
			this->lb_cityDepartTo->Text = L"Город прибывания";
			// 
			// textBox_cityDepartTo
			// 
			this->textBox_cityDepartTo->Location = System::Drawing::Point(126, 30);
			this->textBox_cityDepartTo->Name = L"textBox_cityDepartTo";
			this->textBox_cityDepartTo->Size = System::Drawing::Size(99, 20);
			this->textBox_cityDepartTo->TabIndex = 8;
			// 
			// lb_dateFrom
			// 
			this->lb_dateFrom->AutoSize = true;
			this->lb_dateFrom->Location = System::Drawing::Point(231, 14);
			this->lb_dateFrom->Name = L"lb_dateFrom";
			this->lb_dateFrom->Size = System::Drawing::Size(101, 13);
			this->lb_dateFrom->TabIndex = 9;
			this->lb_dateFrom->Text = L"Дата отправления";
			// 
			// textBox_dateFrom
			// 
			this->textBox_dateFrom->Location = System::Drawing::Point(234, 30);
			this->textBox_dateFrom->Name = L"textBox_dateFrom";
			this->textBox_dateFrom->Size = System::Drawing::Size(98, 20);
			this->textBox_dateFrom->TabIndex = 10;
			// 
			// lb_dateDepart
			// 
			this->lb_dateDepart->AutoSize = true;
			this->lb_dateDepart->Location = System::Drawing::Point(338, 14);
			this->lb_dateDepart->Name = L"lb_dateDepart";
			this->lb_dateDepart->Size = System::Drawing::Size(85, 13);
			this->lb_dateDepart->TabIndex = 11;
			this->lb_dateDepart->Text = L"Дата прибытия";
			// 
			// textBox_dateDepart
			// 
			this->textBox_dateDepart->Location = System::Drawing::Point(341, 30);
			this->textBox_dateDepart->Name = L"textBox_dateDepart";
			this->textBox_dateDepart->Size = System::Drawing::Size(82, 20);
			this->textBox_dateDepart->TabIndex = 12;
			// 
			// btn_safe
			// 
			this->btn_safe->Location = System::Drawing::Point(794, 4);
			this->btn_safe->Name = L"btn_safe";
			this->btn_safe->Size = System::Drawing::Size(154, 23);
			this->btn_safe->TabIndex = 13;
			this->btn_safe->Text = L"Safe";
			this->btn_safe->UseVisualStyleBackColor = true;
			this->btn_safe->Click += gcnew System::EventHandler(this, &DataBaseViewer::btn_safe_Click);
			// 
			// lb_Status
			// 
			this->lb_Status->AutoSize = true;
			this->lb_Status->Location = System::Drawing::Point(429, 14);
			this->lb_Status->Name = L"lb_Status";
			this->lb_Status->Size = System::Drawing::Size(154, 13);
			this->lb_Status->TabIndex = 14;
			this->lb_Status->Text = L"Прибытие/отправление (0/1)";
			// 
			// textBox_Status
			// 
			this->textBox_Status->Location = System::Drawing::Point(432, 29);
			this->textBox_Status->Name = L"textBox_Status";
			this->textBox_Status->Size = System::Drawing::Size(151, 20);
			this->textBox_Status->TabIndex = 15;
			// 
			// checkBox_Kupe
			// 
			this->checkBox_Kupe->AutoSize = true;
			this->checkBox_Kupe->Location = System::Drawing::Point(15, 66);
			this->checkBox_Kupe->Name = L"checkBox_Kupe";
			this->checkBox_Kupe->Size = System::Drawing::Size(50, 17);
			this->checkBox_Kupe->TabIndex = 16;
			this->checkBox_Kupe->Text = L"Купе";
			this->checkBox_Kupe->UseVisualStyleBackColor = true;
			// 
			// checkBox_Sleep
			// 
			this->checkBox_Sleep->AutoSize = true;
			this->checkBox_Sleep->Location = System::Drawing::Point(71, 66);
			this->checkBox_Sleep->Name = L"checkBox_Sleep";
			this->checkBox_Sleep->Size = System::Drawing::Size(109, 17);
			this->checkBox_Sleep->TabIndex = 17;
			this->checkBox_Sleep->Text = L"Спальный вагон";
			this->checkBox_Sleep->UseVisualStyleBackColor = true;
			// 
			// checkBox_Platscart
			// 
			this->checkBox_Platscart->AutoSize = true;
			this->checkBox_Platscart->Location = System::Drawing::Point(186, 66);
			this->checkBox_Platscart->Name = L"checkBox_Platscart";
			this->checkBox_Platscart->Size = System::Drawing::Size(75, 17);
			this->checkBox_Platscart->TabIndex = 18;
			this->checkBox_Platscart->Text = L"Плацкарт";
			this->checkBox_Platscart->UseVisualStyleBackColor = true;
			this->checkBox_Platscart->CheckedChanged += gcnew System::EventHandler(this, &DataBaseViewer::checkBox_Platscart_CheckedChanged);
			// 
			// DataBaseViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 633);
			this->Controls->Add(this->checkBox_Platscart);
			this->Controls->Add(this->checkBox_Sleep);
			this->Controls->Add(this->checkBox_Kupe);
			this->Controls->Add(this->textBox_Status);
			this->Controls->Add(this->lb_Status);
			this->Controls->Add(this->btn_safe);
			this->Controls->Add(this->textBox_dateDepart);
			this->Controls->Add(this->lb_dateDepart);
			this->Controls->Add(this->textBox_dateFrom);
			this->Controls->Add(this->lb_dateFrom);
			this->Controls->Add(this->textBox_cityDepartTo);
			this->Controls->Add(this->lb_cityDepartTo);
			this->Controls->Add(this->lb_cityFrom);
			this->Controls->Add(this->textBox_cityFrom);
			this->Controls->Add(this->btn_search);
			this->Controls->Add(this->btn_openNewFile);
			this->Controls->Add(this->btn_clear);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"DataBaseViewer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DataBaseViewer";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void btn_clear_Click(System::Object^ sender, System::EventArgs^ e) {
		table->Clear();
	}
	private: System::Void btn_openNewFile_Click(System::Object^ sender, System::EventArgs^ e) {
		table->Clear();
		TrainsList->Clear();
		FileName = "";
		FillTable();
	}
	private: System::Void btn_safe_Click(System::Object^ sender, System::EventArgs^ e) {

		//List<Train^>^ Worker = gcnew List<Train^>();

		FileStream^ myFileStream = File::Create(FileName);
		StreamWriter^ TxtFileStream = gcnew StreamWriter(myFileStream);

		for (int i = 0; i < table->Rows->Count; i++) {

			array<Object^>^ row = table->Rows[i]->ItemArray;

			String^ From = (String^)row[0];
			String^ DepartTo = (String^)row[1];
			Int32 Status = Convert::ToInt32((String^)row[2]);
			String^ DateF = (String^)row[3];
			String^ DateD = (String^)row[4];
			Int32 Kupe = Convert::ToInt32((String^)row[6]);
			Int32 Sleep = Convert::ToInt32((String^)row[7]);
			Int32 Platscart = Convert::ToInt32((String^)row[8]);

			TxtFileStream->WriteLine(String::Format("{0} {1} {2} {3} {4} {5} {6} {7}", From, DepartTo, Status, DateF, DateD, Kupe, Sleep, Platscart));

			//Worker->Add(gcnew Train(From, DepartTo, Status, DateF, DateD, Kupe, Sleep, Platscart));

		}

		TxtFileStream->Close();
		myFileStream->Close();

		TrainsList->Clear();
		table->Clear();
		FillTable();

		//FileStream^ myFileStream = File::Create(FileName);
		//StreamWriter^ TxtFileStream = gcnew StreamWriter(myFileStream);

	}
	private: System::Void textBox_cityFrom_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox_Platscart_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

		if (e->ColumnIndex == 2) {
			if (true) {
				int a = 10;
			}
		}

		if (e->ColumnIndex == 3 || e->ColumnIndex == 4) {
			DataGridView^ a = (DataGridView^)sender;
			String^ b = (String^)table->Rows[e->RowIndex]->ItemArray[e->ColumnIndex];
			DateTime dummi;
			if (!DateTime::TryParse(b, dummi)) {
				MessageBox::Show("Entered date value isn't valid.\nEnter a new valid date.\nДата была написана неверно.\nНапишите дату правильно.", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	}
	private: System::Void dataGridView1_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
		if (e->ColumnIndex == 5) {
			e->Cancel = true;
		}
	}
};
}
