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
map<char,char> mapa;
char de[] = "abcdefghijklmnopqrstuvwxyz";
char en[] = "yhesocvxduiglbkrztnwjpfmaq";
int main(){
   f(i,0,26)mapa[de[i]]=en[i];
   int cases;
   cin>>cases;
   int ct=0;
   string cad;
   getline(cin,cad);
   f(t,1,cases+1){
      getline(cin,cad);
      cout<<"Case #"<<t<<": ";
      f(i,0,cad.size())if(cad[i]!=' ')cout<<mapa[cad[i]];
      else cout<<" ";
      cout<<endl;
   }
   return 0;
}

