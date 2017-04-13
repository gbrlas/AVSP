#include <stdio.h>

// 오름차순
int ascending(const void* a, const void* b)
{
	if(*(double *)a > *(double *)b)
	return 1;
	else if(*(double *)a < *(double *)b)
  	return -1;
 	else
 	return 0;
}

// 내림차순
int descending(const void* a, const void* b)
{
	if(*(double *)a < *(double *)b)
	return 1;
	else if(*(double *)a > *(double *)b)
  	return -1;
 	else
 	return 0;
}


int main()
{
	FILE *fin;
	FILE *fout;

	int TestCase;
	int iT;
	int iCnt;
	int ArrSize;
	int Dena;
	// DecitFul War 의 나오미의 이긴판
	int nDena;
	// 정직한 나오미의 이긴판
	int NaPos;
	int KenPos;

	double NaArr[1000];
	double KenArr[1000];

	fin = fopen("D-small-attempt0.in", "r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d", &TestCase);

	for(iT = 1; TestCase >= iT; ++iT)
	{
		fscanf(fin,"%d", &ArrSize);
		for(iCnt = 0; ArrSize > iCnt; ++iCnt)
		{
			fscanf(fin,"%g", &NaArr[iCnt]);
		}
		for(iCnt = 0; ArrSize > iCnt; ++iCnt)
		{
			fscanf(fin,"%g", &KenArr[iCnt]);
		}

		qsort(NaArr, ArrSize, sizeof(double), ascending);
		qsort(KenArr, ArrSize, sizeof(double), ascending);
		Dena = 0;
		NaPos = 0;
		KenPos = 0;
		while(1)
		{
			if(NaArr[NaPos] > KenArr[KenPos])
			{
				Dena+=1;
				++KenPos;
			}
			++NaPos;
			if(NaPos == ArrSize)break;
		}
		nDena = ArrSize;
		NaPos = 0;
		KenPos = 0;
		while(1)
		{
			if(NaArr[NaPos] < KenArr[KenPos])
			{
				nDena-=1;
				++NaPos;
			}
			++KenPos;
			if(KenPos == ArrSize)break;
		}
		
		fprintf(fout,"Case #%d: %d %d\n", iT, Dena, nDena);
	}


	fclose(fin);
	fclose(fout);

	return 0;
}