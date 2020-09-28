#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

using namespace std;

class Matrix
{
private:
	static int count_;

	int** data_;

	int rowCount_;
	int colCount_; 

	void checkPosition(int i, int j) const;


public:	

	Matrix(int rowCount, int colCount);
	Matrix(const Matrix& matrix);
	~Matrix();


	bool IsEmpty();
	void SetSize(int rowCount, int colCount);

	void Delete();

	void Clear(int value = 0);

	int GetValue(int index) const;
	int GetValue(int i, int j) const;
	void SetValue(int i, int j, int value);

	void Fill(int value);

	void View();
	void Random(int min, int max);
	void Trade(int i1, int j1, int i2, int j2);

	static int RandGet(int min, int max);
	static void RandomOn();
	static void ShowMessage(string str);

	void Invoke(function<void(int,int,int&)>);


	/*������� ������ �������� ������ � ������� � ����������� ���������*/
	void f1();
	
	/*������� ������ � ������ ������ ������� ������ �������� ��. ������ � ������ ���������*/
	void f2();

	template <class Op>
	friend static const void Oper(const Matrix& left, const Matrix& right, Op op)
	{		
		int minR = left.rowCount_ < right.rowCount_ ? left.rowCount_ : right.rowCount_;
		int minC = left.colCount_ < right.colCount_ ? left.colCount_ : right.colCount_;

		string m(right.ToStr());
		for (int i = 0; i < minR; i++)
		{
			for (int j = 0; j < minC; j++)
			{
				left.data_[i][j] = op(left.data_[i][j], right.data_[i][j]);
				string m1(left.ToStr());
			}
			string m2(left.ToStr());
		}
	}

	friend const Matrix operator+(const Matrix& left, const Matrix& right)
	{
		Matrix result(left);

		Oper(result, right, std::plus<int>());

		return result;
	}

	friend const Matrix operator&(const Matrix& left, const Matrix& right)
	{
		Matrix result(left);

		Oper(result, right, std::multiplies<int>());
		
		return result;
	}
	int operator[] (const int index) const
	{
		int i(index / rowCount_);
		int j(index % rowCount_);
		checkPosition(i, j);
		return data_[i][j];
	}

	string ToStr() const
	{
		string result("");
		for (int i = 0; i < GetSize(); i++)
		{
			result = result + " " + to_string(GetValue(i));
		}
		return result;
	}

	int GetSize() const
	{
		return rowCount_ * colCount_;
	}
	int GetRowCount()
	{
		return rowCount_;
	}
	int GetColCount()
	{
		return colCount_;
	}
};


#endif