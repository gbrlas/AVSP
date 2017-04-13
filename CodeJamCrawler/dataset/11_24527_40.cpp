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
	ifstream be("B-small-attempt1.in");
	ofstream ki("ki.txt");
	int t;
	be>>t;
	FOR(tt,t){
		LL L,t,N,C;
		be>>L>>t>>N>>C;
		vector<LL> dist(N);
		FOR(i,C){
			int ai;
			be>>ai;
			for(int k=0; k*C+i<N; k++)
				dist[k*C+i]=ai;
		}

		vector<LL> adist(N+1);
		adist[0]=0;
		for(int i=1; i<=N; i++)
			adist[i]=adist[i-1]+dist[i-1];

		LL mi=10000000000000000L;
		if(L==2){
			for(int b1=0; b1<=N-1; b1++) //FOR(b1,N)
				for(int b2=b1+1; b2<=N-1; b2++){
					if(b1!=b2){
						LL s=adist[N]*2;
						if(t<=adist[b1]*2)
							s-= dist[b1] + dist[b2];
						else
							if(t<=adist[b1+1]*2)
								s-=(  dist[b1]*2-(t-adist[b1]*2)  )/2 + dist[b2];
							else
								if(t<=adist[b2]*2)
									s-= dist[b2];
								else
									if(t<=adist[b2+1]*2)
										s-= (  dist[b2]*2-(t-adist[b2]*2)  )/2;
									else
										s-= 0;
						mi=min(mi,s);
					}
				}
		}else{
			if(L==1){
				for(int b1=0; b1<=N-1; b1++){
					LL s=adist[N]*2;
					if(t<=adist[b1]*2)
							s-= dist[b1];
						else
							if(t<=adist[b1+1]*2)
								s-=(  dist[b1]*2-(t-adist[b1]*2)  )/2;
							else
								s-= 0;
					mi=min(mi,s);
				}
			}else{//L==0
				mi=adist[N]*2;
			}
		}
		ki<<"Case #"<<tt+1<<": "<<mi<<endl;
	}
	

	ki.close();
	return 0;
}