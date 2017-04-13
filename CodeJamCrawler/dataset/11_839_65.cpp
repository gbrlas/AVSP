#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main(){
	int cases=1,o[101],N,L,H;
	scanf("%d",&cases);
	for(int t=1;t<=cases;t++){
		scanf("%d%d%d",&N,&L,&H);
		bool valid=true;
		for(int i=0;i<N;i++){
			scanf("%d",&o[i]);
		}
		int res=0;
		for(int i=L;i<=H;i++){
			valid=true;
			for(int j=0;j<N;j++){
				if(i%o[j]!=0 && o[j]%i!=0){
					//printf("%d %d\n",i,o[j]);
					valid=false;
					break;
				}
			}
			if(valid){
			res=i;
			break;
			}
		}
		printf("Case #%d: ", t);
		if(valid)printf("%d\n",res);
		else printf("NO\n");
	}
	return 0;
}
