#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

// #define TEST
#define FOR(i, a, b) for(int i=(a); i < (b); i++)
#define MAX_SIZE 512

static int turn;
static fstream fin(stdin);
#ifdef TEST
static FILE* infile = stdin; // fopen(inName, "r");
#else
static char* inName = "B-small.in";
static FILE* infile = fopen(inName, "r");
#endif
static char* outFile = "output.txt";
static FILE* fout = fopen(outFile, "w");


struct train
{
  int freetime;
  int curloc;
};

int read_int() 
{ 
#if 0
  char str[1024];
  fin.getline(str, MAX_SIZE);
  int x; 
  sscanf(str, "%d", &x); 
  return x; 
#endif
  int x; 
#ifdef TEST
  scanf("%d", &x); 
#else
  fscanf(infile, "%d", &x); 
#endif
  return x;
}

string read_string() 
{
  char str[1024]; 
#if 0
  fin.getline(str, MAX_SIZE);
#if 0
  char ch; int count = 0;
  while( (ch = getchar()) != '\n')
    str[count++] = ch;
  str[count] = '\0';
  string ret = str; 
#endif
#endif
#ifdef TEST
  scanf("%s", str);
#else
  fscanf(infile, "%s", str);
#endif
  // printf("name = %s\n", str);
  return str; 
}

int time_to_mins(int hh, int mm)
{
  return hh * 60 + mm;
}

pair<int, int> min_trains(vector< pair<int, int> >& a, vector< pair<int, int> >& b)
{
  vector<train> trains;
  int apos = 0, bpos = 0, atrains = 0, btrains = 0;
  for(; apos < a.size() || bpos < b.size();)
  {
    int tsize = trains.size();
    pair<int, int> pp; 
    int loc; 
    if(apos < a.size() && bpos < b.size())
    {
      pp = (a[apos].first < b[bpos].first) ? a[apos] : b[bpos];
      loc = (a[apos].first < b[bpos].first) ? 0 : 1;
      if(a[apos].first < b[bpos].first) apos++;
      else bpos++;
    }
    else if(apos < a.size())
    {
      pp = a[apos];
      loc = 0;
      apos++;
    }
    else
    {
      pp = b[bpos];
      loc = 1;
      bpos++;
    }

    bool found = false;
    FOR(i, 0, tsize)
    {
      if(trains[i].curloc == loc && trains[i].freetime <= pp.first)
      {
        found = true;
        trains[i].freetime = pp.second + turn;
        trains[i].curloc = trains[i].curloc ^ 0x1;
        break;
      }
    }

    if(!found)
    {
      train t;
      if(loc == 0) atrains++;
      else btrains++;
      t.curloc = loc ^ 0x1;
      t.freetime = pp.second + turn;
      trains.push_back(t);
    }

    tsize = trains.size();
#if 0
    fprintf(fout, "Situation of trains : \n");
    FOR(i, 0, tsize)
      fprintf(fout, "Train num %d, location = %d, freetime = %d\n", i, trains[i].curloc, trains[i].freetime);
#endif
  }

  return make_pair(atrains, btrains);
}

int main()
{
  int N = read_int();
  FOR(test, 0, N)
  {
    turn = read_int();
    // string str = read_string();
    int NA = read_int(), NB = read_int();
    printf("NA = %d, NB = %d\n", NA, NB);
    // sscanf(str.c_str(), "%d %d", &NA, &NB);
    vector< pair<int, int> > a(NA), b(NB);

    FOR(i, 0, NA)
    {
      string s = read_string();
      int ah, am, dh, dm;
      sscanf(s.c_str(), "%d:%d", &ah, &am);
      s = read_string();
      sscanf(s.c_str(), "%d:%d", &dh, &dm);
      int arrm = time_to_mins(ah, am), depm = time_to_mins(dh, dm);
      a[i] = make_pair(arrm, depm);
    }

    FOR(i, 0, NB)
    {
      string s = read_string();
      int ah, am, dh, dm;
      sscanf(s.c_str(), "%d:%d", &ah, &am);
      s = read_string();
      sscanf(s.c_str(), "%d:%d", &dh, &dm);
      int arrm = time_to_mins(ah, am), depm = time_to_mins(dh, dm);
      b[i] = make_pair(arrm, depm);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    pair<int, int> res = min_trains(a, b);
#ifdef TEST
    printf("Case #%d: %d %d\n", test+1, res.first, res.second);
#else
    fprintf(fout, "Case #%d: %d %d\n", test+1, res.first, res.second);
#endif
  }

  return 0;
}
