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
		int r,c;
		be>>r>>c;
		vector<vector<bool> > T(r+2,vector<bool>(c+2));
		/*FOR(i,r+2){
			T[i][0]='.';
			T[i][c+1]='.';
		}
		FOR(i,c+2){
			T[0][i]='.';
			T[r+1][i]='.';
		}*/
		FOR(i,r){
			string s;
			be>>s;
			FOR(j,c)
				T[i+1][j+1]= s[j]=='#';
		}
		r+=2; c+=2;

		vector<vector<char> > kit(r+2,vector<char>(c+2));
		int rem=0;
		FOR(i,r)
			FOR(j,c){
				kit[i][j]= (T[i][j]?'#':'.');
				if(T[i][j])
					rem++;
			}

		bool impos=false;
		while(rem && !impos){
			for(int i=1; i<=r-2; i++) //FOR(i,r)
				for(int j=1; j<=c-2; j++){ //FOR(j,c){
					if(T[i][j] && !T[i-1][j] && !T[i][j-1]){
						if(!T[i+1][j] || !T[i][j+1] || !T[i+1][j+1]){
							impos=true;
						}else{
							T[i][j]=false;
							T[i+1][j]=false;
							T[i][j+1]=false;
							T[i+1][j+1]=false;
							kit[i][j]='/';
							kit[i+1][j]='\\';
							kit[i][j+1]='\\';
							kit[i+1][j+1]='/';
							rem-=4;
						}
					}
				}
		}

		//kiírásnál kisebbet kell
		ki<<"Case #"<<tt+1<<":"<<endl;
		if(impos)
			ki<<"Impossible"<<endl;
		else{
			for(int i=1; i<=r-2; i++){
				for(int j=1; j<=c-2; j++)
					ki<<kit[i][j];
				ki<<endl;
			}
		}
	}
	

	ki.close();
	return 0;
}