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
#include <queue>

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

struct O{
  int mult;
  int val;
  O(int m, int v){mult=m;val=v;}
};

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d: ",_case);
    int a[1000];
    int n;scanf("%d",&n);
    REP(i,n)scanf("%d",&a[i]);
    int cnt[10100];
    CLEAR(cnt);
    REP(i,n)cnt[a[i]]++;
    int ocnt[10100];
    CLEAR(ocnt);
    REP(i,n)ocnt[a[i]]++;
    sort(a,a+n);
    if(n==0){printf("0\n");continue;}
    for(int len=n;len>0;len--){
      int end[10100];CLEAR(end);
      bool ok=true;
      for(int i=1;i<=10000;i++){
/*          while(cnt[i]>0 && end[i]>0){
            cnt[i]--;
            end[i]--;
            end[i+1]++;
          }*/
          int m = min(cnt[i],end[i]);
          cnt[i]-=m;
          end[i]-=m;
          end[i+1]+=m;
          if(cnt[i]>0){
            int k=cnt[i];
            REP(j,len)
              if(cnt[i+j]>=k)cnt[i+j]-=k;
              else{ok=false;break;}
            end[i+len]+=k;
          }
      }
      if(ok){printf("%d\n",len);break;}
      CLEAR(cnt);
      REP(i,n)cnt[a[i]]++;
/*      queue<O> q;
      int index=0;
      bool ok=true;
      while(index<n && ok){
        while(!q.empty() && index<n){
          O o = q.front();
          if(o.val < a[index]){ok=false;break;}
          if(o.val == a[index]){
            if(o.mult>1)q.push(O(o.mult-1,o.val+1));
            index++;
            q.pop();
          }
          if(o.val > a[index])break;
        }
        if(index<n){
          int cur=a[index];
          while(index<n && a[index]==cur){
            if(i>1)q.push(O(i-1,cur+1));
            index++;
          }
        }
      }
      if(ok && q.empty()){printf("%d\n",i);break;}*/
    }
  }
  return 0;
}
