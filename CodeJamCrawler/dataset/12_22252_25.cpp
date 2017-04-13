#include <algorithm> 
#include <numeric>
#include <cmath> 

#include <string> 
#include <string.h>
#include <vector> 
#include <queue> 
#include <stack> 
#include <set> 
#include <map> 

#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cassert> 

using namespace std;
#pragma comment(linker, "/STACK:20000000")

// useful defines
#define sz(x) (int)(x).size()
#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define Ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i) 
#define Rep(i,n) for (int i=0;i<(n);++i)
#define RepV(i,v) for (int i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a))   
#define All(a) (a).begin(),(a).end()   
typedef long long LL;
typedef pair <int,int> PI;
typedef pair <double,double> PD;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <PI> VP;

int tt,a,b;

int ln(int x){
	if(x==0) return 1;
	int len=0;

	while(x){
		len++;
		x/=10;
	}

	return len;
}

int st(int x){
	int res=1;
	For(i,1,x) res*=10;
	return res;
}

bool check(int x, int y){

	if(ln(x)!=ln(y)) return 0;

	int len = ln(x);

	string sx,sy;

	stringstream ss;
	ss<<x<<" "<<y;
	ss>>sx>>sy;

	For(i,1,len-1){
		string ax = sx.substr(i)+sx.substr(0,i);
		if(ax==sy) return 1;
	}

	return 0;
}

int main() {
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	cin>>tt;

	Rep(t,tt){

		cin>>a>>b;

		int cnt=0;

		For(i,a,b){
			For(j,i+1,b){
				if(check(i,j)){
					//cout<<i<<" "<<j<<endl;
					cnt++;
				}
			}
		}

		cout<<"Case #"<<t+1<<": "<<cnt<<endl;
	}




	return 0;
}