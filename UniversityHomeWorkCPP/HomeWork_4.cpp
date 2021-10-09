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

	cout << "Введите число: ";

	if (cin >> number);
	else
	{
		cout << "Вы ввели не число." << '\n';
	}

	if (number > 0) {
		cout << "Число положительное." << '\n';
		return;
	}

	if (number == 0) {
		cout << "Число не имеет знака." << '\n';
		return;
	}

	if (number < 0) {
		cout << "Число отрицательное." << '\n';
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

	cout << "Введите первую сторону: ";

	if (cin >> a);
	else
	{
		cout << "Введёная сторона является не числом, ошибка!" << '\n';
		return 0;
	}

	cout << "Введите вторую сторону: ";

	if (cin >> b);
	else
	{
		cout << "Введёная сторона является не числом, ошибка!" << '\n';
		return 0;
	}

	if (a == 0 || b == 0)
	{
		cout << "Прямоугольника не существует!" << '\n';
		return 0;
	}

	cout << a * b << '\n';
	return a * b;
}

int Work_3_Count_triangle() {
	float a = 0;
	float b = 0;

	cout << "Введите первую сторону: ";

	if (cin >> a);
	else
	{
		cout << "Введёная сторона является не числом, ошибка!" << '\n';
		return 0;
	}

	cout << "Введите вторую сторону: ";

	if (cin >> b);
	else
	{
		cout << "Введёная сторона является не числом, ошибка!" << '\n';
		return 0;
	}

	if (a == 0 || b == 0)
	{
		cout << "Треугольника не существует!" << '\n';
		return 0;
	}

	cout << (a * b) / 2 << '\n';
	return (a * b) / 2;
}

int Work_3_Count_cirqle() {
	float r = 0;

	cout << "Введите радиус: ";

	if (cin >> r);
	else
	{
		cout << "Введённый радиус является не числом, ошибка!" << '\n';
		return 0;
	}

	if (r <= 0)
	{
		cout << "Круга не существует!" << '\n';
		return 0;
	}

	cout << "Площадь круга равна: " << pow(r, 2) * 3.14 << '\n';
	return pow(r, 2) * 3.14;
}

void Work_3() {

	float a = 0;
	float b = 0;

	unsigned int square = 1;

	float triangle = 0;
	float rectangle = 0;
	float cirqle = 0;

	cout << "Будем считать площади:"
		<< '\n'
		<< "1.Площадь Прямоугольника: a * b = c"
		<< "\n"
		<< "2.Площадь Треугольника: c = (a * b)/2"
		<< "\n"
		<< "3.Площадь Круга: c = pi * r^2"
		<< '\n';

	cout << "Введите номер вычисляемой площади: ";

	if (cin >> square);
	else
	{
		cout << "Введёный номер не соответствует предложенным, по умолчанию 1." << '\n';
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
		cout << "Не выбрана вычисляемая площадь: " << '\n';
		return;
	}

	if (square > 3)
	{
		cout << "Не выбрана вычисляемая площадь: " << '\n';
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
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 836);
			cout << "//";
			continue;
		}

		if (top <= 7)
		{
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 543);
			cout << '*';
			cout << ' ';
		}

		if (top > 15 && ChangedColor == false)
		{
			ChangedColor = true;
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 836);
		}

		if (top > 15)
			cout << "//";
	}
	// Устанавливаю цвет текста на обычный, символов и заднего фона на обычный
	SetConsoleTextAttribute(hOUTPUT, 271);
	cout << '\n';
}

