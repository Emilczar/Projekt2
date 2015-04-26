#include <iostream>
#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>


using namespace std;

const int n = 1000000; // zakres
int blok = 10;
bool numbersTable[n + 1]; // tablica o indeksach od 0 do 100 | wszystkie false (czyli: 0);
void rownolegle(){
	//Global variables:
	long int i = 0, j = 0;

	double nSqrt = sqrt(n);

	
#pragma omp parallel for shared(numbersTable)

	for (int i = 2; i <= n; i++) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (numbersTable[i] == true) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= n; j += i) // przejdŸ od liczby 2*i do n przesuwaj¹c siê o i
			numbersTable[j] = true; // i ka¿d¹ z nich usuwaj ze zbioru

	}

}
void rownolegle_2W(){
	omp_set_num_threads(2);
	long int i = 0, j = 0;

	double nSqrt = sqrt(n);


#pragma omp parallel for shared(numbersTable)

	for (int i = 2; i <= n; i++) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (numbersTable[i] == true) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= n; j += i) // przejdŸ od liczby 2*i do n przesuwaj¹c siê o i
			numbersTable[j] = true; // i ka¿d¹ z nich usuwaj ze zbioru

	}

}
void rownolegle_S(){
	//Global variables:
	long int i = 0, j = 0;

	double nSqrt = sqrt(n);


#pragma omp parallel for shared(numbersTable) schedule(static , blok)

	for (int i = 2; i <= n; i++) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (numbersTable[i] == true) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= n; j += i) // przejdŸ od liczby 2*i do n przesuwaj¹c siê o i
			numbersTable[j] = true; // i ka¿d¹ z nich usuwaj ze zbioru

	}

}
void rownolegle_D(){
	//Global variables:
	long int i = 0, j = 0;

	double nSqrt = sqrt(n);


#pragma omp parallel for shared(numbersTable) schedule(dynamic, blok)

	for (int i = 2; i <= n; i++) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (numbersTable[i] == true) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= n; j += i) // przejdŸ od liczby 2*i do n przesuwaj¹c siê o i
			numbersTable[j] = true; // i ka¿d¹ z nich usuwaj ze zbioru

	}

}
void rownolegle_2P(){
	//Global variables:
	HANDLE thread_uchwyt = GetCurrentThread();
	long int i = 0, j = 0;

	double nSqrt = sqrt(n);
	int th_id = omp_get_thread_num();
	DWORD_PTR mask = (1 << (th_id % 2));
	DWORD_PTR result = SetThreadAffinityMask(thread_uchwyt, mask);
	if (result == 0) printf("blad SetThreadAffnityMask \n");

#pragma omp parallel for shared(numbersTable)

	for (int i = 2; i <= n; i++) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (numbersTable[i] == true) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= n; j += i) // przejdŸ od liczby 2*i do n przesuwaj¹c siê o i
			numbersTable[j] = true; // i ka¿d¹ z nich usuwaj ze zbioru

	}

}
void rownolegle_2P_S(){
	//Global variables:
	HANDLE thread_uchwyt = GetCurrentThread();
	long int i = 0, j = 0;

	double nSqrt = sqrt(n);
	int th_id = omp_get_thread_num();
	DWORD_PTR mask = (1 << (th_id % 2));
	DWORD_PTR result = SetThreadAffinityMask(thread_uchwyt, mask);
	if (result == 0) printf("blad SetThreadAffnityMask \n");

#pragma omp parallel for shared(numbersTable) schedule(static , blok)

	for (int i = 2; i <= n; i++) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (numbersTable[i] == true) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= n; j += i) // przejdŸ od liczby 2*i do n przesuwaj¹c siê o i
			numbersTable[j] = true; // i ka¿d¹ z nich usuwaj ze zbioru

	}

}
void rownolegle_2P_D(){
	//Global variables:
	HANDLE thread_uchwyt = GetCurrentThread();
	long int i = 0, j = 0;

	double nSqrt = sqrt(n);
	int th_id = omp_get_thread_num();
	DWORD_PTR mask = (1 << (th_id % 2));
	DWORD_PTR result = SetThreadAffinityMask(thread_uchwyt, mask);
	if (result == 0) printf("blad SetThreadAffnityMask \n");

#pragma omp parallel for shared(numbersTable) schedule(dynamic, blok)

	for (int i = 2; i <= n; i++) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (numbersTable[i] == true) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= n; j += i) // przejdŸ od liczby 2*i do n przesuwaj¹c siê o i
			numbersTable[j] = true; // i ka¿d¹ z nich usuwaj ze zbioru

	}

}
int main()
{
	clock_t start, stop;
	
	start = clock();
	rownolegle();
	stop = clock();
	printf("PR %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_2W();
	stop = clock();
	printf("2W %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_S();
	stop = clock();
	printf("S %f sekund\n", ((double)(stop - start) / 1000.0));


	start = clock();
	rownolegle_D();
	stop = clock();
	printf("D  %f sekund\n", ((double)(stop - start) / 1000.0));
	
	
	start = clock();
	rownolegle_2P();
	stop = clock();
	printf("2P %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_2P_S();
	stop = clock();
	printf("2P_S %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_2P_D();
	stop = clock();
	printf("2P_D %f sekund\n", ((double)(stop - start) / 1000.0));
	// Print primes

	/*for (i = 2; i <= n; i++)
	if (numbersTable[i] == false)
	cout << i << endl; */
	return 0;
}