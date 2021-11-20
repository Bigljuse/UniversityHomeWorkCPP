#include <cstdio>
#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include <math.h>
#include <string>
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
			cin.ignore(WINT_MAX, '\n');

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
			cin.ignore(WINT_MAX, '\n');
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

void Work_3_number8()
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

void Work_4_number18()
{
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
			cin.ignore(WINT_MAX, '\n');

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


void Work_4_number32()
{
	bool numberWasCorrect = false;
	int number = 0;

	do
	{
		cout << "Введите натуральное число: ";
		cin >> number;

		if (cin.fail() || number < 0)
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before, preparing for new input from console
			cin.ignore(WINT_MAX, '\n');

			cout << "\nНе вводите не натуральное число!" << '\n';
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

void Work_5_number21()
{
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
				cin.ignore(WINT_MAX, '\n');

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
		for (int countryId = 0; countryId <= countries.size() -1; countryId++)
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
	
	outputFile.close();
}