#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#define CLEAR(X) memset(X,0,sizeof(X))

char names[1010][1010];
int s,q;
char query[1010][1010];
int a[1010][1010];
bool c[1010][1010];

int f(int en, int ind){
  if (ind==q) return 0;
  if (a[en][ind]!=-1) return a[en][ind];
  a[en][ind]=1000000;

  for(int i=0;i<s;i++)
    if (c[i][ind]){
      int v = f(i,ind+1);
      if (i!=en)v++;
      a[en][ind]=min(a[en][ind],v);
  }
  return a[en][ind];
};

int main(){
  int xx;scanf("%d",&xx);
  for(int xxx=1;xxx<=xx;xxx++){
    memset(a,-1,sizeof(a));
    scanf("%d ",&s);
    for(int i=0;i<s;i++)gets(names[i]);
    scanf("%d ",&q);
    for(int i=0;i<q;i++)gets(query[i]);
    for(int i=0;i<s;i++)for(int j=0;j<q;j++) c[i][j]=(strcmp(names[i],query[j])!=0);
    int an=f(0,0);
    for(int i=1;i<s;i++)an=min(an,f(i,0));
    printf("Case #%d: %d\n",xxx,an);
  };
  return 0;
}
