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

int n,s,p;
int arr[103];
int main(){
   int cases;
   cin>>cases;
   f(t,1,cases+1){
      cin>>n>>s>>p;
      f(i,0,n)cin>>arr[i];
      vector <int> ini;
      int x;
      f(i,0,n){
         x=arr[i]/3;
         if(arr[i]%3)x++;
         ini.push_back(x);
      }
      //sort(all(ini));
      int res=0;
      bool esta[103];
     // f(i,0,n)cout<<" "<<ini[i];cout<<endl; 
      clr(esta,true);
      f(i,0,n)
         if(ini[i]>=p)res++,esta[i]=false;
      f(i,0,n)
         if(s && ini[i]>1 && ini[i]<10 && esta[i] && ini[i]+1 >= p)res++,s--;
      
      cout<<"Case #"<<t<<": "<<res<<endl;
   }
   return 0;
}

