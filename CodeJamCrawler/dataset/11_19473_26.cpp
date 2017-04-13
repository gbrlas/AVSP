/*
#include<iostream>
using namespace std;
#include<cstdio>

const int LIMIT=310;
int n;
typedef double lld;

double a[LIMIT][LIMIT]={0};
inline double div2(double a,double b)
{
	return a/b;
}
inline double mul(double a,double b)
{
	return a*b;
}
inline double sub(double a,double b)
{
	return a-b;
}
inline double add(double a,double b)
{
	return a+b;
}
double deter(double a[][LIMIT],int forder)
{
  int i,j,k;
  double mult;
  double deter=1;
  for(i=0;i<forder;i++)
  {
	for(j=0;j<forder;j++)
	{
	  mult=div2(a[j][i],a[i][i]);//a[j][i]/a[i][i];
	  for(k=0;k<forder;k++)
	  {
		if(i==j) break;
		a[j][k]=sub(a[j][k],mul(a[i][k],mult));
		//a[j][k]=a[j][k]-a[i][k]*mult;
	  }
	}
  }
  for(i=0;i<forder;i++)
  {
	  deter=mul(deter,a[i][i]);
	//deter=deter*a[i][i];
  }
  return(deter);
}


double chckdgnl(double array[][LIMIT],int forder)
{
  int i,j,k;
  double nonzero;
  for(i=0;i<forder;i++)
  {
	 if(array[i][i]==0)
	 {
		for(j=0;j<forder;j++)
		{
		  if(array[i][j]!=0)
		  {
			 k=j;
			 break;
		  }
		  if(j==(forder)) //forder-1
			 return(false);
		}
		for(j=0;j<forder;j++)
		{
		  array[j][i]=sub(array[j][i],array[j][k]);
		}
	 }
  }
  return(true);
}
*/
/*
#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>
#include<cmath>
const int MAXN=310;
int n;
double a[MAXN][MAXN]={0.0};
void output()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			printf("%d",(int)a[i][j]);
		printf("\n");
	}
	printf("\n");
}
void swaprow(int i,int j)
{
	for(int k=0;k!=n;++k)
		swap(a[i][k],a[j][k]);
}
const double eps=1e-6;
bool cal()
{
	for(int i=0;i!=n;++i)
	{
		//output();
		if(fabs(a[i][i])<eps)
		{
			int j=i+1;
			for(;j!=n;++j)
				if(fabs(a[j][i])>eps)
					break;
			if(j==n)
				return false;
			swaprow(i,j);
		}
		for(int j=i+1;j!=n;++j)
		{
			if(fabs(a[j][i])>eps)
			{
				double det=a[j][i]/a[i][i];
				for(int k=i;k!=n;++k)
				{
					a[j][k]=a[j][k]-det*a[i][k];
				}
				//	a[j][k]=a[j][k]^a[i][k];
			}
		}
		//output();
	}
	int res=1;
	for(int i=0;i!=n;++i)
		if((int)(fabs(a[i][i])+0.1)%2==0)
			return false;
	//double res=1.0;
	//for(int i=0;i!=n;++i)
	//	res*=a[i][i];
	return true;
}
inline char getint(int &x)
{
     char ch=getchar();
     while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF)
         ch=getchar();
     if(ch==EOF)
       return EOF;
     double neg=false;
     if('-'==ch)
     {
       neg=true;
       ch=getchar();
     }
     x=0;
     while('0'<=ch&&ch<='9')
     {
          x=x*10+ch-'0';
          ch=getchar();
     }     
     x=neg?-x:x;
     return ch;
}
//char str[LIMIT];
typedef __int64 lld;
int main()
{
	int T;
	getint(T);
	//scanf("%d",&T);
 	while(T--)
	{
		getint(n);
		//scanf("%d",&n);
		for(int i=0;i!=n;++i)
		{
			//scanf("%s",str);
			for(int j=0;j!=n;++j)
			   a[i][j]=(('0'==getchar())?0.0:1.0);
			getchar();
		}
		//int res=false;
		//if(!chckdgnl(a,n)==0)
		//	res=((int)(deter(a,n)+0.5))%2;
		//lld myres=res;
		//double myres=fabs(cal());
		//lld rr=(lld)(myres+0.5);
		printf("%s\n",cal()?"Odd":"Even");
	}
	return 0;
}
*/
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
#include<cmath>
using namespace std;
int main()
{
	string str;
	while(cin>>str)
	{
		int len=str.length();
		int res=0,now=0;
		char c='C';
		for(int i=0;i<len;++i)
		{
			if(str[i]==c)
				++now;
			else
			{
				if(now>res)
					res=now;
				now=1;
			}
			c=str[i];
		}
		if(now>res)
			res=now;
		cout<<res<<endl;
	}
	return 0;
}
*/
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
#include<cmath>
using namespace std;
const double PI=acos(-1.0);
int main()
{
	double N;
	while(EOF!=scanf("%lf",&N)&&N>=3)
	{
		printf("%.2lf\n",N/4.0/tan(PI/N));
	}
	return 0;
}
*/
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
#include<cmath>
using namespace std;
const int MAXN=110;
int mat[MAXN][MAXN],cnt[MAXN][MAXN],nxt[MAXN][MAXN],res;
int main()
{
	int M,N;
	while(EOF!=scanf("%d%d",&M,&N))
	{
		memset(mat,0,sizeof(mat));
		memset(cnt,0,sizeof(cnt));
		memset(nxt,0,sizeof(nxt));
		res=0;
		for(int i=1;i<=M;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&mat[i][j]);
		for(int k=1;k<=M;++k)
		{
			memset(nxt,0,sizeof(nxt));
			for(int i=1;i<=N;++i)
			{
				for(int j=i+1;j<=N;++j)
				{
					if(mat[k][i]==1&&mat[k][j]==1)
					{
						res+=cnt[i][j];
						nxt[i][j]=cnt[i][j]+1;
					}
					else
						nxt[i][j]=cnt[i][j];
				}
			}
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=N;++i)
				for(int j=i+1;j<=N;++j)
					cnt[i][j]=nxt[i][j];
		}
		printf("%d\n",res);
	}
	return 0;
}
*/
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
#include<cmath>
#include<queue>
using namespace std;
inline char getint(int &x)
{
     char ch=getchar();
     while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF)
         ch=getchar();
     if(ch==EOF)
       return EOF;
     bool neg=false;
     if('-'==ch)
     {
       neg=true;
       ch=getchar();
     }
     x=0;
     while('0'<=ch&&ch<='9')
     {
          x=x*10+ch-'0';
          ch=getchar();
     }     
     x=neg?-x:x;
     return ch;
}
struct node
{
	int end,value;
	node(int e=0,int v=0)
	{
		end=e;
		value=v;
	}
	bool operator<(const node &oth)const
	{
		if(end==oth.end)
			return value<oth.value;
		return end<oth.end;
	}
};
int n,m;
const int MAXN=100010;
node dv[MAXN];
int main()
{
	while(EOF!=scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&dv[i].end,&dv[i].value);
			//getint(dv[i].end);
			//getint(dv[i].value);
		}
			//scanf("%d%d",d+i,v+i);
		priority_queue<int> data;;
		int res=0;
		sort(dv,dv+n);
		reverse(dv,dv+n);
		//for(int i=0;i<n;++i)
			//printf("%d %d    ",dv[i].end,dv[i].value);
		//printf("\n");
		for(int i=0;i<n&&m>=1;)
		{
			while(i<n&&dv[i].end>=m)
			{
				data.push(dv[i].value);
				++i;
			}
			if(!data.empty())
			{
				res+=data.top();
				data.pop();
				--m;
			}
			else
			{
				if(i<n)
					m=dv[i].end;
			}
		}
		while(m>=1&&!data.empty())
		{
			res+=data.top();
			data.pop();
			--m;
		}
		printf("%d\n",res);
	}
	return 0;
}
*/
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
#include<cmath>
#include<queue>
#include<bitset>
using namespace std;
typedef __int64 lld;
inline lld mod(lld x,lld y)
{
       return x>0?x%y:(y-(-x)%y)%y;
}
inline void exgcd(lld a,lld b,lld &d,lld &x,lld &y)
{
       if(0==b)
       {
           d=a,x=1,y=0;
           return;
       }
       exgcd(b,a%b,d,x,y);
       lld t=y;
       y=x-a/b*y;
       x=t;
}

