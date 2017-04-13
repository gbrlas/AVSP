#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

#define x first
#define y second

using namespace std;

int d[10002], l[10002];
bool p[10002][10002];

int main(){
	int t, n;
	cin >> t;
	
	for(int qq=1; qq<=t; ++qq){
		cin >> n;
		for(int i=0; i<n; ++i){
			cin >> d[i] >> l[i];
		}
		d[n] = 0;
		cin >> d[n+1];
		l[n] = l[n+1] = 0;
		n+=2;
		
		pair<int,int> te[10002];
		for(int i=0; i<n; ++i){
			te[i].x = d[i];
			te[i].y = l[i];
		}
		
		sort(te, te+n);
		for(int i=0; i<n; ++i){
			d[i] = te[i].x;
			l[i] = te[i].y;
			
		//	cout << d[i] << ' ' << l[i] << '\n';
		}
		
		memset(p,0,sizeof(p));
		
		queue<pair<int,int> > q;
		q.push(make_pair(1,0));
		
		bool can = 0;
		
		while(!q.empty()){
			pair<int,int> f = q.front();
			q.pop();
			
			if(p[f.x][f.y]) continue;
			p[f.x][f.y] = 1;
			
		//	cout << f.x << ' ' << f.y << '\n';
			
			if(f.x == n-1){
				can = 1;
				break;
			}
			
			int piv = d[f.x];
			int ran = min(l[f.x], abs(d[f.y]-d[f.x]) );
			
		//	cout << piv+ran << '\n';
			
			for(int i=f.x+1; i<n; ++i){
				
				if(d[i] > piv+ran) break;
			//	cout << "a" << d[i] << '\n';
				q.push(make_pair(i,f.x));
			}
		}
		
		if(can) printf("Case #%d: YES\n", qq);
		else printf("Case #%d: NO\n", qq);
	}
	
	return 0;
}
