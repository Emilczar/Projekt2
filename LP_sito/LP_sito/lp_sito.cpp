#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<stdlib.h>

#define N 10000000
#define S sqrt(N)
#define M N/10

int main(int argc, char** argv){
	
	
	int a[S + 1];
	long int pierwsza[M];
	long int i, k,liczba,reszta;
	long int lpodz;
	long int llpier = 0;
	double czas;

	czas = omp_get_wtime();
#pragma omp parallel for default(none) shared(a)
	for (i = 2; i <= S; i++)
	for (i = 2; i <= S; i++)
	if (a[i] == 1){
		pierwsza[llpier++] = i;
		for (k = i + i; k <= S; k += i) a[k] = 0;
	}

	lpodz = llpier;
#pragma omp parallel for default(nome) private(k,reszta) shared(llpier,lpodz,pierwsza)
	for (liczba = S + 1; liczba <= N;liczba++){
		for (k = 0; k < lpodz; k++){
			reszta = (liczba %pierwsza[k]);
			if (reszta == 0) break;
		}
		if (reszta != 0){
#pragma omp critical
			pierwsza[llpier++] = liczba;
		}
	}
	
	czas = omp_get_wtime()- czas;
	printf("czas: %f sek \n", czas);

	return 0;
}
