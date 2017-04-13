#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Problem-A

using namespace std;




struct donnee
{
	int indice;
	int proba;
};

int N;
donnee donne[1000];

int comparer(const void* a, const void* b)
{
	if((*(donnee*)b).proba - (*(donnee*)a).proba != 0) return (*(donnee*)b).proba - (*(donnee*)a).proba;
	else return (*(donnee*)a).indice - (*(donnee*)b).indice; 
}

int main()
{
	int T, i, j, k, test;
	scanf("%d", &T);
	for(test = 1; test <= T; test++)
	{
		printf("Case #%d: ", test);
		scanf("%d", &N);
		for(i = 0; i < N; i++) scanf("%*d");
		for(i = 0; i < N; i++) scanf("%d", &(donne[i].proba));
		for(i = 0; i < N; i++) donne[i].indice = i;	
		
		qsort(donne, N, sizeof(donnee), comparer);
		for(i = 0; i < N; i++) printf("%d ", donne[i].indice);
		printf("\n");
	}
	
	return 0;
}
