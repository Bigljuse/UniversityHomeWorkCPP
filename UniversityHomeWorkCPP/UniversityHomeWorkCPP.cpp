#include <iostream>
#include <vector>
#include <cstdlib> 
#include <fstream>
#include <string>
#include <iomanip>
#include <thread>

using namespace std;

void Work_1()
{
	int borderLeft = 0;
	int BorderRight = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;

	cout << "1) Пифагорово число (пифагорова тройка)\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первое число: ";
			cin >> borderLeft;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите второе число: ";
			cin >> BorderRight;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(WINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в первую переменную не число!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели во вторую переменную не число!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

	if (borderLeft > BorderRight)
	{
		int tmp = borderLeft;
		borderLeft = BorderRight;
		BorderRight = tmp;
	}

	cout << "Пифагоровы тройки чисел от " << borderLeft << " до " << BorderRight << " включительно:\n";
	for (int i = borderLeft; i <= BorderRight; i++)
	{
		for (int j = borderLeft; j <= BorderRight; j++)
		{
			for (int k = borderLeft; k <= BorderRight; k++)
			{
				if (i * i + j * j == k * k)
					std::cout << "{" << i << "," << j << "," << k << "}\n";
			}
		}
	}

	return;
}

bool is_perfect(int num)
{
	int sum = 0;

	for (int j = 1; j < num; j++)
	{
		if (num % j == 0)
			sum += j;
	}

	if (sum == num)
		return true;

	return false;
}
void Work_2()
{
	int borderLeft = 0;
	int BorderRight = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;

	cout << "1) Совершенные числа\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первое число: ";
			cin >> borderLeft;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите второе число: ";
			cin >> BorderRight;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(WINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в первую переменную не число!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели во вторую переменную не число!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

	if (borderLeft > BorderRight)
	{
		int tmp = borderLeft;
		borderLeft = BorderRight;
		BorderRight = tmp;
	}

	for (int i = borderLeft; i < BorderRight; ++i) {
		if (is_perfect(i)) {
			cout << i << endl;
		}
	}
}

void Work_3()
{
	int borderLeft = 0;
	int BorderRight = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;
	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите первое число: ";
			cin >> borderLeft;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите второе число: ";
			cin >> BorderRight;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(WINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели в первую переменную не число!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели во вторую переменную не число!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

	if (borderLeft > BorderRight)
	{
		int tmp = borderLeft;
		borderLeft = BorderRight;
		BorderRight = tmp;
	}

	int s = 0;
	int o = 0;
	int m = 0;

	cout << "на интервале " << '[' << borderLeft << ',' << BorderRight << "] найдены ";

	for (int i = BorderRight; i > borderLeft; --i)
	{
		s = i * i;

		for (m = 10; m < i; m *= 10);

		o = s % m;

		if (i == o)
			cout << i << ", ";
	}
}

void Work_4()
{
	int number1 = 0;

	bool firstNumberIsCorrect = false;
	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите число фибоначчи: ";
			cin >> number1;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(WINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели не число!\n";
		}
	} while (firstNumberIsCorrect == false);


	int a = 0;
	int b = 1;

	for (int i = 0; i < number1; i++)
	{
		a = a + b;
		b = a - b;
	}

	cout << number1 << "-ое число Фибоначчи = " << a << '\n';
}

int get_digit_count(int const number)
{
	int digits = 0;
	int remainder = number;

	while (remainder > 0)
	{
		++digits;
		remainder /= 10;
	}

	return digits;
}

bool is_armstrong_number(int const number)
{
	int const digit_count = get_digit_count(number);
	int remainder = number;
	int sum = 0;

	while (remainder > 0)
	{
		int const last_digit = remainder % 10;
		sum += pow(last_digit, digit_count);
		remainder /= 10;
	}

	return number == sum;
}

void asyncCounter(long long const number1, int startNumberArg, int endNumberArg) {
	long long startNumber = pow(10, number1) / 10 * startNumberArg + 1;
	long long maxNumber = pow(10, number1) / 10 * endNumberArg;

	for (long long i = startNumber; i <= maxNumber; ++i)
	{
		if (is_armstrong_number(i))
			if (get_digit_count(i) == number1)
				cout << i << ' ';
	}
}

void Work_5()
{
	int number1 = 0;

	bool firstNumberIsCorrect = false;
	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите количество цифр в числе Армстронга: ";
			cin >> number1;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(WINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели не число!\n";
		}
	} while (firstNumberIsCorrect == false);

	if (number1 > 10)
	{
		cout << "Вы слишком долго будете ждать такого числа с " << number1 << "цифрами\n";
		return;
	}

	long long maxNumber = pow(10, number1);

	if (number1 >= 8)
	{
		thread func_thread1(asyncCounter, number1, 1, 2);
		thread func_thread2(asyncCounter, number1, 2, 3);
		thread func_thread3(asyncCounter, number1, 3, 4);
		thread func_thread4(asyncCounter, number1, 4, 5);
		thread func_thread5(asyncCounter, number1, 5, 6);
		thread func_thread6(asyncCounter, number1, 6, 7);
		thread func_thread7(asyncCounter, number1, 7, 8);
		thread func_thread8(asyncCounter, number1, 8, 9);
		thread func_thread9(asyncCounter, number1, 9, 10);

		maxNumber = maxNumber / 10;

		for (long long i = 0; i <= maxNumber; ++i)
		{
			if (is_armstrong_number(i))
				if (get_digit_count(i) == number1)
					cout << i << ' ';
		}
		func_thread1.join();
		func_thread2.join();
		func_thread3.join();
		func_thread4.join();
		func_thread5.join();
		func_thread6.join();
		func_thread7.join();
		func_thread8.join();
		func_thread9.join();
		cout << '\n';
	}
	else
	{
		for (int i = 0; i <= maxNumber; ++i)
		{
			if (is_armstrong_number(i))
				if (get_digit_count(i) == number1)
					cout << i << ' ';
		}

		cout << '\n';
	}
}

void HomeWork_ShowWorks()
{
	int homeWorkNumber = 1;
	bool isWorkNumberCorrect = false;

	cout << "1)Пифагоровы числа"
		<< "\n2)Совершенные числа"
		<< "\n3)Автоморфные числа"
		<< "\n4)Числа Фибоначчи"
		<< "\n5)Числа Армстронга (Внимание, используется многопоточность, ваш процессор может нагрется очень сильно при n >= 9!)"
		<< "\n6)Числа - близнецы"
		<< "\n7)Числа Софи Жермен"
		<< "\n8)Числа Каталана"
		<< "\n9)Числа Нараняны"
		<< "\n10)Числа Якобсталя\n";

	while (isWorkNumberCorrect == false) {

		isWorkNumberCorrect = true;
		cout << "Какой номер из Структурных чисел вы хотите проверить: ";
		cin >> homeWorkNumber;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(WINT_MAX, '\n');

			cout << "Вы ввели неверно номер, ошибка!\n";
			isWorkNumberCorrect = false;
			continue;
		}

		switch (homeWorkNumber)
		{
		case 1:
			Work_1();
			break;
		case 2:
			Work_2();
			break;
		case 3:
			Work_3();
			break;
		case 4:
			Work_4();
			break;
		case 5:
			Work_5();
			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;

		default:
			isWorkNumberCorrect = false;
			break;
		}
		if (isWorkNumberCorrect == true)
			break;
	}
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	Work_5();

	system("pause");
	return 0;
}
