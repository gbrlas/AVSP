
// Headers {{{
#include<iostream>
#include<assert.h>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<bitset>
#include<numeric>
using namespace std;


#define FOR(I,A,B) for(int I=(A);I<=(B);++I)
#define FORD(I,A,B) for(int I=(A);I>=(B);--I)
#define REP(I,N) for(int I=0;I<(N);++I)
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();++I)
#define CLR(A,v) memset((A),v,sizeof((A)))

#define SIZE(x) ((int)((x).size()))
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef long long LL;
typedef vector<string> VS;
// }}}


void error(string s)
{
	fprintf(stderr,"%s\n",s.c_str());
	exit(1);
}


const int lmx=6500;

// {{{
struct mntree
{
	int T[lmx*10];
	void init(int val)
	{
		REP(i,lmx*10) T[i]=val;
	}
	void set(int x,int a,int b,int l,int r,int v)
	{
		if (a==l && b==r)
		{
			T[x]=min(T[x],v);
			return;
		}
		int s=(a+b)/2;
		if (r<=s) set(x*2,a,s,l,r,v);
		else if(s< l) set(x*2+1,s+1,b,l,r,v);
		else
		{
			set(x*2,a,s,l,s,v);
			set(x*2+1,s+1,b,s+1,r,v);
		}
	}
	int get(int x,int a,int b,int f)
	{
//		printf("x:%d a:%d b:%d f:%d\n",x,a,b,f);
		if(a==b) return T[x];
		int s=(a+b)/2;
		int val=T[x];
if (f <= s) val=min(val,get(x*2,a,s,f));
else val=min(val,get(x*2+1,s+1,b,f));
		return val;
	}
};
struct mxtree
{
	int T[lmx*10];
	void init(int val)
	{
		REP(i,lmx*10) T[i]=val;
	}
	void set(int x,int a,int b,int l,int r,int v)
	{
		if (l>r) return;
	
		if (a==l && b==r)
		{
			T[x]=max(T[x],v);
			return;
		}
		int s=(a+b)/2;
		if (r<=s) set(x*2,a,s,l,r,v);
		else if(s< l) set(x*2+1,s+1,b,l,r,v);
		else
		{
			set(x*2,a,s,l,s,v);
			set(x*2+1,s+1,b,s+1,r,v);
		}
	}
	int get(int x,int a,int b,int f)
	{
		if(a==b) return T[x];
		int s=(a+b)/2;
		int val=T[x];
		if (f <= s) val=max(val,get(x*2,a,s,f));
		else val=max(val,get(x*2+1,s+1,b,f));
		return val;
	}
};
// }}}




const int DX[]={0,1,0,-1},DY[]={1,0,-1,0};

mxtree MX,MXW;
mntree MN,MNW;


int main(int argc,char **args)
{
	if (argc != 3) error("Bad arguments");
	FILE *in=fopen(args[1],"r");
	FILE *out=fopen(args[2],"w");
	int z; fscanf(in,"%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		MX.init(-8000);
		MXW.init(-8000);
		MNW.init(8000);
		MN.init(8000);
		int k;
		LL area=0;
		fscanf(in,"%d",&k);
		int x=0,y=0,lx=0,ly=0,dr=0,stp=0;
		char tmp[40];
		int rp,l;
		while(k--)
		{	
			fscanf(in,"%s%d",tmp,&rp);
			if (zz==46) printf("%s %d\n",tmp,rp);
			l=strlen(tmp);
			while(rp--)
			{
				REP(j,l)
				{
					if(tmp[j]!='F')
					{
						x=lx+DX[dr]*stp;
						y=ly+DY[dr]*stp;
						area+=(LL)(8000-x-lx)*(LL)(y-ly);
						if (lx!= x || ly!=y)
						{
							if (y!=ly)
							{
								int m=min(y,ly),w=max(y,ly)-1;
								MX.set(1,0,6003,m+3001,w+3001,x+3001);
								MN.set(1,0,6003,m+3001,w+3001,x+3001);
							}
							else
							{
								int m=min(x,lx),w=max(x,lx)-1;
								MXW.set(1,0,6003,m+3001,w+3001,y+3001);
								MNW.set(1,0,6003,m+3001,w+3001,y+3001);
							}
						}
						if(zz==46)							printf("x:%d y:%d   - > %d %d\n",lx,ly,x,y);
						lx=x;
						ly=y;
						stp=0;
						if(tmp[j]=='R')
							dr=(dr+1)%4;
						else dr=(dr-1+4)%4;
					}
					else stp++;						
				}
			}
		}
			x=lx+DX[dr]*stp;
			y=ly+DY[dr]*stp;
			area+=(LL)(8000-x-lx)*(LL)(y-ly);
			if (lx!= x || ly!=y)
			{
				if (y!=ly)
				{
					int m=min(y,ly),w=max(y,ly)-1;
					MX.set(1,0,6003,m+3001,w+3001,x+3001);
					MN.set(1,0,6003,m+3001,w+3001,x+3001);
				}
				else
				{
					int m=min(x,lx),w=max(x,lx)-1;
					MXW.set(1,0,6003,m+3001,w+3001,y+3001);
					MNW.set(1,0,6003,m+3001,w+3001,y+3001);
				}
			}
			lx=x;
			ly=y;
			stp=0;
		area=-(abs(area))/2;
		int r;
		FOR(i,0,6001)
		{
			l=MN.get(1,0,6003,i);
			r=MX.get(1,0,6003,i);
			if( l < r)	
			{	
				while (l&& MNW.get(1,0,6003,l-1)<=i && MXW.get(1,0,6003,l-1) > i) l--;
				while (r<6001 && MNW.get(1,0,6003,r) <=i && MXW.get(1,0,6003,r) > i) r++;
				area+=(LL)(r-l);
			}
		}
			printf("area:%lld\n",area);
		
		fprintf(out,"Case #%d: %lld\n",zz+1,area);
	}
	fclose(in); fclose(out);
	return 0;
}
