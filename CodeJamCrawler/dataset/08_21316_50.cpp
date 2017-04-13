// a.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std; 

const int MAXN = 1024 ; 

int s[MAXN], fre[MAXN], n , p , k , l ; 

int casenum, ca ; 
int _tmain(int argc, _TCHAR* argv[])
{
	int i ; 
	freopen("A-large.in","r",stdin);
	freopen("out_large_0.txt","w",stdout);
	scanf("%d",&casenum);
	for(ca = 1 ; ca <= casenum ; ca++){
		scanf("%d%d%d",&p,&k,&l);
		for(i = 0 ; i < l ; i++) scanf("%d",&s[i]);
		sort(s,s+l) ; 
		int cnt = 0 , val = 1 ;
		__int64 ans = 0 ;
		printf("Case #%d: ",ca);
		if( (__int64)p * k < l ) {
			printf("Impossible\n") ; continue ; 
		}
		for(i = l - 1 ; i >= 0 ; i--){
			ans += (__int64)s[i] * val ; 
			cnt++ ; 
			if(cnt % k == 0) val++ ; 
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

