#include <iostream>
#include <iomanip>
#include <string>

#include "Matrix.h"

using namespace std;

Matrix::Matrix(int rowCount = 0, int colCount = 0)
{
	Matrix::SetSize(rowCount, colCount);
}

Matrix::Matrix(const Matrix &matrix)
{	
	Matrix::SetSize(matrix.rowCount_, matrix.colCount_);
	for (int i = 0; i < rowCount_; i++)
	{
		for (int j = 0; j < colCount_; j++)
		{
			SetValue(i, j, matrix.data_[i][j]);
		}
	}
}

Matrix::~Matrix()
{
	Delete();
}

bool Matrix::IsEmpty() {
	return rowCount_ == 0 && colCount_ == 0;
}

void Matrix::checkPosition(int i, int j) const
{
	if (i < 0 || i >= rowCount_ || j < 0 || j > colCount_)
	{
		throw exception("Ошибка: Выход за пределы массива");// .доступ к " + (i)  + "_" + j + ".размер матрицы : ");
	}
}

void Matrix::SetSize(int rowCount, int colCount)
{
	if (rowCount < 0)
		rowCount = 0;
	if (colCount < 0)
		colCount = 0;
	rowCount_ = rowCount;
	colCount_ = colCount;
	data_ = new int* [rowCount_];

	for (int i = 0; i < rowCount_; i++)
	{
		data_[i] = new int[colCount_];
	}

	Clear();
}

void Matrix::Delete()
{
	for (int i = 0; i < rowCount_; i++)
	{
		delete data_[i];
	}
	delete data_;
}

void Matrix::Clear(int value)
{
	Invoke([&](int i, int j, int& v) mutable
	{
		v = value;
	});
}
int Matrix::GetValue(int index) const
{
	int i(index / colCount_);
	int j(index % colCount_);
	checkPosition(i, j);
	int result = data_[i][j];
	return result;
}

int Matrix::GetValue(int i, int j) const
{
	checkPosition(i, j);
	return data_[i][j];
}

void Matrix::SetValue(int i, int j, int value)
{
	checkPosition(i, j);
	data_[i][j] = value;
}

void Matrix::View()
{
	cout << "###" << setfill('_');
	for (int j = 0; j < colCount_; j++)
	{
		cout << setw(4) << '(' << j + 1 << ')';
	}
	cout << endl;
	
	cout << setfill(' ');

	for (int i = 0; i < rowCount_; i++)
	{
		cout << '(' << i + 1 << ')';
		cout << "|";
		for (int j = 0; j < colCount_; j++)
		{

			cout << setw(5) << data_[i][j];
			cout << "|";
		}
		cout << endl;
	}
}

void Matrix::Random(int min, int max)
{
	Invoke([&](int i, int j, int& v) mutable
	{
		v = RandGet(min, max);
	});
}


int Matrix::RandGet(int min, int max)
{
	max++;
	return rand() % (max - min) + min;
}
void Matrix::RandomOn()
{
	srand(time(NULL));
}
void Matrix::ShowMessage(string str)
{
	char a = '=';
	cout << '+' << setw(str.length()) << setfill(a) << a << '+' << endl;
	cout << '|' << str << '|' << endl;
	cout << '+' << setw(str.length()) << setfill(a) << a << '+' << endl;
	setfill(' ');
}

void Matrix::Trade(int i1, int j1, int i2, int j2)
{
	checkPosition(i1, j1);
	checkPosition(i2, j2);

	int buf = GetValue(i1, j1);
	SetValue(i1, j1, GetValue(i2, j2));
	SetValue(i2, j2, buf);

}

/*функция должна обнулить строку и столбец с минимальным элементом*/
void Matrix::f1() {
	if (IsEmpty())
		return;
	int minI = 0;
	int minJ = 0;

	//поиск мин элемента
	for (int i = 0; i < rowCount_; i++)
	{
		for (int j = 0; j < colCount_; j++)
		{
			if (data_[i][j] < data_[minI][minJ])
			{
				minI = i;
				minJ = j;
			}
		}
	}

	//очистка столбца
	for (int i = 0; i < rowCount_; i++)
	{
		data_[i][minJ] = 0;
	}

	//очистка строки
	for (int j = 0; j < colCount_; j++)
	{
		data_[minI][j] = 0;
	}
}

/*функция должна в каждой строке массива первый нечётный эл. менять с первым элементом*/
void Matrix::f2()
{
	for (int i = 0; i < rowCount_; i++)
	{
		int pos = -1;

		for (int j = 0; j < colCount_; j++)
		{
			if (abs(GetValue(i, j) % 2) == 1)
			{
				pos = j;
				break;
			}
		}

		if (pos != -1)
		{
			Trade(i, 0, i, pos);
		}
	}
}

void Matrix::Invoke(function<void(int, int, int&)> f)
{
	for (int i = 0; i < rowCount_; i++)
	{
		for (int j = 0; j < colCount_; j++)
		{
			f(i, j, data_[i][j]);
		}
	}
}
