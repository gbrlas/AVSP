#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i < (b); i++)
#define MAX_SIZE 512

char* fileName = "A-small.in";
ifstream fin(fileName);
char* outFileName = "output.txt";
FILE* fout = fopen(outFileName, "w");

char str[1024];

int arr[101][1001];

int read_int() 
{ 
  fin.getline(str, MAX_SIZE);
  int x; 
  sscanf(str, "%d", &x); 
  return x; 
}

string read_string() 
{ 
  // char str[1024]; 
  fin.getline(str, MAX_SIZE);
#if 0
  char ch; int count = 0;
  while( (ch = getchar()) != '\n')
    str[count++] = ch;
  str[count] = '\0';
  string ret = str; 
#endif
  // printf("name = %s\n", str);
  return str; 
}

set<string> n;
vector<string> names;
vector<string> queries;

int doit(int S, int Q)
{
  for(int i = Q - 1; i >= 0; i--)
  {
    FOR(j, 0, S)
    {
      string query = queries[i], name = names[j];
      if(query == name)
      {
        if(i == Q-1) arr[j][i] = 1;
        else
        {
          int min = 1 << 30;
          FOR(k, 0, S)
            if(min > arr[k][i + 1] && k != j) min = arr[k][i + 1];
          arr[j][i] = min + 1;
        }
      }
      else 
      {
        if(i != Q - 1)
          arr[j][i] = arr[j][i + 1];
        else arr[j][i] = 0;
      }
    }
  }

  int ret = 1 << 30;
  FOR(i, 0, S)
    if(ret > arr[i][0]) ret = arr[i][0];
  return ret;
}

int main()
{
  int T = read_int();

  FOR(test, 0, T)
  {
    memset(arr, sizeof(arr), 0);
    names.clear();
    queries.clear();
    int S = read_int();

    FOR(i, 0, S)
    {
      string str = read_string();
      names.push_back(str);
    }

    // printf("Names entered, Not enter queries\n");
#if 0
    for(set<string>::iterator itor = n.begin(); itor != n.end(); ++itor)
      names.push_back(*itor);
    S = names.size();
#endif

    int Q = read_int();
    FOR(i, 0, Q)
    {
      string str = read_string();
      queries.push_back(str);
    }

    int res = doit(S, Q);
    fprintf(fout, "Case #%d: %d\n", test + 1, res);
  }

  return 0;
}

