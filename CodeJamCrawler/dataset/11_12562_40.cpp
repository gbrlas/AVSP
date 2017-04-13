#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include <functional>
#include<vector>
#include<string>
#include <iostream>
#include <sstream>
#include<set>
#include<map>
#include<stdlib.h>
#include<queue>
//#include<cstdio>
//#include<cstdlib>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)


typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

double truncate(double x,int n)
{
	return (floor(x*pow(10,n))*pow(10,-n));
}
int min(int x,int y) {return x<y ? 1:0;}
int max(int x,int y) {return x>y ? 1:0;}
int main(void)
{
	FILE *in, *out;
	in = fopen("A-small-attempt0.in", "r");
	out= fopen("aOutput.out","w");

	int i,j,t,n,b,k, oInd, bInd, res;
	char r;
	int oPos, bPos;
	vector<int> oSeq, bSeq;
	vector<char> seq;
	fscanf(in,"%d\n", &t);
	//printf("%d\n", t);

	for(i=0;i<t;i++)
	{
		fscanf(in,"%d", &n);

		oSeq.resize(0);
		bSeq.resize(0);
		seq.resize(0);
		for(j=0;j<n;j++)
		{
			fscanf(in," %c %d",&r,&b);
			if(r =='O')
				oSeq.push_back(b);
			else
				bSeq.push_back(b);

			seq.push_back(r);
		}

		oInd = bInd = 0;
		oPos = bPos = 1;
		res = 0;
		k = 0;
		while(k<seq.size())
		{
			res++;
			if(seq[k] == 'O')
			{
				if(oPos == oSeq[oInd])
				{
					k++;
					oInd++;

					if(bPos != bSeq[bInd])
						bPos+= bSeq[bInd]>bPos ? 1:-1;

				}
				else
				{
					oPos+= oSeq[oInd]>oPos ? 1:-1;
					if(bPos != bSeq[bInd])
						bPos+= bSeq[bInd]>bPos ? 1:-1;
				}
			}
			else if(seq[k] == 'B')
			{
				if(bPos == bSeq[bInd])
				{
					k++;
					bInd++;

					if(oPos != oSeq[oInd])
						oPos+= oSeq[oInd]>oPos ? 1:-1;

				}
				else
				{
					bPos+= bSeq[bInd]>bPos ? 1:-1;
					if(oPos != oSeq[oInd])
						oPos+= oSeq[oInd]>oPos ? 1:-1;
				}

			}

		}

		fprintf(out, "Case #%d: %d\n", i+1, res);
	}
	return 0;
}
