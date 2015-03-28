#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<stdlib.h>

#define N 1000000 // zakres
#define S 1000 // z braku pomys³u aby dzia³a³o sprt(N) wpisa³em recznie
#define M N/10

int main(){
	long int a[S + 1]; // tablica pomocnicza
	long int pierwsza[M]; // liczby pierwsze w przedziale 2..N
	long int i, k,liczba,reszta;
	long int lpodz; // liczba podzielnikow
	long int llpier = 0; // liczba  liczb pieewszych
	double czas;// zmiena do mierzenia czasu

	czas = omp_get_wtime();
	printf("start \n");
#pragma omp parallel for shared(a)
	
	for (i =2; i <= S; i++) a[i] = 1; // inicjowanie
	for (i =2; i <= S; i++)
	if (a[i] == 1){
	pierwsza[llpier++] = i; //zapamietanie podzielnika
	for (k = i + i; k <= S; k += i) a[k] = 0;
	}

	lpodz = llpier; //zapamietanie liczby podzielnikow
#pragma omp parallel for  private(k, reszta) shared(llpier, lpodz, pierwsza)
	for (liczba = S + 1; liczba <= N; liczba++){
		for (k = 0; k < lpodz; k++) {
			reszta = (liczba % pierwsza[k]);
			if (reszta == 0) break;
		}
		if (reszta != 0){
			#pragma omp critical
			pierwsza[llpier++] = liczba; // zapamietanie liczby pierwszej
			//printf("liczby: %d \n",liczba); // wypisanie licz pierwszych
		}
	}
	czas = omp_get_wtime()- czas;
	printf("czas: %f sek \n", czas);
	return 0;
}
