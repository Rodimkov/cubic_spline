#pragma once
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <fstream>
#include <iomanip> 
//using namespace std;

typedef std::vector<double> vec;

struct SplineSet {
	double a;
	double b;
	double c;
	double d;
	double x;
};

vec fx;
vec fy;

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::Button^  button1;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button4;




	protected:
	private: System::ComponentModel::IContainer^  components;

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
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(38, 30);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(600, 600);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(851, 401);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 40);
			this->button1->TabIndex = 1;
			this->button1->Text = L"нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(685, 351);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(14, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"X";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(739, 351);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(59, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(848, 351);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"F(X)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(902, 348);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(59, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(684, 546);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"шаг";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(737, 546);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(61, 20);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"0,1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(688, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(544, 271);
			this->dataGridView1->TabIndex = 9;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"X";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"a";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"b";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"c";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"d";
			this->Column5->Name = L"Column5";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(688, 401);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 40);
			this->button2->TabIndex = 10;
			this->button2->Text = L"добавить точку";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(688, 470);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 40);
			this->button3->TabIndex = 11;
			this->button3->Text = L"удалить все точки";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(986, 318);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(246, 268);
			this->richTextBox1->TabIndex = 12;
			this->richTextBox1->Text = L"";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(851, 470);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 40);
			this->button4->TabIndex = 13;
			this->button4->Text = L"удалить точку";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1277, 646);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		std::vector<SplineSet> spline(vec &x, vec &y)
		{
			int n = x.size();
			vec a;
			a.insert(a.begin(), y.begin(), y.end());
			vec b(n);
			vec d(n);
			vec h;

			for (int i = 0; i < n - 1; ++i)
				h.push_back(x[i + 1] - x[i]);

			vec alpha;
			alpha.push_back(0);

			for (int i = 1; i < n - 1; ++i)
			{
				alpha.push_back(3 * (a[i + 1] - a[i]) / h[i] - 3 * (a[i] - a[i - 1]) / h[i - 1]);
			}

			vec c(n);
			vec l(n);
			vec mu(n);
			vec z(n);
			l[0] = 1;
			mu[0] = 0;
			z[0] = 0;



			for (int i = 1; i < n - 1; ++i)
			{
				l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
				mu[i] = h[i] / l[i];
				z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
			}

			l[n - 1] = 1;
			z[n - 1] = 0;
			c[n - 1] = 0;

			for (int j = n - 2; j >= 0; --j)
			{
				c[j] = z[j] - mu[j] * c[j + 1];
				b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
				d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
			}

			std::vector<SplineSet> output_set(n);
			for (int i = 0; i < n - 1; ++i)
			{
				output_set[i].a = a[i];
				output_set[i].b = b[i];
				output_set[i].c = c[i];
				output_set[i].d = d[i];
				output_set[i].x = x[i];
			}
			output_set[n - 1].x = x[n - 1];
			return output_set;
		}
	private:
		double f1(double x) {
			return sin(x);
		}

		double f2(double x) {
			return sin(2 * x);
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		dataGridView1->ClearSelection();
		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();
		PointPairList^ f1_list = gcnew ZedGraph::PointPairList();
		PointPairList^ f2_list = gcnew ZedGraph::PointPairList();


		// Интервал, где есть данные
		//double xmin = Convert::ToDouble(textBox1->Text);
		//double xmax = Convert::ToDouble(textBox2->Text);
		double xmin = fx[0];
		double xmax = fx[fx.size() - 1];

		double h = Convert::ToDouble(textBox3->Text);

		// Список точек
		std::vector<SplineSet> cs = spline(fx, fy);

		for (int k = 0; k < cs.size() - 1; k++)
		{
			double xmin = cs[k].x;
			double xmax = cs[k + 1].x;

			for (double x = xmin; x <= xmax + 0.0001; x += h)
			{
				double m = (x - xmin);
				double tmp = cs[k].a + cs[k].b*m + cs[k].c*m*m + cs[k].d*m*m*m;
				f1_list->Add(x, tmp);
			}
		}

		std::ofstream fout("cppstudio.txt");
		fout.fixed;
		fout << cs.size() - 1 << std::endl;
		for (int i = 0; i < cs.size(); i++)
		{
			fout << cs[i].x << std::endl;
		}
		for (int i = 0; i < cs.size() - 1; i++)
		{
			dataGridView1->Rows->Add();
			if (i < cs.size() - 2)
				dataGridView1->Rows[i]->Cells[0]->Value = "[" + cs[i].x + ":" + cs[i + 1].x + ")";
			else
				dataGridView1->Rows[i]->Cells[0]->Value = "[" + cs[i].x + ":" + cs[i + 1].x + "]";
			dataGridView1->Rows[i]->Cells[1]->Value = cs[i].a;
			dataGridView1->Rows[i]->Cells[2]->Value = cs[i].b;
			dataGridView1->Rows[i]->Cells[3]->Value = cs[i].c;
			dataGridView1->Rows[i]->Cells[4]->Value = cs[i].d;
			if (cs[i].a >= 0)
				fout << std::fixed << std::setprecision(3) << "a" << i << ":  " << cs[i].a;
			else
				fout << std::fixed << std::setprecision(3) << "a" << i << ": " << cs[i].a;
			if (cs[i].b >= 0)
				fout << std::fixed << std::setprecision(3) << "  b" << i << ":  " << cs[i].b;
			else
				fout << std::fixed << std::setprecision(3) << "  b" << i << ": " << cs[i].b;
			if (cs[i].c >= 0)
				fout << std::fixed << std::setprecision(3) << "  c" << i << ":  " << cs[i].c;
			else
				fout << std::fixed << std::setprecision(3) << "  c" << i << ": " << cs[i].c;
			if (cs[i].d >= 0)
				fout << std::fixed << std::setprecision(3) << "  d" << i << ":  " << cs[i].d;
			else
				fout << std::fixed << std::setprecision(3) << "  d" << i << ": " << cs[i].d;
			fout << std::endl;
		}
		fout.close();

		LineItem Curve1 = panel->AddCurve("F1(x)", f1_list, Color::Red, SymbolType::None);
		for (int k = 0; k < fx.size(); k++)
		{
			PointPairList^ f2_list = gcnew ZedGraph::PointPairList();
			f2_list->Add(fx[k], fy[k]);
			LineItem Curve2 = panel->AddCurve("", f2_list, Color::Blue);
		}

		fout.close();

		double min_limit, max_limit;
		min_limit = xmin;
		max_limit = xmax;
		for (int i = 0; i < fy.size(); i++)
		{
			if (min_limit > fy[i])
				min_limit = fy[i];
		}

		for (int i = 0; i < fy.size(); i++)
		{
			if (max_limit < fy[i])
				max_limit = fy[i];
		}
		min_limit -= 0.5;
		max_limit += 0.5;

		panel->XAxis->Scale->Min = min_limit;
		panel->XAxis->Scale->Max = max_limit;
		panel->YAxis->Scale->Min = min_limit;
		panel->YAxis->Scale->Max = max_limit;

		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();
	}
	private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		richTextBox1->Text += "x: " + textBox1->Text + " y: " + textBox2->Text + "\n";
		fx.push_back(Convert::ToDouble(textBox1->Text));
		fy.push_back(Convert::ToDouble(textBox2->Text));
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		richTextBox1->Clear();
		fx.clear();
		fy.clear();
		dataGridView1->Rows->Clear();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		richTextBox1->Clear();
		fx.pop_back();
		fy.pop_back();
		for (int i = 0; i < fx.size(); i++)
			richTextBox1->Text += "x: " + fx[i] + " y: " + fy[i] + "\n";
	}
	};
}
