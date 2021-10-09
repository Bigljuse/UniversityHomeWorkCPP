#include <cstdio>
#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include <math.h>
#include<string>
using namespace std;

void Work_1_Algoritm_Evklida()
{
	bool correctNumbers = false;
	int firstNumber = 0;
	int secondNumber = 0;
	int result = 0;

	do
	{
		cout << "Введите первое и второе число: ";
		cin >> firstNumber >> secondNumber;;

		if (cin.fail())
		{
			// Если в cin было подано не число, то для разблокировки потока необходимо разблокировать поток
			cin.clear();
			// После разблокировки потока идёт игнор уже неверно введённых данных в строке, посути мы очишаем для подготовки к новому вводу.
			cin.ignore(UINT_MAX,'\n');

			cout << "Не вводите символы!" << '\n';
			correctNumbers = false;
		}
		else
			correctNumbers = true;

	} while (correctNumbers == false);

	int first_Buffer = firstNumber;
	int second_Buffer = secondNumber;

	cout << "Наибольший общий делитель чисел через метод деления " << firstNumber << " и " << secondNumber << ": ";

	while (firstNumber != 0 && secondNumber != 0)
	{
		if (firstNumber > secondNumber)
			firstNumber = firstNumber % secondNumber;
		else
			secondNumber = secondNumber % firstNumber;
	};
	cout << firstNumber + secondNumber << '\n';

	 firstNumber  = first_Buffer;
	 secondNumber = second_Buffer;

	cout << "Наибольший общий делитель чисел через метод вычитания " << firstNumber << " и " << secondNumber << ": ";

	while (firstNumber != secondNumber)
	{
		if (firstNumber > secondNumber)
			firstNumber = firstNumber - secondNumber;
		else
			secondNumber = secondNumber - firstNumber;
	};
	cout << firstNumber << '\n';
}