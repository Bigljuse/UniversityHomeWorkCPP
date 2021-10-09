#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <filesystem>
#include <math.h>
#include <windows.h>
#include <string>

using namespace std;

void Work_1()
{
	string fileName = "Preparing.txt";
	string textInput = "";
	string textOutput = "";
	string constructedText = "";

	float summ = 0;

	bool notNumber = false;
	bool negativeNumber = false;
	bool floatNumber = false;
	bool hasPlus = false;

	cout << "������� ����� ������: ";
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

			summ += stoi(constructedText);

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
			if (floatNumber == true)
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
			if (hasPlus == true)
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

	if (constructedText != "")
		summ += stof(constructedText);

	cout << setprecision(10) << summ << '\n';
}

void Work_2()
{
	float number = 0;

	cout << "������� �����: ";

	if (cin >> number);
	else
	{
		cout << "�� ����� �� �����." << '\n';
	}

	if (number > 0) {
		cout << "����� �������������." << '\n';
		return;
	}

	if (number == 0) {
		cout << "����� �� ����� �����." << '\n';
		return;
	}

	if (number < 0) {
		cout << "����� �������������." << '\n';
		return;
	}
}
\
void Work_3_Cout_rectangle(float* x, float a, float b) {

	*x = a * b;
	float read = *x;
}

int Work_3_Cout_rectangle()
{
	float a = 0;
	float b = 0;

	cout << "������� ������ �������: ";

	if (cin >> a);
	else
	{
		cout << "������� ������� �������� �� ������, ������!" << '\n';
		return 0;
	}

	cout << "������� ������ �������: ";

	if (cin >> b);
	else
	{
		cout << "������� ������� �������� �� ������, ������!" << '\n';
		return 0;
	}

	if (a == 0 || b == 0)
	{
		cout << "�������������� �� ����������!" << '\n';
		return 0;
	}

	cout << a * b << '\n';
	return a * b;
}

int Work_3_Count_triangle() {
	float a = 0;
	float b = 0;

	cout << "������� ������ �������: ";

	if (cin >> a);
	else
	{
		cout << "������� ������� �������� �� ������, ������!" << '\n';
		return 0;
	}

	cout << "������� ������ �������: ";

	if (cin >> b);
	else
	{
		cout << "������� ������� �������� �� ������, ������!" << '\n';
		return 0;
	}

	if (a == 0 || b == 0)
	{
		cout << "������������ �� ����������!" << '\n';
		return 0;
	}

	cout << (a * b) / 2 << '\n';
	return (a * b) / 2;
}

int Work_3_Count_cirqle() {
	float r = 0;

	cout << "������� ������: ";

	if (cin >> r);
	else
	{
		cout << "�������� ������ �������� �� ������, ������!" << '\n';
		return 0;
	}

	if (r <= 0)
	{
		cout << "����� �� ����������!" << '\n';
		return 0;
	}

	cout << "������� ����� �����: " << pow(r, 2) * 3.14 << '\n';
	return pow(r, 2) * 3.14;
}

void Work_3() {

	float a = 0;
	float b = 0;

	unsigned int square = 1;

	float triangle = 0;
	float rectangle = 0;
	float cirqle = 0;

	cout << "����� ������� �������:"
		<< '\n'
		<< "1.������� ��������������: a * b = c"
		<< "\n"
		<< "2.������� ������������: c = (a * b)/2"
		<< "\n"
		<< "3.������� �����: c = pi * r^2"
		<< '\n';

	cout << "������� ����� ����������� �������: ";

	if (cin >> square);
	else
	{
		cout << "������� ����� �� ������������� ������������, �� ��������� 1." << '\n';
		square = 1;
	}

	if (square == 1)
	{
		Work_3_Cout_rectangle();
		return;
	}

	if (square == 2)
	{
		Work_3_Count_triangle();
		return;
	}

	if (square == 3)
	{
		Work_3_Count_cirqle();
		return;
	}

	if (square < 1)
	{
		cout << "�� ������� ����������� �������: " << '\n';
		return;
	}

	if (square > 3)
	{
		cout << "�� ������� ����������� �������: " << '\n';
		return;
	}

	return;
}

