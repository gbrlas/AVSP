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

II ir(char c){
	if(c=='|')
		return MP(-1,0);
	else if(c=='/')
		return MP(-1,1);
	else if(c=='-')
		return MP(0,1);
	else// '\'
		return MP(1,1);
}

int main(){
	ifstream be("C-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		int r,c;
		be>>r>>c;
		vector<vector<char> > floor(r,vector<char>(c));
		FOR(i,r)
			FOR(j,c)
				be>>floor[i][j];
		int kic=0;
		for(unsigned int a=0; a<(1<<(r*c)); a++){
			bool ok=true;
			vector<vector<bool> >volt(r,vector<bool>(c));
			//FOR(i,r)
				//FOR(j,c){
			for(int i=0; i<r && ok; i++)
				for(int j=0; j<c && ok; j++){
					if(!volt[i][j]){
						int ai=i, aj=j;
						volt[ai][aj]=true;
						while(1){
							II irp=ir(floor[ai][aj]);
							int iri=irp.first, irj=irp.second;
							unsigned int bm= (1<<(aj))<<(ai*c);
							if(a & bm){
								iri=-iri;
								irj=-irj;
							}
							ai+=iri; ai+=r; ai%=r;
							aj+=irj; aj+=c; aj%=c;
						
							if(volt[ai][aj]){
								if(ai!=i || aj!=j)
									ok=false;
								break;
							}
							volt[ai][aj]=true;
						}
					}
				}
			if(ok)
				kic++;
		}
		ki<<"Case #"<<tt+1<<": "<<kic<<endl;
	}
	

	ki.close();
	return 0;
}