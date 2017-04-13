#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#define PI acos(-1.0)
using namespace std;

int main(){
  string go = "ynficwlbkuomxsevzpdrjgthaq";
  string en = "abcdefghijklmnopqrstuvwxyz";
  map<char,char> m;
  m[' '] = ' ';
  for (int i=0 ; i<go.length() ; i++)
  	m[go[i]] = en[i];
  int cases;
  cin>>cases;
  string line;
  getline(cin,line);
  int count = 1;
  while(cases--){
    cout<<"Case #"<<count++<<": ";
    getline(cin,line);
    for (int i=0 ; i<line.length() ; i++)
    	putchar(m[line[i]]);
    cout<<endl;
  }
  return 0;
}
