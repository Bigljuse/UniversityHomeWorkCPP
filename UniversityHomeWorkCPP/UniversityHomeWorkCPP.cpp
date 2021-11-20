#include <iostream>
#include <vector>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;

void Spinner_Work_1()
{
	int BodyPrice = 0;
	int WingPrice = 0;
	int FinalPrice = 0;

	int countedPrice = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;
	bool ThirdNumberIsCorrect = false;

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите стоимость корпуса спинера: ";
			cin >> BodyPrice;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите стоимость лопости спинера: ";
			cin >> WingPrice;

			if (cin.fail() == false)
				SecondNumberIsCorrect = true;
		}

		if (ThirdNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите максимальную стоимость спинера: ";
			cin >> FinalPrice;

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
				cout << "Ошибка, вы ввели неправильно цену корпуса спинера!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно стоимость лопости спинера!\n";
			else if (ThirdNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно финальную стоимость спинера!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false || ThirdNumberIsCorrect == false);

	countedPrice += BodyPrice;

	int wingsCount = 0;

	while (countedPrice < FinalPrice)
	{
		countedPrice += WingPrice;
		wingsCount++;
	}

	countedPrice -= WingPrice;
	wingsCount--;

	if (wingsCount <= 0)
		cout << "Такого спинера нельзя собрать\n";
	else
		cout << "Всего лопостей у такого спинера может быть: " << wingsCount << '\n';
}

void Spinner_Work_2()
{
	int TotalWingsCount = 0;

	bool firstNumberIsCorrect = false;

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите количество лопостей: ";
			cin >> TotalWingsCount;

			if (cin.fail() == false)
				firstNumberIsCorrect = true;
			if (TotalWingsCount <= 2)
			{
				cout << "0\n0\n";
				return;
			}
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно количество лопостей!\n";
		}
	} while (firstNumberIsCorrect == false);

	int ThreeSpinner = 1;
	int FourSpinner = 1;
	int spinnersWingsCount = 0;

	bool firstError = false;
	bool secondError = false;

	while (firstError == false || secondError == false)
	{
		spinnersWingsCount = 3 * ThreeSpinner + 4 * FourSpinner;

		if (spinnersWingsCount == TotalWingsCount)
		{
			cout << "Количество спинеров с 3 лопостями: " << ThreeSpinner << "\nКоличество спинеров с 4 лопостями: " << FourSpinner << '\n';
			return;
		}

		if (spinnersWingsCount < TotalWingsCount)
			FourSpinner++;
		else
		{
			ThreeSpinner++;
			FourSpinner = 1;

			if (firstError == false) {
				firstError = true;
				continue;
			}
			if (secondError == false) {
				secondError = true;
				continue;
			}
		}
	}

	cout << "0\n0\n";
}

void Not_Spinner_Work_3()
{
	int n = 0;
	int m = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите ширину бумаги: ";
			cin >> n;

			if (cin.fail() == false && n > 0)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите длину бумаги: ";
			cin >> m;

			if (cin.fail() == false && m > 0)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно ширину бумаги!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно длину бумаги!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

	int linesAnswer = 0;
	int rowsAnswer = 0;

	for (int first = 1; first <= n; first++)
		linesAnswer += first;
	for (int second = 1; second <= n; second++)
		rowsAnswer += linesAnswer * second;

	if (rowsAnswer <= 0)
		cout << "Число слишком большое в ответе получается\n";
	else
		cout << rowsAnswer << '\n';
}

class Cupe
{
public:
	vector<int> seats;

	int FreeSeats = 0;

	bool FreeCupe = false;
};

vector<Cupe> SetFreeSeat(int freeSeatNumber, vector<Cupe> seatsArray)
{
	for (int cupeNumber = 0; cupeNumber < seatsArray.size(); cupeNumber++)
	{
		for (int cupeSeatNumber = 0; cupeSeatNumber < seatsArray[cupeNumber].seats.size(); cupeSeatNumber++) {
			if (freeSeatNumber == seatsArray[cupeNumber].seats[cupeSeatNumber])
			{
				seatsArray[cupeNumber].seats[cupeSeatNumber] = -1;
				seatsArray[cupeNumber].FreeSeats++;

				if (seatsArray[cupeNumber].FreeSeats == 6)
					seatsArray[cupeNumber].FreeCupe = true;

				return seatsArray;
			}
		}
	}
}

int GetFreeCupeCountInRow(vector<Cupe> seatsArray)
{
	int freeCupeCount = 0;
	int freeCupeInRow = 0;
	for (Cupe cupe : seatsArray)
	{
		if (cupe.FreeCupe)
			freeCupeCount++;
		else
		{
			if (freeCupeCount != 0)
				freeCupeInRow = freeCupeCount;

			freeCupeCount = 0;
		}
	}

	if (freeCupeCount != 0)
		return freeCupeCount;
	else
		return freeCupeInRow;
}

