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
  vector<string> result(110);
  vector<vector<int> > rel(110);
  double W[110][3];
  double pj[110];
  double pg[110];
  int cases;
  int cont = 0;
  scanf("%d",&cases);
  while(cases--){
    printf("Case #%d:\n",++cont);
    int n;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
      pj[i] = 0;
      pg[i] = 0;      
      rel[i].clear();
      cin>>result[i];
    }
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<n ; j++){
	pj[i] += result[i][j]!='.';
	pg[i] += result[i][j]=='1';
	if(result[i][j]!='.')
	  rel[j].push_back(i);
      }
      W[i][0] = pg[i]/pj[i];
    }
    for(int i=0 ; i<n ; i++){
      double acu = 0;
      for(int j=0 ; j<rel[i].size() ; j++)
	acu += (pg[rel[i][j]]-(result[rel[i][j]][i]=='1'))/(pj[rel[i][j]]-1);
      W[i][1] = acu/(double)rel[i].size();
    }
    for(int i=0 ; i<n ; i++){
      double acu = 0;
      for(int j=0 ; j<rel[i].size() ; j++)
	acu += W[rel[i][j]][1];
      W[i][2] = acu/(double)rel[i].size();
    }
    for(int i=0 ; i<n ; i++)
      printf("%lf\n",0.25*W[i][0] + 0.50*W[i][1] + 0.25*W[i][2]);
  }
  return 0;
}