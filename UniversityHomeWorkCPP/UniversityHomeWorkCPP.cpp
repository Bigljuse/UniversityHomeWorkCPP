#include <iostream>
#include <vector>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;

void HomeWork_1_Work_1()
{
	setlocale(0, "");
	cout << "Моё имя: Андрей" << endl;
}

void HomeWork_1_Work_2()
{
	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;

	float first = 0;
	float second = 0;

	cout << "2) Задание «Имя». Ввести с клавиатуры два числа и найти их сумму, разность, произведение и, если возможно, частное от деления одного на другое.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первое число: ";
			cin >> first;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите второе число: ";
			cin >> second;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в первую переменную не число!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели во вторую переменную не число!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

	cout << "Сумма двух чисел: " << first + second << endl;
	cout << "Разность двух чисел: " << first - second << endl;
	cout << "Произведение двух чисел: " << first * second << endl;

	if (second != 0) {
		cout << "Частное двух чисел: " << first * second << endl;
		return;
	}
	else
	{
		cout << "Частное двух чисел невозможно, второе число равно 0\n";
	}
}

void HomeWork_1_Work_3(float b = 0, float c = 0, bool fromFunction = false)
{
	float x = 0;

	if (fromFunction == true)
	{
		x = -(c / b);
		cout << "Корень равен: " << x << endl;
		return;
	}

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;

	float first = 0;
	float second = 0;

	cout << "3) Задание «Уравнение». Для любых введенных с клавиатуры b и c решить уравнение вида bx + c = 0.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первое число: ";
			cin >> first;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите второе число: ";
			cin >> second;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в первую переменную не число!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели во вторую переменную не число!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

	if (second == 0)
	{
		cout << "Ошибка, на ноль делить нельзя!" << endl;
		return;
	}

	x = -(second / first);
	cout << "Переменная x равна: " << x << endl;
}

