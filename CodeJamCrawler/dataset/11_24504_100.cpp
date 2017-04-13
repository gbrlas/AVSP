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

#define cin be

int main(){
	int t;
	ifstream be("A-large.in");
	cin>>t;
	ofstream ki("ki.txt");
	FOR(i,t){
		int n;
		cin>>n;
		int ouh=1, buh=1;//utolsó push helye
		int oui=0, bui=0; //utolsó push ideje
		int t=0;
		FOR(i,n){
			string r;
			int p;
			cin>>r>>p;
			if(r=="O"){
				t=max(t,oui+abs(ouh-p))+1;
				oui=t;
				ouh=p;
			}else{
				t=max(t,bui+abs(buh-p))+1;
				bui=t;
				buh=p;
			}
		}
		ki<<"Case #"<<i+1<<": "<<t<<endl;
	}
	be.close();
	ki.close();
	return 0;
}