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

int sumx[555][555];
int sumy[555][555];
int sum[555][555];

int sq(int x1, int y1, int x2, int y2, int a[555][555]){
  return a[y2][x2] - a[y2][x1] - a[y1][x2] + a[y1][x1];
}

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);
    int r,c,d;cin>>r>>c>>d;
    int w[500][500];
    CLEAR(w);
    REP(i,r){
      string s;cin>>s;
      REP(j,c)w[i][j]=s[j]-'0';
//      REP(j,c)w[i][j]+=d;
    }

    CLEAR(sumx);CLEAR(sumy);CLEAR(sum);
    for(int i=1;i<=r;i++)
      for(int j=1;j<=c;j++){
        sumx[i][j] = sumx[i-1][j] + sumx[i][j-1] - sumx[i-1][j-1] + w[i-1][j-1]*j;
        sumy[i][j] = sumy[i-1][j] + sumy[i][j-1] - sumy[i-1][j-1] + w[i-1][j-1]*i;
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + w[i-1][j-1];
      }
    int res=0;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)for(int k=3;k+i<=r && k+j<=c;k++){
      ll sx = sq(j,i,j+k,i+k,sumx);
      ll sy = sq(j,i,j+k,i+k,sumy);
      ll ss = sq(j,i,j+k,i+k,sum);
//      cout<<i<<" "<<j<<" "<<k<<" "<<sx<<" "<<sy<<endl;
      REP(dx,2)REP(dy,2){
        sx -= w[i+(k-1)*dy][j+(k-1)*dx] * (j+(k-1)*dx+1);
        sy -= w[i+(k-1)*dy][j+(k-1)*dx] * (i+(k-1)*dy+1);
        ss -= w[i+(k-1)*dy][j+(k-1)*dx];
      }
      ll cx = j + (k-1)/2+1;
      ll cy = i + (k-1)/2+1;
      ll area = ss;
    //  cout<<i<<" "<<j<<" "<<k<<" "<<sx<<" "<<sy<<" "<<cx<<" "<<cy<<" "<<ss<<endl;
      if(k > res && 2 * sx == (2*j+k-1+2) * area && 2*sy == (2*i+k-1+2) * area) res = k;
    }
    if(res==0)cout<<" IMPOSSIBLE"<<endl;
    else cout<<" "<<res<<endl;
  }
  return 0;
}
