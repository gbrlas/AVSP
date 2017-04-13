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

const double eps=0.2;

int main(){
	ifstream be("B-small-attempt0.in");
	ofstream ki("ki.txt");
	int t;
	be>>t;
	FOR(tt,t){
		int R,C,D;
		be>>R>>C>>D;
		VVI w(R,VI(C));
		FOR(i,R){
			FOR(j,C){
				char c;
				be>>c;
				w[i][j]=c-'0';
			}
		}
				
		int n=min(R,C);
		int res=-1;
		for(int k=3; k<=n; k++){
			bool ok=false;
			for(int i=0; i<R-k+1 && !ok; i++)
				for(int j=0; j<C-k+1 && !ok; j++){
					pair<LL,LL> cent;
					LL sum=0;
					FOR(ii,k)
						FOR(jj,k){
							cent.first+=w[i+ii][j+jj]*ii;
							cent.second+=w[i+ii][j+jj]*jj;
							sum+=w[i+ii][j+jj];
						}

					//corners
					cent.first-=(k-1)*w[i+k-1][j];
					cent.second-=(k-1)*w[i][j+k-1];
					cent.first-=(k-1)*w[i+k-1][j+k-1];
					cent.second-=(k-1)*w[i+k-1][j+k-1];

					sum-=w[i][j]+w[i+k-1][j]+w[i][j+k-1]+w[i+k-1][j+k-1];

					pair<double, double> cent2=MP(cent.first, cent.second);
					cent2.first-=(((double)k-1)/2)*sum;
					cent2.second-=(((double)k-1)/2)*sum;
					if(abs(cent2.first-0)<eps && abs(cent2.second-0)<eps)
						ok=true;
				}
			if(ok)
				res=k;
		}

		ki<<"Case #"<<tt+1<<": "<< (res==-1?"IMPOSSIBLE":tostring(res))<<endl;
	}
	

	ki.close();
	return 0;
}