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
#include <iomanip>

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
	ifstream be("A-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		int X,S,R,N;
		double t;
		be>>X>>S>>R>>t>>N;

		vector<pair<int, double> > wws; //speed, length
		int pos=0;
		FOR(i,N){
			int b,e,w;
			be>>b>>e>>w;
			if(b-pos>0)
				wws.PB(MP(0, b-pos));
			wws.PB(MP(w, e-b));
			pos=e;
		}
		if(X>pos)
			wws.PB(MP(0, X-pos));

		double time=0;
		FOR(i,SZ(wws))
			time += wws[i].second / (wws[i].first +S);

		sort(ALL(wws));

		int i=0;
		while(t>0){
			int run=(wws[i].first +R), walk=(wws[i].first +S);

			double tft= wws[i].second / run;

			if(tft<=t){
				t-=tft;
				time-= wws[i].second / walk  -  tft;
			}else{
				double ll= run * t;
				tft= ll / run;
				t-=tft;//itt pontosan 0-ra kell hogy csökkenjen
				time-= ll / walk - tft;
			}

			i++;
			if(i==SZ(wws))
				break;
		}

		ki<<setprecision(8);
		ki<<"Case #"<<tt+1<<": "<<time<<endl;
	}
	

	ki.close();
	return 0;
}