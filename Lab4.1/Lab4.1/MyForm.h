#pragma once
#include <cmath>

namespace FunctionProject {

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
        Label^ labelA;
        Label^ labelB;
        Label^ labelC;
        TextBox^ inputA;
        TextBox^ inputB;
        TextBox^ inputC;
        Button^ btnCalc;
        Button^ btnClear;
        Label^ labelResult;
        Label^ labelAuthor;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->labelA = (gcnew Label());
            this->labelB = (gcnew Label());
            this->labelC = (gcnew Label());
            this->inputA = (gcnew TextBox());
            this->inputB = (gcnew TextBox());
            this->inputC = (gcnew TextBox());
            this->btnCalc = (gcnew Button());
            this->btnClear = (gcnew Button());
            this->labelResult = (gcnew Label());
            this->labelAuthor = (gcnew Label());
            this->SuspendLayout();

            // ========= LABELS =========
            this->labelA->Text = "a:";
            this->labelA->Location = Point(20, 20);

            this->labelB->Text = "b:";
            this->labelB->Location = Point(20, 60);

            this->labelC->Text = "c:";
            this->labelC->Location = Point(20, 100);

            // ========= INPUTS =========
            this->inputA->Location = Point(60, 20);
            this->inputB->Location = Point(60, 60);
            this->inputC->Location = Point(60, 100);

            // ========= BUTTON CALC =========
            this->btnCalc->Text = "Обчислити";
            this->btnCalc->Location = Point(20, 150);
            this->btnCalc->Click += gcnew EventHandler(this, &MyForm::btnCalc_Click);

            // ========= BUTTON CLEAR =========
            this->btnClear->Text = "Очистити";
            this->btnClear->Location = Point(140, 150);
            this->btnClear->Click += gcnew EventHandler(this, &MyForm::btnClear_Click);

            // ========= RESULT =========
            this->labelResult->Text = "Результат: ";
            this->labelResult->Location = Point(20, 200);
            this->labelResult->AutoSize = true;

            // ========= AUTHOR =========
            this->labelAuthor->Text =
                "Проект: Обчислення значення функції\nАвтор: Миколаєнко Дмитро, ВДПУ, ФМФКН";
            this->labelAuthor->Location = Point(20, 250);
            this->labelAuthor->AutoSize = true;

            // ========= FORM =========
            this->ClientSize = System::Drawing::Size(420, 330);
            this->Controls->Add(this->labelA);
            this->Controls->Add(this->labelB);
            this->Controls->Add(this->labelC);
            this->Controls->Add(this->inputA);
            this->Controls->Add(this->inputB);
            this->Controls->Add(this->inputC);
            this->Controls->Add(this->btnCalc);
            this->Controls->Add(this->btnClear);
            this->Controls->Add(this->labelResult);
            this->Controls->Add(this->labelAuthor);
            this->Text = "Обчислення функції";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // ============ FUNCTION CALCULATION ============
        void btnCalc_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (inputA->Text == "" || inputB->Text == "" || inputC->Text == "")
            {
                MessageBox::Show("Заповніть усі поля.");
                return;
            }

            double a = Convert::ToDouble(inputA->Text);
            double b = Convert::ToDouble(inputB->Text);
            double c = Convert::ToDouble(inputC->Text);

            if (a + c < 0)
            {
                MessageBox::Show("Підкореневий вираз (a + c) < 0. Обчислення неможливе.");
                return;
            }

            double numerator = a + tan(b);
            double denominator = 3 * a - 4 * sqrt(a + c);

            double result = numerator / denominator + 3 * fabs(b);

            labelResult->Text = "Результат: " + result.ToString();
        }

        // ============ CLEAR BUTTON ============
        void btnClear_Click(System::Object^ sender, System::EventArgs^ e)
        {
            inputA->Text = "";
            inputB->Text = "";
            inputC->Text = "";
            labelResult->Text = "Результат: ";
        }
    };
}
