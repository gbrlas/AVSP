#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map <char, char> h;

int main()
{
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  vector <string> g;
  g.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
  g.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
  g.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");

  vector <string> e;
  e.push_back("our language is impossible to understand");
  e.push_back("there are twenty six factorial possibilities");
  e.push_back("so it is okay if you want to just give upi");


  for (int i = 0; i < g.size(); i++)
  {
    for (int j = 0; j < g[i].size(); j++)
        h[ g[i][j]] =  e[i][j];
  }


  h['z'] = 'q';
  h['q'] = 'z';

  string line;
  int n;
  scanf("%d\n", &n);

   
  for (int cases = 1; cases <= n; cases++)
  {
    getline(cin, line);
    for (int i = 0; i < line.size(); i++)
        line[i] = h[line[i]];
    cout << "Case #" << cases << ": " << line << '\n';
  }
  return 0;
}