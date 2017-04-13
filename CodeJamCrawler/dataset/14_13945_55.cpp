#include <string>
#include <map>
#include <math.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#define fx first
#define sx second

typedef pair<int,int> ii;
typedef vector<int> vec;
typedef vector<ii> vecp;
typedef long long int lli;
typedef unsigned long long int ulli;

ii func(vector<double> na, vector<double> ke)
{
  sort(na.begin(), na.end());
  sort(ke.begin(), ke.end());
  int n=na.size();
  if(n==1)
  {
    return ii(na[0]>ke[0],na[0]>ke[0]);
  }

  int ind1=0;
  int i=0;
  int j=n-1;

  for (ind1 = 0; ind1 < n; ++ind1)
  {
    if(na[ind1]>ke[i])
    {
      ++i;
    }
    else
    {
      --j;
    }
  }
  int cnt1=i;

  ind1=0;
  i=0;
  j=n-1;

  for (ind1 = 0; ind1 < n; ++ind1)
  {
    if(ke[ind1]>na[i])
    {
      ++i;
    }
    else
    {
      --j;
    }
  }
  int cnt2=n-1-j;

  return ii(cnt1,cnt2);
}

int main()
{
  ifstream input;
  input.open("d0.in",ios::in);
  ofstream out;
  out.open("d.out",ios::out);
  // ofstream out2;
  // out2.open("bb.out",ios::out);


  int count;
  input>>count;
  vector<double> na,ke;

  for (int i = 1; i <= count; ++i)
  {
    int n;
    input>>n;
    na.clear();
    ke.clear();
    double temp;

    for (int j = 0; j < n; ++j)
    {
      input>>temp;
      na.push_back(temp);
    }

    for (int j = 0; j < n; ++j)
    {
      input>>temp;
      ke.push_back(temp);
    }

    ii o=func(na,ke);

    
    //printing the output
    out<<"Case #"<<i<<": ";
    out<<o.fx<<" "<<o.sx;
    cout<<o.fx<<" "<<o.sx<<endl;


    if(i<count) out<<endl;
  }

  return 0;
}
