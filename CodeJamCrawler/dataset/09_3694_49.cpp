#include <iostream>
#include <bitset>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
char map[100][100];
int cnt[100];
char tmp[100];
int main()
{
	int n,i,j,k,T,t,ans;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<n;i++){
			scanf("%s",map[i]);
			for(j=0;map[i][j];j++)
				if(map[i][j]=='1') cnt[i]++;
		}
		ans = 0;
		for(i=0;i<n;i++)
		{
			if(cnt[i]<=i+1){
				for(j=i+1;j<n;j++) if(map[i][j]=='1') break;
				if(j>=n) continue;
			}
			for(j=i+1;j<n;j++)
			{
				if(cnt[j]<=i+1){
					for(k=i+1;k<n;k++) if(map[j][k]=='1') break;
					if(k>=n) break;
				}
			}
			for(k=j;k>i;k--){
				ans++;
				strcpy(tmp,map[k]);
				strcpy(map[k],map[k-1]);
				strcpy(map[k-1],tmp);
				t = cnt[k];
				cnt[k] = cnt[k-1];
				cnt[k-1] = t;
			}
			//printf("i = %d cnt = %d\n",i,ans);
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}