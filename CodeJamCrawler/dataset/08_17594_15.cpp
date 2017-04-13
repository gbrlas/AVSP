#include <iostream>

using namespace std;

int r,c,num=0,md[12],buf[1024],dp[12][1024];
string g[12];

void search(int d,int p,int mark)
{
	if(d==c)
	{
		buf[num++]=mark;
	}
	else
	{
		if(p!=d-1) search(d+1,d,(mark<<1)+1);
		search(d+1,p,mark<<1);
	}
}

int main()
{
	freopen("c.txt","r",stdin);
	freopen("cout.txt","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		memset(md,0,sizeof(md));
		memset(dp,0,sizeof(dp));
		num=0;
		cin>>r>>c;
		for(int i=0;i<r;++i)
		{
			cin>>g[i];
			md[i]=0;
			for(int j=0;j<c;++j) md[i]=(md[i]<<1)+(g[i][j]=='x');
		}
		search(0,-100,0);
		int ans=0;
		for(int i=0;i<num;++i)
		{
			dp[1][i]=0;
			if((md[0]&buf[i])==0)
				for(int t=buf[i];t;t>>=1)
					if(t&1)
						++dp[1][i];
			if(dp[1][i]>ans) ans=dp[1][i];
		}
		for(int i=2;i<=r;++i)
			for(int j=0;j<num;++j)
			{
				if(md[i-1]&buf[j]) dp[i][j]=0;
				else
				{
					dp[i][j]=0;
					int temp=0;
					for(int t=buf[j];t;t>>=1)
						if(t&1)
							++temp;
					for(int k=0;k<num;++k)
						if((md[i-2]&buf[k])==0&&((buf[j]<<1)&buf[k])==0&&((buf[j]>>1)&buf[k])==0)
							if(temp+dp[i-1][k]>dp[i][j])
								dp[i][j]=temp+dp[i-1][k];
				}
				if(dp[i][j]>ans) ans=dp[i][j];
			}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
