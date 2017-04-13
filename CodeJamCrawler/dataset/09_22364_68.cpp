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
    printf("Case #%d: ",_case);
    char s[55];scanf("%s",s);
    int l=strlen(s);
    bool ok=false;
    for(int i=l-1;i>=0;i--){
      for(int j=i+1;j<l;j++)
        if(s[j]>s[i]){
          ok=true;
        }
      if(ok){
        int cnt[10];CLEAR(cnt);
        for(int j=i;j<l;j++)
          cnt[s[j]-'0']++;
        REP(j,i)printf("%c",s[j]);
        for(int j=s[i]-'0'+1;;j++)
          if(cnt[j]){
            printf("%d",j);
            cnt[j]--;
            break;
          }
        REP(j,10)REP(k,cnt[j])printf("%d",j);
        printf("\n");
        break;
      }
    }
    if(ok)continue;
         int cnt[10];CLEAR(cnt);
         cnt[0]++;
        for(int j=0;j<l;j++)
          cnt[s[j]-'0']++;
        for(int j=1;;j++)
          if(cnt[j]){
            printf("%d",j);
            cnt[j]--;
            break;
          }
        REP(j,10)REP(k,cnt[j])printf("%d",j);printf("\n");
      
  }
  return 0;
}