inline void modliner(lld a,lld b,lld n,lld &xmin,lld &step,lld &d)
{
       lld x,y;
       exgcd(a,n,d,x,y);
       if(b%d==0)
       {
           step=n/d;
           xmin=(x*(b/d));
           xmin=mod(xmin,step);
       }
       else
         xmin=-1;
}
bitset<10000001> mybit;
int main()
{
	int T,n,p,q;
	scanf("%d",&T);
	for(int test=1;test<=T;++test)
	{
		scanf("%d%d%d",&n,&p,&q);
		//int x,y,value;
		//printf("x,y= %d %d\n",x,y);
		int value;
		lld res=0;
		mybit.reset();
		for(int i=0;i<n;++i)
		{
			scanf("%d",&value);
			mybit.set(value);
			res+=value;
		}
		lld x,y,d;
		exgcd(p,q,d,x,y);
		lld det=-y*res/p;
		while(true)
		{
			lld tmp=y*res+det*p;
			if(tmp>0)
				break;
			++det;
		}
		lld xmin=y*res+det*p;
		printf("Case %d:\n",test);
		printf("%d\n",(int)xmin);
	}
	return 0;
}
*/
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
#include<cmath>
#include<queue>
#include<bitset>
using namespace std;
const double eps=1e-6;
int main()
{
	int T;
	double a,b,c;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		if(a+b<=c||a-b>=c||b-a>=c)
		{
			printf("NO\n");
			continue;
		}
		double cosa=(c*c+b*b-a*a)/(2*b*c);
		double cosb=(a*a+c*c-b*b)/(2*a*c);
		double cosc=(a*a+b*b-c*c)/(2*a*b);
		if(cosa<0.0||cosb<0.0||cosc<0.0)
			printf("Obtuse triangle\n");
		else if(cosa>0.0&&cosb>0.0&&cosc>0.0)
			printf("Acute triangle\n");
		else
			printf("Right triangle\n");
	}
	return 0;
}
*/
/*
#include<cstdio>
const int MAXN=100010;
int data[MAXN];
int main()
{
	data[0]=0;
	for(int i=1;i<MAXN;++i)
	{
		data[i]=2*data[i-1]+1;
		if(data[i]>200000)
			data[i]=200000;
	}
	int T,M,N;
	scanf("%d\n",&T);
	for(int i=0;i<T;++i)
	{
		scanf("%d%d",&M,&N);
		if(M<=data[N])
			printf("YES\n");
		else
			printf("NO\n");
	}
}
*/
/*
#include<cstdio>
int data[110];
int main()
{
	int T;
	scanf("%d",&T);
	int n;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",data+i);
		int res=0;
		for(int i=0;i<n;++i)
		{
			int j;
			for(j=i-1;j>=0;--j)
			{
				if(data[j]==data[i])
					break;
			}
			if(j>=0)
			{
				++res;
				for(int k=i;k>=j;--k)
					data[k]=0;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
*/
/*
#include<cstdio>
inline char getint(int &x)
{
     char ch=getchar();
     while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF)
         ch=getchar();
     if(ch==EOF)
       return EOF;
     bool neg=false;
     if('-'==ch)
     {
       neg=true;
       ch=getchar();
     }
     x=0;
     while('0'<=ch&&ch<='9')
     {
          x=x*10+ch-'0';
          ch=getchar();
     }     
     x=neg?-x:x;
     return ch;
}
typedef int lld;
inline lld gcd(lld a,lld b)
{
       return 0==b?a:gcd(b,a%b);
}
inline lld lcm(lld a,lld b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		getint(a);
		getint(b);
		getint(c);
		getint(d);
		int e,f=lcm(b,d);
		e=gcd(a*f/b,c*f/d);
		//printf("e f %d %d\n",e,f);
		int g=gcd(e,f);
		e=e/g;
		f=f/g;
		printf("%d/%d\n",e,f);
	}
	return 0;
}
*/
/*
#include<cstdio>
const int MAXN=55;
int mat[MAXN][MAXN];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&mat[i][j]);
		if(n<m)
		{
			bool yes=true;
			for(int i=0;i<n;++i)
			{
				for(int j=1;j<m;++j)
				{
					if(mat[i][j]!=mat[i][j-1])
					{
						yes=false;
						break;
					}
				}
				if(!yes)
					break;
			}
			printf(yes?"YES\n":"NO\n");
		}
		else if(n>m)
		{
			bool yes=true;
			for(int j=0;j<m;++j)
			{
				for(int i=1;i<n;++i)
				{
					if(mat[i][j]!=mat[i-1][j])
					{
						yes=false;
						break;
					}
				}
				if(!yes)
					break;
			}
			printf(yes?"YES\n":"NO\n");
		}
		else
		{
			bool yes=true;
			for(int i=1;i<n;++i)
			{
				for(int j=1;j<m;++j)
				{
					if(mat[i][j]+mat[i-1][j-1]!=mat[i-1][j]+mat[i][j-1])
					{
						yes=false;
						break;
					}
				}
				if(!yes)
					break;
			}
			printf(yes?"YES\n":"NO\n");
		}
	}
	return 0;
}
*/

