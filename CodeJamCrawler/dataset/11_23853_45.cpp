#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cfloat>
#include<numeric>
#include<vector>
using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin() , (c).end()
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORD(i,a,b) for(int i=int(b)-1; i>=a; i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)

int main(){
	int tc;
	cin >> tc;
	FOR(t,0,tc){
		int n;
		cin >> n;
		int time=0, otherfree=0, posr=1, poso=1;
		char last='t';
		FOR(i,0,n){
			char rob; int but;
			cin >> rob >> but;
			int dist;
			if(rob=='B'){
				dist=abs(posr-but)+1;
				posr=but;
			}
			else{
				dist=abs(poso-but)+1;
				poso=but;
			}
//			cout << " " << i << " " << otherfree << " " << dist << endl;
			if(last!=rob){
				if(otherfree>=dist){
					dist=1;
				}
				else
					dist-=otherfree;
				otherfree=0;
			}
			otherfree+=dist;
			last=rob;
//			cout << i << " " << dist << endl;
			time+=dist;
		}
		cout << "Case #" << t+1 << ": " << time << endl;
	}
	return 0;
}
