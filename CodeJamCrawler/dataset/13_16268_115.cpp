#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int a[111][111];
int b[111][111];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n, m;
		cin>>n>>m;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>a[i][j];
				b[i][j] = 100;
			}
		}
		for(int i=0; i<n; i++){
			int maxL = a[i][0];
			for(int j=1; j<m; j++){
				maxL = max(maxL,a[i][j]);
			}
			for(int j=0; j<m; j++){
				b[i][j] = min(b[i][j],maxL);
			}
		}
		for(int j=0; j<m; j++){
			int maxL = a[0][j];
			for(int i=1; i<n; i++){
				maxL = max(maxL,a[i][j]);
			}
			for(int i=0; i<n; i++){
				b[i][j] = min(b[i][j],maxL);
			}
		}
		bool ok = true;
		for(int i=0; i<n && ok; i++){
			for(int j=0; j<m && ok; j++){
				if(a[i][j]!=b[i][j]) ok = false;
			}
		}
		cout<<"Case #"<<testnum+1<<": "<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}