void HomeWork_1_Work_4()
{
	double xFirst = 0;
	double xSecond = 0;
	double Descrimenant = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;
	bool ThirdNumberIsCorrect = false;

	float first = 0;
	float second = 0;
	float third = 0;

	cout << "4) Задание «Еще уравнение». Для любых введенных с клавиатуры a, b и c решить уравнение вида ax2 + bx + c = 0.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первое число: ";
			cin >> first;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите второе число: ";
			cin >> second;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (ThirdNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите третье число: ";
			cin >> third;

			if (cin.fail() == false)
				ThirdNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в первую переменную не число!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели во вторую переменную не число!\n";
			else if (ThirdNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в третью переменную не число!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false || ThirdNumberIsCorrect == false);

	if (first == 0 && second == 0 && third == 0)
	{
		cout << "Корней нет" << endl;
		return;
	}

	if (second == 0 && third == 0)
	{
		cout << "Корень 1, он равен 0" << endl;
		return;
	}

	if (first == 0 && second == 0)
	{
		cout << "Корней нет" << endl;
		return;
	}

	if (first == 0 && third == 0)
	{
		cout << "Корень равен 0" << endl;
		return;
	}

	if (second == 0) {

		if ((first < 0 && third > 0) || (third < 0 && first > 0))
		{
			xFirst = -(third / first);
			xFirst = sqrt(xFirst);
			return;
		}

		cout << "Корней нет" << endl;
		return;
	}

	if (third == 0)
	{

		if ((first < 0 && second > 0) || (second < 0 && first > 0))
		{
			xFirst = 0;
			xSecond = -(second / first);
			return;
		}

		cout << "Корней нет" << endl;
		return;
	}

	if (first == 0) {
		HomeWork_1_Work_3(second, third, true);
		return;
	}

	Descrimenant = pow(second, 2);
	Descrimenant = Descrimenant - 4 * first * third;

	if (Descrimenant < 0) {
		cout << "Корней нет" << endl;
		return;
	}
	if (Descrimenant == 0) {
		xFirst = -(second / 2 * first);
		cout << "Корней один: " << xFirst << endl;
		return;
	}

	Descrimenant = sqrt(Descrimenant);

	xFirst = (-second + Descrimenant) / 2 * first;
	xSecond = (-second - Descrimenant) / 2 * first;

	cout << "Переменная x1 равна: " << xFirst << endl;
	cout << "Переменная x2 равна: " << xSecond << endl;
}

void HomeWork_1_Work_5()
{
	bool roomhasLight = false;
	bool day = false;
	bool curtainsOpen = false;
	bool lampLight = false;
	string question = "";

	bool firstQuestionIsCorrect = false;
	bool secondQuestionIsCorrect = false;
	bool thirdQuestionIsCorrect = false;

	cout << "5) Задание «Лампа со шторой». В комнате светло, если на улице день и раздвинуты шторы или если включена лампа.Ваша программа должна, в зависимости от времени суток и состояния лампы и штор, отвечать на вопрос, светло ли в комнате.\n";

	do
	{
		if (firstQuestionIsCorrect == false) {
			cout << "Шторы раздвинуты? (да или нет): ";
			cin >> question;

			if (question == "да")
			{
				firstQuestionIsCorrect = true;
				curtainsOpen = true;
			}
			else if (question == "нет")
			{
				firstQuestionIsCorrect = true;
				curtainsOpen = false;
			}
		}


		if (secondQuestionIsCorrect == false) {
			cout << "Лампа включена? (да или нет): ";
			cin >> question;

			if (question == "да")
			{
				secondQuestionIsCorrect = true;
				lampLight = true;
			}
			else if (question == "нет")
			{
				secondQuestionIsCorrect = true;
				lampLight = false;
			}
		}

		if (thirdQuestionIsCorrect == false) {
			cout << "На улице день? (да или нет) : ";
			cin >> question;

			if (question == "да")
			{
				thirdQuestionIsCorrect = true;
				day = true;
			}
			else if (question == "нет")
			{
				thirdQuestionIsCorrect = true;
				day = false;
			}
		}

		if (firstQuestionIsCorrect == false)
			cout << "Ошибка, вы неправильный ответ на вопрос о шторах!\n";
		if (secondQuestionIsCorrect == false)
			cout << "Ошибка, вы неправильный ответ на вопрос о лампе!\n";
		if (thirdQuestionIsCorrect == false)
			cout << "Ошибка, вы неправильный ответ на вопрос о улице!\n";

	} while (firstQuestionIsCorrect == false || secondQuestionIsCorrect == false || thirdQuestionIsCorrect == false);

	if (curtainsOpen == true && day == true ||
		curtainsOpen == false && lampLight == true
		)
	{
		cout << "В комнате светло!" << endl;
		return;
	}

	cout << "В комнате темно!" << endl;
}


void HomeWork_2_Work_1()
{
	int V = 0;
	int S = 0;

	short h = 0;
	short R = 0;
	short r = 0;
	short l = 0;
	const double pi = 2 * acos(0.0);

	cout << "используються формулы:\n 1. V = 1/3*pi*h*(R^2+R*r+r^2)\n 2. S = pi*(R^2+(R+r)*l+r^2)" << '\n';

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;
	bool ThirdNumberIsCorrect = false;

	cout << "1) Вычислить объем и полную поверхность усеченного конуса, используються формулы:\nV = 1/3*pi*h*(R^2+R*r+r^2)\nS = pi*(R^2+(R+r)*l+r^2)\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите ВЫСОТУ (h) конуса: ";
			cin >> h;

			if (h < 0 && cin.fail() == false)
			{
				cout << "Конуса не существует! h < 0\n";
				return;
			}

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите радиус основания (R) конуса: ";
			cin >> R;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (ThirdNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите радиус сечения (r) конуса: ";
			cin >> r;

			if (cin.fail() == false)
				ThirdNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильную высоту!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильный радус основания!\n";
			else if (ThirdNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильное сечение!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false || ThirdNumberIsCorrect == false);

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

void HomeWork_2_Work_2()
{
	double a = 0;
	double x = 0;
	double w = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;

	cout << "2) Задача «Разветвление». Для произвольных x и a вычислить: \nw = : \na * ln |x|, |x|<1 при |x| < 1;\nsqrt(a - x^2), |x|>=1;\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите x: ";
			cin >> x;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите a: ";
			cin >> a;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в x не число!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в a не число!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

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

void HomeWork_2_Work_3()
{
	float z = 0;

	float x = 0;
	float y = 0;
	float b = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;
	bool ThirdNumberIsCorrect = false;

	cout << "1) Для произвольных x, y и b вычислить функцию z = log(b - y) * sqrt(b - x);\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите x: ";
			cin >> x;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите y: ";
			cin >> y;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (ThirdNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите b: ";
			cin >> b;

			if (cin.fail() == false)
				ThirdNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно x!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно y!\n";
			else if (ThirdNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно b!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false || ThirdNumberIsCorrect == false);

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

void HomeWork_2_Work_4()
{
	int n = 1;
	unsigned short i = 1;

	bool firstNumberIsCorrect = false;
	float first = 0;

	cout << "4) Задача «Порядок». Распечатать 10 последовательных натуральных чисел в возрастающем порядке, начиная с произвольного числа N.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первое число: ";
			cin >> first;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели не натуральное число!\n";
		}
	} while (firstNumberIsCorrect == false);

	if (n > 0)
	{

		for (; i <= 10; i++)
		{
			n++;
			cout << n << ' ';
		}

		cout << '\n';

		return;
	}

	for (; i <= 10; i++)
	{
		cout << i << ' ';
	}

	cout << '\n';
}

void HomeWork_2_Work_5()
{
	double x = -4;
	double y = 0;
	cout << "5) Задача «Табуляция». Протабулировать функцию y.\n";

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


void HomeWork_3_Work_1() {
	unsigned int m = 0;
	unsigned int S = 0;
	double r = 0;
	double p = 0;
	double n = 0;

	double checkForZero = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;
	bool ThirdNumberIsCorrect = false;

	cout << "1) Задача «Заем». Месячная выплата m по займу в S рублей на n лет под процент p вычисляется по формуле.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите займ (S): ";
			cin >> S;

			if (cin.fail() == false && S > 0)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите займ по годам (n): ";
			cin >> n;

			if (cin.fail() == false && n > 0)
				SecondNumberIsCorrect = true;
		}

		if (ThirdNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите процент(p): ";
			cin >> p;

			if (cin.fail() == false && p > 0)
				ThirdNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно S!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно n!\n";
			else if (ThirdNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно p!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false || ThirdNumberIsCorrect == false);

	r = p / 100;

	m = S * r * pow((1 + r), n);

	checkForZero = (12 * (pow((1 + r), n) - 1));

	if (checkForZero == 0)
	{
		cout << "Ошибка расчёта, деление на ноль невозможно" << '\n';
		return;
	}

	m = m / checkForZero;

	cout << "Месячная выплата равна: " << m << '\n';
}

void HomeWork_3_Work_2() {
	double monthyPayment = 0;
	double monthyPaymentCorrection = 0;
	double amountOfMoney = 0;
	double years = 0;

	int monthyPaymentCounted = 1;
	double percent = 1;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;
	bool ThirdNumberIsCorrect = false;

	cout << "2) Задача «Ссуда». Под какой процент p выдана ссуда величиной S рублей, которая гасится месячными выплатами величиной m в течение n лет.Формула приведена в предыдущей задаче.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите займ (S): ";
			cin >> amountOfMoney;

			if (cin.fail() == false && amountOfMoney > 0)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите ежемесячную выплату (m): ";
			cin >> monthyPayment;

			if (cin.fail() == false && monthyPayment > 0)
				SecondNumberIsCorrect = true;
		}

		if (ThirdNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите займ по годам (n): ";
			cin >> years;

			if (cin.fail() == false && years > 0)
				ThirdNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно S!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно m!\n";
			else if (ThirdNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно n!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false || ThirdNumberIsCorrect == false);

	while (abs(monthyPaymentCounted) > 1)
	{
		monthyPaymentCorrection = amountOfMoney * percent * pow((1 + percent), years);
		monthyPaymentCorrection = monthyPaymentCorrection / (12 * (pow((1 + percent), years) - 1));

		monthyPaymentCounted = monthyPayment - monthyPaymentCorrection;

		if (monthyPaymentCounted == 0)
			break;

		if (monthyPaymentCounted > 0)
			percent += 0.00001;
		else
			percent -= 0.00001;
	}

	amountOfMoney += amountOfMoney * percent;
	percent *= 100;

	cout << "Займ под процент: " << percent << '%' << "\nИтоговая сумма: " << amountOfMoney << '\n';
}

void HomeWork_3_Work_3()
{
	cout << "3) Задача «Копирование файла». Создать на диске текстовый файл и скопировать его на экран.\n";

	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	string fileName = "Preparing.txt";
	string textInput = "";
	string textOutput = "";

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите любую строку: ";

	getline(cin, textInput);

	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << textInput;
	outputFile.close();

	cout << "Текст записанный в файла: " << textInput << '\n';

	ifstream inputFile;
	inputFile.open(fileName);
	getline(inputFile, textOutput);
	inputFile.close();

	cout << "Текст прочитанный из файла: " << textOutput << '\n';
}

void HomeWork_3_Work_4()
{
	cout << "4) Задача «Фильтр». Вывести на экран только числа из созданного Вами на диске текстового файла, содержащего буквы и числа.\n";

	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	string fileName = "Preparing.txt";
	string textInput = "";
	string textOutput = "";
	string constructedText = "";
	bool notNumber = false;
	bool negativeNumber = false;
	bool floatNumber = false;
	bool hasPlus = false;

	cout << "Введите любую строку: ";
	getline(cin, textInput);

	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << textInput;
	outputFile.close();

	ifstream inputFile;
	inputFile.open(fileName);
	getline(inputFile, textOutput);
	inputFile.close();

	for (auto number : textOutput)
	{
		if (notNumber && number != ' ')
			continue;

		if (number == ' ')
		{
			notNumber = false;
			negativeNumber = false;
			floatNumber = false;
			hasPlus = false;

			if (constructedText.size() == 0)
				continue;

			if (constructedText[constructedText.size() - 1] != '.')
				cout << constructedText << ' ';

			constructedText = "";
			continue;
		}

		if ((int(number) < 48 || int(number) > 58) && number != ' ' && number != '.' && number != '-' && number != '+') {
			notNumber = true;
			constructedText = "";
			continue;
		}

		if (number == '-')
		{
			if (negativeNumber == true || constructedText.size() > 0)
			{
				notNumber = true;
				constructedText = "";
				continue;
			}

			negativeNumber = true;
			constructedText += number;
			continue;
		}

		if (number == '.')
		{
			if (floatNumber == true || constructedText.size() == 0)
			{
				notNumber = true;
				constructedText = "";
				continue;
			}

			floatNumber = true;
			constructedText += number;
			continue;
		}

		if (number == '+')
		{
			if (hasPlus == true || constructedText.size() > 0)
			{
				notNumber = true;
				constructedText = "";
				continue;
			}

			hasPlus = true;
			constructedText += number;
			continue;
		}

		constructedText += number;
	}
	if (constructedText[constructedText.size() - 1] != '.')
		cout << constructedText << '\n';
}

void HomeWork_3_Work_5()
{
	cout << "5) Задача «Сортировка букв». Задать строку из 30 букв и расставить их в алфавитном порядке.\n";
	cout << "Введите любую строку: ";

	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	string fileName = "Preparing.txt";
	string textInput = "";
	string textOutput = "";
	string sortedLine = "";
	string sortedLetters = "";

	getline(cin, textInput);

	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << textInput;
	outputFile.close();

	ifstream inputFile;
	inputFile.open(fileName);
	getline(inputFile, textOutput);
	inputFile.close();

	string textBuffer = "";
	char tempBuffer;

	for (int upLetters = 65; upLetters < 97; upLetters++) {
		for (auto letter : textOutput)
		{
			if (int(letter) == upLetters)
				sortedLetters = letter + sortedLetters;

			if (int(letter) == upLetters + 32)
				sortedLetters += letter;
		}
		sortedLine += sortedLetters;
		sortedLetters = "";
	}

	cout << sortedLine << '\n';
}


void HomeWork_4_Work_1()
{
	cout << "1) Задача «Файл». Создать файл, записать в него 10 чисел, закрыть, потом вновь открыть файл и найти сумму чисел.\n";
	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	string fileName = "Preparing.txt";
	string textInput = "";
	string textOutput = "";
	string constructedText = "";

	float summ = 0;

	bool notNumber = false;
	bool negativeNumber = false;
	bool floatNumber = false;
	bool hasPlus = false;

	cout << "Введите любую строку: ";
	getline(cin, textInput);

	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << textInput;
	outputFile.close();

	ifstream inputFile;
	inputFile.open(fileName);
	getline(inputFile, textOutput);
	inputFile.close();

	for (auto number : textOutput)
	{
		if (notNumber && number != ' ')
			continue;

		if (number == ' ')
		{
			notNumber = false;
			negativeNumber = false;
			floatNumber = false;
			hasPlus = false;

			if (constructedText.size() == 0)
				continue;

			summ += stoi(constructedText);

			constructedText = "";
			continue;
		}

		if ((int(number) < 48 || int(number) > 58) && number != ' ' && number != '.' && number != '-' && number != '+') {
			notNumber = true;
			constructedText = "";
			continue;
		}

		if (number == '-')
		{
			if (negativeNumber == true || constructedText.size() > 0)
			{
				notNumber = true;
				constructedText = "";
				continue;
			}

			negativeNumber = true;
			constructedText += number;
			continue;
		}

		if (number == '.')
		{
			if (floatNumber == true)
			{
				notNumber = true;
				constructedText = "";
				continue;
			}

			floatNumber = true;
			constructedText += number;
			continue;
		}

		if (number == '+')
		{
			if (hasPlus == true)
			{
				notNumber = true;
				constructedText = "";
				continue;
			}

			hasPlus = true;
			constructedText += number;
			continue;
		}

		constructedText += number;
	}

	if (constructedText != "")
		summ += stof(constructedText);

	cout << setprecision(10) << summ << '\n';
}

void HomeWork_4_Work_2()
{
	float number = 0;

	bool firstNumberIsCorrect = false;

	cout << "2) Задача «Знак числа». Определить знак введенного с клавиатуры числа, использовав подпрограмму-функцию.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите число: ";
			cin >> number;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели не число!\n";
		}
	} while (firstNumberIsCorrect == false);

	if (number > 0) {
		cout << "Число положительное." << '\n';
		return;
	}

	if (number == 0) {
		cout << "Число не имеет знака." << '\n';
		return;
	}

	if (number < 0) {
		cout << "Число отрицательное." << '\n';
		return;
	}
}

int  HomeWork_4_Work_3_Cout_rectangle()
{
	float a = 0;
	float b = 0;

	bool firstNumberIsCorrect = false;
	bool seconsNumberIsCorrect = false;

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первую сторону: ";
			cin >> a;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (seconsNumberIsCorrect == false) {
			cout << "Введите вторую сторону: ";
			cin >> b;

			if (cin.fail() == false)
				seconsNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно первую сторону!\n";
			if (seconsNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно вторую сторону!\n";
		}
	} while (firstNumberIsCorrect == false || seconsNumberIsCorrect == false);

	cout << "Введите первую сторону: ";

	if (a == 0 || b == 0)
	{
		cout << "Прямоугольника не существует!" << '\n';
		return 0;
	}

	cout << a * b << '\n';
	return a * b;
}

int  HomeWork_4_Work_3_Count_triangle() {
	float a = 0;
	float b = 0;

	bool firstNumberIsCorrect = false;
	bool seconsNumberIsCorrect = false;

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первую сторону: ";
			cin >> a;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (seconsNumberIsCorrect == false) {
			cout << "Введите вторую сторону: ";
			cin >> b;

			if (cin.fail() == false)
				seconsNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно первую сторону!\n";
			if (seconsNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно вторую сторону!\n";
		}
	} while (firstNumberIsCorrect == false || seconsNumberIsCorrect == false);

	if (a == 0 || b == 0)
	{
		cout << "Треугольника не существует!" << '\n';
		return 0;
	}

	cout << (a * b) / 2 << '\n';
	return (a * b) / 2;
}

int  HomeWork_4_Work_3_Count_cirqle() {
	float r = 0;

	bool firstNumberIsCorrect = false;

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите радиус круга: ";
			cin >> r;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}
		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно радиус круга!\n";

		}
	} while (firstNumberIsCorrect == false);

	if (r <= 0)
	{
		cout << "Круга не существует!" << '\n';
		return 0;
	}

	cout << "Площадь круга равна: " << pow(r, 2) * 3.14 << '\n';
	return pow(r, 2) * 3.14;
}

