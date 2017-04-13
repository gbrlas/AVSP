#include "stdio.h"
#include "stdlib.h"

static FILE *fin,*fout;
static int NbWords, NbChar,NbCases,NbPerm=0,NbHit=0;
static char** Dictionary;
static char Msg[1000];
void CheckPossibilities ();
void PrintOutput (int casenum);
void HitParanth();

int main ()
{
  int LoopCounter = 1;
  int i,j;
  char LINE[1001];
  char* Substr[1];

  fin = fopen("A-large.in", "rb");
  fout = fopen("A-large.out","wb");

  fgets(LINE , 1000, fin);
  Substr[0] = strtok(LINE," ");
  NbChar = atoi(Substr[0]);
  Substr[0] = strtok(NULL," ");
  NbWords = atoi(Substr[0]);
  Substr[0] = strtok(NULL," ");
  NbCases = atoi(Substr[0]);

  Dictionary = (char**) malloc (NbWords * sizeof(char**));
  for (i = 0 ; i< NbWords; i++)
  {
    Dictionary[i] = (int*) malloc (NbChar * sizeof(int*));
    fgets(Dictionary[i] , 100, fin);
  }
  while(LoopCounter <= NbCases)
  {
    fgets(Msg , 1000, fin);
    NbHit = 0;
    NbPerm = 0;
    CheckPossibilities();
    PrintOutput(LoopCounter);
    LoopCounter++;
    free(Msg);
  }
  fclose(fin);
  fclose(fout);
}

void PrintOutput (int casenum)
{
  fprintf(fout,"Case #%d: %d\n",casenum,NbPerm);
}

void CheckPossibilities()
{
  int i = 0;
  int Counter = 0;
  int TempHit = 0;
  for (Counter = 0 ; Counter < NbWords ; Counter ++)
  {
    i = 0;
    NbHit = 0;
    while((Msg[i] != '\n') || (Msg[i] != '\r'))
    {
      if((Msg[i] == '('))
      {
        TempHit = NbHit;
        while(Msg[i] != ')')
        {
          if (TempHit == NbHit)
          {
            if(Dictionary[Counter][TempHit] == Msg[i])
            {
              NbHit ++;
              if (NbHit == NbChar)
              {
                break;
              }
            }
          }
          i++;
        }
      }
      else
      {
        if(Dictionary[Counter][NbHit] == Msg[i])
        {
          NbHit ++;

          if (NbHit == NbChar)
          {
            break;
          }
       }
        else
          break;
      }
      i++;
    }
    if (NbHit == NbChar)
    {
      printf("%s\n",Dictionary[Counter]);
      NbPerm ++;
    }
  }
}

