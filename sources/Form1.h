#pragma once
#include <string>
#include "translate.h"

namespace K {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
		
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  DD;
	private: System::Windows::Forms::TextBox^  MM;
	private: System::Windows::Forms::TextBox^  YYYY;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  mdate;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label3;


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->DD = (gcnew System::Windows::Forms::TextBox());
			this->MM = (gcnew System::Windows::Forms::TextBox());
			this->YYYY = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->mdate = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// DD
			// 
			this->DD->BackColor = System::Drawing::Color::White;
			resources->ApplyResources(this->DD, L"DD");
			this->DD->Name = L"DD";
			this->DD->TabStop = false;
			this->DD->Click += gcnew System::EventHandler(this, &Form1::DD_Click);
			this->DD->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::DD_KeyDown);
			this->DD->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::DD_KeyPress);
			// 
			// MM
			// 
			resources->ApplyResources(this->MM, L"MM");
			this->MM->Name = L"MM";
			this->MM->TabStop = false;
			this->MM->Click += gcnew System::EventHandler(this, &Form1::MM_Click);
			this->MM->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::MM_KeyDown);
			this->MM->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::MM_KeyPress);
			// 
			// YYYY
			// 
			resources->ApplyResources(this->YYYY, L"YYYY");
			this->YYYY->Name = L"YYYY";
			this->YYYY->TabStop = false;
			this->YYYY->Click += gcnew System::EventHandler(this, &Form1::YYYY_Click);
			this->YYYY->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::YYYY_KeyDown);
			this->YYYY->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::YYYY_KeyPress);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->button1, L"button1");
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Name = L"button1";
			this->button1->TabStop = false;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// mdate
			// 
			this->mdate->BackColor = System::Drawing::Color::BurlyWood;
			this->mdate->BorderStyle = System::Windows::Forms::BorderStyle::None;
			resources->ApplyResources(this->mdate, L"mdate");
			this->mdate->Name = L"mdate";
			this->mdate->ReadOnly = true;
			this->mdate->TabStop = false;
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Name = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Name = L"label3";
			// 
			// Form1
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->mdate);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->YYYY);
			this->Controls->Add(this->MM);
			this->Controls->Add(this->DD);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) 
		 {
			DD->Focus(); 
		 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

				 ///проверка на заполненность полей
				 bool empty=true;
				 if(Equals(DD->Text, "") == false)
							 {
							 if(Equals(MM->Text, "") == false)
										 {
										 if((Equals(YYYY->Text, "") == false)&&(Equals(YYYY->Text, "-") == false))
														 {
														 empty=false;
														 }
										 }
							 }
if (empty==false)	
			  { 
			  int y = System::Convert::ToInt32(YYYY->Text);
			  int mm = System::Convert::ToInt16(MM->Text);
			  int dd = System::Convert::ToInt16(DD->Text);
			  if ((mm==2)&&(dd==29))
						{
						 int feb;
						 if(y<0) y=y-3;
						 if(!(y%400)){feb=1; goto oun;}
						 if(!(y%100)){feb=0;goto oun;}
						 if(!(y%4)){feb=1;goto oun;}
						 feb=0;
						 oun:
						 if (feb==0)
								{
								MessageBox::Show("¬ невисокосном году отсутствует дата 29 феврал€!");
								DD->Focus();
								DD->SelectAll();
								}
						 else
								{
//старт процедуры трансл€ции даты
								  signed long d = System::Convert::ToInt32(DD->Text);
								  int m = System::Convert::ToInt16(MM->Text);
								  signed long yy = System::Convert::ToInt32(YYYY->Text);
								  string st = translate (d,m,yy);
								  String^ st2 = gcnew String(st.c_str());
								  mdate->Text = st2;
//конец процедуры трансл€ции даты
								}
					     }
			     else
								{
//старт процедуры трансл€ции даты
								  signed long d = System::Convert::ToInt32(DD->Text);
								  int m = System::Convert::ToInt16(MM->Text);
								  signed long yy = System::Convert::ToInt32(YYYY->Text);
								  string st = translate (d,m,yy);
								  String^ st2 = gcnew String(st.c_str());
								  mdate->Text = st2;
//конец процедуры трансл€ции даты
								}
			 }
			 
			 if(empty==true)
					 {
					 MessageBox::Show("Ќе все пол€ заполнены!"); 
					 DD->Focus();
					 DD->SelectAll();
					 }
			
			 }

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) 
		     {
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
			 }

