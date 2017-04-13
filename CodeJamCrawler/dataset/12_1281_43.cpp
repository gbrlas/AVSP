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
		int stars = 0;
		int completedLevels = 0;
		int runs = 0;
		int levels = atoi(t.getToken());
		bool* completedA = new bool[levels];
		bool* completedB = new bool[levels];
		int* a = new int[levels];
		int* b = new int[levels];
		for(int lev = 0; lev<levels; ++lev)
		{
			completedA[lev] = false;
			completedB[lev] = false;
			a[lev] = atoi(t.getToken());
			b[lev] = atoi(t.getToken());
		}

		bool possible=true;
		while(completedLevels < levels)
		{
			bool found = false;
			//seek out a 2 star available
			for(int lev=0; lev<levels; ++lev)
			{
				if(!completedB[lev] && b[lev] <= stars)
				{
					++runs;
					completedB[lev] = true;
					++stars;
					if(!completedA[lev])
					{
						completedA[lev] = true;
						++stars;
					}
					++completedLevels;
					found = true;
					lev = levels;
				}
			}
			if(!found) //try for a 1 star level
			{
				//want the largest B val that fits
				int bVal = 0;
				int idx = 0;
				for(int lev=0; lev<levels; ++lev)
				{
					if(!completedA[lev] && a[lev] <= stars)
					{
						if(b[lev] > bVal)
						{
							bVal = b[lev];
							idx = lev;
						}
						found = true;
					}
				}
				if(found)
				{
					++runs;
					completedA[idx]=true;
					++stars;
				}
			}
			if(!found)
			{
				possible=false;
				levels = completedLevels;
			}
		}
		if(possible)
		{
			fprintf(outF,"Case #%d: %d\n",i,runs);
		}
		else
		{
			fprintf(outF,"Case #%d: Too Bad\n",i);
		}


		delete[] a;
		delete[] b;
		delete[] completedA;
		delete[] completedB;
	}
	fclose(outF);
	fclose(inF);
	return 0;
}

