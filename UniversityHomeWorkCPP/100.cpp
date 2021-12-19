#include <iostream>
#include <vector>
#include <cstdlib> 
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <signal.h>

using namespace std;

int aliveMicrobs = 0;

class Symbol
{
public:
	char symbol;
	int age;
	bool isMicrob;
	int aliveNeighbors;
};

void arrayCopy(Symbol(&arrayFrom)[50][50], Symbol(&arrayTo)[50][50])
{
	for (int lineId = 0; lineId < 50; lineId++)
		for (int columnId = 0; columnId < 50; columnId++)
			arrayTo[lineId][columnId] = arrayFrom[lineId][columnId];
}

int GetPopulationCount()
{
	bool isCorrectNumber = 0;
	int populationCount = 0;

	do
	{
		if (isCorrectNumber == false) {
			cout << "Введите число поколений, которые программа должна обработать: ";
			cin >> populationCount;

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
				cout << "Ошибка, введено не число!\n";
		}
	} while (isCorrectNumber == false);

	return populationCount;
}

vector<char> GetSymbolsFromConsole()
{
	cout << "Введите символы: ";
	string symbolsStringArray = "";

	do
	{
		getline(cin, symbolsStringArray);

	} while (symbolsStringArray.size() == 0);

	vector<char> symbolsArray;

	for (auto symbol : symbolsStringArray)
		if (symbol != ' ')
			symbolsArray.push_back(symbol);

	return symbolsArray;
}

vector<string> GenerateRandomField(vector<char> symbolsArray)
{
	string randomLine;
	vector<string> linesOfWymbols;

	for (int length = 0; length < 50; length++)
	{
		for (int symbolId = 0; symbolId < 50; symbolId++)
		{
			int randomSymbolId = rand() % symbolsArray.size();
			char randomSymbol = symbolsArray[randomSymbolId];

			randomLine.push_back(randomSymbol);
		}
		linesOfWymbols.push_back(randomLine);
		randomLine.clear();
	}
	return linesOfWymbols;
}

void CountMicrobsNeighbors(Symbol(&symbolsTable)[50][50])
{
	for (int symbolIdLine = 0; symbolIdLine < 50; symbolIdLine++)
	{
		for (int symbolIdHeight = 0; symbolIdHeight < 50; symbolIdHeight++)
		{
			Symbol* microb = &symbolsTable[symbolIdLine][symbolIdHeight];

			// Чтобы при проверке к поле 3 на 3 учитывать символ той же клетки, для которой идёт проверка.
			if (microb->age > 0) 
				microb->aliveNeighbors = -1;
			else 
				microb->aliveNeighbors = 0;

			// Установка начала проверки квадрата размером 3 на 3
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

				bool borderColumnCheck = columnCheck > 49;
				bool borderLineCheck = lineCheck > 49;

				if (borderColumnCheck == true)
				{
					ColumnCounter = -1;
					lineCounter++;
					continue;
				}
				if (borderLineCheck == true)
					break;

				Symbol microbChecker = symbolsTable[lineCheck][columnCheck];

				if (microbChecker.age > 0)
					(*microb).aliveNeighbors++;

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

void MarkMicrobs(Symbol(&symbolsTable)[50][50], vector<string> startField, char microbSymbol)
{
	for (int symbolLine = 0; symbolLine < 50; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 50; symbolColumn++)
		{
			char symbol = startField[symbolLine][symbolColumn];
			Symbol* microb = &symbolsTable[symbolLine][symbolColumn];

			if (symbol == microbSymbol)
			{
				(*microb).isMicrob = true;
				(*microb).age = 1;
				(*microb).aliveNeighbors = -1;
				(*microb).symbol = microbSymbol;
				continue;
			}

			(*microb).isMicrob = true;
			(*microb).age = 0;
			(*microb).aliveNeighbors = 0;
			(*microb).symbol = microbSymbol;
		}
	}
}

void ReviveDiedMicrobs(Symbol(&symbolsTable)[50][50])
{
	for (int symbolLine = 0; symbolLine < 50; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 50; symbolColumn++)
		{
			Symbol* microb = &symbolsTable[symbolLine][symbolColumn];

			if (microb->age == 0 && microb->aliveNeighbors == 3)
				microb->age = 1;			
		}
	}
}

void KillMicrobs(Symbol(&symbolsTable)[50][50])
{
	for (int symbolLine = 0; symbolLine < 50; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 50; symbolColumn++)
		{
			Symbol* microb = &symbolsTable[symbolLine][symbolColumn];

			if (microb->aliveNeighbors < 2 || microb->aliveNeighbors > 3)
				microb->age = 0;			
		}
	}
}

