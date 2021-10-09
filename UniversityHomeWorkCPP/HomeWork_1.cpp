#include <iostream>
#include <cstdlib> 

using namespace std;

void Work_1()
{
	setlocale(0, "");
	cout << "Моё имя: Андрей" << endl;
}

void Work_2()
{
	float first = 0;
	float second = 0;

	cout << "Введите 2 числа: ";
	cin >> first >> second;
	cout << "Сумма двух чисел: " << first + second << endl;
	cout << "Разность двух чисел: " << first - second << endl;
	cout << "Произведение двух чисел: " << first * second << endl;

	if (second != 0) {
		cout << "Частное двух чисел: " << first * second << endl;
		return;
	}
}

void Work_3(float b = 0, float c = 0, bool fromFunction = false)
{
	float x = 0;

	if (fromFunction == true)
	{
		x = -(c / b);
		cout << "Корень равен: " << x << endl;
		return;
	}

	cout << "Введите a и b для уравнения bx + c = 0: ";
	if (cin >> b >> c);
	else
	{
		cout << "Введены неверно данные!";
		return;
	}

	if (b == 0)
	{
		cout << "Ошибка, на ноль делить нельзя!" << endl;
		return;
	}

	x = -(c / b);
	cout << "Переменная x равна: " << x << endl;
}

void Work_4()
{
	double a = 0;
	double b = 0;
	double c = 0;
	double xFirst = 0;
	double xSecond = 0;
	double Descrimenant = 0;

	cout << "Введите a и b, и c для уравнения ax^2 + bx + c = 0: ";
	if (cin >> a >> b >> c);
	else
	{
		cout << "Введены неверно данные!";
		return;
	}

	if (a == 0 && b == 0 && c == 0)
	{
		cout << "Корней нет" << endl;
		return;
	}

	if (b == 0 && c == 0)
	{
		cout << "Корень 1, он равен 0" << endl;
		return;
	}

	if (a == 0 && b == 0)
	{
		cout << "Корней нет" << endl;
		return;
	}

	if (a == 0 && c == 0)
	{
		cout << "Корень равен 0" << endl;
		return;
	}

	if (b == 0) {

		if ((a < 0 && c > 0) || (c < 0 && a > 0))
		{
			xFirst = -(c / a);
			xFirst = sqrt(xFirst);
			return;
		}

		cout << "Корней нет" << endl;
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

		cout << "Корней нет" << endl;
		return;
	}

	if (a == 0) {
		Work_3(b, c, true);
		return;
	}

	Descrimenant = pow(b, 2);
	Descrimenant = Descrimenant - 4 * a * c;

	if (Descrimenant < 0) {
		cout << "Корней нет" << endl;
		return;
	}
	if (Descrimenant == 0) {
		xFirst = -(b / 2 * a);
		cout << "Корней один: " << xFirst << endl;
		return;
	}

	Descrimenant = sqrt(Descrimenant);

	xFirst = (-b + Descrimenant) / 2 * a;
	xSecond = (-b - Descrimenant) / 2 * a;

	cout << "Переменная x1 равна: " << xFirst << endl;
	cout << "Переменная x2 равна: " << xSecond << endl;
}

void Work_5()
{
	bool roomhasLight = false;
	bool day = false;
	bool curtainsOpen = false;
	bool lampLight = false;
	string question = "";

	cout << "Шторы раздвинуты? (да или нет): ";
	cin >> question;
	if (question == "да")
		curtainsOpen = true;

	cout << "Лампа включена? (да или нет): ";
	cin >> question;

	if (question == "да")
		lampLight = true;

	cout << "На улице день? (да или нет) : ";
	cin >> question;

	if (question == "да")
		day = true;

	if (curtainsOpen == true && day == true ||
		curtainsOpen == false && lampLight == true
		)
	{
		cout << "В комнате светло!" << endl;
		return;
	}

	cout << "В комнате темно!" << endl;
}