//при клике по окнам дл€ даты их содержимое выдел€етс€, данные верифицируютс€

private: System::Void DD_Click(System::Object^  sender, System::EventArgs^  e) 
			{
			 DD->SelectAll();	 
			}

private: System::Void MM_Click(System::Object^  sender, System::EventArgs^  e) 
			{
 
			if((Equals(DD->Text, "")) == true)
								  {
			        				DD->Focus(); 
									MessageBox::Show("—начала введите число мес€ца!");  
								  }
			 else
			 {
			 int dd = System::Convert::ToInt16(DD->Text);
			 if (dd<=0||dd>31)
								 {
			        				DD->Clear(); 
									MessageBox::Show("«начение числа мес€ца должно быть от 1 до 31!");  
									DD->Focus(); 
								 }
			 else
             MM->SelectAll();
			}
			}

private: System::Void YYYY_Click(System::Object^  sender, System::EventArgs^  e) 
			{
			if((Equals(DD->Text, "")) == true)
								  {
			        				DD->Focus(); 
									MessageBox::Show("—начала введите число мес€ца!");  
								  }
			 else
			 {
			 int dd = System::Convert::ToInt16(DD->Text);
			 if (dd<=0||dd>31)
								 {
			        				DD->Clear(); 
									MessageBox::Show("«начение числа мес€ца должно быть от 1 до 31!");  
									DD->Focus(); 
								 }
			else
			if((Equals(MM->Text, "")) == true)
								  {
			        				MM->Focus(); 
									MessageBox::Show("—начала введите мес€ц!");  
								  }
			 else
			 {
			 int mm = System::Convert::ToInt16(MM->Text);
			 if (mm<=0||mm>12)
								 {
			        				MM->Clear(); 
									MessageBox::Show("«начение мес€ца должно быть от 1 до 12!");  
									MM->Focus(); 
								 }
			 else
			{
			 int ver;
				  switch(mm)
						  {
						  case 2: {ver=29;} break;
						  case 4: {ver=30;} break;
						  case 6: {ver=30;} break;
						  case 9: {ver=30;} break;
						  case 11: {ver=30;} break;
						  default: {ver=31;} break;
						  }
				  if (dd>ver)
						   {
							MessageBox::Show("Ќеверна€ дата!");
							DD->Focus();
							DD->SelectAll();
						   }
				  else
						  {
			 YYYY->SelectAll();
						  }
				
			}
			}
			}
			}

// «ащита от идиота: запрет ввода некорректных символов и неправильных дат

private:		 
	bool errint;
private: System::Void DD_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {
		  errint = false;
		  if ( e->KeyCode < Keys::D0 || e->KeyCode > Keys::D9 )
								{
								 // Determine whether the keystroke is a number from the keypad.
								 if ( e->KeyCode < Keys::NumPad0 || e->KeyCode > Keys::NumPad9 )
										{
										// Determine whether the keystroke is a backspace.
										if ( e->KeyCode != Keys::Back )
												  {
												  // A non-numerical keystroke was pressed.
												  // Set the flag to true and evaluate in KeyPress event.
												  errint = true;
												  }
										}
								}
        //If shift key was pressed, it's not a number.
        if (Control::ModifierKeys == Keys::Shift)
		      {
			  errint = true;
              }
		if((e->KeyCode == Keys::Enter)||(e->KeyCode == Keys::Tab))
	        	{
				if((Equals(DD->Text, "")) == false)
					      {
						  int dd = System::Convert::ToInt16(DD->Text); 
						  if (dd<=0||dd>31)
								 {
			        				DD->Clear(); 
									MessageBox::Show("«начение числа мес€ца должно быть от 1 до 31!");  
								 }
						  else
						  MM->Focus();
				          MM->SelectAll();
						  }
		        }
		 }