void HomeWork_4_Work_3() {

	float a = 0;
	float b = 0;

	unsigned int square = 1;

	float triangle = 0;
	float rectangle = 0;
	float cirqle = 0;

	bool firstNumberIsCorrect = false;

	cout << "3) Задача «Геометрические фигуры». Вычислить площади прямоугольника, треугольника, круга, используя подпрограммы - функции.\n";

	cout << "Будем считать площади:"
		<< '\n'
		<< "1.Площадь Прямоугольника: a * b = c"
		<< "\n"
		<< "2.Площадь Треугольника: c = (a * b)/2"
		<< "\n"
		<< "3.Площадь Круга: c = pi * r^2"
		<< '\n';

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите номер вычисляемой площади: ";
			cin >> square;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели не число!\n";
		}
	} while (firstNumberIsCorrect == false);

	if (square == 1)
	{
		HomeWork_4_Work_3_Cout_rectangle();
		return;
	}

	if (square == 2)
	{
		HomeWork_4_Work_3_Count_triangle();
		return;
	}

	if (square == 3)
	{
		HomeWork_4_Work_3_Count_cirqle();
		return;
	}

	if (square < 1)
	{
		cout << "Не выбрана вычисляемая площадь: " << '\n';
		return;
	}

	if (square > 3)
	{
		cout << "Не выбрана вычисляемая площадь: " << '\n';
		return;
	}

	return;
}

void HomeWork_4_Work_4_DrawRedLine(bool drawStars = false)
{
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	bool ChangedColor = false;
	int top = 0;

	if (drawStars == true)
		top = 8;

	for (; top <= 37; top++)
	{
		if (drawStars == true)
		{
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 836);
			cout << "//";
			continue;
		}

		if (top <= 7)
		{
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 543);
			cout << '*';
			cout << ' ';
		}

		if (top > 15 && ChangedColor == false)
		{
			ChangedColor = true;
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 836);
		}

		if (top > 15)
			cout << "//";
	}
	// Устанавливаю цвет текста на обычный, символов и заднего фона на обычный
	SetConsoleTextAttribute(hOUTPUT, 271);
	cout << '\n';
}

void HomeWork_4_Work_4_DrawWhiteLine(bool drawStars = false)
{
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	bool ChangedColor = false;
	int counter = 0;

	// Если я рисую линию без звёзд, то я просто пропускаю 
	if (drawStars == true)
		counter = 8;

	for (; counter <= 37; counter++)
	{
		if (drawStars == true)
		{
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 511);
			cout << "//";
			continue;
		}

		if (counter <= 7)
		{
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 543);
			cout << '*';
			cout << ' ';
		}

		if (counter > 15 && ChangedColor == false)
		{
			ChangedColor = true;
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 511);
		}

		if (counter > 15)
			cout << "//";
	}
	// Устанавливаю цвет текста, символов и заднего фона на обычный
	SetConsoleTextAttribute(hOUTPUT, 271);
	cout << '\n';
}

void HomeWork_4_Work_4() {
	cout << "4) Задача «Былая слава». В 1912 году американский флаг «Былая слава» имел 48 звезд (по одной на каждый штат) и 13 полос(по одной на колонию).Напечатать «Былую славу 1912 года».\n";

	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i <= 5; i++)
	{
		if (i < 3) {
			HomeWork_4_Work_4_DrawRedLine(false);
			HomeWork_4_Work_4_DrawWhiteLine(false);
		}
		else {
			HomeWork_4_Work_4_DrawRedLine(true);
			HomeWork_4_Work_4_DrawWhiteLine(true);
		}
	}
	HomeWork_4_Work_4_DrawRedLine(true);

	SetConsoleTextAttribute(hOUTPUT, 271);
	cout << '\n';
	return;
}

