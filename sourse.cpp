/*
�������� �.�.
��. 044691
������������ ������ �2

13. ������� �����, � ������� ����������� ������� ��� ������ � �������-
���� ���������:
�) ������� ������ �������� ������ � ������� � ����������� ���������;
�) ������� ������ � ������ ������ ������� ������ ��������� ��������
������� �������� ������� � ������ ��������� ���� ������.
������ ��� ������� �������� �����������. ������������ ����������� �
�����������. ���������� ������ ����������� ������, ���������� ��� �������.


������������ ������ �3
3. ������� �����, � ������� ����������� ���������:
�) �&� ��� ������������ ���� ������;
�) �+� ��� �������� ���� ������.
������ ��� ������� �������� �����������. ������������ �����������
�����������. ���������� friend-������� ��� ���������� �����/������ � �����.
*/

#include <iomanip>
#include "Matrix.h"

using namespace std;

int getValue(string name)
{
	cout << name << ": ";
	int result;
	cin >> result; 	
	return result;
}

void main() {	
	setlocale(LC_ALL, "ru");
	try
	{
		Matrix::RandomOn();

		

		///*��� ��� �2*/
		//Matrix::ShowMessage("��� ��� �2");
		//cout << "������� ������� �������" << endl;
		//int h = getValue("���-�� �����   ");
		//int w = getValue("���-�� ��������");

		//Matrix m(h, w);

		//m.Random(-10,10);
		//m.View();
		//m.f1();
		//Matrix::ShowMessage("������� ������ �������� ������ � ������� � ����������� ���������");
		//m.View();
		//m.f2();
		//Matrix::ShowMessage("������� ������ � ������ ������ ������� ������ �������� ��. ������ � ������ ���������");
		//m.View();
		////m.GetValue(20, 20);

		/*��� ��� �3*/
		Matrix::ShowMessage("��� ��� �3");

		/*Matrix m1(3, 10);
		Matrix m2(3, 10);
		m1.Random(0, 10);
		m2.Random(0, 10);

		Matrix m3(m1 + m2);
		Matrix m4(m1 & m2);

		m1.View();
		cout << " + " << endl;
		m2.View();
		cout << " = " << endl;
		m3.View();
		cout << endl << endl;*/

		Matrix m3(2, 4);
		Matrix m4(4, 3);
		m3.Random(0, 1);
		m4.Random(1, 2);
		Matrix m5(m3 & m4);

		m3.View();
		cout << " & " << endl;
		m4.View();
		cout << " = " << endl;
		m5.View();

	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	system("pause");
}