void Work_4_DrawWhiteLine(bool drawStars = false)
{
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	bool ChangedColor = false;
	int counter = 0;

	// Если я рисую линию без звёзд, то я просто пропускаю 
	if (drawStars == true)
		counter = 8;

	for (; counter <= 37; counter++)
	{
		if (drawStars == true)
		{
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 511);
			cout << "//";
			continue;
		}

		if (counter <= 7)
		{
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 543);
			cout << '*';
			cout << ' ';
		}

		if (counter > 15 && ChangedColor == false)
		{
			ChangedColor = true;
			// Устанавливаю цвет текста, символов и заднего фона
			SetConsoleTextAttribute(hOUTPUT, 511);
		}

		if (counter > 15)
			cout << "//";
	}
	// Устанавливаю цвет текста, символов и заднего фона на обычный
	SetConsoleTextAttribute(hOUTPUT, 271);
	cout << '\n';
}

// Рисую флаг Америки
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
	GetConsoleTitle(Title, 1040); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	HDC hdc = GetDC(hwnd);    // Получаем контекст для рисования
	HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Создаем красное перо
	HBRUSH b1, b2 = CreateSolidBrush(RGB(0, 255, 0)); // Создаем зеленую кисть
	p1 = (HPEN)SelectObject(hdc, p2);  // Заносим красное перо в контекст рисования

	// Рисую синусоиду
	for (float i = 0; i <= 100; i += 0.1) {
		LineTo(hdc, i * 15, 200 + sin(i) * 20);
	}

	SelectObject(hdc, p1);   // Возвращаем старое перо 
	ReleaseDC(hwnd, hdc);    // Освобождаем контекст рисования
	DeleteObject(p2);       // Удаляем созданное перо 
}

// Словарь, для выдачи значения римской цифры в 10-ричной системе счисления
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
		cout << "Введите римское число: ";
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
			cout << "Введено неверное римское число. Повторите попытку." << '\n';
		else
			correctRomanNumber = true;

		counter = 0;

	} while (correctRomanNumber == false);

	// Количество римских символов в строке
	int roman_Numbers_Count = roman_Numbers.length();
	// Получаю id самого последнего римского символа в тексте
	int roman_Numbers_Char_Array_Counter = roman_Numbers_Count - 1;
	// Предыдущая римская цифра, переведённая в 10-ричную систему счисления
	int roman_Number = 0;
	// Следующая римская цифра, которая стоит слева от roman_Number. Напоминаю, считывание строки происходит справа на лево.
	int next_Roman_Number = 0;
	// Максимально возможное кол-во совпадений римских чисел, к примеру VIII существует, а VIIII не существует, т.к число I повторилось больше 3 раз, а так нельзя.
	int roman_Number_Equalities_Possible = 3;
	// Переменная хранит количество римских чисел, которые повтаряются справо на лево при чтении строки посимвольно, максимально может быть 3 совпадения, не больше!
	int roman_Number_Equalities_Possible_Counter = 0;

	// Переменная, в которую я записываю финальное число в 10-ричной системе счисления
	int roman_Final_Number = 0;


	for (; roman_Numbers_Char_Array_Counter >= 0; roman_Numbers_Char_Array_Counter--)
	{
		// Находит предыдущую римскую цифру, если она оказалась 0, то есть не записана была
		if (roman_Number == 0)
		{
			// Получаю из словаря римское число, переведённое в 10-ричную систему счисления
			roman_Number = Work_6_Get_Number_From_Roman_Dictionary(roman_Numbers[roman_Numbers_Char_Array_Counter]);
			// Прибавляю 1,т.к я предполагаю, что следующий римское число ( next_Roman_Number ) будет равено нашему предыдущему римскому числу ( roman_Number ).
			roman_Number_Equalities_Possible_Counter++;
			// Добавляю римскую цифру в ( 10-ричной сис.счисл. ) в финальное число
			roman_Final_Number += roman_Number;
			continue;
		}

		// Нахожу следующее римское число, так же с помощью словаря
		next_Roman_Number = Work_6_Get_Number_From_Roman_Dictionary(roman_Numbers[roman_Numbers_Char_Array_Counter]);

		// Проверяет на совпадение предыдущего и следующего римского символа
		if (next_Roman_Number == roman_Number)
		{
			// Если предыдущий и следующий римский символ совпал, то сохраняет этот случай совпадения в кол-во всех совпадений
			roman_Number_Equalities_Possible_Counter++;

			// Добавляю римскую цифру в ( 10-ричной сис.счисл. ) в финальное число
			roman_Final_Number += next_Roman_Number;
			// Предыдущая значение римского символа становиться равно текущему значению римского символа, всё уже переведено в ( 10-сист.счисл )
			roman_Number = next_Roman_Number;
		}

		// Проверяет, является ли следующее значение римской цифры с предыдущей
		if (next_Roman_Number > roman_Number)
		{
			// Если следующее значение римской цифры больше предыдущей, то добавляет это число в финальное число перевода
			roman_Final_Number += next_Roman_Number;
			// Обнулает счётчит совпадений римских цифр
			roman_Number_Equalities_Possible_Counter = 0;
		}

		if (next_Roman_Number < roman_Number)
		{
			// Если следующее значение римской цифры меньше предыдущей, то вычитает это число из финального числа перевода
			roman_Final_Number -= next_Roman_Number;
			// Обнулает счётчит совпадений римских цифр
			roman_Number_Equalities_Possible_Counter = 0;
		}

		// Если счётчик совпадений равен 0, то мы специально обнуляем предыдущее число, чтобы оно больше не считалось дальше, это делается для того,
		// чтобы мы не записывали дважы предыдущее число при подсчёте. К примеру в XVII, VII мы уже посчитали как 8, а следующее
		// число  будет X. Нам ненужно, чтобы предыдущим римским числом было V, поэтому мы обнуляем предыдущий, иначе перевод будет неправильный
		if (roman_Number_Equalities_Possible_Counter == 0)
			roman_Number = 0;
		else
			roman_Number = next_Roman_Number;
	}

	cout << "Переведённое число: " << roman_Final_Number << '\n';

}

