#include <stdio.h>

int main()
{
	FILE * fin;
	FILE * fout;

	int TestCase;
	int iT;

	int iNum;
	int iCnt1;
	int iCnt2;

	int iNum1;
	int iNum2;

	int tmp;
	
	long long ans;

	int A,B,K;
	
	fin = fopen("B-small-attempt0 (1).in", "r");
//	fin = fopen("input.txt", "r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d", &TestCase);

	for(iT = 1; TestCase >= iT; ++iT)
	{
		fscanf(fin,"%d %d %d", &A, &B, &K);
	/*	tmp = A;
		ans = 0;
		iCnt1 = 1;
		iCnt2 = 1;
		iNum = 0;
		iNum1 = 0;
		iNum2 = 0;*/
		
		iNum = 0;
	/*	while(tmp>1)
		{
			tmp/=2;
			iCnt1*=2;
			iNum1++;
		}
		
		tmp = B;
		while(tmp>1)
		{
			tmp/=2;
			iCnt2*=2;
			iNum2++;
		
		}	

		if(K >A && K >B)
		{
			ans = A*B;
		}
		else if(B < A)
		{
			if(K <= B)
			{
				ans = K*A+(B-K)*(iNum1-1)*K;//+(A-iCnt1)*(B-K);
			
			}
			else if(K > B)
			{	
				ans = A*B;
			}
		}
		else if(A <= B)
		{
			if(K < A)
			{
				ans = K*B+(A-K)*(iNum2-1)*K;//+(B-iCnt2)*(A-K);
			}
			else if(K >= A)
			{

				ans = A*B;
			}
		}
*/

	//	printf("%d %d %d\n",A,B,K);
		for(iCnt1 = 0; iCnt1 < A; ++iCnt1)
		{
			for(iCnt2 = 0; iCnt2< B; ++iCnt2)
			{
				if((iCnt1&iCnt2) < K)
				{
				//	printf("%d %d\n", iCnt1, iCnt2);
					iNum++;
				}
			}
		}

		fprintf(fout,"Case #%d: %d\n", iT,iNum);
	}


	fclose(fin);
	fclose(fout);

	return 0;
}