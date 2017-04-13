// R2A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdio.h"
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[])
{
	// File Handling;
	int num_case,casecnt;
	FILE *fp_in=NULL, *fp_out=NULL;

	int p;
	int k;
	int l;
	int cnt = 1;

	int tmp=0;
	long fr;

	vector<long> freq;
	vector<long>::reverse_iterator rt;

	long max[2000];
	double prod=0;

	fp_in = fopen("D:\\Jam\\A-small-attempt0.in","r");
	fp_out = fopen("D:\\Jam\\A-small.out","w");

	fscanf(fp_in, "%d\n", &num_case);

	for(casecnt=0;casecnt<num_case;casecnt++)
	{
		cnt=1;
		tmp=0;
		freq.clear();
		prod = 0.0;

		fscanf(fp_in, "%d %d %d ", &p, &k, &l);

		for(int j=0;j<l;j++)
		{
			fscanf(fp_in, "%d ",&fr);
			freq.push_back(fr);
		}

		sort(freq.begin(), freq.end());

		
		for(int i=0;i<2000;i++)
			max[i]=0;

		for(rt=freq.rbegin(); rt!=freq.rend();++rt)
		{
			//while(max[tmp] == p) tmp++;
			
			prod += (*rt)*cnt;

			max[tmp]++;
		
			if(tmp+1 >= k)
			{
				tmp = 0;
				cnt++;
			}
			else
				tmp++;
		}
		
		fprintf(fp_out, "Case #%d: %.0lf\n", casecnt+1, prod);
		printf("Case #%d: %.0lf\n", casecnt+1, prod);
	}
	
	return 0;
}
