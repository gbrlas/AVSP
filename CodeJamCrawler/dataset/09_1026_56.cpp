// B1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "libfns.h"
#include <vector>

int _tmain(int argc, _TCHAR* argv[])
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
  char answer[32];
  size_t lenAnswer;
  bool need0;
  int testCases = atoi(t.getToken());
  for(int i=1; i<=testCases;++i)
  {
    need0 = true;
    memset(answer,0,32);
    strcpy(answer,t.getToken());
    lenAnswer = strlen(answer);
    for(size_t idx = 1; idx<lenAnswer;++idx)
    {
      if(answer[idx] > answer[idx-1])
      {
        need0 = false;
        idx=lenAnswer;
      }
    }

    if(need0 == true)
    {
      for(size_t x = lenAnswer; x > 0; --x)
      {
        answer[x] = answer[x-1];
      }
      answer[0] = '0';
      ++lenAnswer;
    }


    int j = lenAnswer-2;
    while (answer[j]>=answer[j+1])
      --j;
    
    int k = lenAnswer-1;
    while(answer[j]>=answer[k])
      --k;
    
    int temp;
    temp = answer[k];
    answer[k] = answer[j];
    answer[j] = temp;

    int last = lenAnswer-1;
    int first = j+1;

    while (last > first) {
      temp = answer[last];
      answer[last] = answer[first];
      answer[first] = temp;
      --last;
      ++first;
    }

    fprintf(outFile,"Case #%d: %s\n",i,answer);
  }
  fclose(outFile);
  fclose(inFile);
  return 0;
}

