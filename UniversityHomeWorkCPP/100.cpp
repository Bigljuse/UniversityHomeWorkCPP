#include <iostream>
#include <vector>
#include <cstdlib> 
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

class Symbol
{
public:
	char symbol;
	int age;
	bool isMicrob;
	int neighborCount;
	int deathTimer;
};

void arrayCopy(Symbol(&arrayFrom)[21][21], Symbol(&arrayTo)[21][21])
{
	for (int lineId = 0; lineId < 21; lineId++)
	{
		for (int columnId = 0; columnId < 21; columnId++)
		{
			arrayTo[lineId][columnId] = arrayFrom[lineId][columnId];
		}
	}
}

vector<string> GenerateRandomField(vector<char> fieldOfLife)
{
	string randomLine;
	vector<string> linesOfWymbols;

	for (int length = 0; length < 21; length++)
	{
		for (int symbolId = 0; symbolId < 21; symbolId++)
		{
			int randomSymbolId = rand() % fieldOfLife.size();
			char randomSymbol = fieldOfLife[randomSymbolId];

			randomLine.push_back(randomSymbol);
		}
		linesOfWymbols.push_back(randomLine);
		randomLine.clear();
	}
	return linesOfWymbols;
}

void countMicrobsNeigbors(Symbol(&futureTime)[21][21])
{
	for (int symbolIdLine = 0; symbolIdLine < 21; symbolIdLine++)
	{
		for (int symbolIdHeight = 0; symbolIdHeight < 21; symbolIdHeight++)
		{
			futureTime[symbolIdLine][symbolIdHeight].neighborCount = -1;

			Symbol* microb = &futureTime[symbolIdLine][symbolIdHeight];

			if ((*microb).isMicrob == false)
				continue;

			int checkerLineStart = symbolIdLine - 1;
			int checkerColumnStart = symbolIdHeight - 1;

			for (int ColumnCounter = 0, lineCounter = 0; ColumnCounter <= 2, lineCounter <= 2; ColumnCounter++)
			{
				int columnCheck = checkerColumnStart + ColumnCounter;
				int lineCheck = checkerLineStart + lineCounter;

				if (columnCheck < 0)
				{
					columnCheck++;
					ColumnCounter++;
				}
				if (lineCheck < 0)
				{
					lineCheck++;
					lineCounter++;
				}

				bool borderColumnCheck = columnCheck > 20;
				bool borderLineCheck = lineCheck > 20;

				if (borderColumnCheck == true)
				{
					ColumnCounter = -1;
					lineCounter++;
					continue;
				}
				if (borderLineCheck == true)
					break;

				Symbol checker = futureTime[lineCheck][columnCheck];

				if (checker.isMicrob == true && checker.age != 0)
					(*microb).neighborCount++;

				if (ColumnCounter == 2)
				{
					ColumnCounter = -1;
					lineCounter++;
				}
				if (lineCounter == 3)
					break;
			}
		}
	}
}

void MarkMicrobs(Symbol(&futureTime)[21][21], vector<string> fieldOfLife, char microbSymbol)
{
	for (int symbolLine = 0; symbolLine < 21; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 21; symbolColumn++)
		{
			char symbol = fieldOfLife[symbolLine][symbolColumn];
			Symbol* microb = &futureTime[symbolLine][symbolColumn];

			if (symbol == microbSymbol)
			{
				(*microb).isMicrob = true;
				(*microb).age = 1;
				(*microb).neighborCount = -1;
				(*microb).symbol = symbol;
				continue;
			}

			(*microb).isMicrob = false;
			(*microb).age = 0;
			(*microb).neighborCount = -1;
			(*microb).symbol = symbol;
		}
	}
}

void ReviveDiedMicrobs(Symbol(&futureTime)[21][21])
{
	for (int symbolLine = 0; symbolLine < 21; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 21; symbolColumn++)
		{
			Symbol* microb = &futureTime[symbolLine][symbolColumn];

			if (microb->isMicrob == false)
				continue;

			if (microb->age == 0 && microb->deathTimer > 1) 
			{
				microb->age = 1;
				microb->deathTimer = 0;
			}
		}
	}
}

