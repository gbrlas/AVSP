#include <stdio.h>
#include <string.h>

int main()
{
	FILE * fin;
	FILE * fout;

	int TestCase;
	int iT;
	int N;
	char str[100][101]={0};

	int iNum;
	int iCnt1;
	int iCnt2;
	int ans;
	int len[100];

	char ch;

//	fin = fopen("input.txt", "r");
	fin = fopen("A-small-attempt0.in", "r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d", &TestCase);

	for(iT = 1; TestCase >= iT; ++iT)
	{
		ans = 0;
		fscanf(fin,"%d", &N);
		for(iCnt1 = 0; iCnt1 < N; ++iCnt1)
		{
			fscanf(fin,"%s",str[iCnt1]);
		}
		
		len[0] = strlen(str[0]);
		len[1] = strlen(str[1]);

		iCnt2 = 0;
		iCnt1 = 0;
		iNum = 0;
		
		while(iCnt1 != len[0] || iCnt2 != len[1])
		{
			while(str[0][iCnt1] == str[1][iCnt2])
			{
			//	printf("%d %d\n", iCnt1, iCnt2);		
				++iCnt1;
				++iCnt2;
				
				if(str[0][iCnt1] == 0 && str[1][iCnt2] == 0)break;
			}
			while(str[0][iCnt1] == str[1][iCnt2-1])
			{
			//	printf("%d %d\n", iCnt1, iCnt2);		
				++iCnt1;
				++iNum;
				
			if(str[0][iCnt1] == 0 && str[1][iCnt2] == 0)break;
			}
			while(str[0][iCnt1-1] == str[1][iCnt2])
			{		
		//		printf("%d %d\n", iCnt1, iCnt2);
				++iCnt2;
				++iNum;
				
			if(str[0][iCnt1] == 0 && str[1][iCnt2] == 0)break;
			}
			if(str[0][iCnt1] != str[1][iCnt2])
			{
				iNum = -1;
				break;
			}
			if(str[0][iCnt1] == 0 && str[1][iCnt2] == 0)break;
		}

		if(iNum >= 0)
		{
			fprintf(fout,"Case #%d: %d\n", iT,iNum);
		}
		else
		{
			fprintf(fout,"Case #%d: %s\n", iT,"Fegla Won");
		}
	}


	fclose(fin);
	fclose(fout);

	return 0;
}