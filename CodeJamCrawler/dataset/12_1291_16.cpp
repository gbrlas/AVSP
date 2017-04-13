#include "libfns.h"

int main(int argc, char* argv[])
{
	FILE* inF, *outF;
	getFiles(argc,argv,inF,outF);
	tokenizer t(inF);
	t.setSEPS(" \t\n");

	int cases = atoi(t.getToken());

	for(int x=1; x<=cases;++x)
	{
		std::map<int,int> sums;
		std::map<int,int>::iterator itr;
		int N = atoi(t.getToken());
		int* S = new int[N];
		for(int s=0; s<N; ++s)
		{
			S[s] = atoi(t.getToken());
		}
		for(int i=0; i<1048576; ++i)
		{
			int en = i;
			int counter=0;
			int tmpsum = 0;
			while(en>0)
			{
				if(en & 0x01)
				{
					tmpsum += S[counter];
				}
				en >>= 1;
				++counter;
			}
			itr = sums.find(tmpsum);
			if(itr != sums.end())
			{
				fprintf(outF,"Case #%d:\n",x);
				en = itr->second;
				counter=0;
				while(en>0)
				{
					if(en & 0x01)
					{
						fprintf(outF,"%d ",S[counter]);
					}
					en >>= 1;
					++counter;
				}
				fprintf(outF,"\n");
				en = i;
				counter=0;
				while(en>0)
				{
					if(en & 0x01)
					{
						fprintf(outF,"%d ",S[counter]);
					}
					en >>= 1;
					++counter;
				}
				fprintf(outF,"\n");
				i=1048576;
			}
			sums.insert(std::pair<int,int>(tmpsum,i));
		}
	}
	fclose(outF);
	fclose(inF);
	return 0;
}

