#include <cstdio>
#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include <math.h>
#include<string>

using namespace std;

void Work_18()
{
	bool NumberZeroWasFound = false;
	int height = 0;
	int avarage = 0;
	int peoplehigherAvarage = 0;

	vector<int> arrayOfheight;

	cout << " **** ������ ����� �������� ***\n" <<
		"������� ����(��) � ������� <Enter>.\n" <<
		"��� ���������� ������� 0 � ������� < Enter>\n";

	do
	{
		cout << "-> ";
		cin >> height;

		if (cin.fail())
		{
			// Unlocking cin from (translate char to int) error
			cin.clear();
			// Ignoring all data in cin buffer before preparing for new input from console
			cin.ignore(UINT_MAX, '\n');

			cout << "\n�� ������� �������!" << '\n';
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

	cout << "������� ����: " << avarage;
	cout << "� "<< peoplehigherAvarage << "-x ������� ���� ��������� �������." << avarage;
}