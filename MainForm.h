#pragma once
#include "Manager.h"
#include "PopObject.h"
#include <iostream>
#include "Ball.h"
#include "Rectan.h"
#include "Triangle.h"
#include "Star.h"

namespace PopBallKrasovskis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			MouseWheel += gcnew MouseEventHandler(this, &MainForm::Form_MouseWheel);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ frame;
	private: System::Windows::Forms::Timer^ drawTimer;
	public:
	private: System::Windows::Forms::Timer^ moveTimer;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ starBtn;

	private: System::Windows::Forms::RadioButton^ triangleBtn;

	private: System::Windows::Forms::RadioButton^ rectangleBtn;

	private: System::Windows::Forms::RadioButton^ ballBtn;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			this->drawTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->moveTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->starBtn = (gcnew System::Windows::Forms::RadioButton());
			this->triangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->rectangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->ballBtn = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(12, 12);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(781, 444);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->frame->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseMove);
			this->frame->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseUp);
			// 
			// drawTimer
			// 
			this->drawTimer->Enabled = true;
			this->drawTimer->Interval = 10;
			this->drawTimer->Tick += gcnew System::EventHandler(this, &MainForm::drawTimer_Tick);
			// 
			// moveTimer
			// 
			this->moveTimer->Enabled = true;
			this->moveTimer->Interval = 10;
			this->moveTimer->Tick += gcnew System::EventHandler(this, &MainForm::moveTimer_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->starBtn);
			this->groupBox1->Controls->Add(this->triangleBtn);
			this->groupBox1->Controls->Add(this->rectangleBtn);
			this->groupBox1->Controls->Add(this->ballBtn);
			this->groupBox1->Location = System::Drawing::Point(804, 14);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(169, 241);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Shape";
			// 
			// starBtn
			// 
			this->starBtn->AutoSize = true;
			this->starBtn->Location = System::Drawing::Point(17, 157);
			this->starBtn->Name = L"starBtn";
			this->starBtn->Size = System::Drawing::Size(55, 21);
			this->starBtn->TabIndex = 3;
			this->starBtn->TabStop = true;
			this->starBtn->Text = L"Star";
			this->starBtn->UseVisualStyleBackColor = true;
			// 
			// triangleBtn
			// 
			this->triangleBtn->AutoSize = true;
			this->triangleBtn->Location = System::Drawing::Point(17, 116);
			this->triangleBtn->Name = L"triangleBtn";
			this->triangleBtn->Size = System::Drawing::Size(81, 21);
			this->triangleBtn->TabIndex = 2;
			this->triangleBtn->TabStop = true;
			this->triangleBtn->Text = L"Triangle";
			this->triangleBtn->UseVisualStyleBackColor = true;
			// 
			// rectangleBtn
			// 
			this->rectangleBtn->AutoSize = true;
			this->rectangleBtn->Location = System::Drawing::Point(17, 76);
			this->rectangleBtn->Name = L"rectangleBtn";
			this->rectangleBtn->Size = System::Drawing::Size(93, 21);
			this->rectangleBtn->TabIndex = 1;
			this->rectangleBtn->TabStop = true;
			this->rectangleBtn->Text = L"Rectangle";
			this->rectangleBtn->UseVisualStyleBackColor = true;
			// 
			// ballBtn
			// 
			this->ballBtn->AutoSize = true;
			this->ballBtn->Location = System::Drawing::Point(17, 36);
			this->ballBtn->Name = L"ballBtn";
			this->ballBtn->Size = System::Drawing::Size(52, 21);
			this->ballBtn->TabIndex = 0;
			this->ballBtn->TabStop = true;
			this->ballBtn->Text = L"Ball";
			this->ballBtn->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 461);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Balls V1: Single Ball";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		int x1, y1, x2, y2, nt;
		bool timer_counter;
		float dx, dy;
		PopObject* popObject;




	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		//ответ на запрос перерисовки кадра
		manager->drawFrame(e->Graphics);
	}

	private: System::Void MainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		PopObject* obj = manager->search(e->X, e->Y);
		

		if (!obj) {
			if (ballBtn->Checked) {
				popObject = new Ball(frame->Width, frame->Height, e->X, e->Y);
				popObject->setPos(e->X, e->Y);
				popObject->setSpeed(0, 0);
			}
			else if (rectangleBtn->Checked) {
				popObject = new Rectan(frame->Width, frame->Height, e->X, e->Y);
				popObject->setPos(e->X, e->Y);
				popObject->setSpeed(0, 0);
			}
			else if (triangleBtn->Checked) {
				popObject = new Triangle(frame->Width, frame->Height, e->X, e->Y);
				popObject->setPos(e->X, e->Y);
				popObject->setSpeed(0, 0);

			}
			else if(starBtn->Checked) {
				popObject = new Star(frame->Width, frame->Height, e->X, e->Y);
				popObject->setPos(e->X, e->Y);
				popObject->setSpeed(0, 0);
			}
		
			

			x1 = e->X; // передаем координаты 
			y1 = e->Y;
		
			nt = 0;
			timer_counter = true;
			
			
		}
		else {

			manager->remove(obj);
		}





	}

	private: System::Void frame_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		/*	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			popobject->setPos(e->X, e->Y);
		}
		*/
		/*
		else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			ball->followTo(e->X, e->Y);
		}
		*/
	}




	private: void Form_MouseWheel(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// ≈сть ошибка если резко мен€ть скорость программа зависает ( она багуетс€ в одной координате )



		if (e->Delta > 0) {
			manager->decreaseSpeed(popObject);
		}
		else {
			manager->increaseSpeed(popObject);
		}
	}
		
		

	private: System::Void moveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		manager->move();
		
		if (timer_counter == true) {
			nt++;
		}

	}


	private: System::Void drawTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		frame->Invalidate();
	}


	private: System::Void frame_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		timer_counter = false;
		x2 = e->X; // передаем координаты после того как мы отпустили левый шелчек
		y2 = e->Y;
		
		if (popObject) {
			manager->add(popObject);
			dx = (x2 - x1) / nt; // Ѕывает ошибка что делю на 0
			dy = (y2 - y1) / nt;
			popObject->setSpeed(dx, dy);


			popObject = nullptr;
		
		}

	}
	
		   
private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::ControlKey) {
		moveTimer->Enabled = false;
	}
}


private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::ControlKey) {
		moveTimer->Enabled = true;
	}
}


};
}
