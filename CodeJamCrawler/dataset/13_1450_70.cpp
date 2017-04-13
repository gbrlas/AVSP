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
    int N = atoi(t.getToken()); // rows
    int M = atoi(t.getToken()); // cols

    int* lawn = new int[N*M];
    std::set<int> badspots;
    std::set<int>::iterator itr;

    for(int j=0; j<N*M; ++j)
    {
      lawn[j] = atoi(t.getToken());
      badspots.insert(j);
    }

    //find good spots in each row
    for(int row=0; row<N; ++row)
    {
      int maxrowval = -1;
      for(int col=0; col<M; ++col)
      { //find max height
        if(lawn[row*M + col] > maxrowval)
        {
          maxrowval = lawn[row*M + col];
        }
      }
      for(int col=0; col<M; ++col)
      { //mark max height as good
        if(lawn[row*M + col] == maxrowval)
        {
          itr = badspots.find(row*M + col);
          if(itr != badspots.end())
            badspots.erase(itr);
        }
      }
    }

    //find good spots in each col
    for(int col=0; col<M; ++col)
    {
      int maxcolval = -1;
      for(int row=0; row<N; ++row)
      { //find max height
        if(lawn[row*M + col] > maxcolval)
        {
          maxcolval = lawn[row*M + col];
        }
      }
      for(int row=0; row<N; ++row)
      { //mark max height as good
        if(lawn[row*M + col] == maxcolval)
        {
          itr = badspots.find(row*M + col);
          if(itr != badspots.end())
            badspots.erase(itr);
        }
      }
    }

    fprintf(outF,"Case #%d: %s\n",i,(badspots.size()>0)?"NO":"YES");
	}
	fclose(outF);
	fclose(inF);
	return 0;
}