void DocumentChanges(Symbol(&symbolsTable)[50][50], int pocolenie)
{
	string microbsLine;
	string microbSymbol = "";
	vector<string> microbsField;

	string workOutName = "work.out";
	ofstream workDatStream;
	workDatStream.open(workOutName, std::ios::app);

	for (int symbolLine = 0; symbolLine < 50; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 50; symbolColumn++)
		{
			Symbol* microb = &symbolsTable[symbolLine][symbolColumn];

			if (microb->age == 0)
				microbsLine += "  ";
			else
				microbsLine += "* ";

			if (microb->age <= 0)
				continue;

			aliveMicrobs++;
		}
		microbsField.push_back(microbsLine);
		microbsLine.clear();

		cout << microbsField[symbolLine] << '\n';
		workDatStream << microbsField[symbolLine] << '\n';
	}

	cout << "Живых микробов: " << aliveMicrobs << "\nПоколение: " << pocolenie << "\n\n";
	workDatStream << "Живых микробов: " << aliveMicrobs << "\nПоколение: " << pocolenie << "\n\n";

	workDatStream.close();
}

void EvolveMicrobes(Symbol(&symbolsTable)[50][50])
{
	for (int symbolLine = 0; symbolLine < 50; symbolLine++)
	{
		for (int symbolColumn = 0; symbolColumn < 50; symbolColumn++)
		{
			Symbol* microb = &symbolsTable[symbolLine][symbolColumn];

			if (microb->age > 29)
			{
				microb->age = 0;
				continue;
			}

			if (microb->age <= 0)
				continue;

			microb->age++;
		}
	}
}

void SimulateEvolution(Symbol(&symbolsTable)[50][50], vector<string> startField, char microbSymbol, int totalSteps)
{
	int step = 1;
	system("cls");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	MarkMicrobs(symbolsTable, startField, microbSymbol);
	DocumentChanges(symbolsTable, step);

	SetConsoleCursorPosition(consoleHandle, { 0,0 });
	
	do
	{
		SetConsoleCursorPosition(consoleHandle, { 0,0 });
		system("cls");

		CountMicrobsNeighbors(symbolsTable);
		EvolveMicrobes(symbolsTable);
		KillMicrobs(symbolsTable);
		ReviveDiedMicrobs(symbolsTable);
		DocumentChanges(symbolsTable, step);

		step++;		
		Sleep(350);		
	} while (step < totalSteps || aliveMicrobs > 0);
}

void Ctrl_C_Blocker(int singint) {
	fflush(stdout);
	signal(SIGINT, Ctrl_C_Blocker);
}

int main()
{
	///////////////
	signal(SIGINT, Ctrl_C_Blocker);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(static_cast<unsigned int>(time(0)));

	Symbol symbolsTable[50][50] = {};
	///////////////

	vector<char> symbolsArray = GetSymbolsFromConsole();

	///////////////
	int microbRandomSymbolId = rand() % symbolsArray.size();

	char microbSymbol = symbolsArray[microbRandomSymbolId];

	vector<string> startField = GenerateRandomField(symbolsArray);
	///////////////

	///////////////
	string workDatName = "work.dat";
	ofstream workDatStream;
	workDatStream.open(workDatName);
	for (int lineId = 0; lineId < 50; lineId++)
		workDatStream << startField[lineId] << '\n';
	workDatStream.close();

	SimulateEvolution(symbolsTable, startField, microbSymbol, GetPopulationCount());

	system("pause");
}