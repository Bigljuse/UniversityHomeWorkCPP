#include <iostream>
#include <cstdlib> 

using namespace std;

void Work_1()
{
	int V = 0;
	int S = 0;

	short h = 0;
	short R = 0;
	short r = 0;
	short l = 0;
	const double pi = 2 * acos(0.0);

	cout << "используються формулы:\n 1. V = 1/3*pi*h*(R^2+R*r+r^2)\n 2. S = pi*(R^2+(R+r)*l+r^2)" << '\n';


	cout << "Введите ВЫСОТУ (h) конуса" << '\n';
	if (cin >> h);
	else
	{
		cout << "Вы ввели не число. h должно быть числом!";
		return;
	}
	if (h == 0)
	{
		cout << "Конуса не существует! h < 0";
		return;
	}

	cout << "Введите Радиус ОСНОВАНИЯ (R) конуса" << '\n';
	if (cin >> R);
	else
	{
		cout << "Вы ввели не число. R должно быть числом!";
		return;
	}

	cout << "Введите радиус СЕЧЕНИЯ (r) конуса" << '\n';
	if (cin >> r);
	else
	{
		cout << "Вы ввели не число. R должно быть числом!";
		return;
	}

	if (R <= 0 && r <= 0) {
		cout << "Конуса не существует! R < 0 и r < 0";
		return;
	}

	if (R > 0 && r > 0) {

		V = ((pi * h) * (pow(R, 2) + (R * r) + pow(r, 2))) / 3;

		S = pi * (pow(R, 2) + (R + r) * l + pow(r, 2));
	}
	else
	{
		if (R < r)
			R = r;

		S = pi * pow(R, 2);
		l = sqrt(pow(R, 2) + pow(h, 2));
		V = (h * S) / 3;

	}

	cout << "V = " << V << endl;
	cout << "S = " << S << endl;
}

void Work_2()
{
	double a = 0;
	double x = 0;
	double w = 0;

	cout << "будут использоваться формулы w = : \n1. a * ln |x|, |x|<1 при |x| < 1;\n 2. sqrt(a - x^2), |x|>=1;\n";
	cout << "Введите a и x: " << '\n';

	if (cin >> a >> x);
	else
	{
		cout << "Введены неверные данные" << '\n';
		return;
	}

	x = abs(x);

	if (x < 1)
	{
		if (x == 0)
		{
			cout << "Логорифм равен 0. Такого не должно быть!" << '\n';
			return;
		}

		cout << "Будет использоваться формула w = a * ln |x|, |x|<1; т.к |x| < 1;" << '\n';
		w = a * log(x);
		cout << "w = " << w << endl;
		return;
	}

	cout << "Будет использоваться формула w = sqrt(a - x^2), |x|>=1;" << '\n';
	w = a - pow(x, 2);

	if (w < 0)
	{
		cout << "Ошибка, Подкоренное выражение не может быть отрицательным!" << '\n';
		return;
	}

	cout << "w = " << sqrt(w) << '\n';
}

void Work_3()
{
	float z = 0;

	float x = 0;
	float y = 0;
	float b = 0;

	cout << "Будет использоватья формула : \n z = log(b - y) * sqrt(b - x);" << '\n';
	cout << "Введите x, y, z;" << '\n';

	if (cin >> x >> y >> b);

	if (b - y <= 0) {
		cout << "Ошибка,Число в логорифме меньше нуля!";
		return;
	}

	if (b - x < 0) {
		cout << "Ошибка,Число под корнем меньше нуля!";
		return;
	}

	z = log(b - y);
	z = z * sqrt(b - x);

	cout << "z = " << z << '\n';
}

void Work_4()
{
	int n = 1;
	unsigned short i = 1;

	cout << "Введите натуральное число n: ";

	if (cin >> n);
	else
	{
		cout << "Ошибка, Введёное значение не числовое!" << '\n';
		return;
	}

	if (n > 0)
	{

		for (; i <= 10; i++)
		{
			n++;
			cout << n << ' ';
		}
		return;
	}

	for (; i <= 10; i++)
	{
		cout << i << ' ';
	}

	cout << '\n';
}

void Work_5()
{
	double x = -4;
	double y = 0;

	for (; x <= 4; x += 0.5)
	{
		y = pow(x, 2) - 2 * x + 2;
		if (int(x - 1) == 0)
		{
			y = y / x - 1;
			cout << "Табуляция со значением x = " << x << " Результат: " << y << '\n';
		}
	}
}
