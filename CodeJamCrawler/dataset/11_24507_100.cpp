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

#define be cin

string addc(char a, char b){return tostring(a)+tostring(b);}

int main(){
	int t;
	ifstream be("B-large.in");
	be>>t;
	ofstream ki("ki.txt");
	FOR(tt,t){
		int c,d,n;
		map<string,char> comb;
		be>>c;
		FOR(i,c){
			string s;
			be>>s;
			comb[addc(s[0],s[1])]=s[2];
			comb[addc(s[1],s[0])]=s[2];
		}
		vector<vector<char> > opp('Z'+1,vector<char>());
		be>>d;
		FOR(i,d){
			string s;
			be>>s;
			opp[s[0]].PB(s[1]);
			opp[s[1]].PB(s[0]);
		}
		be>>n;
		string s;
		be>>s;
		vector<char> l;
		char h['Z'+1];
		memset(h,0,sizeof(h));
		FOR(i,SZ(s)){
			char c=s[i];
			l.PB(c);

#define L2 addc(l[SZ(l)-2],l[SZ(l)-1])
#define L LAST(l)

			h[L]++;

			while(SZ(l)>=2 && comb.count(L2)){
				char mire=comb[L2];
				h[L]--;
				l.pop_back();
				h[L]--;
				l.pop_back();
				l.PB(mire);
				h[mire]++;
			}

			bool clear=false;
			FOR(j,SZ(opp[L]))
				if(h[opp[L][j]]){
					clear=true;
					break;
				}
			if(clear){
				memset(h,0,sizeof(h));
				l.clear();
			}
		}
		ki<<"Case #"<<tt+1<<": [";
		FOR(j,SZ(l)){
			ki<<l[j];
			if(j<SZ(l)-1)
				ki<<", ";
		}
		ki<<"]\n";
	}
	be.close();
	ki.close();
	return 0;
}