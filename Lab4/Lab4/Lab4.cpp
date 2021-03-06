// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <ctime>
#include <cmath>
#include <memory.h>
#include "Levenshtein.h"
#include "MultyMatrix.h"
#define sz1 300
#define sz2 250
#define N 16
int main()
{
	setlocale(LC_ALL, "rus");
	clock_t t1 = 0, t2 = 0, t3, t4;
	//-----------Task1
	srand(time(NULL));
	char* str1 = new char[300];
	char* str2 = new char[250];
	int i = 0;
	for (i; i < 250; i++)
	{
		str2[i] = (char)(rand() % 25 + 65);
		str1[i] = (char)(rand() % 25 + 65);
	}
	str2[i] = 0x00;
	for(i; i< 300; i++) str1[i] = (char)(rand() % 25 + 65);
	str1[i] = 0x00;
	//-------------Task2
	int k[] = {100, 50, 25, 20, 10, 5, 4, 2, 1};
	int res[sizeof(k) / sizeof(int)];
	std::cout << "Исходные строки: " << std::endl;
	std::cout << str1 << std::endl;
	std::cout << "--------------------------------------------- " << std::endl;
	std::cout << str2 << std::endl;
	for (int i = 0; i < sizeof(k) / sizeof(int); i++)
	{
		t1 = clock();
		res[i] = levenshtein((int)(sz2/k[i]), str2, (int)(sz1/k[i]), str1);
		t2 = clock();
		std::cout << "Для размеров строк : " << sz2 / k[i] << " и " << sz1 / k[i] << "-----" <<res[i] <<std::endl;
		std::cout << "Время :" << (double)(t2 - t1) / (double)(CLOCKS_PER_SEC) << std::endl;
	}
	int r = levenshtein_r(3, "эхо", 5, "хорек");
	std::cout << r << std::endl;
	std::cout << "--------------------------------------------- " << std::endl;

	//---------------------------------------------------------------
	/*int Mc[N + 1] = { 11,19,50,8,22,29,39,10,13,23,44,33,53,6,15,16,14}, Ms[N][N], r = 0, rd = 0;
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	memset(Ms, 0, sizeof(int)*N*N);
	t1 = clock();
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	t2 = clock();
	std::cout << std::endl << "-- расстановка скобок (рекурсивное решение) "<< std::endl;
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: " << r;
	std::cout << std::endl << std::endl << "матрица S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++) std::cout << Ms[i][j] << " ";
	}
	std::cout << std::endl;
	memset(Ms, 0, sizeof(int)*N*N);
	t3 = clock();
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	t4 = clock();
	std::cout << std::endl<< "-- расстановка скобок (динамическое программирование) " << std::endl;
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: "<< rd;
	std::cout << std::endl << std::endl << "матрица S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++) std::cout << Ms[i][j] << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "Время на рекурсию:" << (double)(t2 - t1) / (double)(CLOCKS_PER_SEC) << std::endl;
	std::cout << "Время на динамический:" << (double)(t4 - t3) / (double)(CLOCKS_PER_SEC) << std::endl;*/
	system("pause");
    return 0; 
}


