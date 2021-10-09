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
		cout << "������� ������ � ������ �����: ";
		cin >> firstNumber >> secondNumber;;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before, preparing for new input from console
			cin.ignore(UINT_MAX,'\n');

			cout << "�� ������� �������!" << '\n';
			correctNumbers = false;
		}
		else
			correctNumbers = true;

	} while (correctNumbers == false);

	int first_Buffer = firstNumber;
	int second_Buffer = secondNumber;

	cout << "���������� ����� �������� ����� ����� ����� ������� " << first_Buffer << " � " << second_Buffer << ": ";

	while (firstNumber != 0 && secondNumber != 0)
	{
		if (firstNumber > secondNumber)
			firstNumber = firstNumber % secondNumber;
		else
			secondNumber = secondNumber % firstNumber;
	};
	cout << firstNumber + secondNumber << '\n';

	cout << "���������� ����� �������� ����� ����� ����� ��������� " << first_Buffer << " � " << second_Buffer << ": ";

	while (firstNumber != secondNumber)
	{
		if (firstNumber > secondNumber)
			firstNumber = firstNumber - secondNumber;
		else
			secondNumber = secondNumber - firstNumber;
	};
	cout << firstNumber << '\n';
}