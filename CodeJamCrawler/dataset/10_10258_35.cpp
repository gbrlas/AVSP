#include <iostream>
using namespace std;
int mp[70][70];
bool go[5];
int N,k;
bool FR()
{
	int i,j,p;	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(mp[i][j]!=1) continue;
			for(p=1;p<k;p++)
			{
				if(i+p>=N) break;
				if(mp[i+p][j]!=1) break;
			}
			if(p==k) return true;
			for(p=1;p<k;p++)
			{
				if(j+p>=N) break;
				if(mp[i][j+p]!=1) break;
			}
			if(p==k) return true;
			for(p=1;p<k;p++)
			{
				if(j+p>=N||i+p>=N) break;
				if(mp[i+p][j+p]!=1) break;
			}
			if(p==k) return true;
			for(p=1;p<k;p++)
			{
				if(j-p<0||i+p>=N) break;
				if(mp[i+p][j-p]!=1) break;
			}
			if(p==k) return true;
		}
	return false;
}
bool FB()
{
	int i,j,p;	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(mp[i][j]!=-1) continue;
			for(p=1;p<k;p++)
			{
				if(i+p>=N) break;
				if(mp[i+p][j]!=-1) break;
			}
			if(p==k) return true;
			for(p=1;p<k;p++)
			{
				if(j+p>=N) break;
				if(mp[i][j+p]!=-1) break;
			}
			if(p==k) return true;
			for(p=1;p<k;p++)
			{
				if(j+p>=N||i+p>=N) break;
				if(mp[i+p][j+p]!=-1) break;
			}
			if(p==k) return true;
			for(p=1;p<k;p++)
			{
				if(j-p<0||i+p>=N) break;
				if(mp[i+p][j-p]!=-1) break;
			}
			if(p==k) return true;
		}
	return false;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	int i,j;
	for(i=1;i<=T;i++)
	{
		memset(mp,0,sizeof(mp));
		memset(go,0,sizeof(go));
		char moment[70];		
		scanf("%d%d",&N,&k);
		for(j=0;j<N;j++)
		{
			cin>>moment;
			int p,q;
			for(p=strlen(moment)-1,q=0;p>=0;p--)
			{
				if(moment[p]=='.' ) continue;
				else if(moment[p]=='R')
				{
					mp[j][q]=1; q++;
				}
				else
				{
					mp[j][q]=-1; q++;
				}
			}
		}
		bool flag1=FR();
		bool flag2=FB();
		printf("Case #%d: ",i);
		if(flag1==1&&flag2==1) printf("Both\n");
		else if(flag1==1&&flag2==0) printf("Red\n");
		else if(flag1==0&&flag2==0) printf("Neither\n");
		else printf("Blue\n");
	}
}
