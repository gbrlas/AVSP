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
double pro[100013];
double acu[100013];
int A,B;
int main(){
   int t;
   cin>>t;
   f(ii,1,t+1){
      cin>>A>>B;
      f(i,1,A+1)cin>>pro[i];
      acu[0]=1.0;
      f(i,1,A+1)acu[i]=acu[i-1]*pro[i];
      int izq=A;
      double res=1e30;
      int falta=B-A;
      int supr=0;
      //f(i,1,A+1)cout<<" "<<acu[i];
      //cout<<endl;
      while(izq>=0){
        // cout<<falta<<" "<<izq<<" "<<B<<endl;
         double res2=acu[izq]*(falta+supr+1)+(1.0-acu[izq])*(falta+1+supr+B+1);
        // cout<<res2<<endl;
         res=min(res,res2);
         falta++;
         supr++;
         izq--;
      }
      res=min(res,0.0+B+1+1);
      cout<<"Case #"<<ii<<": ";
      //res<<" d"<<endl;
      printf("%.6lf\n",res);
   }
   return 0;
}

