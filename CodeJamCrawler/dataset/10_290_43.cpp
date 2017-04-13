#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
	int t;
	int k;
	int r;
	int n;
	int g;
	int t1,t2;
	int qs;
	int count;
	FILE* fpi;
	FILE* fpo;

	fpi = fopen("C-small.in", "r");
	fpo = fopen("output.out", "w");
	
	fscanf(fpi,"%d",&t);
	for (int i = 0; i < t; i++)
	{
		queue<int> mq;

		fscanf(fpi,"%d%d%d",&r,&k,&n);
		for (int j = 0; j < n; j++)
		{
			fscanf(fpi,"%d",&g);
			mq.push(g);
		}

		t2 = 0;
		for (int j = 0; j < r; j++)
		{
			t1 = 0;
			count = 0;
			qs = mq.size();
			while(t1 + mq.front() <= k && count < qs)
			{
				t1 += mq.front();
				mq.push(mq.front());
				mq.pop();
				count++;
			}
			t2 += t1;
		}

		fprintf(fpo,"Case #%d: %d\n",i + 1, t2);
	}

	fclose(fpo);
	fclose(fpi);
	return 0;
}