void Work_4_DrawRedLine(bool drawStars = false)
{
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	bool ChangedColor = false;
	int top = 0;

	if (drawStars == true)
		top = 8;

	for (; top <= 37; top++)
	{
		if (drawStars == true)
		{
			// ������������ ���� ������, �������� � ������� ����
			SetConsoleTextAttribute(hOUTPUT, 836);
			cout << "//";
			continue;
		}

		if (top <= 7)
		{
			// ������������ ���� ������, �������� � ������� ����
			SetConsoleTextAttribute(hOUTPUT, 543);
			cout << '*';
			cout << ' ';
		}

		if (top > 15 && ChangedColor == false)
		{
			ChangedColor = true;
			// ������������ ���� ������, �������� � ������� ����
			SetConsoleTextAttribute(hOUTPUT, 836);
		}

		if (top > 15)
			cout << "//";
	}
	// ������������ ���� ������ �� �������, �������� � ������� ���� �� �������
	SetConsoleTextAttribute(hOUTPUT, 271);
	cout << '\n';
}

void Work_4_DrawWhiteLine(bool drawStars = false)
{
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	bool ChangedColor = false;
	int counter = 0;

	// ���� � ����� ����� ��� ����, �� � ������ ��������� 
	if (drawStars == true)
		counter = 8;

	for (; counter <= 37; counter++)
	{
		if (drawStars == true)
		{
			// ������������ ���� ������, �������� � ������� ����
			SetConsoleTextAttribute(hOUTPUT, 511);
			cout << "//";
			continue;
		}

		if (counter <= 7)
		{
			// ������������ ���� ������, �������� � ������� ����
			SetConsoleTextAttribute(hOUTPUT, 543);
			cout << '*';
			cout << ' ';
		}

		if (counter > 15 && ChangedColor == false)
		{
			ChangedColor = true;
			// ������������ ���� ������, �������� � ������� ����
			SetConsoleTextAttribute(hOUTPUT, 511);
		}

		if (counter > 15)
			cout << "//";
	}
	// ������������ ���� ������, �������� � ������� ���� �� �������
	SetConsoleTextAttribute(hOUTPUT, 271);
	cout << '\n';
}

// ����� ���� �������
void Work_4() {
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i <= 5; i++)
	{
		if (i < 3) {
			Work_4_DrawRedLine(false);
			Work_4_DrawWhiteLine(false);
		}
		else {
			Work_4_DrawRedLine(true);
			Work_4_DrawWhiteLine(true);
		}
	}
	Work_4_DrawRedLine(true);

	SetConsoleTextAttribute(hOUTPUT, 271);
	cout << '\n';
	return;
}

void Work_5()
{
	HWND hwnd;
	TCHAR Title[1040] = { 0 };
	GetConsoleTitle(Title, 1040); // ������ ��� ����
	hwnd = FindWindow(NULL, Title); // ������ hwnd ����
	HDC hdc = GetDC(hwnd);    // �������� �������� ��� ���������
	HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // ������� ������� ����
	HBRUSH b1, b2 = CreateSolidBrush(RGB(0, 255, 0)); // ������� ������� �����
	p1 = (HPEN)SelectObject(hdc, p2);  // ������� ������� ���� � �������� ���������

	// ����� ���������
	for (float i = 0; i <= 100; i += 0.1) {
		LineTo(hdc, i * 15, 200 + sin(i) * 20);
	}

	SelectObject(hdc, p1);   // ���������� ������ ���� 
	ReleaseDC(hwnd, hdc);    // ����������� �������� ���������
	DeleteObject(p2);       // ������� ��������� ���� 
}

// �������, ��� ������ �������� ������� ����� � 10-������ ������� ���������
int Work_6_Get_Number_From_Roman_Dictionary(char roman_Number)
{
	if (roman_Number == 'I')
		return 1;
	if (roman_Number == 'V')
		return 5;
	if (roman_Number == 'X')
		return 10;
	if (roman_Number == 'L')
		return 50;
	if (roman_Number == 'C')
		return 100;
	if (roman_Number == 'D')
		return 500;
	if (roman_Number == 'M')
		return 1000;

	return -1;
}

