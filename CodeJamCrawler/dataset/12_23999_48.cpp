//I use publicly available and free program lp_solve (lpsolve.sourceforge.net) to solve integer programming instances generated in the code
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
    int n;scanf("%d",&n);
    int a[2222];
    REP(i,n-1)scanf("%d",&a[i]);
    REP(i,n-1)a[i]--;
    FILE *f=fopen("l.lp","w");
    fprintf(f,"min: ");
    REP(i,n){
      if(i!=0)fprintf(f,"+");
      fprintf(f,"x%d",i);
    }
    fprintf(f,";\n");
    REP(i,n-1){
      for(int j=i+1;j<n;j++)if(a[i]!=j){
        ll d2=a[i]-i;
        ll d1=j-i;
        if(j<a[i]){d2*=100000;
                   d1*=100000;}
        fprintf(f,"%Ld*x%d-%Ld*x%d",d2,j,d2,i);
        if(j<a[i])fprintf(f,"+1");
        fprintf(f,"<=");
        fprintf(f,"%Ld*x%d-%Ld*x%d;\n",d1,a[i],d1,i);
      }
    }
    REP(i,n)fprintf(f,"x%d>=0;\n",i);
    REP(i,n)fprintf(f,"int x%d;\n",i);
    fclose(f);
    remove("sol.txt");
    system("./lp_solve l.lp > sol.txt");
    f=fopen("sol.txt","r");
    char s[10000];
    fgets(s,10000,f);
    fgets(s,10000,f);
    if(s[0]=='T'){printf(" Impossible\n");continue;}
    fgets(s,10000,f);
    fgets(s,10000,f);
    REP(i,n){
      ll H;
      fscanf(f,"%s%Ld",s,&H);
      printf(" %Ld",H);
      if(H>1000000000){printf("Zle je\n");return 0;}
    }
    printf("\n");
  }
  return 0;
}
