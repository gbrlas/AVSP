#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define maxn 100

typedef struct {
	long long amount;
	int type;
} Product;

Product Box[maxn];
Product Toy[maxn];

int boxs, toys;

long long best = 0;

void Backtrack(int i, int j, long long cur)//i indicates box, j indicate toy
{
	if(i == boxs || j == toys)
	{
		if(cur > best) 
		{ 
			best = cur;
		}
		return ;
	}

	if(Box[i].type == Toy[j].type)
	{
		if(Box[i].amount > Toy[j].amount) 
		{	
			Box[i].amount -= Toy[j].amount;
			Backtrack(i, j+1, cur+Toy[j].amount);
			Box[i].amount += Toy[j].amount;
		}
		else if(Box[i].amount < Toy[j].amount)
		{
			Toy[j].amount -= Box[i].amount;
			Backtrack(i+1, j, cur+Box[i].amount);
			Toy[j].amount += Box[i].amount;
		}
		else
		{
			Backtrack(i+1, j+1, cur+Box[i].amount);
		}
		return;
	}
	
	Backtrack(i+1, j, cur);
	Backtrack(i, j+1, cur);

}

int main()
{
	FILE *fp = fopen("C:\\Users\\Jeffrey\\Desktop\\A-small.in", "r");
	FILE *fp1 = fopen("C:\\Users\\Jeffrey\\Desktop\\output.txt", "w");
	int T = 0;
	int t = 0;

	fscanf(fp, "%d", &T);

	while(t++ < T)
	{	
		long long cur = 0;
		int i = 0, j = 0;
		
		best = 0;
		cur = 0;

		fscanf(fp, "%d%d", &boxs, &toys);
		for(i = 0; i < boxs; i++)
			fscanf(fp, "%lld%d", &Box[i].amount, &Box[i].type);
		for(i = 0; i < toys; i++)
			fscanf(fp, "%lld%d", &Toy[i].amount, &Toy[i].type);

		Backtrack(0, 0, cur);


		fprintf(fp1, "Case #%d: %lld\n", t, best);
	}

	fclose(fp);
	fclose(fp1);
	return 0;
}
