#include "stdafx.h"
#include "Combi.h"
#include <iostream>
#include <ctime>

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Boat.h"

#define NN 36
#define MM 6
#define N 33
#define SPACE setw
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char  AA[][2] = { "A", "B", "C", "D", "E" };
	std::cout << std::endl << " --- Генератор сочетаний ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)

		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация сочетаний ";
	combi::xcombination xc(sizeof(AA) / 2, 3);
	std::cout << "из " << xc.n << " по " << xc.m;
	int  n = xc.getfirst();
	while (n >= 0)
	{

		std::cout << std::endl << xc.nc << ": { ";

		for (int i = 0; i < n; i++)


			std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

		std::cout << "}";

		n = xc.getnext();
	};
	std::cout << std::endl << "всего: " << xc.count() << std::endl;


	// СУДНО
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	int V = 1500;

	int  v[NN], c[NN];

	for (int i = 0; i < NN; i++)
	{
		v[i] = ((int)rand() / (int)RAND_MAX) * (900 - 100) + 100;;
		c[i] = ((int)rand() / (int)RAND_MAX) * (150 - 10) + 10;;
	}
	short r[MM];
	int maxcc = 0;
	clock_t t1, t2;
	cout << endl << "-- Задача об оптимальной загрузке судна -- ";
	cout << endl << "-  ограничение по весу    : " << V;
	cout << endl << "-  количество мест        : " << MM;
	cout << endl << "-- количество ------ продолжительность -- ";
	cout << endl << "   контейнеров        вычисления  ";
	for (int i = 25; i <= NN; i++)
	{
		t1 = clock();
		int maxcc = boat(V, MM, i, v, c, r);
		t2 = clock();
		cout << endl << SPACE(7) << setw(2) << i
			<< SPACE(15) << setw(5) << (t2 - t1);
	}
	cout << endl << endl;

	
	system("pause");
	return 0;
}
