#include "stdio.h"
#include "stdlib.h"

static FILE *fin,*fout;
void PrintOutput (int casenum);
static int NbCases=0;
static int *PrisonList;
static int* FreePrison;
static int* Perms;
static int NbPrisons, NbFree,TotBribe;
static int count = 0;
static int* comb;
void visit(int *Value, int N, int k,int jump);
void NextPerm(int i , int perms);
int GetSum(int Free);
int GetBribe();

int main ()
{
  int LoopCounter = 1;
  int i,LeastBribe,perms,j;
  char LINE[101];
  char* Substr[1];

  fin = fopen("C-small.in", "rb");
  fout = fopen("C-small.out","wb");

  fgets(LINE , 100, fin);
  Substr[0] = strtok(LINE," ");
  NbCases = atoi(Substr[0]);
  
  while(LoopCounter <= NbCases)
  {
    perms = 1;
    fgets(LINE , 100, fin);
    Substr[0] = strtok(LINE," ");
    NbPrisons = atoi(Substr[0]);
    PrisonList = (int*) malloc(NbPrisons * sizeof(int));
    for (i = 0 ; i<NbPrisons ; i++)
      PrisonList[i] = 1;
    Substr[0] = strtok(NULL," ");
    NbFree = atoi(Substr[0]);
    FreePrison = (int*) malloc(NbFree * sizeof(int));
    Perms = (int*) malloc(NbFree * sizeof(int));
    comb = (int*) malloc(NbFree * sizeof(int));
    fgets(LINE , 100, fin);
    Substr[0] = strtok(LINE," ");
    for (i = 0 ;i<NbFree; i++)
    {
      FreePrison[i]=atoi(Substr[0]);
      Substr[0] = strtok(NULL," ");
    }
    for (i=NbFree; i >0; i--)
      perms = perms * i;
    for (i = 0 ;i<perms; i++)
    {
      for (j = 0 ; j<NbPrisons ; j++)
        PrisonList[j] = 1;
      NextPerm(i,NbFree);
      TotBribe = GetBribe();
      if(i == 0)
        LeastBribe = TotBribe;
      if(LeastBribe > TotBribe)
      {
        LeastBribe = TotBribe;
      }
    }
    TotBribe = LeastBribe;
    PrintOutput(LoopCounter);
    LoopCounter++;
  }
  fclose(fin);
  fclose(fout);
  printf("I am OUT\n");
  getch();
}

void PrintOutput (int casenum)
{
  fprintf(fout,"Case #%d: %d\n",casenum,TotBribe);
}

void NextPerm(int i, int Free)
{
  int Value[Free],j;

  for ( j = 0; j < Free; j++) 
  {
    comb[j] = 0;
    Value[j] = 0;
  }
  count = 0;
  visit(Value, Free, 0,i);
  for ( j = 0; j < Free; j++) 
  {
    Perms[j] = FreePrison[comb[j]-1];
    printf("%d",Perms[j]);
  }
  printf("\n");
}

int GetBribe()
{
  int i,sum = 0;
  for (i =0; i<NbFree; i++)
  {
    PrisonList[Perms[i]-1] = 0;
    sum = sum + GetSum(Perms[i]-1);
  }
  return sum;
}

int GetSum(int Free)
{
  int i, sum = 0;
  for(i = Free+1;(PrisonList[i]!=0)&&(i<NbPrisons); i++)
    sum++;
  for(i = Free-1;(PrisonList[i]!=0)&&(i>=0); i--)
  {
    sum++;
  }
  return sum;
}

void visit(int *Value, int N, int k,int jump)
{
  int i;
  static level = -1;
  level = level+1; Value[k] = level;

  if (level == N)
  {

    if(count == jump)
    {
      for (i = 0; i < N; i++)
        comb[i] = Value[i];
    }  
    count ++;
  }
  else
    for (i = 0; i < N; i++)
      if (Value[i] == 0)
        visit(Value, N, i,jump);

  level = level-1; Value[k] = 0;
}
