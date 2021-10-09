#include <iostream>
#include <cstdlib> 

using namespace std;

void Work_1()
{
	setlocale(0, "");
	cout << "�� ���: ������" << endl;
}

void Work_2()
{
	float first = 0;
	float second = 0;

	cout << "������� 2 �����: ";
	cin >> first >> second;
	cout << "����� ���� �����: " << first + second << endl;
	cout << "�������� ���� �����: " << first - second << endl;
	cout << "������������ ���� �����: " << first * second << endl;

	if (second != 0) {
		cout << "������� ���� �����: " << first * second << endl;
		return;
	}
}

void Work_3(float b = 0, float c = 0, bool fromFunction = false)
{
	float x = 0;

	if (fromFunction == true)
	{
		x = -(c / b);
		cout << "������ �����: " << x << endl;
		return;
	}

	cout << "������� a � b ��� ��������� bx + c = 0: ";
	if (cin >> b >> c);
	else
	{
		cout << "������� ������� ������!";
		return;
	}

	if (b == 0)
	{
		cout << "������, �� ���� ������ ������!" << endl;
		return;
	}

	x = -(c / b);
	cout << "���������� x �����: " << x << endl;
}

void Work_4()
{
	double a = 0;
	double b = 0;
	double c = 0;
	double xFirst = 0;
	double xSecond = 0;
	double Descrimenant = 0;

	cout << "������� a � b, � c ��� ��������� ax^2 + bx + c = 0: ";
	if (cin >> a >> b >> c);
	else
	{
		cout << "������� ������� ������!";
		return;
	}

	if (a == 0 && b == 0 && c == 0)
	{
		cout << "������ ���" << endl;
		return;
	}

	if (b == 0 && c == 0)
	{
		cout << "������ 1, �� ����� 0" << endl;
		return;
	}

	if (a == 0 && b == 0)
	{
		cout << "������ ���" << endl;
		return;
	}

	if (a == 0 && c == 0)
	{
		cout << "������ ����� 0" << endl;
		return;
	}

	if (b == 0) {

		if ((a < 0 && c > 0) || (c < 0 && a > 0))
		{
			xFirst = -(c / a);
			xFirst = sqrt(xFirst);
			return;
		}

		cout << "������ ���" << endl;
		return;
	}

	if (c == 0)
	{

		if ((a < 0 && b > 0) || (b < 0 && a > 0))
		{
			xFirst = 0;
			xSecond = -(b / a);
			return;
		}

		cout << "������ ���" << endl;
		return;
	}

	if (a == 0) {
		Work_3(b, c, true);
		return;
	}

	Descrimenant = pow(b, 2);
	Descrimenant = Descrimenant - 4 * a * c;

	if (Descrimenant < 0) {
		cout << "������ ���" << endl;
		return;
	}
	if (Descrimenant == 0) {
		xFirst = -(b / 2 * a);
		cout << "������ ����: " << xFirst << endl;
		return;
	}

	Descrimenant = sqrt(Descrimenant);

	xFirst = (-b + Descrimenant) / 2 * a;
	xSecond = (-b - Descrimenant) / 2 * a;

	cout << "���������� x1 �����: " << xFirst << endl;
	cout << "���������� x2 �����: " << xSecond << endl;
}

void Work_5()
{
	bool roomhasLight = false;
	bool day = false;
	bool curtainsOpen = false;
	bool lampLight = false;
	string question = "";

	cout << "����� ����������? (�� ��� ���): ";
	cin >> question;
	if (question == "��")
		curtainsOpen = true;

	cout << "����� ��������? (�� ��� ���): ";
	cin >> question;

	if (question == "��")
		lampLight = true;

	cout << "�� ����� ����? (�� ��� ���) : ";
	cin >> question;

	if (question == "��")
		day = true;

	if (curtainsOpen == true && day == true ||
		curtainsOpen == false && lampLight == true
		)
	{
		cout << "� ������� ������!" << endl;
		return;
	}

	cout << "� ������� �����!" << endl;
}