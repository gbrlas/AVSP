#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int old(int num, double* Nao, double* Ken)
{
	int n=0;
	int k = 0;
	while(k!=num&&n!=num)
	{
		if(Nao[n]<Ken[k])
		{
			n++;
			k++;
		}
		else
		{
			k++;
		}
	}
	if(n==num)
	{
		return 0;
	}
	else
	{
		return num-n;
	}
}

int newG(int num, double* Nao, double* Ken)
{
	int n=0;
	int k = 0;
	int kend = num-1;
	int total=0;
	while(n!=num&&k<=kend)
	{
		if(Nao[n]>Ken[k])
		{
			total++;
			n++;
			k++;
		}
		else
		{
			n++;
			kend--;
		}
	}
	return total;
}



int main()
{
	int size;
	scanf("%d",&size);
	for (int i = 0; i < size; ++i)
	{
		int num;
		scanf("%d",&num);
		double *Nao = (double *)malloc(num*sizeof(double));
		double *Ken = (double *)malloc(num*sizeof(double));
		for (int j = 0; j < num; ++j)
		{
			scanf("%lf",&Nao[j]);
		}
		for (int j = 0; j < num; ++j)
		{
			scanf("%lf",&Ken[j]);
		}
		sort(Nao,Nao+num);
		sort(Ken,Ken+num);
		int newScore = newG(num,Nao,Ken);
		int oldScore = old(num,Nao,Ken);
		free(Nao);
		free(Ken);
		printf("Case #%d: %d %d\n",i+1,newScore,oldScore);
	}
}