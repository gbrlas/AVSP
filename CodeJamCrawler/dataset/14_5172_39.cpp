#include <stdio.h>

int main()
{
	FILE *fin;
	FILE *fout;

	int TestCase;
	int iT;
	int iCnt;

	double C;
	double F;
	double X;
	double Ans;
	double newAns;
	double diff;
	double Tmp;

	fin = fopen("B-Large.in", "r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d", &TestCase);

	for(iT = 1; TestCase >= iT; ++iT)
	{
		fscanf(fin,"%lf %lf %lf", &C, &F, &X);
		iCnt = 0;
		Ans = X/2+1;
		Tmp = 0.;
		while(1)
		{
			newAns = Tmp + X/(2+iCnt*F);
			diff = newAns - Ans;
			if(diff > 0. ) break;
			Tmp = Tmp + C/(2+iCnt*F);
			Ans = newAns;
			++iCnt;
		}
		fprintf(fout,"Case #%d: %0.7lf\n",iT, Ans);
	}


	fclose(fin);
	fclose(fout);

	return 0;
}