private: System::Void MM_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		 {
		 errint = false;
         if ( e->KeyCode < Keys::D0 || e->KeyCode > Keys::D9 )
                 {
				 // Determine whether the keystroke is a number from the keypad.
				 if ( e->KeyCode < Keys::NumPad0 || e->KeyCode > Keys::NumPad9 )
						{
						// Determine whether the keystroke is a backspace.
						if ( e->KeyCode != Keys::Back )
							   {
							   // A non-numerical keystroke was pressed.
							   // Set the flag to true and evaluate in KeyPress event.
							   errint = true;
                               }
						 }
				 }
		 //If shift key was pressed, it's not a number.
		 if (Control::ModifierKeys == Keys::Shift) 
			   {
			   errint = true;
			   }
		 if((e->KeyCode == Keys::Enter)||(e->KeyCode == Keys::Tab))
	           {
				  if((Equals(MM->Text, "")) == false)
					      {
						  int mm = System::Convert::ToInt16(MM->Text);
						  if (mm<=0||mm>12)
									 {
			        				 MM->Clear(); 
									 MessageBox::Show("«начение мес€ца должно быть от 1 до 12!");  
									 }

		///////проверка соотвестви€ дн€ мес€ца числу дней в мес€це
						  int dd = System::Convert::ToInt16(DD->Text); 
						  int ver;
						  switch(mm)
								  {
								  case 2: {ver=29;} break;
								  case 4: {ver=30;} break;
								  case 6: {ver=30;} break;
								  case 9: {ver=30;} break;
								  case 11: {ver=30;} break;
								  default: {ver=31;} break;
								  }
						  if (dd>ver)
								   {
									MessageBox::Show("Ќеверна€ дата!");
									DD->Focus();
									DD->SelectAll();
								   }
						  else 
						  if(Equals(MM->Text, "") == false)
									 {
									 YYYY->Focus();
									 YYYY->SelectAll();
									 }
						}
		 }
		 }
private: System::Void YYYY_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		 {
		 errint = false;
		 if ( e->KeyCode < Keys::D0 || e->KeyCode > Keys::D9 )
				 {
				 // Determine whether the keystroke is a number from the keypad.
				 if ( e->KeyCode < Keys::NumPad0 || e->KeyCode > Keys::NumPad9 )
						{
						// Determine whether the keystroke is a backspace.
						if (e->KeyCode != Keys::Back)
							       {
								   // A non-numerical keystroke was pressed.
								   // Set the flag to true and evaluate in KeyPress event.
								   errint = true;
								   }
                        }
                 }

         //If shift key was pressed, it's not a number. 
         if (Control::ModifierKeys == Keys::Shift) 
					{
						errint = true;
					}
		 if (YYYY->Text->Length == 0)
				{
				if (( e->KeyCode == Keys::Subtract )||( e->KeyCode == Keys::OemMinus )) // разрешение отрицитальных чисел
		               {
		               errint = false;
		               }
	            }
	     

		if((e->KeyCode == Keys::Enter)||(e->KeyCode == Keys::Tab))
	        	   {  
				   if((Equals(YYYY->Text, "") == false)&&(Equals(YYYY->Text, "-") == false))
						   {
						   int y = System::Convert::ToInt32(YYYY->Text);
						   if (y==0)
									 {
			        					YYYY->Clear(); 
										MessageBox::Show("Ќет нулевого года!");
										YYYY->Focus();
									 }
						   else
						   {
						   int mm = System::Convert::ToInt16(MM->Text);
						   int dd = System::Convert::ToInt16(DD->Text);
						   if ((mm==2)&&(dd==29))
								 {
									  int feb;
									  if(y<0) y=y-3;
									  if(!(y%400)){feb=1; goto oun;}
									  if(!(y%100)){feb=0;goto oun;}
									  if(!(y%4)){feb=1;goto oun;}
									  feb=0;
									  oun:
									  if (feb==0)
											   {
											   MessageBox::Show("¬ невисокосном году отсутствует дата 29 феврал€!");
											   DD->Focus();
											   DD->SelectAll();
											   }
									  else {button1->PerformClick();}
							  
								 }
							 else {button1->PerformClick();}
						    }
							}
					}
		 }

//применение полученного значени€ errint

private: System::Void DD_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
		 if ( errint == true )
			 {         // Stop the character from being entered into the control since it is non-numerical.
			 e->Handled = true;
			 }
		 }

private: System::Void MM_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
		 {
         if ( errint == true )
			  {         // Stop the character from being entered into the control since it is non-numerical.
				 e->Handled = true;
			  }
		 }

private: System::Void YYYY_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
		 {
		 if ( errint == true )
			  {         // Stop the character from being entered into the control since it is non-numerical.
				 e->Handled = true;
			  }
		 }
};
}