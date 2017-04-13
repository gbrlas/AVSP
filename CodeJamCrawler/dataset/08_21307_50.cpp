#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1024 ; 

struct Train{
	int st, end, flg ;
}t[MAXN] ; 

struct Ans{
	int end, flg ; 
}last[MAXN];
int casenum, na, nb, n; 

bool cmp(Train a, Train b){
	if(a.st != b.st) return a.st < b.st ; 
	return a.end < b.end ; 
}

int main(){
	int i,j,k,pt,ansa,ansb,tim,h,m,ca=1;
	freopen("B-large.in","r",stdin);
	freopen("B_large.txt","w",stdout);
	scanf("%d",&casenum);
	while(casenum--){
		scanf("%d",&tim);
		scanf("%d %d",&na,&nb);
		for(i = 0 ; i < na + nb ; i++){
			scanf("%d:%d",&h,&m);
			t[i].st = h * 60 + m ; 
			scanf("%d:%d",&h,&m);
			t[i].end = h * 60 + m ; 
			if(i < na) t[i].flg = 0 ; 
			else t[i].flg = 1 ; 
		}
		n = na + nb ; 
		sort(t,t+n,cmp); 
		pt = ansa = ansb = 0 ; 
		for(i = 0 ; i < n ; i++){
			int p = -1 , best = -1; 
			for(k = 0 ; k < pt ; k++){
				if( last[k].end + tim <= t[i].st && last[k].flg + t[i].flg == 1 ){
					if( last[k].end > best ){
						best = last[k].end ; 
						p = k ; 
					}
				}
			}
			if(p == -1){
				last[pt].end = t[i].end ; 
				last[pt++].flg = t[i].flg ; 
				if(t[i].flg == 0) ansa++;
				else ansb++;
			}
			else {
				last[p].end = t[i].end ; 
				last[p].flg = t[i].flg ; 
			}
		}
		printf("Case #%d: %d %d\n",ca++,ansa,ansb);
	}
	return 0;
}
