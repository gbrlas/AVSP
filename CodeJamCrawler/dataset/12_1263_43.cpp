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
		int A = atoi(t.getToken());
		int B = atoi(t.getToken());
		double* p = new double[A+1];
		for(int a=1; a<=A; ++a)
		{
			p[a] = atof(t.getToken());
		}
		p[0] = 1.0;
		for(int pIdx=1; pIdx <= A; ++pIdx)
		{
			p[pIdx]*=p[pIdx-1];
		}
		double best = B + 2;
		double tmp = B-A+1;
		for(int keepchars=0; keepchars<=A; ++keepchars)
		{
			double expected = p[keepchars]*(static_cast<double>(A+B+1-2*keepchars)) + (1.0 - p[keepchars])*(static_cast<double>(A+2*B+2-2*keepchars));
			if(expected < best)
				best = expected;
		}
		fprintf(outF,"Case #%d: %f\n",i,best);
		delete[] p;
	}
	fclose(outF);
	fclose(inF);
	return 0;
}