/*
#include<cstdio>
#include<cmath>
const double eps=1e-6;
int main()
{
	int T;
	int vx,vy;
	double D,L,h,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf%d%d",&D,&L,&h,&vx,&vy);
		x=vx;
		y=vy;
		if(y<0.0)
		{
		    h=h+L/x*y;
			if(h>=0.0)
				printf("%d %d\n",vx,vy);
			else
			{
				int cnt=(int)fabs((h+eps)/D);
				//printf("cnt=%d\n",cnt);
			    //if(fabs(cnt*D-h)<eps)
					//++cnt;
				++cnt;
				if(cnt%2==0)
					printf("%d %d\n",vx,vy);
				else
					printf("%d %d\n",vx,-vy);
			}
		}
		else
		{
			h=h+L/x*y;
			if(h<=D)
				printf("%d %d\n",vx,vy);
			else
			{
				int cnt=(int)fabs((h-D-eps)/D);
				//if(fabs(cnt*D+D-h)<eps)
					//++cnt;
				//printf("cnt=%d\n",cnt);
				++cnt;
				if(cnt%2==0)
					printf("%d %d\n",vx,vy);
				else
					printf("%d %d\n",vx,-vy);
			}
		}
	}
	return 0;
}
*/
/*
#include<cstdio>
#include<cstring>
const int MAXN=110;
int hate[MAXN][2],value[MAXN];
int dp[MAXN][MAXN];
bool hasbeen[MAXN];
int dfs(int index,int value1,int value2,int &v1,int &v2)
{
	v1=value1,v2=value2;
	hasbeen[index]=true;
	if(hate[index][0]>index)
	{
		value1=dfs(hate[index][0],value2,value1+value[hate[index][0]],v1,v2);
	}
	if(hate[index][1]>index)
	{
		value2=dfs(hate[index][1],value2,value1+value[hate[index][1]],v1,v2);
	}
	return value1>value2?value1:value2;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(hate,0,sizeof(hate));
		int n,k;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&k);
			for(int j=0;j<k;++j)
				scanf("%d",&hate[i][j]);
		}
		for(int i=1;i<=n;++i)
			scanf("%d",value+i);
		memset(dp,0,sizeof(dp));
		memset(hasbeen,false,sizeof(hasbeen));
		int res=0;
		for(int i=1;i<=n;++i)
		{
			if(hasbeen[i])
				continue;
			hasbeen[i]=true;
			int v1,v2;
			res+=dfs(i,0,value[i],v1,v2);
		}
		printf("%d\n",res);
	}
	return 0;
}
*/
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
#include<cmath>
#include<queue>
#include<bitset>
using namespace std;
typedef long long lld;
inline lld gcd(lld a,lld b)
{
       return 0==b?a:gcd(b,a%b);
}
inline lld lcm(lld a,lld b)
{
	return a/gcd(a,b)*b;
}
class AllButOneDivisor
{
public: int getMinimum(vector <int> divisors)
	{
		int len=divisors.size();
		lld l[10];
		for(int i=0;i<len;++i)
		{
			lld cm=1;
			for(int j=0;j<len;++j)
			{
				if(j==i)
					continue;
				cm=lcm(cm,divisors[j]);
			}
			l[i]=cm;
		}
		int res=-1;
		for(int i=0;i<len;++i)
		{
			if(l[i]%divisors[i]!=0&&res==-1)
				res=l[i];
			else if(l[i]%divisors[i]!=0&&l[i]<res)
				res=l[i];
			else
				;
		}
		return res;
	}
};
int main()
{
	return 0;
}
*/