void KillAloneMicrobs(Symbol(&futureTime)[21][21])
{
	for (int symbolLine = 0; symbolLine < 21; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 21; symbolColumn++)
		{
			Symbol* microb = &futureTime[symbolLine][symbolColumn];

			if (microb->isMicrob == false)
				continue;

			if (microb->neighborCount < 2) 
			{
				microb->deathTimer++;
				microb->age = 0;
			}
		}
	}
}

void DocumentChanges(Symbol(&futureTime)[21][21], int pocolenie)
{
	string microbsLine;
	vector<string> microbsFiel;
	int aliveMicrobs = 0;
	string workOutName = "work.out";
	ofstream workDatStream;

	workDatStream.open(workOutName, std::ios::app);

	for (int symbolLine = 0; symbolLine < 21; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 21; symbolColumn++)
		{
			Symbol* microb = &futureTime[symbolLine][symbolColumn];

			if (microb->isMicrob == false)
			{
				microbsLine += "_ ";
				continue;
			}
			microbsLine += to_string(microb->age) + " ";

			if (microb->age <= 0)
				continue;

			aliveMicrobs++;
		}
		microbsFiel.push_back(microbsLine);
		microbsLine.clear();

		cout << microbsFiel[symbolLine] << '\n';
		workDatStream << microbsFiel[symbolLine] << '\n';
	}

	cout << "Живых микробов: " << aliveMicrobs << "\nПоколение: " << pocolenie << "\n\n";
	workDatStream << "Живых микробов: " << aliveMicrobs << "\nПоколение: "<< pocolenie << "\n\n";

	workDatStream.close();
}

void EvolveMicrobes(Symbol(&futureTime)[21][21])
{
	for (int symbolLine = 0; symbolLine < 21; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 21; symbolColumn++)
		{
			Symbol* microb = &futureTime[symbolLine][symbolColumn];

			if (microb->isMicrob == false)
				continue;
			if (microb->age == 12)
			{
				microb->age == 0;
				microb->isMicrob = false;
				microb->neighborCount = -1;
			}
			if (microb->age == 0)
				continue;
			microb->age++;
		}
	}
}

void SimulateEvolution(Symbol(&futureTime)[21][21], vector<string> startField, char microbSymbol, int step, int totalSteps)
{
	MarkMicrobs(futureTime, startField, microbSymbol);
	DocumentChanges(futureTime, step);
	do
	{
		countMicrobsNeigbors(futureTime);
		KillAloneMicrobs(futureTime);
		EvolveMicrobes(futureTime);
		DocumentChanges(futureTime, step);

		if (step % 2 == 0) {
			ReviveDiedMicrobs(futureTime);
			DocumentChanges(futureTime, step);
		}

		step++;
		Sleep(400);
	} while (step < totalSteps);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(static_cast<unsigned int>(time(0)));

	Symbol futureTime[21][21] = {};

	///////////////
	cout << "Введите символы: ";
	string symbolsString = "";

	do
	{
		getline(cin, symbolsString);

	} while (symbolsString.size() == 0);

	vector<char> symbolsArray;

	for (auto symbol : symbolsString)
		if (symbol != ' ')
			symbolsArray.push_back(symbol);
	///////////////


	///////////////
	int microbRandomSymbolId = rand() % symbolsArray.size();

	char microbSymbol = symbolsArray[microbRandomSymbolId];

	vector<string> startField = GenerateRandomField(symbolsArray);
	///////////////


	/////////////
	bool isCorrectNumber = 0;
	int totalSteps = 0;

	do
	{
		if (isCorrectNumber == false) {
			cout << "Введите число поколений: ";
			cin >> totalSteps;

			if (cin.fail() == false)
				isCorrectNumber = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(WINT_MAX, '\n');

			if (isCorrectNumber == false)
				cout << "Ошибка, вы ввели неправильно число поколений!\n";
		}
	} while (isCorrectNumber == false);
	///////////////


	///////////////
	string workDatName = "work.dat";
	ofstream workDatStream;
	workDatStream.open(workDatName);
	for (int lineId = 0; lineId < 21; lineId++)
		workDatStream << startField[lineId] << '\n';
	workDatStream.close();

	SimulateEvolution(futureTime, startField, microbSymbol, 1, totalSteps);

	system("pause");
}