void Cupe_Work_4()
{
	vector<Cupe> cupeArray;

	for (int i = 1, b = 1; i <= 9; i++)
	{
		Cupe newCupe = { {b,b + 1,b + 2,b + 3,54 + (2 - 2 * i),54 + (1 - 2 * i)},0 ,false };
		cupeArray.push_back(newCupe);
		b += 4;
	}

	int FreeSeatsCount = 0;
	int InputedSeatsCount = 0;
	int InputedSeat = 0;

	bool isCorrectFreeSeatsCount = false;
	bool isCorrectFreeSeatNumber = false;

	do
	{
		if (isCorrectFreeSeatsCount == false)
		{
			cout << "Введите количество свободных мест: ";
			cin >> FreeSeatsCount;

			if (cin.fail() == true && (FreeSeatsCount > 5 && FreeSeatsCount < 55))
				isCorrectFreeSeatsCount = false;
			else if (FreeSeatsCount > 54)
			{
				cout << "Количество свободных мест превышает 54 места. По условию максимум 54 места включительно.\n";
				return;
			}
			else if (FreeSeatsCount < 6)
			{
				cout << "В вагоне нет свободных купе\n";
				return;
			}
			else
			{
				isCorrectFreeSeatsCount = true;
			}
		}

		if (cin.fail() == false)
		{
			cout << "Введите номер свободного места (от 0 до 54): " << InputedSeatsCount + 1 << " из " << FreeSeatsCount << ": ";
			cin >> InputedSeat;

			if (cin.fail() == false && (InputedSeat > 0 && InputedSeat < 55))
			{
				InputedSeatsCount++;
				cupeArray = SetFreeSeat(InputedSeat, cupeArray);
			}

			if (InputedSeatsCount == FreeSeatsCount)
				isCorrectFreeSeatNumber = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (isCorrectFreeSeatsCount == false)
				cout << "Ошибка, вы ввели неправильно количество мест!\n";
			else if (isCorrectFreeSeatNumber == false)
				cout << "Ошибка, вы ввели неправильно свободное место!\n";
		}
	} while (isCorrectFreeSeatNumber == false || isCorrectFreeSeatsCount == false || InputedSeatsCount < FreeSeatsCount);

	cout << "Свободно подряд " << GetFreeCupeCountInRow(cupeArray) << " купе в вагоне.\n";
}

int GetMaxNumber(vector<int> arrayOfNumbers)
{
	int maxNumber = 0;
	for (int number : arrayOfNumbers)
		if (maxNumber < number)
			maxNumber = number;
	return maxNumber;
}

void Cinema_Work_5()
{
	vector<int> cinemaFreeSeatsGroups;
	int freeSeats = 0;
	int schoolBoys = 0;

	bool firstNumberIsCorrect = false;
	bool SecondNumberIsCorrect = false;

	do
	{
		if (firstNumberIsCorrect == false) {
			cout << "Введите количество свободных мест: ";
			cin >> freeSeats;

			if (cin.fail() == false && freeSeats > 0)
				firstNumberIsCorrect = true;
		}

		if (SecondNumberIsCorrect == false && cin.fail() == false) {
			cout << "Введите количество школьников: ";
			cin >> schoolBoys;

			if (cin.fail() == false && schoolBoys > 0)
				SecondNumberIsCorrect = true;
		}

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			if (firstNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно количество свободных мест!\n";
			else if (SecondNumberIsCorrect == false)
				cout << "Ошибка, вы ввели неправильно количество школьников!\n";
		}
	} while (firstNumberIsCorrect == false || SecondNumberIsCorrect == false);

	int boyleftFreeSeatsCount = 0;
	int boyrightFreeSeatsCount = 0;

	for (int schoolBoyNumber = 1; schoolBoyNumber <= schoolBoys; schoolBoyNumber++)
	{
		int maxFreeSeats = GetMaxNumber(cinemaFreeSeatsGroups);

		if (maxFreeSeats == 0)
		{
			freeSeats -= 1;

			boyleftFreeSeatsCount = freeSeats / 2;
			boyrightFreeSeatsCount = freeSeats - boyleftFreeSeatsCount;
		}
		else
		{
			maxFreeSeats -= 1;

			boyleftFreeSeatsCount = maxFreeSeats / 2;
			boyrightFreeSeatsCount = maxFreeSeats - boyleftFreeSeatsCount;

			cinemaFreeSeatsGroups.pop_back();
		}

		if (boyleftFreeSeatsCount < boyrightFreeSeatsCount)
		{
			cinemaFreeSeatsGroups.push_back(boyleftFreeSeatsCount);
			cinemaFreeSeatsGroups.push_back(boyrightFreeSeatsCount);
		}
		else
		{
			cinemaFreeSeatsGroups.push_back(boyrightFreeSeatsCount);
			cinemaFreeSeatsGroups.push_back(boyleftFreeSeatsCount);
		}
	}

	cout << "От последнего севшего школника свободных мест:\nСлева свободно: " << boyleftFreeSeatsCount << "\nСправа свободно: " << boyrightFreeSeatsCount << '\n';
}

void HomeWork_ShowWorks()
{
	int homeWorkNumber = 1;
	bool isWorkNumberCorrect = false;

	cout << "1)Спинеры № 1\n2)Снова спинеры № 2\n3)Не про спинеры № 3\n4)Плацкарный вагон № 4\n5)Кинотеатр № 5\n";

	while (isWorkNumberCorrect == false) {

		isWorkNumberCorrect = true;
		cout << "Какой номер домашней работы вы хотите проверить про спиннеры: ";
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
			Spinner_Work_1();
			break;
		case 2:
			Spinner_Work_2();
			break;
		case 3:
			Not_Spinner_Work_3();
			break;
		case 4:
			Cupe_Work_4();
			break;
		case 5:
			Cinema_Work_5();
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ios::sync_with_stdio(false);
	setlocale(LC_CTYPE, "rus");

	//HomeWork_ShowWorks();
	HomeWork_ShowWorks();

	system("pause");
	return 0;
}
