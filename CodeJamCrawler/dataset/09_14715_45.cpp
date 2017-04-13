#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <map>
#include <set>

using namespace std;

void parse(const string& s, int& pos, int n, map<int,double>& value, map<int,string>& feature)
{
  if (pos >= s.size()) return;
  if (s[pos] == ' ')
  {
    parse(s, ++pos, n, value, feature);
    return;
  }

  if (s[pos] == '(')
  {
    int k;
    double v;
    sscanf(s.c_str()+pos+1, "%lf%n", &v, &k);
    pos += k + 1;
    value[n] = v;

    while (s[pos] == ' ') ++pos;
    if (s[pos] == ')') { ++pos; return; }

    char buf[200];
    sscanf(s.c_str()+pos, "%s%n", &buf, &k);

    feature[n] = buf;

    pos += k;
    parse(s,pos,2*n+1,value,feature);
    parse(s,pos,2*n+2,value,feature);
    while (s[pos] == ' ') ++pos;
    assert(s[pos] == ')');
    ++pos;
  }
  else
  {
    assert(s[pos] == ')');
    ++pos;
  }
}

int main()
{
  freopen( "A-small-attempt0.in", "rt", stdin );
  freopen( "a.out", "wt", stdout );

  string line;
  getline(cin, line);

  int N;
  {
    istringstream iss(line);
    iss >> N;
  }

  for (int t = 0; t < N; ++t)
  {
    int L;

    {
      getline(cin, line);
      istringstream iss(line);
      iss >> L; 
    }
    string s;
    for (int i = 0; i < L; ++i)
    {
      getline(cin,line);
      s += line;
    }

    map<int,double> value;
    map<int,string> feature;

    int pos = 0;
    parse(s, pos, 0, value, feature);

    int A;
    {
      getline(cin,line);
      istringstream iss(line);
      iss >> A;
    }

    printf("Case #%d: \n", t+1);
    for (int i = 0; i < A; ++i)
    {
      getline(cin, line);
      istringstream iss(line);

      set<string> f;

      string name;
      string ff;
      int n;
      iss >> name >> n;
      for (int j = 0; j < n; ++j)
      {
        iss >> ff;
        f.insert(ff);
      }

      double p = 1;
      int x = 0;
      for (;;)
      {
        p *= value[x];
        if (feature[x].empty()) break;
        x = (f.count(feature[x]) ? 2*x+1 : 2*x+2);
      }

      printf("%lf\n", p);
    }
  }
  return 0;
}