/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
#include<cmath>
#include<queue>
#include<bitset>
using namespace std;
struct node
{
	int need,give,det;
	bool operator<(const node &oth)const
	{
		if(det==oth.det)
			return need<oth.need;
		return det<oth.det;
	}
};
node data[100];
class CoinMachinesGame
{
public:
	int maxGames(int coins, vector <int> need, vector <int> give)
	{
		int len=need.size();
		for(int i=0;i<len;++i)
		{
			data[i].need=need[i];
			data[i].give=give[i];
			data[i].det=need[i]-give[i];
		}
		sort(data,data+len);
		int res=0;
		for(int i=0;i<len;++i)
		{
			if(coins>=data[i].need)
			{
				int t=(coins-data[i].need)/data[i].det;
				res+=t;
				coins-=t*data[i].det;
				while(coins>=data[i].need)
				{
					coins-=data[i].det;
					++res;
				}
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}
*/
/*
#include<vector>
#include<string>
using namespace std;
class ComplementMachine2D
{
public:
	int largestSubmatrix(vector <string> matrix)
	{
		int ans=0,n=matrix.size(),m=n>0?matrix[0].length():0;
		for(int i=0;i<n;++i)
		{
			for(int j=i;j<n;++j)
			{
				int last=0;
				for(int k=0;k<m;++k)
				{
					bool same=true,diff=true;
					for(int p=i;p<=j;++p)
					{
						if(matrix[p][k]!=matrix[p][last])
							same=false;
						else
							diff=false;
					}
					if(same||diff)
					{
						if((j-i+1)*(k-last+1)>ans)
							ans=(j-i+1)*(k-last+1);
					}
					else
						last=k;
				}
			}
		}
		return ans;
	}
};

int main()
{
	return 0;
}
*/
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef __int64 lld;
int main()
{
	int T;
	while(EOF!=scanf("%d",&T))
	{
		for(int test=1;test<=T;++test)
		{
			lld n,m;
			scanf("%I64d%I64d",&n,&m);
			if(1==n)
			{
			printf("Case %d:\n",test);
			printf("%d\n",(int)m);
				continue;
			}
			lld mid=(n&0x01)?(n-1)/2:n/2;
			lld up=mid*mid/n+1,res=0;
			if(up>=m)
			{
				res=(lld)sqrt(((m-1)*n)*1.0);
				if(res*res<(m-1)*n)
					++res;
			}
			else
			{
				res=m+mid-up;
			}
			printf("Case %d:\n",test);
			printf("%d\n",res);
		}
	}
	return 0;
}
*/
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int GCD_depth( int x , int y ) {
        if ( y == 0 ) return 0;
        else return GCD_depth( y , x%y ) + 1;
}
int x,d,y00,y11;
const int maxn=200010;
int depth[maxn],dd[50];
int main()
{
	while(EOF!=scanf("%d%d%d%d",&x,&d,&y00,&y11))
	{
		memset(dd,0,sizeof(dd));
		if(0==x)
		{
			dd[0]=1;
			if(y11>0)
			{
				y00=max(y00,1);
				dd[1]=y11-y00+1;
			}
			printf("%d\n",dd[d]);
		}
		for(int i=0;i<=x;++i)
			depth[i]=GCD_depth(x,i);
		for(int i=y00;i<=min(x,y11);++i)
		    if(depth[i]<40)
			++dd[depth[i]];
		int s=max(x+1,y00);
		if(s<=y11)
		{
			int turn=(y11-s+1)/x,rem=(y11-s+1)%x;
			for(int i=0;i<x;++i)
				if(depth[i]+2<40)
				dd[depth[i]+2]+=turn;
			for(int i=s;i<s+rem;++i)
				if(depth[i%x]+2<40)
				++dd[depth[i%x]+2];
		}
		printf("%d\n",dd[d]);
	}
	return 0;
}
*/
/*
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<iterator>
using namespace std;
typedef __int64 T;
//template<typename T>
inline T pow_mod(T a,T n,T p)
{
	T res=1%p,half=a%p;
	while(n>0)
	{
		if(n&0x01)
			res=res*half%p;
		half=half*half%p;
		n>>=1;
	}
	return res;
}
//template<typename T>
	struct node
	{
		T i,value;
		node(T ii=0,T vv=0)
		{
			i=ii;value=vv;
		}
		bool operator<(const node &oth)const
		{
			return value<oth.value; 
		}
	};
//a=g^y (mod p),known a,g,p,return min y,p is a prime number. O(sqrt(p)*log(p))
//template<typename T>
T babystep(T a,T g,T p)
{
	a=a%p;
	T m=(T)ceil(sqrt((double)p)+0.1),gm=pow_mod(g,m,p);
	//printf("g=%I64d m=%I64d p=%I64d gm=%I64d\n",g,m,p,gm);
	vector<node> left((size_t)m),right((size_t)m);
	left[0]=node(1,gm),right[0]=node(1,a*g%p);
	//left[0].i=right[0].i=1;
	//left[0].value=gm,right[0].value=a*g%p;
	for(T k=1;k<m;++k)
	{
		left[(int)k].i=right[(int)k].i=k+1;
		left[(int)k].value=left[(int)(k-1)].value*gm%p;
		right[(int)k].value=right[(int)(k-1)].value*g%p;
	}
	sort(right.begin(),right.end());
	//for(int k=0;k<m;++k)
	//{
	//	printf("%I64d  %I64d  %I64d   %I64d\n",left[k].i,left[k].value,right[k].i,right[k].value);
	//}
	//printf("m=%I64d\n",m);
	T i=0,j=0;
	for(vector<node>::iterator it=left.begin();it!=left.end();++it)
	{
		vector<node>::iterator yy=lower_bound(right.begin(),right.end(),*it);
		if(yy!=right.end()&&yy->value==it->value)
		{
			i=it->i;j=yy->i;
			//printf("i=%I64d j=%I64d\n",i,j);
			break;
		}
	}
	return (i*m-j)%(p-1);
}

template<typename lld>
inline lld mod(lld x,lld y)
{
       return x>0?x%y:(y-(-x)%y)%y;
}

//通过值d,x,y返回答案
template<typename lld>
inline void exgcd(lld a,lld b,lld &d,lld &x,lld &y)
{
       if(0==b)
       {
           d=a,x=1,y=0;
           return;
       }
       exgcd(b,a%b,d,x,y);
       lld t=y;
       y=x-a/b*y;
       x=t;
}


template<typename lld>
inline void modliner(lld a,lld b,lld n,lld &xmin,lld &step,lld &d)
{
       lld x,y;
       exgcd(a,n,d,x,y);
       if(b%d==0)
       {
           step=n/d;
           xmin=(x*(b/d));
           xmin=mod(xmin,step);
       }
       else
         xmin=-1;
}
struct A;
//struct B;

struct B
{
	A * tmp;

	A dosth();
};

struct A
{
	B * tmp;

	B dosth();
};

A B::dosth()
{
	return A();
}

B A::dosth()
{
	return B();
}
typedef __int64 lld;
int main()
{
	int T;
	while(EOF!=scanf("%d",&T))
	{
		for(int test=0;test<T;++test)
		{
			lld p,h,g,a,b;
			scanf("%I64d%I64d%I64d%I64d%I64d",&p,&h,&g,&a,&b);
			lld y=babystep(a,g,p);
			if(a%p!=pow_mod(g,y,p))
			{
				printf("babystep wrong\n");
			}
			lld s=pow_mod(h,y,p);
			lld m,step,d;
			modliner<lld>(s,b,p,m,step,d);
			printf("%I64d\n",m);
		}
	}
	return 0;
}
*/
/*
#include<cstdio>
#include<algorithm>
using namespace std;
inline int mod(int a,int b)
{
	if(0==b)return 0;
	if(a>0)return a%b;
	return (b-(-a)%b)%b;
}
inline int gcd(int a,int b)
{
	return 0==b?a:gcd(b,a%b);
}
struct point
{
	int x,y,z;
	int hx,hy,hz;
};
int vx,vy,vz;
inline bool cmp1(const point &a,const point &b)
{
	if(a.hx!=b.hx)
		return a.x<b.x;
	if(a.hy!=b.hy)
		return a.hy<b.hy;
	if(a.hz!=b.hz)
		return a.hz<b.hz;
	if(vx<0&&a.x!=b.x)
		return a.x>b.x;
	if(vx>0&&a.x!=b.x)
		return a.x<b.x;
	if(vy<0&&a.y!=b.y)
		return a.y>b.y;
	if(vy>0&&a.y!=b.y)
		return a.y<b.y;
	if(vz<0&&a.z!=b.z)
		return a.z>b.z;
	if(vz>0&&a.z!=b.z)
		return a.z<b.z;
	return false;
}
inline bool cmp2(const point &a,const point &b)
{
	if(a.hx!=b.hx)
		return a.x<b.x;
	if(a.hy!=b.hy)
		return a.hy<b.hy;
	if(a.hz!=b.hz)
		return a.hz<b.hz;
	return false;
}
const int maxn=10010;
point sol[maxn],man[maxn];
int main()
{
	int T;
	while(EOF!=scanf("%d",&T))
	{
		for(int test=1;test<=T;++test)
		{
			int n,m;
			scanf("%d%d",&n,&m);
			for(int i=0;i<n;++i)
				scanf("%d%d%d",&sol[i].x,&sol[i].y,&sol[i].z);
			for(int i=0;i<m;++i)
				scanf("%d%d%d",&man[i].x,&man[i].y,&man[i].z);
			scanf("%d%d%d",&vx,&vy,&vz);
			int xx=vx>0?vx:-vx,yy=vy>0?vy:-vy,zz=vz>0?vz:-vz;
			int g=gcd(xx,gcd(yy,zz));
			xx/=g,yy/=g,zz/=g;
			for(int i=0;i<n;++i)
			{
				sol[i].hx=mod(sol[i].x,xx);
				sol[i].hy=mod(sol[i].y,yy);
				sol[i].hz=mod(sol[i].z,zz);
			}
			for(int i=0;i<m;++i)
			{
				man[i].hx=mod(man[i].x,xx);
				man[i].hy=mod(man[i].y,yy);
				man[i].hz=mod(man[i].z,zz);
			}
			//sort(sol,sol+n,cmp2);
			sort(man,man+m,cmp1);
			int cnt=0;
			for(int i=0;i<n;++i)
			{
				int ind=lower_bound(man,man+m,sol[i],cmp2)-man;
				while(ind<m&&man[ind].hx==sol[i].hx&&man[ind].hy==sol[i].hy&&man[ind].hz==sol[i].hz)
				{
				int m=0;
				if(vx!=0)
					m=(sol[i].x-man[ind].x)/vx;
				else if(vy!=0)
					m=(sol[i].y-man[ind].y)/vy;
				else
					m=(sol[i].z-man[ind].z)/vz;
				if(m>=0&&man[ind].x+m*vx==sol[i].x&&man[ind].y+m*vy==sol[i].y&&man[ind].z+m*vz==sol[i].z)
				{
					++cnt;
					break;
				}
				++ind;
				break;
				}
			}
			printf("Case %d: %d\n",test,cnt);
		}
	}
	return 0;
}
*/
/*
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=20010,sol=1,man=2;
int vx,vy,vz;
const double eps=1e-8;
struct point
{
	int x,y,z;
	double hx,hy,hz;
	int level;
	void get()
	{
		if(vx!=0)
		{
			double det=(double)x/(double)vx;
			hx=(double)x-det*vx;
			hy=(double)y-det*vy;
			hz=(double)z-det*vz;
		}
		else if(vy!=0)
		{
			double det=(double)y/(double)vy;
			hx=(double)x-det*vx;
			hy=(double)y-det*vy;
			hz=(double)z-det*vz;
		}
		else
		{
			double det=(double)z/(double)vz;
			hx=(double)x-det*vx;
			hy=(double)y-det*vy;
			hz=(double)z-det*vz;
		}
	}
	bool operator<(const point &oth)const
	{
		if(fabs(hx-oth.hx)>eps)
			return hx<oth.hx;
		if(fabs(hy-oth.hy)>eps)
			return hy<oth.hy;
		if(fabs(hz-oth.hz)>eps)
			return hz<oth.hz;
		if(vx>0&&x!=oth.x)
			return x<oth.x;
		if(vx<0&&x!=oth.x)
			return x>oth.x;
		if(vy>0&&y!=oth.y)
			return y<oth.y;
		if(vy<0&&y!=oth.y)
			return y>oth.y;
		if(vz>0&&z!=oth.z)
			return z<oth.z;
		if(vz<0&&z!=oth.z)
			return z>oth.z;
		if(level!=oth.level)
			return level==man;
		return false;
	}
};
point data[maxn];
int main()
{
	int T;
	while(EOF!=scanf("%d",&T))
	{
		for(int test=1;test<=T;++test)
		{
			int n,m;
			scanf("%d%d",&n,&m);
			for(int i=0;i<n;++i)
			{
				scanf("%d%d%d",&data[i].x,&data[i].y,&data[i].z);
				data[i].level=sol;
			}
			for(int i=n;i<n+m;++i)
			{
				scanf("%d%d%d",&data[i].x,&data[i].y,&data[i].z);
				data[i].level=man;				
			}
			scanf("%d%d%d",&vx,&vy,&vz);
			for(int i=0;i<n+m;++i)
				data[i].get();
			sort(data,data+n+m);
			int pre=0;
			while(pre<n&&data[pre].level==sol)
				++pre;
			int cnt=0;
			for(int i=pre+1;i<n+m;++i)
			{
				if(data[i].level==man)
					pre=i;
				else
				{
					if(fabs(data[i].hx-data[pre].hx)<eps&&fabs(data[i].hy-data[pre].hy)<eps&&fabs(data[i].hz-data[pre].hz)<eps)
						++cnt;
				}
			}
			printf("Case %d: %d\n",test,cnt);
		}
	}
	return 0;
}
*/

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1100;
struct node
{
	double b,e,w;
	bool operator<(const node &oth)const
	{
		return w<oth.w;
	}
};
node data[maxn];
//double b[maxn],e[maxn],w[maxn];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("Alarge.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;++test)
	{
		double x,s,r,t;
		int n;
		scanf("%lf%lf%lf%lf%d",&x,&s,&r,&t,&n);
		for(int i=0;i<n;++i)
			scanf("%lf%lf%lf",&data[i].b,&data[i].e,&data[i].w);
		double res=0.0,walk=x;
		for(int i=0;i<n;++i)
			walk=walk-(data[i].e-data[i].b);
		sort(data,data+n);
		if(t*r<walk)
		{
			res=res+t+(walk-t*r)/s;
			t=0;
		}
		else
		{
			res+=walk/r;
			t=t-walk/r;
		}
		for(int i=0;i<n;++i)
		{
			double need=(data[i].e-data[i].b)/(data[i].w+r);
			if(need<=t)
			{
				res+=need;
				t-=need;
			}
			else
			{
			    double dis=(data[i].e-data[i].b)-(data[i].w+r)*t;
				res+=t;
				res=res+dis/(data[i].w+s);
				t=0;
			}
		}
		printf("Case #%d: %.8lf\n",test,res);
	}
	return 0;
}
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=550;
int mat[maxn][maxn];
char str[maxn][maxn];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("Bsmall.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;++test)
	{
	int R,C,D;
	scanf("%d%d%d",&R,&C,&D);
	for(int i=0;i<R;++i)
		scanf("%s",&str[i][0]);
	for(int i=0;i<R;++i)
	{
		for(int j=0;j<C;++j)
			mat[i][j]=str[i][j]-'0';
	}
	int mysize=0;
	bool hasans=false;
	for(mysize=min(R,C);mysize>=3;--mysize)
	{
		for(int up=0;up+mysize-1<R;++up)
		{
			for(int left=0;left+mysize-1<C;++left)
			{
				int down=up+mysize-1,right=left+mysize-1;
				double midx=(up+down)*1.0/2.0,midy=(left+right)*1.0/2.0;
				double resx=0.0,resy=0.0;
				for(int x=up;x<=down;++x)
				{
					for(int y=left;y<=right;++y)
					{
						if(x==up&&y==left)
							continue;
						if(x==up&&y==right)
							continue;
						if(x==down&&y==left)
							continue;
						if(x==down&&y==right)
							continue;
						resx+=(x-midx)*mat[x][y];
						resy+=(y-midy)*mat[x][y];
					}
				}
				if(fabs(resx)<1e-6&&fabs(resy)<1e-6)
				{
					hasans=true;
					break;
				}
			}
			if(hasans)
				break;
		}
		if(hasans)
			break;
	}
	if(!hasans)
	{
		printf("Case #%d: IMPOSSIBLE\n",test);
	}
	else
	{
        printf("Case #%d: %d\n",test,mysize);
	}
	}
	return 0;
}