void HomeWork_4_Work_5()
{
	cout << "5) Задача «Синусоида». Напечатать график функции у = sin x.\n";

	HWND hwnd;
	TCHAR Title[1040] = { 0 };
	GetConsoleTitle(Title, 1040); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	HDC hdc = GetDC(hwnd);    // Получаем контекст для рисования
	HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Создаем красное перо
	HBRUSH b1, b2 = CreateSolidBrush(RGB(0, 255, 0)); // Создаем зеленую кисть
	p1 = (HPEN)SelectObject(hdc, p2);  // Заносим красное перо в контекст рисования

	// Рисую синусоиду
	for (float i = 0; i <= 100; i += 0.1) {
		LineTo(hdc, i * 15, 200 + sin(i) * 20);
	}

	SelectObject(hdc, p1);   // Возвращаем старое перо 
	ReleaseDC(hwnd, hdc);    // Освобождаем контекст рисования
	DeleteObject(p2);       // Удаляем созданное перо 

	int i = 0;
	cin >> i;
}

int  HomeWork_4_Work_6_Get_Number_From_Roman_Dictionary(char roman_Number)
{
	if (roman_Number == 'I')
		return 1;
	if (roman_Number == 'V')
		return 5;
	if (roman_Number == 'X')
		return 10;
	if (roman_Number == 'L')
		return 50;
	if (roman_Number == 'C')
		return 100;
	if (roman_Number == 'D')
		return 500;
	if (roman_Number == 'M')
		return 1000;

	return -1;
}

void HomeWork_4_Work_6()
{
	cout << "6) Задача «Автоматный распознаватель». Декодировать римскую запись числа, состоящего из любого количества знаков.Правила: I-1, V-5, X-10, L-50, C-100, D-500, M-1000.Значение римской цифры не зависит от позиции, а знак –- зависит.\n";

	string roman_Numbers = "";

	bool correctRomanNumber = false;
	char lastSymbol = '0';
	int counter = 1;

	do
	{
		cout << "Введите римское число: ";
		cin >> roman_Numbers;

		for (auto symvol : roman_Numbers)
		{
			if (HomeWork_4_Work_6_Get_Number_From_Roman_Dictionary(symvol) == -1)
			{
				lastSymbol = '0';
				break;
			}

			if (lastSymbol == symvol)
				counter++;

			lastSymbol = symvol;
		}

		if (counter > 3 || lastSymbol == '0')
			cout << "Введено неверное римское число. Повторите попытку." << '\n';
		else
			correctRomanNumber = true;

		cin.clear();
		cin.ignore(UINT_MAX, '\n');

		counter = 0;

	} while (correctRomanNumber == false);

	// Количество римских символов в строке
	int roman_Numbers_Count = roman_Numbers.length();
	// Получаю id самого последнего римского символа в тексте
	int roman_Numbers_Char_Array_Counter = roman_Numbers_Count - 1;
	// Предыдущая римская цифра, переведённая в 10-ричную систему счисления
	int roman_Number = 0;
	// Следующая римская цифра, которая стоит слева от roman_Number. Напоминаю, считывание строки происходит справа на лево.
	int next_Roman_Number = 0;
	// Максимально возможное кол-во совпадений римских чисел, к примеру VIII существует, а VIIII не существует, т.к число I повторилось больше 3 раз, а так нельзя.
	int roman_Number_Equalities_Possible = 3;
	// Переменная хранит количество римских чисел, которые повтаряются справо на лево при чтении строки посимвольно, максимально может быть 3 совпадения, не больше!
	int roman_Number_Equalities_Possible_Counter = 0;

	// Переменная, в которую я записываю финальное число в 10-ричной системе счисления
	int roman_Final_Number = 0;


	for (; roman_Numbers_Char_Array_Counter >= 0; roman_Numbers_Char_Array_Counter--)
	{
		// Находит предыдущую римскую цифру, если она оказалась 0, то есть не записана была
		if (roman_Number == 0)
		{
			// Получаю из словаря римское число, переведённое в 10-ричную систему счисления
			roman_Number = HomeWork_4_Work_6_Get_Number_From_Roman_Dictionary(roman_Numbers[roman_Numbers_Char_Array_Counter]);
			// Прибавляю 1,т.к я предполагаю, что следующий римское число ( next_Roman_Number ) будет равено нашему предыдущему римскому числу ( roman_Number ).
			roman_Number_Equalities_Possible_Counter++;
			// Добавляю римскую цифру в ( 10-ричной сис.счисл. ) в финальное число
			roman_Final_Number += roman_Number;
			continue;
		}

		// Нахожу следующее римское число, так же с помощью словаря
		next_Roman_Number = HomeWork_4_Work_6_Get_Number_From_Roman_Dictionary(roman_Numbers[roman_Numbers_Char_Array_Counter]);

		// Проверяет на совпадение предыдущего и следующего римского символа
		if (next_Roman_Number == roman_Number)
		{
			// Если предыдущий и следующий римский символ совпал, то сохраняет этот случай совпадения в кол-во всех совпадений
			roman_Number_Equalities_Possible_Counter++;

			// Добавляю римскую цифру в ( 10-ричной сис.счисл. ) в финальное число
			roman_Final_Number += next_Roman_Number;
			// Предыдущая значение римского символа становиться равно текущему значению римского символа, всё уже переведено в ( 10-сист.счисл )
			roman_Number = next_Roman_Number;
		}

		// Проверяет, является ли следующее значение римской цифры с предыдущей
		if (next_Roman_Number > roman_Number)
		{
			// Если следующее значение римской цифры больше предыдущей, то добавляет это число в финальное число перевода
			roman_Final_Number += next_Roman_Number;
			// Обнулает счётчит совпадений римских цифр
			roman_Number_Equalities_Possible_Counter = 0;
		}

		if (next_Roman_Number - roman_Number < 0)
		{
			cout << "Неверно введено римское число\n";
			return;
		}

		if (next_Roman_Number < roman_Number)
		{
			// Если следующее значение римской цифры меньше предыдущей, то вычитает это число из финального числа перевода
			roman_Final_Number -= next_Roman_Number;
			// Обнулает счётчит совпадений римских цифр
			roman_Number_Equalities_Possible_Counter = 0;
		}

		// Если счётчик совпадений равен 0, то мы специально обнуляем предыдущее число, чтобы оно больше не считалось дальше, это делается для того,
		// чтобы мы не записывали дважы предыдущее число при подсчёте. К примеру в XVII, VII мы уже посчитали как 8, а следующее
		// число  будет X. Нам ненужно, чтобы предыдущим римским числом было V, поэтому мы обнуляем предыдущий, иначе перевод будет неправильный
		if (roman_Number_Equalities_Possible_Counter == 0)
			roman_Number = 0;
		else
			roman_Number = next_Roman_Number;
	}

	cout << "Переведённое число: " << roman_Final_Number << '\n';

}

void HomeWork_4_Work_7_While(int Si = 0, int counter = 0, int m = 0, int i = 0, int c = 0)
{
	int next_Si = 0;

	while (i > counter)
	{
		next_Si = (m * Si + counter) % c;
		Si = next_Si;
		counter++;
	}

	cout << Si << '\n';
	return;

}

void HomeWork_4_Work_7()
{
	cout << "7) Задача «Генератор псевдослучайных чисел». Построить генератор псевдослучайных чисел по рекуррентной формуле: si + 1 = (msi + i) mod c, где m, i, c – целые числа.I вариант : m = 37, i = 3, c = 64. II вариант : m = 25173, i = 13849, c = 65537. Начальное значение s0 = 0.\n";
	cout << "I Вариант: "; HomeWork_4_Work_7_While(0, 0, 37, 3, 64);
	cout << "II Вариант: "; HomeWork_4_Work_7_While(0, 0, 25173, 13849, 65537);
}

