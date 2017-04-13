#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
#define maxn 2000000
int dig[2000010];
int A,B;
int m;
int pot[10];
int last[2000010];
ll go(int n){
   int rota=dig[n];
   ll res=0;
   int m=n;
   f(i,0,rota){
      if(m<=maxn)
      m=(last[m]*pot[rota-1]+m/10);
      else
       m=((m%10)*pot[rota-1]+m/10);
      if(m > n && m>=A && m<=B && dig[n]==dig[m] )res++;
   }
   return res;
}

int main(){
   
   dig[0]=0;
   f(i,1,2000001)
      dig[i]=dig[i/10]+1,last[i]=i%10;
   pot[0]=1;
   f(i,1,9)pot[i]=10*pot[i-1];
   int cases;
   scanf("%d",&cases);
   f(t,1,cases+1){
      scanf("%d %d",&A,&B);
      ll res=0;
      f(i,A,B+1)res+=go(i);
      cout<<"Case #"<<t<<": ";
      cout<<res<<endl;
   }
   return 0;
}

