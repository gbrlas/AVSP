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
#include <sstream>

using namespace std;

#define CLEAR(X) memset(X,0,sizeof(X))
#define REP(i,n) for(int i=0;i<(n);i++) 
template <class T> vector<T>parse(string s,const char d=' '){
  vector<T> v; string p; s+=d; int i=0; 
  while(i<(int)s.size())
    if (s[i] == d){stringstream u; u<<p; T t; u>>t; v.push_back(t); p=""; while(i<(int)s.size() && s[i]==d)i++;} else p+=s[i++];   
  return v;
} 

typedef long long ll;
typedef long double ld;

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);

    int k;
    char s[10100];
    scanf("%d %s",&k,s);
    int a[10];
    REP(i,k)a[i]=i;
    char ns[10100];
    int l=strlen(s);

    int bl=l;

    do{
      for(int i=0;i<l;i+=k)
        REP(j,k)
          ns[i+j]=s[i+a[j]];
     
      int q=1;
      for(int i=1;i<l;i++)if(ns[i]!=ns[i-1])q++;
      if(q<bl)bl=q;


    }while(next_permutation(a,a+k));
    printf(" %d\n",bl);


  }
  return 0; 
}