void HomeWork_4_Work_8()
{
	cout << "8) Задача «Умножение матриц». Три продавца продают 4 вида товаров. Количество продаваемого товара представлено таблицей A.В таблице B представлены цена каждого товара и комиссионные, полученные от продажи, Задать соответствующие таблицам матрицы A и B, получить матрицу C = AхB и определить: 1) какой продавец выручил больше всего денег с продажи, какой – меньше; 2) какой получил наибольшие комиссионные, какой – наименьшие; 3) чему равна общая сумма денег, вырученных за проданные товары; 4) сколько всего комиссионных получили продавцы; 5) чему равна общая сумма денег, прошедших через руки продавцов?\n";

	// Обьявляю массив\матрицу с 3 строками и 4 столбцами
	int table_A[3][4] =
	{
		{5,2,0,10},
		{3,5,2,5},
		{20,0,0,0}
	};

	// Обьявляю массив\матрицу с 4 строками и 2 столбцами
	float table_B[4][2] =
	{
		{1.20,0.50},
		{2.80,0.40},
		{5.00,1.00},
		{2.00,1.50}
	};

	// Обьявляю массив\матрицу с 3 строками и 2 столбцами
	float table_C[3][2] =
	{
		{0,0},
		{0,0},
		{0,0}
	};

	float all_Money = 0;
	float all_Comission = 0;
	float all_Money_And_Comission = 0;
	float max_Money[2] = { 0 };
	float max_Comission[2] = { 0 };
	float min_Money[2] = { 100 };
	float min_Comission[2] = { 100 };

	// Переменная, которая будет хранить подсчитанный элемент при перемножении матриц по этапно

	// Произвожу перемножение ( table_A ) на ( table_B ) и получаю матрицу ( talbe_C ) с уже вычисленными элементами
	for (int table_A_Line = 0; table_A_Line <= 2; table_A_Line++)
	{
		// Возвращаюсь в матрицу ( table_B ) к первому столбцу, подготавливая к вычислениям
		int table_B_Column = 0;
		// Очищаю буффер для записи вычислений
		float table_Element = 0;

		// Перемножаю матрицы
		for (int table_A_Column = 0; table_A_Column <= 3; table_A_Column++)
		{
			// Произвожу сложение полученных произведений эелементов строки ( table_A ) на элементы столбца ( table_B )
			table_Element += table_A[table_A_Line][table_A_Column] * table_B[table_A_Column][table_B_Column];

			// Перехожу на каждый последующий столбец матрицы ( table_B ) для выполнения вычислений до тех пор, пока в матрице ( table_B ) не закончатся столбики
			if (table_A_Column == 3)
			{
				// Записываю полученные вычисления в новую матрицу
				table_C[table_A_Line][table_B_Column] = table_Element;
				table_Element = 0;
				// Возвращаю в матрице ( table_A_Column ) к первому столбцу и строчки ( table_A_Line )
				table_A_Column = -1;
				// Переход на следующий столбец
				table_B_Column++;
			}
			if (table_B_Column == 2)
				break;
		}
	}

	//// Вывожу подсчитанное произведение матриц в консоль, то есть вывожу матрицу ( talbe_C )
	//for (int table_C_Line = 0; table_C_Line <= 2; table_C_Line++)
	//{
	//	for (int table_C_Column = 0; table_C_Column <= 1; table_C_Column++)
	//	{
	//		float element = table_C[table_C_Line][table_C_Column];
	//		cout << element << ' ';
	//	}
	//	cout << '\n';
	//}

	for (int counter = 0; counter <= 2; counter++)
	{
		float table_First_Column_Number = table_C[counter][0];
		float table_Second_Column_Number = table_C[counter][1];

		if (table_First_Column_Number > max_Money[0]) {
			max_Money[0] = table_First_Column_Number;
			max_Money[1] = counter + 1;
		}
		if (table_First_Column_Number < min_Money[0]) {
			min_Money[0] = table_First_Column_Number;
			min_Money[1] = counter + 1;
		}

		if (table_Second_Column_Number > max_Comission[0]) {
			max_Comission[0] = table_Second_Column_Number;
			max_Comission[1] = counter + 1;
		}
		if (table_Second_Column_Number < min_Comission[0]) {
			min_Comission[0] = table_Second_Column_Number;
			min_Comission[1] = counter + 1;
		}

		all_Money += table_First_Column_Number;
		all_Comission += table_Second_Column_Number;
		all_Money_And_Comission = all_Money + all_Comission;
	}
	cout << "1.Продавец: " << max_Money[1] << " выручил денег " << max_Money[0] << '\n';
	cout << "1.Продавец: " << min_Money[1] << " выручил денег " << min_Money[0] << '\n';
	cout << "2.Продавец: " << max_Comission[1] << " выручил денег " << max_Comission[0] << '\n';
	cout << "2.Продавец: " << min_Comission[1] << " выручил денег " << min_Comission[0] << '\n';
	cout << "3.Общая сумма денег: " << all_Money << '\n';
	cout << "4.Общая сумма комиссионных : " << all_Comission << '\n';
	cout << "5.Общая сумма денег, прошедшая через руки : " << all_Money_And_Comission << '\n';
}

