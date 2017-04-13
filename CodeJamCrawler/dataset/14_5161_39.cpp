#include <stdio.h>

int main()
{
	int Arr1[4];
	int Arr2[4];
	int TestCase;
	int row1;
	int row2;
	int iCnt1;
	int iCnt2;
	int iCnt;
	int iAns;
	int iNum;
	FILE *fp;
	FILE *fpinput;

	fp = fopen("output.txt","w");
	fpinput = fopen("A-small-attempt2.in","r");

	fscanf(fpinput,"%d", &TestCase);

	for(iCnt = 1; TestCase + 1>iCnt; ++iCnt)
	{
		fscanf(fpinput,"%d", &row1);
		for(iCnt1 = 1; 5 > iCnt1; ++iCnt1)
		{
			if(iCnt1 == row1)
			{
				for(iCnt2 =0; 4 > iCnt2; ++iCnt2)
				{
					fscanf(fpinput,"%d", &Arr1[iCnt2]);
				}
			}
			else
			{
				for(iCnt2 =0; 4 > iCnt2; ++iCnt2)
				{
					fscanf(fpinput,"%d", &iNum);
				}
			}
		}
		fscanf(fpinput,"%d", &row2);
		for(iCnt1 = 1; 5 > iCnt1; ++iCnt1)
		{
			if(iCnt1 == row2)
			{
				for(iCnt2 =0; 4 > iCnt2; ++iCnt2)
				{
					fscanf(fpinput,"%d", &Arr2[iCnt2]);
				}
			}
			else
			{
				for(iCnt2 =0; 4 > iCnt2; ++iCnt2)
				{
					fscanf(fpinput,"%d", &iNum);
				}
			}
		}

		iAns = 0;
		for(iCnt1 = 0; 4 > iCnt1; ++iCnt1)
		{
			for(iCnt2 =0; 4 > iCnt2; ++iCnt2)
			{
				if(Arr2[iCnt2] == Arr1[iCnt1])
				{
					iNum = Arr1[iCnt1];
					++iAns;
				}
			}	
		}

		if(iAns > 1 )
		{
			fprintf(fp,"Case #%d: %s\n",iCnt,"Bad magician!");
		}
		else if(iAns == 1)
		{
			fprintf(fp,"Case #%d: %d\n",iCnt,iNum);
		}
		else
		{
			fprintf(fp,"Case #%d: %s\n",iCnt,"Volunteer cheated!");
		}
	}

	fclose(fp);	
	fclose(fpinput);	

	return 0;
}