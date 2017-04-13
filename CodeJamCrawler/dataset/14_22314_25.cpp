// one.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//



#include "stdafx.h"
#include "stdio.h"
#define _CRT_SECURE_NO_DEPRECATE

int _tmain(int argc, _TCHAR* argv[])
{
	int iTestCases = 0;
	int iAnswer1 = 0; // row in "Before"
	int iAnswer2 = 0; // row in "After"
	int iArrangementBefore[4][4];
	int iArrangementAfter[4][4];

	int iCard = 0;

	//read input
	FILE *fpIn = fopen("A-small-attempt5.in", "r");
	FILE *fpOut = fopen("out.txt", "w");
	if (fpIn == NULL) {
		return 1;
	}

	fscanf(fpIn, "%d", &iTestCases);
	for (int i = 0; i < iTestCases; i++){
		fscanf(fpIn, "%d", &iAnswer1);
		iAnswer1 -= 1;
		for (int j = 0; j < 4; j++){
			fscanf(fpIn, "%d %d %d %d ", &iArrangementBefore[j][0], &iArrangementBefore[j][1], &iArrangementBefore[j][2], &iArrangementBefore[j][3]);
		}
		fscanf(fpIn, "%d", &iAnswer2);
		iAnswer2 -= 1;
		for (int j = 0; j < 4; j++){
			fscanf(fpIn, "%d %d %d %d ", &iArrangementAfter[j][0], &iArrangementAfter[j][1], &iArrangementAfter[j][2], &iArrangementAfter[j][3]);
		}

		//find card
		for (int iFind = 0; iFind < 4; iFind++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (iArrangementBefore[iAnswer1][iFind] == iArrangementAfter[iAnswer2][j])
				{
					if (iCard == 0){
						iCard = iArrangementBefore[iAnswer1][iFind];
					}
					else if (iCard > 0)
					{
						iCard = -1;
					}
				}
			}
		}

		if (iCard > 0){
			fprintf(fpOut, "Case #%d: %d\n", i + 1, iCard);
		}
		else if (iCard == 0) {
			fprintf(fpOut, "Case #%d: Volunteer cheated!\n", i + 1, iCard);
		}
		else{
			fprintf(fpOut, "Case #%d: Bad magician!\n", i + 1, iCard);
		}
		iCard = 0;
	}
	fclose(fpIn);
	fclose(fpOut);





	return 0;
}

