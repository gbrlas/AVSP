#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int caseVal;
int main(void)
{
	FILE *fp = fopen("2_result.txt", "w");
	cin >> caseVal;
	double c, f, x, been_per_sec, prev_sec, next_sec;
	for(int caseIndex = 0; caseIndex < caseVal; caseIndex++)
	{
		scanf("%lf %lf %lf", &c, &f, &x);
		been_per_sec = 2;
		prev_sec = 0;
		while(true)
		{
			next_sec = prev_sec + c/been_per_sec;
			if(prev_sec + x/been_per_sec <= next_sec + x/(been_per_sec+f))
				break;
			been_per_sec += f;
			prev_sec = next_sec;
		}
		fprintf(fp, "Case #%d: ", caseIndex+1);
		fprintf(fp, "%.7lf\n", prev_sec + x/been_per_sec);
	}
	return 0;
}