void HomeWork_4_Work_9()
{
	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	string string_Numbers = "";
	int base_System = 10;
	int Target_System = 16;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;
	bool ThirdNumberIsCorrect = false;

	cout << "9) Задача «Системы счисления». Программа должна считывать с клавиатуры число, записанное в одной системе счисления, и выводить на экран это число в записи по другому основанию, например: исходное число – 112D, старое основание – 16, новое основание – 8, результат – 10455.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите строку, которую нужно перевести в другую систему счилсения: ";
			cin >> string_Numbers;
			firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите систему счисления, в которой находится число изначально: ";
			cin >> base_System;

			if (cin.fail() == false && base_System > 0 && base_System < 17)
				SecondNumberIsCorrect = true;
		}

		if (ThirdNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите систему счисления, в которую нужно перевести число: ";
			cin >> Target_System;

			if (cin.fail() == false && Target_System > 0 && Target_System < 17)
				ThirdNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно изначальную систему счисления!\n";
			else if (ThirdNumberIsCorrect == false)
				cout << "Ошибка, вы ввели систему счисления, в которую нужно перевести число!\n";
		}
	} while (SecondNumberIsCorrect == false || ThirdNumberIsCorrect == false);

	// Переменная для конечного результата перевода из ( base_System ) в ( Target_System )
	string translated_number_To_Target_System = "";

	// Пометка ввиде bool операции, если число отрицательное, то есть имеет один минус.
	bool negativeNumber = false;
	// Пометка ввиде bool операции, если число дробное, то есть имеет одну точку.
	bool floatNumber = false;

	// Id символа (по идее точки) разделения целого числа и дробного числа в ( string_Numbers )
	int separate_Char_Id = 0;

	// Проверяю введёное число в строке на точку и минус
	// Если число отрицательное, то negativeNumber = true
	// Если число дробное, то floatNumber = true
	// Если точка повториться либо же минус, то метод выдаст -1
	for (int elementId = 0; elementId < string_Numbers.length(); elementId++)
	{
		char element = string_Numbers[elementId];

		if (element == '-')
			if (negativeNumber == true)
				return;
			else
			{
				negativeNumber = true;
				// Заменяю знак минуса на незначащий ноль, чтобы в вычислении не мешался
				string_Numbers[0] = '0';
			}

		if (element == '.')
			if (floatNumber == true)
				return;
			else
			{
				floatNumber = true;
				separate_Char_Id = elementId;
			}
	}

	// Переменная для запоминания целой части переведённого числа string_Numbers по основанию ( base_System ) в систему счиления 10
	int integer_Numbers_In_System_Ten = 0;
	// Переменная для запоминания дробной части переведённого числа string_Numbers по основанию ( base_System ) в систему счиления 10
	float float_Numbers_In_System_Ten = 0;

	// 1.Перевожу число string_Numbers в 10-ричную систему счисления с помощью метода полинома
	// 2.Перевожу целое число ( integer_Numbers_In_System_Ten ) в систему счисления ( Target_System ) полиномом
	// 3.Перевожу дрробное число ( float_Numbers_In_System_Ten ) в систему счисления ( Target_System ) полиномом
	if (floatNumber == true)
	{
		// Перевожу целую часть в 10-ричную систему счисления
		for (int counter = separate_Char_Id - 1; counter >= 0; counter--)
		{
			// Символ из строки ( string_Numbers )
			char element = string_Numbers[counter];

			// Получаю число из буквы, если система счисления больше 10-ричной
			// Если система счисления не использует буквы, то получаю из символа цифру
			if (element > 58)								   // Выравниваю counter так, чтобы число base_System возводилось в степень 0..1..2 и т.д
				integer_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, (separate_Char_Id - 1) - counter);
			else											   // Выравниваю counter так, чтобы число base_System возводилось в степень 0..1..2 и т.д
				integer_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, (separate_Char_Id - 1) - counter);
		}

		// Перевожу дробную часть в 10-ричную систему счисления
		for (int counter = separate_Char_Id + 1; counter < string_Numbers.length(); counter++)
		{
			// Символ из строки ( string_Numbers )
			char element = string_Numbers[counter];

			// Получаю число из буквы, если система счисления больше 10-ричной
			// Если система счисления не использует буквы, то получаю из символа цифру
			if (element > 58)                                  // Выравниваю counter так, чтобы число base_System возводилось в степень -1..-2..-3 и т.д
				float_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, -(counter - separate_Char_Id));
			else											   // Выравниваю counter так, чтобы число base_System возводилось в степень -1..-2..-3 и т.д
				float_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, -(counter - separate_Char_Id));
		}

		// Переменные будут хранить деление с остатком на ( Target_System )
		int integer_Delimoe = integer_Numbers_In_System_Ten;
		int integer_Delimoe_Buffer = 0;

		// Переведу целую часть из 10-ричной системы счисления в ( Target_System )
		do
		{
			integer_Delimoe_Buffer = integer_Delimoe % Target_System;

			// Проверяем и по возможности заменяе числа, которые больше 9-ти, в системе счисления не меньше 11-ричной включительно
			if (integer_Delimoe_Buffer > 9)
				translated_number_To_Target_System = char(integer_Delimoe_Buffer + 55) + translated_number_To_Target_System;
			else
				translated_number_To_Target_System = to_string(integer_Delimoe_Buffer) + translated_number_To_Target_System;

			integer_Delimoe = integer_Delimoe / Target_System;

		} while (int(integer_Delimoe) != 0);

		// Добавляю разделительный знак для дальнейшего добавления дробной части
		translated_number_To_Target_System += ".";

		float float_Delimoe = float_Numbers_In_System_Ten;
		float float_Delimoe_Buffer = 0;

		// Переведу дробную часть из 10-ричной системы счисления в ( Target_System )
		do
		{
			float_Delimoe_Buffer = float_Delimoe * Target_System;

			// Проверяем и по возможности заменяе числа, которые больше 9-ти, в системе счисления не меньше 11-ричной включительно
			if (int(float_Delimoe_Buffer) > 9)
				translated_number_To_Target_System += char(int(float_Delimoe_Buffer) + 55);
			else
				translated_number_To_Target_System += to_string(int(float_Delimoe_Buffer));

			// По правилу перевода дробного числа из 10-ричной в любую систему счисления у нас целая часть забирается
			float_Delimoe = float_Delimoe_Buffer - int(float_Delimoe_Buffer);

		} while (float_Delimoe > 0);
	}
	else
	{
		// Перевожу целую часть в 10-ричную систему счисления
		for (int counter = string_Numbers.length() - 1; counter >= 0; counter--)
		{
			// Символ из строки ( string_Numbers )
			char element = string_Numbers[counter];

			// Получаю число из буквы, если система счисления больше 10-ричной
			// Если система счисления не использует буквы, то получаю из символа цифру
			if (element > 58)								   // Выравниваю counter так, чтобы число base_System возводилось в степень 0..1..2 и т.д
				integer_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, (string_Numbers.length() - 1) - counter);
			else											   // Выравниваю counter так, чтобы число base_System возводилось в степень 0..1..2 и т.д
				integer_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, (string_Numbers.length() - 1) - counter);
		}

		// Переменные будут хранить деление с остатком на ( Target_System )
		int integer_Delimoe = integer_Numbers_In_System_Ten;
		int integer_Delimoe_Buffer = 0;

		// Переведу целую часть из 10-ричной системы счисления в ( Target_System )
		do
		{
			integer_Delimoe_Buffer = integer_Delimoe % Target_System;

			// Проверяем и по возможности заменяе числа, которые больше 9-ти, в системе счисления не меньше 11-ричной включительно
			if (integer_Delimoe_Buffer > 9)
				translated_number_To_Target_System = char(integer_Delimoe_Buffer + 55) + translated_number_To_Target_System;
			else
				translated_number_To_Target_System = to_string(integer_Delimoe_Buffer) + translated_number_To_Target_System;

			integer_Delimoe = integer_Delimoe / Target_System;

		} while (int(integer_Delimoe) != 0);
	}


	if (negativeNumber)
		cout << '-' << translated_number_To_Target_System;
	else
		cout << translated_number_To_Target_System;
}


void HomeWork_5_Work_1()
{
	bool correctNumbers = false;
	int firstNumber = 0;
	int secondNumber = 0;
	int result = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;

	cout << "1) Задание «Алгоритм Евклида». Задать 2 числа и найти их наибольший общий делитель двумя способами: делением и вычитанием.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первое число: ";
			cin >> firstNumber;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите второе число: ";
			cin >> secondNumber;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильное первое число!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно второе число число!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

	int first_Buffer = firstNumber;
	int second_Buffer = secondNumber;

	cout << "Наибольший общий делитель чисел через метод деления " << first_Buffer << " и " << second_Buffer << ": ";

	while (firstNumber != 0 && secondNumber != 0)
	{
		if (firstNumber > secondNumber)
			firstNumber = firstNumber % secondNumber;
		else
			secondNumber = secondNumber % firstNumber;
	};
	cout << firstNumber + secondNumber << '\n';

	firstNumber = first_Buffer;
	secondNumber = second_Buffer;

	cout << "Наибольший общий делитель чисел через метод вычитания " << first_Buffer << " и " << second_Buffer << ": ";

	while (firstNumber != secondNumber)
	{
		if (firstNumber > secondNumber)
			firstNumber = firstNumber - secondNumber;
		else
			secondNumber = secondNumber - firstNumber;
	};
	cout << firstNumber << '\n';
}

void HomeWork_5_Work_2()
{
	cout << "2) Задание «Решето Эратосфена». Найти все простые числа в диапазоне от 2 до введенного вами натурального числа.\n";

	bool correctNumber = false;
	int number = 2;

	while (correctNumber == false)
	{
		cout << "Введите до какого числа искать простые числа: ";
		cin >> number;

		if (cin.fail() || correctNumber < 0)
		{
			cin.clear();
			cin.ignore(UINT_MAX, '\n');
			cout << "Вы ввели неправильный диапазон, он начинаеться с 0\n";
		}
		else
			correctNumber = true;
	}

	int* numbersArray = new int[number];
	int numberInArray = 0;

	for (int i = 0; i < number + 1; i++)
		numbersArray[i] = i;

	for (int i = 2; i < number + 1; i++)
	{
		numberInArray = numbersArray[i];

		if (numberInArray != 0)
		{
			cout << numberInArray << endl;

			for (int j = i * i; j < number + 1; j += i)
				numbersArray[j] = 0;
		}
	}
}

void HomeWork_5_Work_3_number8()
{
	cout << "4) 8.Преобразование текста в цепочку ASCII-кодов.\n";

	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string fileName = "Preparing.txt";
	string textInput = "";
	string textOutput = "";

	cout << "Введите любую строку: ";
	getline(cin, textInput);

	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << textInput;
	outputFile.close();

	ifstream inputFile;
	inputFile.open(fileName);
	getline(inputFile, textOutput);
	inputFile.close();

	for (auto symbol : textOutput)
	{
		cout << ' ' << int(symbol) << ' ';
	}
}

void HomeWork_5_Work_3_number4()
{
	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	cout << "3) 4.Поиск в тексте слова максимальной длины.\n";

	string fileName = "Preparing.txt";
	string textInput = "";
	string textOutput = "";
	string constructedWord = "";
	string longestWord = "";

	cout << "Введите любую строку: ";
	getline(cin, textInput);

	ofstream outputFile;
	outputFile.open(fileName);
	outputFile << textInput;
	outputFile.close();

	ifstream inputFile;
	inputFile.open(fileName);
	getline(inputFile, textOutput);
	inputFile.close();

	for (auto symbol : textOutput)
	{
		if (symbol == ' ')
		{
			if (constructedWord.length() > longestWord.length())
				longestWord = constructedWord;
			constructedWord = "";
		}
		else
			constructedWord += symbol;
	}
	cout << "Длиннейшее слово в тексте: " << longestWord << " длиной: " << longestWord.length() << '\n';
}

