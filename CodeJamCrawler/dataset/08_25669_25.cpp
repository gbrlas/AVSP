#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cctype>
using namespace std;

#define llong long long

int n,m;
int A;

int main() {
	int cases;
	cin>>cases;
	for(int tc=1;tc<=cases;tc++) {
		cin>>n>>m>>A;
		bool got=0;
		cout<<"Case #"<<tc<<": ";
		for(int x1=0;x1<=n&&!got;x1++) for(int y1=0;y1<=m&&!got;y1++)
		for(int x2=0;x2<=n&&!got;x2++) for(int y2=0;y2<=m&&!got;y2++) {
			int area=x1*y2-x2*y1;
			if(area==A) {
				got=1;
				cout<<0<<' '<<0<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
			}
		}
		if(!got) cout<<"IMPOSSIBLE"<<endl;
	}
}
