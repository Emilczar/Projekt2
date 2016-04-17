#include <iostream>
#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<stdlib.h>

using namespace std;

const int n = 1000000; // zakres

bool numbersTable[n + 1]; // tablica o indeksach od 0 do 100 | wszystkie false (czyli: 0);

int main()
{
	//Global variables:
	long int i = 0, j = 0;
	double time;// zmiena do mierzenia czasu
	double nSqrt = sqrt(n);

	time = omp_get_wtime();
	printf("start \n");
#pragma omp parallel for shared(numbersTable)
	
	for (int i = 2; i <= n; i++) // przeszukuj liczby od 2 do sqrt(n), 0 i 1 nie s¹ liczbami pierwszymi
	{
		if (numbersTable[i] == true) // je¿eli dana liczba jest ju¿ wykreœlona
			continue; // to przejdŸ do kolejnej
		for (int j = 2 * i; j <= n; j += i) // przejdŸ od liczby 2*i do n przesuwaj¹c siê o i
			numbersTable[j] = true; // i ka¿d¹ z nich usuwaj ze zbioru
	}

	time = omp_get_wtime() - time;
	printf("czas: %f sek \n", time);

	// Print primes
	/*for (i = 2; i <= n; i++) 
	if (numbersTable[i] == false) 
		cout << i << endl; */
	return 0;
}