#include "libfns.h"
#include <math.h>

double dist(int x1, int y1, int x2, int y2)
{
  double retval = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
  retval = sqrt(retval);
  return retval;
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

  int** arr;
  for(int testCase = 1; testCase<= testCases; ++testCase)
  {
    double answer;
    double tmp;
    int N = atoi(t.getToken());
    arr = new int*[N];
    for(int plant = 0; plant<N; ++plant)
    {
      arr[plant] = new int[3]; //X,Y,R
      arr[plant][0] = atoi(t.getToken());
      arr[plant][1] = atoi(t.getToken());
      arr[plant][2] = atoi(t.getToken());
    }

    if(N==1)
      answer = arr[0][2];

    if(N==2)
    {
      if(arr[0][2] < arr[1][2])                   
        answer = arr[1][2];
      else
        answer = arr[0][2];
    }

    if(N==3)
    {
      double answers[3];
      double distances[3];
      distances[0] = dist(arr[0][0],arr[0][1],arr[1][0],arr[1][1]);
      tmp = arr[0][2] + arr[1][2];
      distances[0]+=tmp;
      distances[0]/=2;
      tmp = arr[2][2];
      if(distances[0] <= tmp)
        answers[0] = tmp;
      else
        answers[0] = distances[0];

      distances[1] = dist(arr[1][0],arr[1][1],arr[2][0],arr[2][1]);
      tmp = arr[1][2] + arr[2][2];
      distances[1]+=tmp;
      distances[1]/=2;
      tmp = arr[0][2];
      if(distances[1] <= tmp)
        answers[1] = tmp;
      else
        answers[1] = distances[1];

      distances[2] = dist(arr[0][0],arr[0][1],arr[2][0],arr[2][1]);
      tmp = arr[0][2] + arr[2][2];
      distances[2]+=tmp;
      distances[2]/=2;
      tmp = arr[1][2];
      if(distances[2] <= tmp)
        answers[2] = tmp;
      else
        answers[2] = distances[2];

      if(answers[0] < answers[1])
        if(answers[0] < answers[2])
          answer=answers[0];
        else
          answer=answers[2];
      else if(answers[1] < answers[2])
        answer = answers[1];
      else
        answer = answers[2];
    }

    fprintf(outFile,"Case #%d: %.6f\n",testCase,answer);
    for(int plant = 0; plant<N; ++plant)
    {
      delete[] arr[plant]; //X,Y,R
    }
    delete[] arr;

  }





  fclose(outFile);
  fclose(inFile);
  return 0;
}

