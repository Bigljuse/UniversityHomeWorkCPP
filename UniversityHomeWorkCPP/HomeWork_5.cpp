#include <cstdio>
#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include <math.h>
#include<string>
#include <windows.h>

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
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before, preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "Не вводите символы!" << '\n';
			correctNumbers = false;
		}
		else
			correctNumbers = true;

	} while (correctNumbers == false);

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

void Work_2_Resheto_Eratosfena()
{
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

void Work_3_number18() 
{
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

void Work_3_number4()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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