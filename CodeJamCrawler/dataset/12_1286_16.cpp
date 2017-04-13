#include "libfns.h"

int main(int argc, char* argv[])
{
	FILE* inF, *outF;
	getFiles(argc,argv,inF,outF);
	tokenizer t(inF);
	t.setSEPS(" \t\n");

	int cases = atoi(t.getToken());

	for(int i=1; i<=cases;++i)
	{
		int N = atoi(t.getToken());
		int* s = new int[N];
		int X=0;
		int overcount=0;
		int minIdx = 0;
		for(int si=0; si<N; ++si)
		{
			s[si] = atoi(t.getToken());
			if(s[si] < s[minIdx])
				minIdx = si;
			X+=s[si];
		}
		double mean = static_cast<double>(X)*2.0 / static_cast<double>(N);
		double available = static_cast<double>(X)*2.0;

		for(int si=0; si<N; ++si)
		{
			if(s[si] >= mean)
			{
				++overcount;
				available-=static_cast<double>(s[si]);
			}
		}
		fprintf(outF,"Case #%d: ",i);
		

		double newMean = static_cast<double>(available) / static_cast<double>(N-overcount);
		for(int si=0; si<N; ++si)
		{
			double m = newMean - static_cast<double>(s[si]);
			if(m < 0.0)
			{
				m = 0.0;
			}
			m/= static_cast<double>(X);
			fprintf(outF,"%f ",m*100.0);
		}
		fprintf(outF,"\n");
		delete[] s;
	}

	return 0;
}

