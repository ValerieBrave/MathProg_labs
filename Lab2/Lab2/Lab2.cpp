// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime> 
#include <locale>
#include <iomanip> 
#include "Combi.h"
#include "Boat.h"
#include "Auxil.h"
#define N (sizeof(AA)/2)
#define M 3
#define NN 8
#define MM 8

int main()
{
	setlocale(LC_ALL, "rus");
	char AA[][2] = { "A", "B", "C", "D" };
	std::cout << "----Генератор множества всех подмножеств----\nИсходное множество: \n{";
	for (int i = 0; i < sizeof(AA) / 2; i++)
	{
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? "," : " ");
	}
	std::cout << "}\n";
	std::cout << "Генерация всех подмножеств \n";
	combi::subset *s1 = new combi::subset(sizeof(AA) / 2);
	int n = s1->getfirst();
	while (n >= 0)
	{
		std::cout << "{ ";
		for (int i = 0; i < n; i++) std::cout << AA[s1->ntx(i)] << ((i < n - 1) ? ", " : " ");
		std::cout << "}\n";
		n = s1->getnext();
	}
	std::cout << "Всего : " << s1->count() << std::endl;
	//------------------------------------------------------------------------
	std::cout << std::endl << " --- Генератор сочетаний ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++) std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация сочетаний ";
	combi::xcombination xc(sizeof(AA) / 2, 3);
	std::cout << "из " << xc.n << " по " << xc.m;
	int  n2 = xc.getfirst();
	while (n2 >= 0)
	{
		std::cout << std::endl << xc.nc << ": { ";
		for (int i = 0; i < n2; i++) std::cout << AA[xc.ntx(i)] << ((i < n2 - 1) ? ", " : " ");
		std::cout << "}";
		n2 = xc.getnext();
	};
	std::cout << std::endl << "всего: " << xc.count() << std::endl;
	//-----------------------------------------------------------------------
	std::cout << std::endl << " --- Генератор перестановок ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++) std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация перестановок ";
	combi::permutation p(sizeof(AA) / 2);
	__int64  n3 = p.getfirst();
	while (n3 >= 0)
	{
		std::cout << std::endl << std::setw(4) << p.np << ": { ";
		for (int i = 0; i < p.n; i++) std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
		std::cout << "}";
		n3 = p.getnext();
	};
	std::cout << std::endl << "всего: " << p.count() << std::endl;
	//-----------------------------------------------------------------------
	std::cout << std::endl << " --- Генератор размещений ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < N; i++) std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;
	combi::accomodation s(N, M);
	int  n4 = s.getfirst();
	while (n4 >= 0)
	{
		std::cout << std::endl << std::setw(2) << s.na << ": { ";
		for (int i = 0; i < 3; i++) std::cout << AA[s.ntx(i)] << ((i < n4 - 1) ? ", " : " ");
		std::cout << "}";
		n4 = s.getnext();
	};
	std::cout << std::endl << "всего: " << s.count() << std::endl;
	//-------------------------------------------------------------------------------
	clock_t t1 = 0, t2 = 0;
	int *v = new int[NN]; // вес
	int *c = new int[NN]; // доход 
	int *minv = new int[MM];   // минимальный  вес 
	int *maxv = new int[NN];    // максимальный вес
	short r[MM];
	for (int i = 0; i < NN; i++)
	{
		v[i] = 100 + rand() % 200;
		c[i] = 10 + rand() % 100;
	}
	for (int j = 0; j < MM; j++)
	{
		minv[j] = 50 + rand() % 120;
		maxv[j] = 150 + rand() % 850;
	}
	auxil::start(); // старт генерации 
	t1 = clock();
	int cc = boat_с(
		MM,    // [in]  количество мест для контейнеров
		minv,  // [in]  максимальный вес контейнера на каждом  месте 
		maxv,  // [in]  минимальный вес контейнера на каждом  месте  
		NN,    // [in]  всего контейнеров  
		v,     // [in]  вес каждого контейнера  
		c,     // [in]  доход от перевозки каждого контейнера   
		r      // [out] номера  выбранных контейнеров  
	);
	t2 = clock();
	std::cout << std::endl << "- Задача о размещении контейнеров на судне -";
	std::cout << std::endl << "- общее количество контейнеров   : " << NN;
	std::cout << std::endl << "- количество мест для контейнеров  : " << MM;
	std::cout << std::endl << "- минимальный  вес контейнера  : ";
	for (int i = 0; i < MM; i++) std::cout << std::setw(3) << minv[i] << " ";
	std::cout << std::endl << "- максимальный вес контейнера  : ";
	for (int i = 0; i < MM; i++) std::cout << std::setw(3) << maxv[i] << " ";
	std::cout << std::endl << "- вес контейнеров      : ";
	for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";
	std::cout << std::endl << "- доход от перевозки     : ";
	for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";
	std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1) : ";
	for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
	std::cout << std::endl << "- доход от перевозки     : " << cc << std::endl;
	std::cout << "время выполнения - " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << "сек" << std::endl;
	system("pause");
	return 0;
}