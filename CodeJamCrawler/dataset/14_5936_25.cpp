#include<iostream>
#include<sstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define INF 0xffffff
#define LL  long long
#define maxx(a, b) ((a > b)? a: b)
#define minn(a, b) ((a < b)? a: b)

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int t =0;
	while ( ++t ){
		if ( t == (T+1) ) break;
		int r1,r2;
		set<int> s;
		scanf("%d",&r1);
		int sum = 0;
		// getting first arrangement
		for ( int i = 1 ; i <= 4 ; i++ )
			for ( int j = 1 ; j <= 4 ; j++ ){
				int x;
				scanf("%d",&x);
				if ( i == r1 ){
					s.insert(x);
					sum += x;
				}
			}
		// second arrangement
			scanf("%d",&r2);
		for ( int i = 1 ; i <= 4 ; i++ )
			for ( int j = 1 ; j <= 4 ; j++ ){
				int x;
				scanf("%d",&x);
				if ( i == r2 ){
					s.insert(x);
					sum += x;
				}
			}
			if ( s.size() == 8 ){
				printf("Case #%d: Volunteer cheated!\n",t);
				s.clear();
				continue;
			}
			else if ( s.size() < 7 ){
				printf("Case #%d: Bad magician!\n",t);
				s.clear();
				continue;
			}
			else{
				set<int>::iterator it = s.begin();
				for ( ; it != s.end() ; it++ ){
					sum -= *it;
				}
				printf("Case #%d: %d\n",t,sum);
				s.clear();
				continue;
			}
	}
	
	return 0;
}