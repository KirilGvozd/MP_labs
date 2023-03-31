#include "pch.h"
#include "Auxil.h"
#include <iostream>
#include <ctime>
#include <locale>

#define CYCLE 10000000

int Fibonacci(int i)
{
	int value = 0;
	if (i < 1) {
		return 0;
	}
	if (i == 1) {
		return 1;
	}
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	double firstAverage = 0, secondAverage = 0;
	clock_t startTime = 0, endTime = 0;

	setlocale(LC_ALL, "rus");

	Auxil::start();
	startTime = clock();
	for (int i = 0; i < CYCLE; i++)
	{
		firstAverage += (double)Auxil::iget(-100, 100);
		secondAverage += Auxil::dget(-100, 100);
	}
	endTime = clock();


	cout << endl << "\nКоличество циклов: " << CYCLE;
	cout << endl << "Среднее значение (int): " << firstAverage / CYCLE;
	cout << endl << "Среднее значение (double): " << secondAverage / CYCLE;
	cout << endl << "Продолжительность (CLOCKS_PER_SEC): " << (endTime - startTime);
	cout << endl << "Продолжительность (сек): " << ((double)(endTime - startTime)) / ((double)CLOCKS_PER_SEC) << "\n";

	for (int n = 1; n <= 35; n++)
	{
		startTime = clock();
		int num = Fibonacci(n);
		endTime = clock();
		cout << endl << n << "-е число Фибоначчи: " << num << ". Время на нахождение числа: " << (endTime - startTime) << " CLOCKS_PER_SEC";
	}
	cout << endl;
	system("pause");

	return 0;
}