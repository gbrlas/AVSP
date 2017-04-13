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
  int cases;
  int n;
  int s;
  int p;
  int y;
  int aux;
  int goo[110];
  int count_cases = 1;
  cin>>cases;
  while(cases--){
    cin>>n;
    cin>>s;
    cin>>p;
    for (int i=0 ; i<n ; i++)
    	cin>>goo[i];
    y = 0;
    for (int i=0 ; i<n ; i++){
    	aux = goo[i]/3+(goo[i]%3>0);
    	if(goo[i]>1&&(goo[i]%3!=1)&&s&&aux+1==p){
        aux++;
        s--;
    	}
    	y += aux>=p;
    }
    cout<<"Case #"<<count_cases++<<": "<<y<<endl;
  }
  return 0;
}
