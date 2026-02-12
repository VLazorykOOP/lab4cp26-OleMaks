#pragma once
#include "AddForm.h" 

namespace furniture {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient; 

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();

			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(248, 48);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->Size = System::Drawing::Size(800, 150);
			   this->dataGridView1->TabIndex = 0;

			   this->button1->Location = System::Drawing::Point(30, 79);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(150, 52);
			   this->button1->TabIndex = 1;
			   this->button1->Text = L"додати меблі";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);

			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1114, 253);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->dataGridView1);
			   this->Name = L"MyForm";
			   this->Text = L"Облік меблів (Варіант 12)";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
		   }
#pragma endregion

	private: void refreshTable() {
		try {
			String^ connStr = "Data Source=(localdb)\\MSSQLLocalDB; Initial Catalog=furnitureDB; Integrated Security=True";
			SqlConnection^ conn = gcnew SqlConnection(connStr);

			SqlDataAdapter^ adapter = gcnew SqlDataAdapter("SELECT * FROM Furniture", conn);
			DataTable^ table = gcnew DataTable();
			adapter->Fill(table);

			dataGridView1->DataSource = table;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка завантаження даних: " + ex->Message);
		}
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		refreshTable(); 
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AddForm^ form = gcnew AddForm();
		form->ShowDialog(); 
		refreshTable();     
	}
	};
}