void Work_6_Roman_Translator()
{
	string roman_Numbers = "";

	bool correctRomanNumber = false;
	char lastSymbol = '0';
	int counter = 1;

	do
	{
		cout << "������� ������� �����: ";
		cin >> roman_Numbers;

		for (auto symvol : roman_Numbers)
		{
			if (Work_6_Get_Number_From_Roman_Dictionary(symvol) == -1)
				break;

			if (lastSymbol == symvol)
				counter++;

			lastSymbol = symvol;
		}

		if (counter > 3)
			cout << "������� �������� ������� �����. ��������� �������." << '\n';
		else
			correctRomanNumber = true;

		counter = 0;

	} while (correctRomanNumber == false);

	// ���������� ������� �������� � ������
	int roman_Numbers_Count = roman_Numbers.length();
	// ������� id ������ ���������� �������� ������� � ������
	int roman_Numbers_Char_Array_Counter = roman_Numbers_Count - 1;
	// ���������� ������� �����, ����������� � 10-������ ������� ���������
	int roman_Number = 0;
	// ��������� ������� �����, ������� ����� ����� �� roman_Number. ���������, ���������� ������ ���������� ������ �� ����.
	int next_Roman_Number = 0;
	// ����������� ��������� ���-�� ���������� ������� �����, � ������� VIII ����������, � VIIII �� ����������, �.� ����� I ����������� ������ 3 ���, � ��� ������.
	int roman_Number_Equalities_Possible = 3;
	// ���������� ������ ���������� ������� �����, ������� ����������� ������ �� ���� ��� ������ ������ �����������, ����������� ����� ���� 3 ����������, �� ������!
	int roman_Number_Equalities_Possible_Counter = 0;

	// ����������, � ������� � ��������� ��������� ����� � 10-������ ������� ���������
	int roman_Final_Number = 0;


	for (; roman_Numbers_Char_Array_Counter >= 0; roman_Numbers_Char_Array_Counter--)
	{
		// ������� ���������� ������� �����, ���� ��� ��������� 0, �� ���� �� �������� ����
		if (roman_Number == 0)
		{
			// ������� �� ������� ������� �����, ����������� � 10-������ ������� ���������
			roman_Number = Work_6_Get_Number_From_Roman_Dictionary(roman_Numbers[roman_Numbers_Char_Array_Counter]);
			// ��������� 1,�.� � �����������, ��� ��������� ������� ����� ( next_Roman_Number ) ����� ������ ������ ����������� �������� ����� ( roman_Number ).
			roman_Number_Equalities_Possible_Counter++;
			// �������� ������� ����� � ( 10-������ ���.�����. ) � ��������� �����
			roman_Final_Number += roman_Number;
			continue;
		}

		// ������ ��������� ������� �����, ��� �� � ������� �������
		next_Roman_Number = Work_6_Get_Number_From_Roman_Dictionary(roman_Numbers[roman_Numbers_Char_Array_Counter]);

		// ��������� �� ���������� ����������� � ���������� �������� �������
		if (next_Roman_Number == roman_Number)
		{
			// ���� ���������� � ��������� ������� ������ ������, �� ��������� ���� ������ ���������� � ���-�� ���� ����������
			roman_Number_Equalities_Possible_Counter++;

			// �������� ������� ����� � ( 10-������ ���.�����. ) � ��������� �����
			roman_Final_Number += next_Roman_Number;
			// ���������� �������� �������� ������� ����������� ����� �������� �������� �������� �������, �� ��� ���������� � ( 10-����.����� )
			roman_Number = next_Roman_Number;
		}

		// ���������, �������� �� ��������� �������� ������� ����� � ����������
		if (next_Roman_Number > roman_Number)
		{
			// ���� ��������� �������� ������� ����� ������ ����������, �� ��������� ��� ����� � ��������� ����� ��������
			roman_Final_Number += next_Roman_Number;
			// �������� ������� ���������� ������� ����
			roman_Number_Equalities_Possible_Counter = 0;
		}

		if (next_Roman_Number < roman_Number)
		{
			// ���� ��������� �������� ������� ����� ������ ����������, �� �������� ��� ����� �� ���������� ����� ��������
			roman_Final_Number -= next_Roman_Number;
			// �������� ������� ���������� ������� ����
			roman_Number_Equalities_Possible_Counter = 0;
		}

		// ���� ������� ���������� ����� 0, �� �� ���������� �������� ���������� �����, ����� ��� ������ �� ��������� ������, ��� �������� ��� ����,
		// ����� �� �� ���������� ����� ���������� ����� ��� ��������. � ������� � XVII, VII �� ��� ��������� ��� 8, � ���������
		// �����  ����� X. ��� �������, ����� ���������� ������� ������ ���� V, ������� �� �������� ����������, ����� ������� ����� ������������
		if (roman_Number_Equalities_Possible_Counter == 0)
			roman_Number = 0;
		else
			roman_Number = next_Roman_Number;
	}

	cout << "����������� �����: " << roman_Final_Number << '\n';

}

