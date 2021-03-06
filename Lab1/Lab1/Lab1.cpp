#include "pch.h"
#include <iostream>
#include "Auxil.h" // вспомогательные функции 
#include <iostream> 
#include <ctime> 
#include <locale>
//locale - используется для задач, связанных с локализацией
#define CYCLE 1000000 // количество циклов
int main()
{
	double av1 = 0, av2 = 0;
	clock_t t1 = 0, t2 = 0, t21=0, t22=0;
	setlocale(LC_ALL, "rus");
	auxil::start(); // старт генерации 
	t1 = clock();		// фиксация времени
	// clock() возвращает количество тактов, прошедших с момента запуска программы
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
	}
	t2 = clock();
	//------------------
	t21 = clock();		// фиксация времени
	for (int i = 0; i < CYCLE; i++)
	{
		av2 += auxil::dget(-100, 100); // сумма случайных чисел 
	}
	t22 = clock();
	std::cout << std::endl << "количество циклов: " << CYCLE;
	std::cout << std::endl << "среднее значение (int): " << av1 / CYCLE;
	std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
	std::cout << std::endl << "продолжительность для iget (у.е): " << (t2 - t1);
	std::cout << std::endl << "                  (сек): " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	// CLOCKS_PER_SEC - количество тактов за секунду
	std::cout << std::endl << "продолжительность для dget (у.е): " << (t22 - t21);
	std::cout << std::endl << "                  (сек): " << ((double)(t22 - t21)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	system("pause");
	return 0;
}


