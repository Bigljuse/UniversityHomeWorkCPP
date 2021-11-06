#include <iostream>
#include <vector>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;
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

class Ball {
public:
	bool isSelected;
};

unsigned Perestanovka(vector<Ball> ballsList, unsigned n, unsigned step_k = 1)
{
	unsigned count = 0;

	if (step_k <= n)
		for (unsigned i = 1; i <= n; i++)
		{
			if (ballsList[i - 1].isSelected == false)
			{
				if (i == step_k)
				{
					count += factorial(n - step_k);
				}
				else
				{
					ballsList[i - 1].isSelected = true;
					count += Perestanovka(ballsList, n, step_k + 1);

					ballsList[i - 1].isSelected = false;
				}
			}
		}

	return count;
}

void HomeWork_Balls()
{
	int ballsCount = 0;

	bool firstNumberIsCorrect = false;

	cout << "Из урны с 10 пронумерованными шариками вынимают по одному шарику. Подсчитать общее количество ситуаций, когда номер хотя бы одного вынутого шарика совпадает с порядковым номером действия вынимания, например, когда шарик № 3 будет вынут 3-им по порядку.\n";

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите количество шариков: ";
			cin >> ballsCount;
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
				cout << "Ошибка, вы ввели неправильно число!\n";
		}
	} while (firstNumberIsCorrect == false);

	vector<Ball> ballsList;
	ballsList.resize(ballsCount);

	cout << "Всего ситуаций: " << Perestanovka(ballsList, ballsCount) << '\n';
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ios::sync_with_stdio(false);
	setlocale(LC_CTYPE, "rus");

	HomeWork_Balls();


	system("pause");
	return 0;
}