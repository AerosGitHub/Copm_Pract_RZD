#pragma once

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

			DataTable^ table = gcnew DataTable();

			table->Columns->Add("asdf");
			table->Columns->Add();
			table->Columns->Add();
			table->Columns->Add();

			for (size_t i = 0; i < 100; i++)
			{
				DataRow^ row = table->NewRow();
				row["asdf"] = "asdf";
				table->Rows->Add(row);
			}


			this->dataGridView1->DataSource = table;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 143);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(960, 606);
			this->dataGridView1->TabIndex = 1;
			// 
			// DataBaseViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 761);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"DataBaseViewer";
			this->Text = L"DataBaseViewer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