// Только работает для Варианта I
void Work_7_Randomizer_Recursion(int Si = 0, int counter = 0, int m = 0, int i = 0, int c = 0)
{
	if (i == counter) {
		cout << Si << "..." << '\n';
		return;
	}

	int next_Si = (m * Si + counter) % c;

	// ++counter означает, что 1 будет прибавлено к counter до того, когда она попадёт в рекурсию, если писать counter++, то counter никогда не прибавиться в рекурсии, а это ошибка.
	Work_7_Randomizer_Recursion(next_Si, ++counter, m, i, c);
}

// Для Варианта II и Варианта I
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
	// Обьявляю массив\матрицу с 3 строками и 4 столбцами
	int table_A[3][4] =
	{
		{5,2,0,10},
		{3,5,2,5},
		{20,0,0,0}
	};

	// Обьявляю массив\матрицу с 4 строками и 2 столбцами
	float table_B[4][2] =
	{
		{1.20,0.50},
		{2.80,0.40},
		{5.00,1.00},
		{2.00,1.50}
	};

	// Обьявляю массив\матрицу с 3 строками и 2 столбцами
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

	// Переменная, которая будет хранить подсчитанный элемент при перемножении матриц по этапно

	// Произвожу перемножение ( table_A ) на ( table_B ) и получаю матрицу ( talbe_C ) с уже вычисленными элементами
	for (int table_A_Line = 0; table_A_Line <= 2; table_A_Line++)
	{
		// Возвращаюсь в матрицу ( table_B ) к первому столбцу, подготавливая к вычислениям
		int table_B_Column = 0;
		// Очищаю буффер для записи вычислений
		float table_Element = 0;

		// Перемножаю матрицы
		for (int table_A_Column = 0; table_A_Column <= 3; table_A_Column++)
		{
			// Произвожу сложение полученных произведений эелементов строки ( table_A ) на элементы столбца ( table_B )
			table_Element += table_A[table_A_Line][table_A_Column] * table_B[table_A_Column][table_B_Column];

			// Перехожу на каждый последующий столбец матрицы ( table_B ) для выполнения вычислений до тех пор, пока в матрице ( table_B ) не закончатся столбики
			if (table_A_Column == 3)
			{
				// Записываю полученные вычисления в новую матрицу
				table_C[table_A_Line][table_B_Column] = table_Element;
				table_Element = 0;
				// Возвращаю в матрице ( table_A_Column ) к первому столбцу и строчки ( table_A_Line )
				table_A_Column = -1;
				// Переход на следующий столбец
				table_B_Column++;
			}
			if (table_B_Column == 2)
				break;
		}
	}

	// Вывожу подсчитанное произведение матриц в консоль, то есть вывожу матрицу ( talbe_C )
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
	cout << "1.Продавец: " << max_Money[1] << " выручил денег " << max_Money[0] << '\n';
	cout << "1.Продавец: " << min_Money[1] << " выручил денег " << min_Money[0] << '\n';
	cout << "2.Продавец: " << max_Comission[1] << " выручил денег " << max_Comission[0] << '\n';
	cout << "2.Продавец: " << min_Comission[1] << " выручил денег " << min_Comission[0] << '\n';
	cout << "3.Общая сумма денег: " << all_Money << '\n';
	cout << "4.Общая сумма комиссионных : " << all_Comission << '\n';
	cout << "5.Общая сумма денег, прошедшая через руки : " << all_Money_And_Comission << '\n';
}

