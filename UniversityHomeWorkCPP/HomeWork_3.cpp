#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include < windows.h >

using namespace std;

void Work_1() {
	unsigned int m = 0;
	unsigned int S = 0;
	double r = 0;
	double p = 0;
	double n = 0;

	double checkForZero = 0;

	cout << "Введите займ (S): " << '\n';
	if (cin >> S);
	else
	{
		cout << "Не вводите символы!" << '\n';
		return;
	}

	cout << "Введите займ по годам (n): " << '\n';
	if (cin >> n);
	else
	{
		cout << "Не вводите символы!" << '\n';
		return;
	}

	cout << "Введите процент(n): " << '\n';
	if (cin >> p);
	else
	{
		cout << "Не вводите символы!" << '\n';
		return;
	}

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


void  Work_2() {
	double monthyPayment = 0;
	double monthyPaymentCorrection = 0;
	double amountOfMoney = 0;
	double years = 0;

	int monthyPaymentCounted = 1;
	double percent = 1;

	cout << "Введите займ (S): " << '\n';
	if (cin >> amountOfMoney && amountOfMoney > 0);
	else
	{
		cout << "Ошибка, вы неправильно ввели займ." << '\n';
		return;
	}

	cout << "Введите ежемесячную выплату (m): " << '\n';
	if (cin >> monthyPayment && monthyPayment > 0);
	else
	{
		cout << "Ошибка, вы неправильно ввели ежемесячную выплату." << '\n';
		return;
	}

	cout << "Введите займ по годам (n): " << '\n';
	if (cin >> years && years > 0);
	else
	{
		cout << "Ошибка, вы неправильно ввели годы." << '\n';
		return;
	}

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

void Work_3()
{
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

	ifstream inputFile;
	inputFile.open(fileName);
	getline(inputFile, textOutput);
	inputFile.close();

	cout << textOutput << '\n';
}

void Work_4()
{
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

			if(constructedText[constructedText.size() - 1] != '.')
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

void Work_5()
{
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
