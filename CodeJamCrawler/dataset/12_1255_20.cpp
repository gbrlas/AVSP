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
		int answer = 0;
		int N = atoi(t.getToken());
		int S = atoi(t.getToken());
		int p = atoi(t.getToken());
		int normalScore = p*3 - 2;
		if(normalScore < 0)
			normalScore = 0;
		int surpScore = p*3 - 4;
		if(p<2)
			surpScore = p;
		for(int n = 0; n<N; ++n)
		{
			int score = atoi(t.getToken());
			if(score >= normalScore)
				++answer;
			else if(score >= surpScore && S>0)
			{
				++answer;
				--S;
			}
		}
		fprintf(outF,"Case #%d: %d\n",i,answer);
	}
	fclose(outF);
	fclose(inF);
	return 0;
}

