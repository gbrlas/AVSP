#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<map>
using namespace std;

inline int parse() 
{
  string str;
  cin >> str;
  return ((str[0]-'0')*10 + (str[1]-'0'))*60 + (str[3]-'0')*10 + (str[4]-'0');
}

int main(int argc, char*argv[])
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int tat, a, b;
    cin >> tat >> a >> b;
    multimap<int,pair<int,int> > ss;
    for(int j = 0; j < a; j++) {
      int de = parse();
      int ar = parse();
       ss.insert(pair<int,pair<int,int> >(de, pair<int,int>(ar,0)));
    }
    for(int j = 0; j < b; j++) {
      int de = parse();
      int ar = parse();
      ss.insert(pair<int,pair<int,int> >(de, pair<int,int>(ar,1)));
    }
    int as[2];
    as[0] = 0;
    as[1] = 0;
    int abs[2][24*60+100];
    for(int k = 0; k < 24*60+100; k++) {
      abs[0][k] = 0;
      abs[1][k] = 0;
    }
    int t = 0;
    for(multimap<int,pair<int,int> >::const_iterator it = ss.begin(); it!=ss.end(); it++){
      int td = (*it).first;
      while(t < td) {
	abs[0][t+1] += abs[0][t];
	abs[1][t+1] += abs[1][t];
	t++;
      }
      int ds = (*it).second.second;
      if(abs[ds][t]==0) {
	  abs[ds][t]++;
	  as[ds]++;
	}
	abs[ds][t]--;
	abs[ds^1][(*it).second.first + tat]++;
    }
    cout << "Case #" << i << ": " << as[0] << " " << as[1] << endl;
   }
  return 0;
}