// ������ �������� ��� �������� I
void Work_7_Randomizer_Recursion(int Si = 0, int counter = 0, int m = 0, int i = 0, int c = 0)
{
	if (i == counter) {
		cout << Si << "..." << '\n';
		return;
	}

	int next_Si = (m * Si + counter) % c;

	// ++counter ��������, ��� 1 ����� ���������� � counter �� ����, ����� ��� ������ � ��������, ���� ������ counter++, �� counter ������� �� ����������� � ��������, � ��� ������.
	Work_7_Randomizer_Recursion(next_Si, ++counter, m, i, c);
}

// ��� �������� II � �������� I
void Work_7_Randomizer_While(int Si = 0, int counter = 0, int m = 0, int i = 0, int c = 0)
{
	int next_Si = 0;

	while (i > counter)
	{
		next_Si = (m * Si + counter) % c;
		Si = next_Si;
		counter++;
	}

	cout << Si << "..." << '\n';
	return;

}

void Work_8_Count_Sellers_Money()
{
	// �������� ������\������� � 3 �������� � 4 ���������
	int table_A[3][4] =
	{
		{5,2,0,10},
		{3,5,2,5},
		{20,0,0,0}
	};

	// �������� ������\������� � 4 �������� � 2 ���������
	float table_B[4][2] =
	{
		{1.20,0.50},
		{2.80,0.40},
		{5.00,1.00},
		{2.00,1.50}
	};

	// �������� ������\������� � 3 �������� � 2 ���������
	float table_C[3][2] =
	{
		{0,0},
		{0,0},
		{0,0}
	};

	float all_Money = 0;
	float all_Comission = 0;
	float all_Money_And_Comission = 0;
	float max_Money[2] = { 0 };
	float max_Comission[2] = { 0 };
	float min_Money[2] = { 100 };
	float min_Comission[2] = { 100 };

	// ����������, ������� ����� ������� ������������ ������� ��� ������������ ������ �� ������

	// ��������� ������������ ( table_A ) �� ( table_B ) � ������� ������� ( talbe_C ) � ��� ������������ ����������
	for (int table_A_Line = 0; table_A_Line <= 2; table_A_Line++)
	{
		// ����������� � ������� ( table_B ) � ������� �������, ������������� � �����������
		int table_B_Column = 0;
		// ������ ������ ��� ������ ����������
		float table_Element = 0;

		// ���������� �������
		for (int table_A_Column = 0; table_A_Column <= 3; table_A_Column++)
		{
			// ��������� �������� ���������� ������������ ���������� ������ ( table_A ) �� �������� ������� ( table_B )
			table_Element += table_A[table_A_Line][table_A_Column] * table_B[table_A_Column][table_B_Column];

			// �������� �� ������ ����������� ������� ������� ( table_B ) ��� ���������� ���������� �� ��� ���, ���� � ������� ( table_B ) �� ���������� ��������
			if (table_A_Column == 3)
			{
				// ��������� ���������� ���������� � ����� �������
				table_C[table_A_Line][table_B_Column] = table_Element;
				table_Element = 0;
				// ��������� � ������� ( table_A_Column ) � ������� ������� � ������� ( table_A_Line )
				table_A_Column = -1;
				// ������� �� ��������� �������
				table_B_Column++;
			}
			if (table_B_Column == 2)
				break;
		}
	}

	// ������ ������������ ������������ ������ � �������, �� ���� ������ ������� ( talbe_C )
	for (int table_C_Line = 0; table_C_Line <= 2; table_C_Line++)
	{
		for (int table_C_Column = 0; table_C_Column <= 1; table_C_Column++)
		{
			float element = table_C[table_C_Line][table_C_Column];
			cout << element << ' ';
		}
		cout << '\n';
	}

	for (int counter = 0; counter <= 2; counter++)
	{
		float table_First_Column_Number = table_C[counter][0];
		float table_Second_Column_Number = table_C[counter][1];

		if (table_First_Column_Number > max_Money[0]) {
			max_Money[0] = table_First_Column_Number;
			max_Money[1] = counter + 1;
		}
		if (table_First_Column_Number < min_Money[0]) {
			min_Money[0] = table_First_Column_Number;
			min_Money[1] = counter + 1;
		}

		if (table_Second_Column_Number > max_Comission[0]) {
			max_Comission[0] = table_Second_Column_Number;
			max_Comission[1] = counter + 1;
		}
		if (table_Second_Column_Number < min_Comission[0]) {
			min_Comission[0] = table_Second_Column_Number;
			min_Comission[1] = counter + 1;
		}

		all_Money += table_First_Column_Number;
		all_Comission += table_Second_Column_Number;
		all_Money_And_Comission = all_Money + all_Comission;
	}
	cout << "1.��������: " << max_Money[1] << " ������� ����� " << max_Money[0] << '\n';
	cout << "1.��������: " << min_Money[1] << " ������� ����� " << min_Money[0] << '\n';
	cout << "2.��������: " << max_Comission[1] << " ������� ����� " << max_Comission[0] << '\n';
	cout << "2.��������: " << min_Comission[1] << " ������� ����� " << min_Comission[0] << '\n';
	cout << "3.����� ����� �����: " << all_Money << '\n';
	cout << "4.����� ����� ������������ : " << all_Comission << '\n';
	cout << "5.����� ����� �����, ��������� ����� ���� : " << all_Money_And_Comission << '\n';
}

