#pragma once
#include <cmath>

namespace FunctionProject2 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

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
    private:
        Label^ labelX;
        TextBox^ inputX;
        Button^ btnCalc;
        Button^ btnClear;
        Label^ labelResult;
        Label^ labelAuthor;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->labelX = (gcnew Label());
            this->inputX = (gcnew TextBox());
            this->btnCalc = (gcnew Button());
            this->btnClear = (gcnew Button());
            this->labelResult = (gcnew Label());
            this->labelAuthor = (gcnew Label());
            this->SuspendLayout();

            // Label X
            this->labelX->Text = "x:";
            this->labelX->Location = Point(20, 20);

            // Input X
            this->inputX->Location = Point(60, 20);

            // Button Calculate
            this->btnCalc->Text = "Обчислити";
            this->btnCalc->Location = Point(20, 70);
            this->btnCalc->Click += gcnew EventHandler(this, &MyForm::btnCalc_Click);

            // Button Clear
            this->btnClear->Text = "Очистити";
            this->btnClear->Location = Point(140, 70);
            this->btnClear->Click += gcnew EventHandler(this, &MyForm::btnClear_Click);

            // Result Label
            this->labelResult->Text = "Результат: ";
            this->labelResult->Location = Point(20, 120);
            this->labelResult->AutoSize = true;

            // Author Label
            this->labelAuthor->Text =
                "Проект: Обчислення значення функції\nАвтор: Миколаєнко Дмитро, ВДПУ, ФМФКН";
            this->labelAuthor->Location = Point(20, 180);
            this->labelAuthor->AutoSize = true;

            // Form settings
            this->ClientSize = System::Drawing::Size(400, 260);
            this->Controls->Add(this->labelX);
            this->Controls->Add(this->inputX);
            this->Controls->Add(this->btnCalc);
            this->Controls->Add(this->btnClear);
            this->Controls->Add(this->labelResult);
            this->Controls->Add(this->labelAuthor);
            this->Text = "Обчислення функції";

            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // ОБЧИСЛЕННЯ ФУНКЦІЇ
        void btnCalc_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (inputX->Text == "")
            {
                MessageBox::Show("Введіть значення x!");
                return;
            }

            double x = Convert::ToDouble(inputX->Text);

            if (x <= 0)
            {
                MessageBox::Show("Значення x повинно бути більше 0 (логарифм).");
                return;
            }

            double y1 = (log(x) + 2 * x) / (x * x + 1);
            double y2 = (x + 1) / (2 * x * x + 1);

            double y = y1 + y2;

            labelResult->Text = "Результат: " + y.ToString();
        }

        // ОЧИЩЕННЯ
        void btnClear_Click(System::Object^ sender, System::EventArgs^ e)
        {
            inputX->Text = "";
            labelResult->Text = "Результат: ";
        }
    };
}
