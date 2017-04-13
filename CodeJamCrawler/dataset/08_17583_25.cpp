#include <cstdio>

int m,n,type[10001],changable[10001],value[10001];

int f(int d,int v)
{
	if((d<<1)>m)
	{
		if(value[d]==v) return 0;
		else return -1;
	}
	else
	{
		int res=10000000;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
			{
				if(v==1&&(type[d]==1||changable[d])&&i==1&&j==1)
				{
					
					int left=f(d<<1,i),right=f((d<<1)+1,j);
					if(left>-1&&right>-1)
						if(type[d]!=1) res<?=left+right+1;
						else res<?=left+right;
				}
				if(v==1&&(type[d]==0||changable[d])&&(i||j))
				{
					
					int left=f(d<<1,i),right=f((d<<1)+1,j);
					if(left>-1&&right>-1)
						if(type[d]!=0) res<?=left+right+1;
						else res<?=left+right;
				}
				if(v==0&&(type[d]==1||changable[d])&&(!(i==1&&j==1)))
				{
					//if(value[d<<1]!=i&&!changable[d<<1]||value[(d<<1)+1]!=j&&!changable[(d<<1)+1]) continue;
					int left=f(d<<1,i),right=f((d<<1)+1,j);
					if(left>-1&&right>-1)
						if(type[d]!=1) res<?=left+right+1;
						else res<?=left+right;
				}
				if(v==0&&(type[d]==0||changable[d])&&(!(i||j)))
				{
					//if(value[d<<1]!=i&&!changable[d<<1]||value[(d<<1)+1]!=j&&!changable[(d<<1)+1]) continue;
					int left=f(d<<1,i),right=f((d<<1)+1,j);
					if(left>-1&&right>-1)
						if(type[d]!=0) res<?=left+right+1;
						else res<?=left+right;
				}
			}
		if(res==10000000) return -1;
		else return res;
	}
}

void getValue(int v)
{
	if((v<<1)>m) return;
	getValue(v<<1);
	getValue((v<<1)+1);
	if(type[v]==1) value[v]=value[v<<1]&&value[(v<<1)+1];
	else value[v]=value[v<<1]||value[(v<<1)+1];
}

int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("small.out","w",stdout);
	int T,v;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d %d",&m,&v);
		n=(m-1)>>1;
		for(int i=1;i<=n;++i) scanf("%d %d",type+i,changable+i);
		for(int i=n+1;i<=m;++i) scanf("%d",value+i);
		getValue(1);
		int r=f(1,v);
		if(r==-1) printf("Case #%d: IMPOSSIBLE\n",t);
		else printf("Case #%d: %d\n",t,r);
	}
	return 0;
}