string Work_9_NumSystem_Translator(string string_Numbers, int base_System = 10, int Target_System = 16)
{
	// ���������� ��� ��������� ���������� �������� �� ( base_System ) � ( Target_System )
	string translated_number_To_Target_System = "";

	// ������� ����� bool ��������, ���� ����� �������������, �� ���� ����� ���� �����.
	bool negativeNumber = false;
	// ������� ����� bool ��������, ���� ����� �������, �� ���� ����� ���� �����.
	bool floatNumber = false;

	// Id ������� (�� ���� �����) ���������� ������ ����� � �������� ����� � ( string_Numbers )
	int separate_Char_Id = 0;

	// �������� ������� ����� � ������ �� ����� � �����
	// ���� ����� �������������, �� negativeNumber = true
	// ���� ����� �������, �� floatNumber = true
	// ���� ����� ����������� ���� �� �����, �� ����� ������ -1
	for (int elementId = 0; elementId < string_Numbers.length(); elementId++)
	{
		char element = string_Numbers[elementId];

		if (element == '-')
			if (negativeNumber == true)
				return "-1";
			else
			{
				negativeNumber = true;
				// ������� ���� ������ �� ���������� ����, ����� � ���������� �� �������
				string_Numbers[0] = '0';
			}

		if (element == '.')
			if (floatNumber == true)
				return "-1";
			else
			{
				floatNumber = true;
				separate_Char_Id = elementId;
			}
	}

	// ���������� ��� ����������� ����� ����� ������������ ����� string_Numbers �� ��������� ( base_System ) � ������� �������� 10
	int integer_Numbers_In_System_Ten = 0;
	// ���������� ��� ����������� ������� ����� ������������ ����� string_Numbers �� ��������� ( base_System ) � ������� �������� 10
	float float_Numbers_In_System_Ten = 0;

	// 1.�������� ����� string_Numbers � 10-������ ������� ��������� � ������� ������ ��������
	// 2.�������� ����� ����� ( integer_Numbers_In_System_Ten ) � ������� ��������� ( Target_System ) ���������
	// 3.�������� �������� ����� ( float_Numbers_In_System_Ten ) � ������� ��������� ( Target_System ) ���������
	if (floatNumber == true)
	{
		// �������� ����� ����� � 10-������ ������� ���������
		for (int counter = separate_Char_Id - 1; counter >= 0; counter--)
		{
			// ������ �� ������ ( string_Numbers )
			char element = string_Numbers[counter];

			// ������� ����� �� �����, ���� ������� ��������� ������ 10-������
			// ���� ������� ��������� �� ���������� �����, �� ������� �� ������� �����
			if (element > 58)								   // ���������� counter ���, ����� ����� base_System ����������� � ������� 0..1..2 � �.�
				integer_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, (separate_Char_Id - 1) - counter);
			else											   // ���������� counter ���, ����� ����� base_System ����������� � ������� 0..1..2 � �.�
				integer_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, (separate_Char_Id - 1) - counter);
		}

		// �������� ������� ����� � 10-������ ������� ���������
		for (int counter = separate_Char_Id + 1; counter < string_Numbers.length(); counter++)
		{
			// ������ �� ������ ( string_Numbers )
			char element = string_Numbers[counter];

			// ������� ����� �� �����, ���� ������� ��������� ������ 10-������
			// ���� ������� ��������� �� ���������� �����, �� ������� �� ������� �����
			if (element > 58)                                  // ���������� counter ���, ����� ����� base_System ����������� � ������� -1..-2..-3 � �.�
				float_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, -(counter - separate_Char_Id));
			else											   // ���������� counter ���, ����� ����� base_System ����������� � ������� -1..-2..-3 � �.�
				float_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, -(counter - separate_Char_Id));
		}

		// ���������� ����� ������� ������� � �������� �� ( Target_System )
		int integer_Delimoe = integer_Numbers_In_System_Ten;
		int integer_Delimoe_Buffer = 0;

		// �������� ����� ����� �� 10-������ ������� ��������� � ( Target_System )
		do
		{
			integer_Delimoe_Buffer = integer_Delimoe % Target_System;

			// ��������� � �� ����������� ������� �����, ������� ������ 9-��, � ������� ��������� �� ������ 11-������ ������������
			if (integer_Delimoe_Buffer > 9)
				translated_number_To_Target_System = char(integer_Delimoe_Buffer + 55) + translated_number_To_Target_System;
			else
				translated_number_To_Target_System = to_string(integer_Delimoe_Buffer) + translated_number_To_Target_System;

			integer_Delimoe = integer_Delimoe / Target_System;

		} while (int(integer_Delimoe) != 0);

		// �������� �������������� ���� ��� ����������� ���������� ������� �����
		translated_number_To_Target_System += ".";

		float float_Delimoe = float_Numbers_In_System_Ten;
		float float_Delimoe_Buffer = 0;

		// �������� ������� ����� �� 10-������ ������� ��������� � ( Target_System )
		do
		{
			float_Delimoe_Buffer = float_Delimoe * Target_System;

			// ��������� � �� ����������� ������� �����, ������� ������ 9-��, � ������� ��������� �� ������ 11-������ ������������
			if (int(float_Delimoe_Buffer) > 9)
				translated_number_To_Target_System += char(int(float_Delimoe_Buffer) + 55);
			else
				translated_number_To_Target_System += to_string(int(float_Delimoe_Buffer));

			// �� ������� �������� �������� ����� �� 10-������ � ����� ������� ��������� � ��� ����� ����� ����������
			float_Delimoe = float_Delimoe_Buffer - int(float_Delimoe_Buffer);

		} while (float_Delimoe > 0);
	}
	else
	{
		// �������� ����� ����� � 10-������ ������� ���������
		for (int counter = string_Numbers.length() - 1; counter >= 0; counter--)
		{
			// ������ �� ������ ( string_Numbers )
			char element = string_Numbers[counter];

			// ������� ����� �� �����, ���� ������� ��������� ������ 10-������
			// ���� ������� ��������� �� ���������� �����, �� ������� �� ������� �����
			if (element > 58)								   // ���������� counter ���, ����� ����� base_System ����������� � ������� 0..1..2 � �.�
				integer_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, (string_Numbers.length() - 1) - counter);
			else											   // ���������� counter ���, ����� ����� base_System ����������� � ������� 0..1..2 � �.�
				integer_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, (string_Numbers.length() - 1) - counter);
		}

		// ���������� ����� ������� ������� � �������� �� ( Target_System )
		int integer_Delimoe = integer_Numbers_In_System_Ten;
		int integer_Delimoe_Buffer = 0;

		// �������� ����� ����� �� 10-������ ������� ��������� � ( Target_System )
		do
		{
			integer_Delimoe_Buffer = integer_Delimoe % Target_System;

			// ��������� � �� ����������� ������� �����, ������� ������ 9-��, � ������� ��������� �� ������ 11-������ ������������
			if (integer_Delimoe_Buffer > 9)
				translated_number_To_Target_System = char(integer_Delimoe_Buffer + 55) + translated_number_To_Target_System;
			else
				translated_number_To_Target_System = to_string(integer_Delimoe_Buffer) + translated_number_To_Target_System;

			integer_Delimoe = integer_Delimoe / Target_System;

		} while (int(integer_Delimoe) != 0);
	}


	if (negativeNumber)
		return '-' + translated_number_To_Target_System;
	else
		return translated_number_To_Target_System;
}


