#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <stdio.h>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int main(){
	ifstream be("A-large.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		int n; be>>n;
		VI d(n),l(n);
		FOR(i,n)
			be>>d[i]>>l[i];
		int D; be>>D;

		VI DP(n,-1);
		DP[0]=d[0];
		bool ok=false;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n && d[j]<=d[i]+DP[i]; j++){
				DP[j]=max(DP[j],min(d[j]-d[i],l[j]));
			}
			if(d[i]+DP[i]>=D){
				ok=true;
				break;
			}
		}

		ki<<"Case #"<<tt+1<<": "<<(ok?"YES":"NO")<<endl;
	}
	

	ki.close();
	return 0;
}