void HomeWork_5_Work_4_number18()
{
	cout << "5) 18.Написать программу, которая определяет количество учеников в классе, чей рост превышает средний. Рекомендуемый вид экрана во время работы программы приведен ниже(введенные пользователем данные выделены полужирным шрифтом).\n";

	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	bool NumberZeroWasFound = false;
	int height = 0;
	int avarage = 0;
	int peoplehigherAvarage = 0;

	vector<int> arrayOfheight;

	cout << " **** Анализ роста учеников ***\n" <<
		"Введите рост(см) и нажмите <Enter>.\n" <<
		"Для завершения введите 0 и нажмите < Enter>\n";

	do
	{
		cout << "-> ";
		cin >> height;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before, preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "\nНе вводите символы!" << '\n';
		}
		else
		{
			if (height == 0)
				NumberZeroWasFound = true;
			else
				arrayOfheight.push_back(height);
		}
	} while (NumberZeroWasFound == false);

	for (auto number : arrayOfheight) {
		avarage += number;
	}

	avarage /= arrayOfheight.size();

	for (auto number : arrayOfheight) {
		if (number > avarage)
			peoplehigherAvarage++;
	}

	cout << "Средний рост: " << avarage << '\n';
	cout << "У " << peoplehigherAvarage << "-x человек рост превышает средний." << avarage;
}

void HomeWork_5_Work_4_number32()
{
	cout << "6) 32.Дано натуральное число x. Выбросить из записи числа х цифры 0 и 5, оставив прежним порядок остальных цифр. Например, из числа 590155069 должно получиться 9169.\n";

	cin.clear();
	cin.ignore(UINT_MAX, '\n');

	bool numberWasCorrect = false;
	unsigned long long number = 0;

	do
	{
		cout << "Введите натуральное число: ";
		cin >> number;

		if (cin.fail() || number < 0)
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before, preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "Введённое число слишком большое либо не число вовсе!" << '\n';
		}
		else
		{
			if (number > 0)
				numberWasCorrect = true;
		}
	} while (numberWasCorrect == false);

	for (auto symbol : to_string(number)) {
		if (symbol == '5')
			continue;

		if (symbol == '0')
			continue;

		cout << symbol;
	}
	cout << '\n';
}


class CountryData
{
public:
	string countryName;
	int gold;
	int silver;
	int bronze;
	int points;
};

void HomeWork_5_Work_5_number21()
{
	cout << "7) 21.Написать программу подведения итогов Олимпийских игр.\n";

	bool correctInput = false;
	int Gold = 0;
	int Silver = 0;
	int Bronze = 0;

	vector<CountryData> countries;
	vector<CountryData> sortedCountries;
	vector<string> countriesNames =
	{
		"Австрия",
		"Германия",
		"Канада",
		"Китай",
		"Корея",
		"Норвегия",
		"Россия",
		"США",
		"Финляндия",
		"Япония"
	};

	cout << "Введите медали стран (Золото, серебро, бронза)\n";

	for (auto countryName : countriesNames)
	{
		correctInput = false;
		do
		{
			cout << countryName << "-> ";
			cin >> Gold >> Silver >> Bronze;

			if (cin.fail())
			{
				// Unlocking cin from (translate char to int) error
				cin.clear();
				// Ignoring all data in cin buffer before, preparing for new input from console
				cin.ignore(UINT_MAX, '\n');

				cout << "Не вводите символы!" << '\n';
			}
			else
				correctInput = true;

		} while (correctInput == false);

		int points = Gold * 7 + Silver * 6 + Bronze * 5;

		CountryData countryData{ countryName,Gold, Silver, Bronze, points };
		countries.push_back(countryData);
	}

	CountryData countryBuffer;

	while (countries.size() > 0) {
		for (int countryId = 0; countryId <= countries.size() - 1; countryId++)
		{
			if (countries[countryId].points > countries[countries.size() - 1].points)
			{
				countryBuffer = countries[countries.size() - 1];
				countries[countries.size() - 1] = countries[countryId];
				countries[countryId] = countryBuffer;
			}
		}

		sortedCountries.push_back(countries[countries.size() - 1]);
		countries.pop_back();
	}

	ofstream outputFile;
	outputFile.open("Страны.txt");
	for (auto country : sortedCountries)
	{
		outputFile << country.countryName << " " << country.gold << " " << country.silver << " " << country.bronze << " " << country.points << "\n";
	}

	cout << "Данные были выведены в файл Страны.txt там же где и консоль.";

	outputFile.close();
}


void HomeWork_1_CoutWorkNames() {
	cout << "1) Задание «Имя»\n";
	cout << "2) Задание «Арифметика»\n";
	cout << "3) Задание «Уравнение»\n";
	cout << "4) Задание «Еще уравнение»\n";
	cout << "5) Задание «Лампа со шторой»\n";
}

void HomeWork_2_CoutWorkNames() {
	cout << "1) Задача «Конус». Вычислить объем и полную поверхность усеченного конуса:\n";
	cout << "2) Для произвольных x и a вычислить\nw = : \na * ln |x|, |x|<1 при |x| < 1;\nsqrt(a - x^2), |x|>=1;\n";
	cout << "3) Для произвольных x, y и b вычислить функцию z = log(b - y) * sqrt(b - x);\n";
	cout << "4) Распечатать 10 последовательных натуральных чисел в возрастающем порядке, начиная с произвольного числа N.\n";
	cout << "5) Протабулировать функцию\n";
}

void HomeWork_3_CoutWorkNames() {
	cout << "1) Задача «Заем». Месячная выплата m по займу в S рублей на n лет под процент p вычисляется по формуле.\n";
	cout << "2) Задача «Ссуда». Под какой процент p выдана ссуда величиной S рублей, которая гасится месячными выплатами величиной m в течение n лет.Формула приведена в предыдущей задаче.\n";
	cout << "3) Задача «Копирование файла». Создать на диске текстовый файл и скопировать его на экран.\n";
	cout << "4) Задача «Фильтр». Вывести на экран только числа из созданного Вами на диске текстового файла, содержащего буквы и числа.\n";
	cout << "5) Задача «Сортировка букв». Задать строку из 30 букв и расставить их в алфавитном порядке.\n";
}

void HomeWork_4_CoutWorkNames() {
	cout << "1) Задача «Файл». Создать файл, записать в него 10 чисел, закрыть, потом вновь открыть файл и найти сумму чисел.\n";
	cout << "2) Задача «Знак числа». Определить знак введенного с клавиатуры числа, использовав подпрограмму-функцию.\n";
	cout << "3) Задача «Геометрические фигуры». Вычислить площади прямоугольника, треугольника, круга, используя подпрограммы - функции.\n";
	cout << "4) Задача «Былая слава». В 1912 году американский флаг «Былая слава» имел 48 звезд (по одной на каждый штат) и 13 полос(по одной на колонию).Напечатать «Былую славу 1912 года».\n";
	cout << "5) Задача «Синусоида». Напечатать график функции у = sin x.\n";
	cout << "6) Задача «Автоматный распознаватель». Декодировать римскую запись числа, состоящего из любого количества знаков.Правила: I-1, V-5, X-10, L-50, C-100, D-500, M-1000.Значение римской цифры не зависит от позиции, а знак –- зависит.\n";
	cout << "7) Задача «Генератор псевдослучайных чисел». Построить генератор псевдослучайных чисел по рекуррентной формуле: si + 1 = (msi + i) mod c, где m, i, c – целые числа.I вариант : m = 37, i = 3, c = 64. II вариант : m = 25173, i = 13849, c = 65537. Начальное значение s0 = 0.\n";
	cout << "8) Задача «Умножение матриц». Три продавца продают 4 вида товаров. Количество продаваемого товара представлено таблицей A.В таблице B представлены цена каждого товара и комиссионные, полученные от продажи, Задать соответствующие таблицам матрицы A и B, получить матрицу C = AхB и определить: 1) какой продавец выручил больше всего денег с продажи, какой – меньше; 2) какой получил наибольшие комиссионные, какой – наименьшие; 3) чему равна общая сумма денег, вырученных за проданные товары; 4) сколько всего комиссионных получили продавцы; 5) чему равна общая сумма денег, прошедших через руки продавцов?\n";
	cout << "9) Задача «Системы счисления». Программа должна считывать с клавиатуры число, записанное в одной системе счисления, и выводить на экран это число в записи по другому основанию, например: исходное число – 112D, старое основание – 16, новое основание – 8, результат – 10455.\n";
}

