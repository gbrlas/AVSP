#include<stdio.h>

int abs(int a){
	if(a>0)return a;
	return -a;
}
int min(int a,int b){
	if(a>b)return b;
	return a;
}
int main()
{
	int T,t= 0;
	
	bool type[110];
	int pos[110];
	int CurPos[2];
	int CanUseTime[2];
	int i,n;
	int time,m;
	char c;
	freopen("A-small-attempt3.in","r",stdin);
	freopen("Snail.out","w",stdout);
	scanf("%d",&T);
	while(++t<=T)
	{
		scanf("%d%*c",&n);
		for(i=0;i<n;i++){
			scanf("%c %d%*c",&c,pos+i);
			type[i] = (c=='O');
		}
		CurPos[0] = CurPos[1] = 1;
		time = CanUseTime[0] = CanUseTime[1] = 0;
		
		for(i=0;i<n;i++){
			m = abs( pos[i]-CurPos[type[i]] );
			CurPos[type[i]] = pos[i];
			
			m -= min(CanUseTime[type[i]],m);
			CanUseTime[type[i]] = 0;
			CanUseTime[!type[i]] += m+1;
			time += m+1;
		}
		printf("Case #%d: %d\n",t,time);
	}
	return 0;
}

