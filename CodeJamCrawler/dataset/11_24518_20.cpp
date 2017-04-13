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
	int t;
	be>>t;
	FOR(tt,t){
		int n;
		be>>n;
		vector<vector<bool> > W(n,vector<bool>(n));//won
		VVI P(n,VI());//played
		FOR(i,n){
			string s;
			be>>s;
			FOR(j,n){
				W[i][j]= s[j]=='1';
				if(s[j]!='.')
					P[i].PB(j);
			}
		}

		vector<double> wp(n);
		FOR(i,n){
			int w=0;
			FOR(j,n)
				if(W[i][j])
					w++;
			wp[i]=((double)w)/SZ(P[i]);
		}

		vector<double> owp(n);
		FOR(i,n){
			double s=0;
			FOR(j,SZ(P[i]))
				//s+=wp[P[i][j]];
				s+=(wp[P[i][j]] * SZ(P[P[i][j]]) - (W[i][P[i][j]] ?0:1)) / ( SZ(P[P[i][j]])-1 );

			owp[i]=s/SZ(P[i]);
		}

		vector<double> oowp(n);
		FOR(i,n){
			double s=0;
			FOR(j,SZ(P[i]))
				s+=owp[P[i][j]];
			oowp[i]=s/SZ(P[i]);
		}

		ki<<"Case #"<<tt+1<<":"<<endl;
		FOR(i,n){
			ki<<  (0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i])  <<endl;
		}
	}

	

	ki.close();
	return 0;
}