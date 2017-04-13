#include "libfns.h"

int lengthOfRow(int* row, int N)
{
  int last=-1;
  for(int i=0;i<N;++i)
  {
    if(row[i] == 1)
      last = i;
  }
  return last;
}

int main(int argc, char* argv[])
{
  if(argc!=2)
  {
    fprintf(stderr,"usage: %s infile\n",argv[0]);
    exit(0);
  }
  FILE* inFile = fopen(argv[1],"rt");
  if(!inFile)
  {
    fprintf(stderr,"Could not open %s\n",argv[1]);
    exit(0);
  }
  char outFileName[256] = {0};
  sprintf(outFileName,"%s.out.txt",argv[1]);
  FILE* outFile = fopen(outFileName,"wt");
  if(!outFile)
  {
    fprintf(stderr,"Could not open %s\n",outFileName);
    exit(0);
  }
  tokenizer t(inFile);
  t.setSEPS(" \t\n");
  int testCases = atoi(t.getToken());
  int N;
  int swaps;

  for(int testCase = 1; testCase <= testCases; ++testCase)
  {
    swaps = 0;
    char** tokens;
    N = atoi(t.getToken());
    tokens = new char*[N];
    int** Matrix = new int*[N];
    for(int i=0;i<N;++i)
    {
      Matrix[i] = new int[N];
      tokens[i] = new char[80];
      strcpy(tokens[i],t.getToken());
    }
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j)
        Matrix[i][j] = tokens[i][j]-'0';

    for(int rowToSet = 0; rowToSet < N; ++rowToSet)
    {
      int target = rowToSet;
      while(lengthOfRow(Matrix[target],N) > rowToSet && target<N)
      {
        ++target;
      }
      if(target == N)
        fprintf(stderr,"CRAP!");
      //bubble target up to rowToSet;
      int* tmp = Matrix[target];
      for(int x = target; x>rowToSet;--x)
      {
        Matrix[x] = Matrix[x-1];
        ++swaps;
      }
      Matrix[x] = tmp;
    }

    fprintf(outFile,"Case #%d: %d\n",testCase,swaps);

    for(int i=0;i<N;++i)
    {
      delete Matrix[i];
      delete tokens[i];
    }

    delete tokens;
    delete Matrix;
  }

  fclose(outFile);
  fclose(inFile);
  return 0;
}

