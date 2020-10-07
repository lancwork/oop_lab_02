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


	/*функция должна обнулить строку и столбец с минимальным элементом*/
	void f1();
	
	/*функция должна в каждой строке массива первый нечётный эл. менять с первым элементом*/
	void f2();

	template <class Op>
	friend static const void Oper(const Matrix& left, const Matrix& right, Op op)
	{		
		int minR = left.rowCount_ < right.rowCount_ ? left.rowCount_ : right.rowCount_;
		int minC = left.colCount_ < right.colCount_ ? left.colCount_ : right.colCount_;

		for (int i = 0; i < minR; i++)
		{
			for (int j = 0; j < minC; j++)
			{
				left.data_[i][j] = op(left.data_[i][j], right.data_[i][j]);
			}
		}
	}

	friend const Matrix operator+(const Matrix& left, const Matrix& right)
	{
		Matrix result(left);

		Oper(result, right, std::plus<int>());

		return result;
	}

	friend const Matrix operator*(const Matrix& left, const Matrix& right)
	{
		Matrix result(left);

		Oper(result, right, std::multiplies<int>());

		return result;
	}

	friend const Matrix operator&(const Matrix& left, const Matrix& right)
	{
		if (left.colCount_ != right.rowCount_)
			throw exception("Произведение не доступно из-за размеров массивов");

		int size(left.colCount_);		
		Matrix result(left.rowCount_, right.colCount_);
		string m1(left.ToStr());
		string m2(right.ToStr());
		result.Invoke([&](int i, int j, int& v) mutable
		{
			int temp(0);
			for (int k = 0; k < size; k++)
			{
				//temp += left[i, k] * right[k, j];
				temp = temp + left.GetValue(i, k) * right.GetValue(k, j);
			}
			v = temp;
		});

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