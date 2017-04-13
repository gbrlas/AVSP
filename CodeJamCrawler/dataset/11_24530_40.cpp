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
	ifstream be("C-small-attempt0.in");
	ofstream ki("ki.txt");
	int t;
	be>>t;
	FOR(tt,t){
		int n,l,h;
		be>>n>>l>>h;
		VI T;
		FOR(i,n){
			int x;
			be>>x;
			T.PB(x);
		}
		bool ok;
		int i;
		for(i=l; i<=h; i++){
			ok=true;
			FOR(j,n){
				if(i%T[j]!=0 && T[j]%i!=0){
					ok=false;
					break;
				}
			}
			if(ok)
				break;
		}
		ki<<"Case #"<<tt+1<<": "<<(ok?tostring(i):"NO")<<endl;
	}
	

	ki.close();
	return 0;
}