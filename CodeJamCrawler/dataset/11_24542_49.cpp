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
		int n;
		be>>n;

		vector<bool> pr(n+1,true);
		pr[0]=false;
		pr[1]=false;
		FOR(i,n){
			if(pr[i])
				for(int j=i+i; j<=n; j+=i)
					pr[j]=false;
		}

		VI p;
		FOR(i,n+1)
			if(pr[i])
				p.PB(i);

		int best;
		{//best
			best=SZ(p);
		}

		int worst;
		{//worst
			int sum=0;
			FOR(i,SZ(p)){
				int kit=1, x=p[i];
				while(x<=n){
					kit++;
					x*=p[i];
				}
				kit--;
				sum+=kit;
			}
			worst=sum+1;
		}

		if(n==1)
			ki<<"Case #"<<tt+1<<": "<<0<<endl;
		else
			ki<<"Case #"<<tt+1<<": "<<worst-best<<endl;
	}
	

	ki.close();
	return 0;
}