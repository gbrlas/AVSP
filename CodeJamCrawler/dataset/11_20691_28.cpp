#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
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
#include <fstream>
using namespace std;

int main(){
  int cases;
  int cont = 0;
  int arm[110];
  scanf("%d",&cases);
  while(cases--){
    printf("Case #%d: ",++cont);
    int n;
    int l;
    int h;
    scanf("%d %d %d",&n,&l,&h);
    for(int i=0 ; i<n ; i++)
      scanf("%d",&(arm[i]));
    int minim = -1;
    for(int i=l ; i<=h&&minim==-1 ; i++){
      bool is = true;
      for(int j=0 ; j<n&&is ; j++)
	if(max(i,arm[j])%min(i,arm[j])) 
	  is = false;
      if(is) 
	minim = i;
    }
    if(minim==-1)
      printf("NO\n");
    else
      printf("%d\n",minim);
  }
  return 0;
}