string Work_9_NumSystem_Translator(string string_Numbers, int base_System = 10, int Target_System = 16)
{
	// Переменная для конечного результата перевода из ( base_System ) в ( Target_System )
	string translated_number_To_Target_System = "";

	// Пометка ввиде bool операции, если число отрицательное, то есть имеет один минус.
	bool negativeNumber = false;
	// Пометка ввиде bool операции, если число дробное, то есть имеет одну точку.
	bool floatNumber = false;

	// Id символа (по идее точки) разделения целого числа и дробного числа в ( string_Numbers )
	int separate_Char_Id = 0;

	// Проверяю введёное число в строке на точку и минус
	// Если число отрицательное, то negativeNumber = true
	// Если число дробное, то floatNumber = true
	// Если точка повториться либо же минус, то метод выдаст -1
	for (int elementId = 0; elementId < string_Numbers.length(); elementId++)
	{
		char element = string_Numbers[elementId];

		if (element == '-')
			if (negativeNumber == true)
				return "-1";
			else
			{
				negativeNumber = true;
				// Заменяю знак минуса на незначащий ноль, чтобы в вычислении не мешался
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

	// Переменная для запоминания целой части переведённого числа string_Numbers по основанию ( base_System ) в систему счиления 10
	int integer_Numbers_In_System_Ten = 0;
	// Переменная для запоминания дробной части переведённого числа string_Numbers по основанию ( base_System ) в систему счиления 10
	float float_Numbers_In_System_Ten = 0;

	// 1.Перевожу число string_Numbers в 10-ричную систему счисления с помощью метода полинома
	// 2.Перевожу целое число ( integer_Numbers_In_System_Ten ) в систему счисления ( Target_System ) полиномом
	// 3.Перевожу дрробное число ( float_Numbers_In_System_Ten ) в систему счисления ( Target_System ) полиномом
	if (floatNumber == true)
	{
		// Перевожу целую часть в 10-ричную систему счисления
		for (int counter = separate_Char_Id - 1; counter >= 0; counter--)
		{
			// Символ из строки ( string_Numbers )
			char element = string_Numbers[counter];

			// Получаю число из буквы, если система счисления больше 10-ричной
			// Если система счисления не использует буквы, то получаю из символа цифру
			if (element > 58)								   // Выравниваю counter так, чтобы число base_System возводилось в степень 0..1..2 и т.д
				integer_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, (separate_Char_Id - 1) - counter);
			else											   // Выравниваю counter так, чтобы число base_System возводилось в степень 0..1..2 и т.д
				integer_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, (separate_Char_Id - 1) - counter);
		}

		// Перевожу дробную часть в 10-ричную систему счисления
		for (int counter = separate_Char_Id + 1; counter < string_Numbers.length(); counter++)
		{
			// Символ из строки ( string_Numbers )
			char element = string_Numbers[counter];

			// Получаю число из буквы, если система счисления больше 10-ричной
			// Если система счисления не использует буквы, то получаю из символа цифру
			if (element > 58)                                  // Выравниваю counter так, чтобы число base_System возводилось в степень -1..-2..-3 и т.д
				float_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, -(counter - separate_Char_Id));
			else											   // Выравниваю counter так, чтобы число base_System возводилось в степень -1..-2..-3 и т.д
				float_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, -(counter - separate_Char_Id));
		}

		// Переменные будут хранить деление с остатком на ( Target_System )
		int integer_Delimoe = integer_Numbers_In_System_Ten;
		int integer_Delimoe_Buffer = 0;

		// Переведу целую часть из 10-ричной системы счисления в ( Target_System )
		do
		{
			integer_Delimoe_Buffer = integer_Delimoe % Target_System;

			// Проверяем и по возможности заменяе числа, которые больше 9-ти, в системе счисления не меньше 11-ричной включительно
			if (integer_Delimoe_Buffer > 9)
				translated_number_To_Target_System = char(integer_Delimoe_Buffer + 55) + translated_number_To_Target_System;
			else
				translated_number_To_Target_System = to_string(integer_Delimoe_Buffer) + translated_number_To_Target_System;

			integer_Delimoe = integer_Delimoe / Target_System;

		} while (int(integer_Delimoe) != 0);

		// Добавляю разделительный знак для дальнейшего добавления дробной части
		translated_number_To_Target_System += ".";

		float float_Delimoe = float_Numbers_In_System_Ten;
		float float_Delimoe_Buffer = 0;

		// Переведу дробную часть из 10-ричной системы счисления в ( Target_System )
		do
		{
			float_Delimoe_Buffer = float_Delimoe * Target_System;

			// Проверяем и по возможности заменяе числа, которые больше 9-ти, в системе счисления не меньше 11-ричной включительно
			if (int(float_Delimoe_Buffer) > 9)
				translated_number_To_Target_System += char(int(float_Delimoe_Buffer) + 55);
			else
				translated_number_To_Target_System += to_string(int(float_Delimoe_Buffer));

			// По правилу перевода дробного числа из 10-ричной в любую систему счисления у нас целая часть забирается
			float_Delimoe = float_Delimoe_Buffer - int(float_Delimoe_Buffer);

		} while (float_Delimoe > 0);
	}
	else
	{
		// Перевожу целую часть в 10-ричную систему счисления
		for (int counter = string_Numbers.length() - 1; counter >= 0; counter--)
		{
			// Символ из строки ( string_Numbers )
			char element = string_Numbers[counter];

			// Получаю число из буквы, если система счисления больше 10-ричной
			// Если система счисления не использует буквы, то получаю из символа цифру
			if (element > 58)								   // Выравниваю counter так, чтобы число base_System возводилось в степень 0..1..2 и т.д
				integer_Numbers_In_System_Ten += (int(element) - 55) * pow(base_System, (string_Numbers.length() - 1) - counter);
			else											   // Выравниваю counter так, чтобы число base_System возводилось в степень 0..1..2 и т.д
				integer_Numbers_In_System_Ten += (int(element) - 48) * pow(base_System, (string_Numbers.length() - 1) - counter);
		}

		// Переменные будут хранить деление с остатком на ( Target_System )
		int integer_Delimoe = integer_Numbers_In_System_Ten;
		int integer_Delimoe_Buffer = 0;

		// Переведу целую часть из 10-ричной системы счисления в ( Target_System )
		do
		{
			integer_Delimoe_Buffer = integer_Delimoe % Target_System;

			// Проверяем и по возможности заменяе числа, которые больше 9-ти, в системе счисления не меньше 11-ричной включительно
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