void HomeWork_5_CoutWorkNames() {
	cout << "1) Задание «Алгоритм Евклида». Задать 2 числа и найти их наибольший общий делитель двумя способами: делением и вычитанием.\n";
	cout << "2) Задание «Решето Эратосфена». Найти все простые числа в диапазоне от 2 до введенного вами натурального числа.\n";
	cout << "3) 4.Поиск в тексте слова максимальной длины.\n";
	cout << "4) 8.Преобразование текста в цепочку ASCII-кодов.\n";
	cout << "Задание «Ряды». Выполнить два варианта задания\n";
	cout << "5) 18.Написать программу, которая определяет количество учеников в классе, чей рост превышает средний. Рекомендуемый вид экрана во время работы программы приведен ниже(введенные пользователем данные выделены полужирным шрифтом).\n";
	cout << "6) 32.Дано натуральное число x. Выбросить из записи числа х цифры 0 и 5, оставив прежним порядок остальных цифр. Например, из числа 590155069 должно получиться 9169.\n";
	cout << "Задание «Файлы». Выполнить один вариант задания\n";
	cout << "7) 21.Написать программу подведения итогов Олимпийских игр.\n";
}

void HomeWork_1_ShowWork() {

	int workNumber = 1;
	bool isWorkNumberCorrect = false;

	while (isWorkNumberCorrect == false) {

		isWorkNumberCorrect = true;
		cout << "Какую работу вы хотите проверить: ";
		cin >> workNumber;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "Вы ввели символ вместо номера, ошибка!\n" << '\n';
			isWorkNumberCorrect = false;
			continue;
		}

		switch (workNumber)
		{
		case 1:
			HomeWork_1_Work_1();
			break;
		case 2:
			HomeWork_1_Work_2();
			break;
		case 3:
			HomeWork_1_Work_3();
			break;
		case 4:
			HomeWork_1_Work_4();
			break;
		case 5:
			HomeWork_1_Work_5();
			break;

		default:
			isWorkNumberCorrect = false;
			break;
		}
		if (isWorkNumberCorrect == true)
			break;
	}
}

void HomeWork_2_ShowWork() {

	int workNumber = 1;
	bool isWorkNumberCorrect = false;

	while (isWorkNumberCorrect == false) {

		isWorkNumberCorrect = true;
		cout << "Какую работу вы хотите проверить: ";
		cin >> workNumber;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "Вы ввели символ вместо номера, ошибка!\n";
			isWorkNumberCorrect = false;
			continue;
		}

		switch (workNumber)
		{
		case 1:
			HomeWork_2_Work_1();
			break;
		case 2:
			HomeWork_2_Work_2();
			break;
		case 3:
			HomeWork_2_Work_3();
			break;
		case 4:
			HomeWork_2_Work_4();
			break;
		case 5:
			HomeWork_2_Work_5();
			break;

		default:
			isWorkNumberCorrect = false;
			break;
		}
		if (isWorkNumberCorrect == true)
			break;
	}
}

void HomeWork_3_ShowWork() {

	int workNumber = 1;
	bool isWorkNumberCorrect = false;

	while (isWorkNumberCorrect == false) {

		isWorkNumberCorrect = true;
		cout << "Какую работу вы хотите проверить: ";
		cin >> workNumber;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "Вы ввели символ вместо номера, ошибка!\n";
			isWorkNumberCorrect = false;
			continue;
		}


		switch (workNumber)
		{
		case 1:
			HomeWork_3_Work_1();
			break;
		case 2:
			HomeWork_3_Work_2();
			break;
		case 3:
			HomeWork_3_Work_3();
			break;
		case 4:
			HomeWork_3_Work_4();
			break;
		case 5:
			HomeWork_3_Work_5();
			break;

		default:
			isWorkNumberCorrect = false;
			break;
		}
		if (isWorkNumberCorrect == true)
			break;
	}
}

void HomeWork_4_ShowWork() {

	int workNumber = 1;
	bool isWorkNumberCorrect = false;

	while (isWorkNumberCorrect == false) {
		isWorkNumberCorrect = true;
		cout << "Какую работу вы хотите проверить: ";
		cin >> workNumber;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "Вы ввели символ вместо номера, ошибка!\n";
			isWorkNumberCorrect = false;
			continue;
		}

		switch (workNumber)
		{
		case 1:
			HomeWork_4_Work_1();
			break;
		case 2:
			HomeWork_4_Work_2();
			break;
		case 3:
			HomeWork_4_Work_3();
			break;
		case 4:
			HomeWork_4_Work_4();
			break;
		case 5:
			HomeWork_4_Work_5();
			break;
		case 6:
			HomeWork_4_Work_6();
			break;
		case 7:
			HomeWork_4_Work_7();
			break;
		case 8:
			HomeWork_4_Work_8();
			break;
		case 9:
			HomeWork_4_Work_9();
			break;

		default:
			isWorkNumberCorrect = false;
			break;
		}
		if (isWorkNumberCorrect == true)
			break;
	}
}

void HomeWork_5_ShowWork() {

	int workNumber = 1;
	bool isWorkNumberCorrect = false;

	while (isWorkNumberCorrect == false) {
		isWorkNumberCorrect = true;
		cout << "Какую работу вы хотите проверить: ";
		cin >> workNumber;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "Вы ввели символ вместо номера, ошибка!\n";
			isWorkNumberCorrect = false;
			continue;
		}

		switch (workNumber)
		{
		case 1:
			HomeWork_5_Work_1();
			break;
		case 2:
			HomeWork_5_Work_2();
			break;
		case 3:
			HomeWork_5_Work_3_number4();
			break;
		case 4:
			HomeWork_5_Work_3_number8();
			break;
		case 5:
			HomeWork_5_Work_4_number18();
			break;
		case 6:
			HomeWork_5_Work_4_number32();
			break;
		case 7:
			HomeWork_5_Work_5_number21();
			break;

		default:
			isWorkNumberCorrect = false;
			break;
		}
		if (isWorkNumberCorrect == true)
			break;
	}
}

void HomeWork_ShowWorks()
{
	int homeWorkNumber = 1;
	bool isWorkNumberCorrect = false;

	cout << "1)Домашнее задание № 1\n2)Домашнее задание № 2\n3)Домашнее задание № 3\n4)Домашнее задание № 4\n5)Домашнее задание № 5\n";

	while (isWorkNumberCorrect == false) {

		isWorkNumberCorrect = true;
		cout << "Какой номер домашней работы вы хотите проверить: ";
		cin >> homeWorkNumber;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "Вы ввели символ вместо номера, ошибка!\n";
			isWorkNumberCorrect = false;
			continue;
		}

		switch (homeWorkNumber)
		{
		case 1:
			HomeWork_1_CoutWorkNames();
			HomeWork_1_ShowWork();
			break;
		case 2:
			HomeWork_2_CoutWorkNames();
			HomeWork_2_ShowWork();
			break;
		case 3:
			HomeWork_3_CoutWorkNames();
			HomeWork_3_ShowWork();
			break;
		case 4:
			HomeWork_4_CoutWorkNames();
			HomeWork_4_ShowWork();
			break;
		case 5:
			HomeWork_5_CoutWorkNames();
			HomeWork_5_ShowWork();
			break;

		default:
			isWorkNumberCorrect = false;
			break;
		}
		if (isWorkNumberCorrect == true)
			break;
	}
}

unsigned factorial(unsigned n) {
	static vector<unsigned> factorialList;

	if (factorialList.size() < n + 1) {
		factorialList.resize(n + 1, 0);
	}

	if (factorialList[n] == 0) {
		factorialList[n] = ((n > 1) ? n * factorial(n - 1) : 1);
	}

	return factorialList[n];
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ios::sync_with_stdio(false);
	setlocale(LC_CTYPE, "rus");

	HomeWork_ShowWorks();

	system("pause");
	return 0;
}
