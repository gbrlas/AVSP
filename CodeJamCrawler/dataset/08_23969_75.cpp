#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("A-small-attempt2.in");
#define cin fin


string engines[100];
bool useEngine[100];
int numE,numQ;
string queries[1000];

int check(string q)
{
   for(int i=0;i<numE;++i)
   {
      if(engines[i] == q)
      {
         return i;
      }
   }
   return -1;
}

void resetUseFlags()
{
   for(int i=0;i<numE;++i)
   {
      useEngine[i] = 1;
   }
}

int findBestEngine(int *nextStart)
{
   resetUseFlags();
   int enginesLeft = numE;
   //if(*nextStart > 0) --enginesLeft;
   for(int i=*nextStart;i<numQ;++i)
   {
      int bad = check(queries[i]);
      if(bad >= 0 && useEngine[bad])
      {
         useEngine[bad] = false;
         if(--enginesLeft == 0)
         {
            *nextStart = i;
            return bad;
         }
      }
   }
   *nextStart = numQ;
   for(int i=0;i<numE;++i)
   {
      if(useEngine[i]) return i;
   }
}

void rockNroll()
{
   int switches = 0;
   string throwaway;
   cin >> numE;
   getline(cin, throwaway);
   for(int i=0;i<numE;++i)
   {
      getline(cin, engines[i]);
      useEngine[i] = 1;
   }
   cin >> numQ;
   getline(cin, throwaway);
   for(int i=0;i<numQ;++i)
   {
      getline(cin, queries[i]);
   }
   int nextStart = 0;
   while(nextStart < numQ)
   {
      int bestE = findBestEngine(&nextStart);
      //cout << "used " << engines[bestE] << " through " << nextStart-1 << endl;
      if(nextStart < numQ)
         ++switches;
   }
   cout << switches << endl;//<< " switches." << endl;
}

int main()
{
   int cases;
   cin >> cases;
   for(int i=1;i<=cases;++i)
   {
      cout << "Case #" << i << ": ";
      rockNroll();
   }
}
