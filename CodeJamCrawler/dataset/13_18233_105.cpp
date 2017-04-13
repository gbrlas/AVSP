#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctype.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>

using namespace std;

typedef pair<int,int> ii;

#define INF 0x3f3f3f3f
#define ll long long
#define MAXR 110

int r,c,mat[MAXR][MAXR],fin[MAXR][MAXR];

int main() {
	int nt,nteste=1,flag,ok,mn,mx,equal;
	cin>>nt;
	while (nt--) {
		cin>>r>>c;
		
		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++)
				cin>>fin[i][j];
		
		if (r == 1 || c == 1) {
			cout << "Case #" << nteste++ << ": YES" << endl;
			continue;
		}
		
		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++)
				mat[i][j] = 100;
		
		mx = 0;
		equal = 1;
		for (int j=0; j<c; j++) {
			mx = max(mx,fin[0][j]);
			if (j && fin[0][j] != fin[0][j-1]) equal = 0;
		}
				
		if (!equal) {
			for (int j=0; j<c; j++) {
					if (fin[0][j] != mx) 
						for (int i=0; i<r; i++)
							mat[i][j] = fin[0][j];
					else {
						mx = 0;
						for (int i=0; i<r; i++)
							mx = max(mx,fin[i][j]);
						for (int i=1; i<r; i++)
							mat[i][j] = mx;
					}
			}
		}
		
		else {
			for (int j=0; j<c; j++) {
				mx = 0;
				for (int i=0; i<r; i++)
					mx = max(mx,fin[i][j]);
				for (int i=1; i<r; i++)
					mat[i][j] = mx;
			}
		}
	
		flag = 1;
		for (int i=1; i<r; i++) {
			ok = 1;
			mn = 101;	equal = 1;
			for (int j=0; j<c; j++) {
				mn = min(mn,mat[i][j]);
				if (j && fin[i][j] != fin[i][j-1]) equal = 0;
				if (mat[i][j] != fin[i][j]) ok = 0;
			}
			if (ok) continue;
			if (!equal) { flag=0; break; }
			if (fin[i][0]>mn) { flag=0; break; }
		}
		
		cout << "Case #" << nteste++ << ": ";
		cout << (flag ? "YES" : "NO") << endl;
	}
	
	return 0;
}
