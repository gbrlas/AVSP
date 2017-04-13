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
#include <time.h>

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

int rnd(LL m){return rand()*((LL)m)/(RAND_MAX+1)+1;}

vector<II> pos;
int n;
int w,l;
VI r;

bool collide(int x1, int y1, int x2, int y2, int r1, int r2){
	int dx=abs(x2-x1), dy=abs(y2-y1);
	int r=r1+r2;
	return ((LL)dx)*dx+((LL)dy)*dy <= ((LL)r*r);
}

bool bt(int i){
	if(i==n)
		return true;

	FOR(k,5*i+2){
		pos[i].first=rnd(w+1)-1, pos[i].second=rnd(l+1)-1;
		bool ok=true;
		FOR(j,i)
			if(collide(pos[j].first,pos[j].second,pos[i].first,pos[i].second, r[j], r[i])){
				ok=false;
				break;
			}

		if(ok)
			return bt(i+1);
	}

	return false;
}

int main(){
	srand(time(NULL));
	ifstream be("B-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		be>>n>>w>>l;
		pos.resize(n);
		r.resize(n);
		FOR(i,n)
			be>>r[i];

		/*FOR(i,min(n,4)){
			if(i==0) pos[i].first=0; pos[i].second=0;
			if(i==1) pos[i].first=w; pos[i].second=0;
			if(i==2) pos[i].first=0; pos[i].second=l;
			if(i==3) pos[i].first=w; pos[i].second=l;
		}*/

		//if(!bt(min(n,4))){
		if(!bt(0)){
			cout<<"NEM JO\n";
			system("PAUSE");
		}

		ki<<"Case #"<<tt+1<<":";
		FOR(i,n)
			ki<<" "<<pos[i].first<<" "<<pos[i].second;
		ki<<endl;
	}
	

	ki.close();
	return 0;
}