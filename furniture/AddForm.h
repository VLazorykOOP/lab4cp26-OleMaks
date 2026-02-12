#pragma once

namespace furniture {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Data::SqlClient; 

	public ref class AddForm : public System::Windows::Forms::Form
	{
	public:
		AddForm(void)
		{
			InitializeComponent();
		}

	protected:
		~AddForm()
		{
			if (components) delete components;
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1; 
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3; 
	private: System::Windows::Forms::TextBox^ textBox4; 
	private: System::Windows::Forms::TextBox^ textBox5; 
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			
			   this->label1->Location = System::Drawing::Point(30, 30);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(100, 23);
			   this->label1->TabIndex = 6;
			   this->label1->Text = L"Вид";
			
			   this->label2->Location = System::Drawing::Point(30, 70);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(100, 23);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"Марка";
			
			   this->label3->Location = System::Drawing::Point(30, 110);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(100, 23);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"Виробник";
	
			   this->label4->Location = System::Drawing::Point(30, 150);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(100, 23);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"Постачальник";
		
			   this->label5->Location = System::Drawing::Point(30, 190);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(100, 23);
			   this->label5->TabIndex = 10;
			   this->label5->Text = L"Ціна";
			
			   this->textBox1->Location = System::Drawing::Point(150, 30);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(100, 22);
			   this->textBox1->TabIndex = 1;
			  
			   this->textBox2->Location = System::Drawing::Point(150, 150);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(100, 22);
			   this->textBox2->TabIndex = 2;
			 
			   this->textBox3->Location = System::Drawing::Point(150, 70);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(100, 22);
			   this->textBox3->TabIndex = 3;
			
			   this->textBox4->Location = System::Drawing::Point(150, 110);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(100, 22);
			   this->textBox4->TabIndex = 4;
			
			   this->textBox5->Location = System::Drawing::Point(150, 190);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(100, 22);
			   this->textBox5->TabIndex = 5;
			
			   this->button1->Location = System::Drawing::Point(150, 240);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(100, 23);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Зберегти";
			   this->button1->Click += gcnew System::EventHandler(this, &AddForm::button1_Click);
			 
			   this->ClientSize = System::Drawing::Size(869, 320);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->textBox3);
			   this->Controls->Add(this->textBox4);
			   this->Controls->Add(this->textBox5);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label5);
			   this->Name = L"AddForm";
			   this->Text = L"Додати меблі";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connString = "Data Source=(localdb)\\MSSQLLocalDB; Initial Catalog=furnitureDB; Integrated Security=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		try {
			if (textBox1->Text == "" || textBox5->Text == "") {
				MessageBox::Show("Заповніть Вид та Ціну!");
				return;
			}
			sqlConn->Open();
			String^ sqlQuery = "INSERT INTO Furniture (Type, Brand, Producer, Supplier, Price) VALUES (N'"
				+ textBox1->Text + "', N'" + textBox3->Text + "', N'" + textBox4->Text + "', N'"
				+ textBox2->Text + "', " + textBox5->Text + ");";

			SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
			command->ExecuteNonQuery();
			MessageBox::Show("Збережено!");
			this->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Помилка БД: " + ex->Message);
		}
		finally { sqlConn->Close(); }
	}
	};
}