#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <functional>
#include <math.h>
#include <assert.h>
using namespace std;
typedef pair<int,int> pii;
typedef __int64 ll;
#define MP(X,Y) make_pair(X,Y)
#define two(X) (1<<(X))//NOTES:two(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int)(x).size())
template<class T> inline T sqr(T x){return x*x;}
const double eps=1e-6;
const int maxn=1000+5;
int g[maxn];
int lable[maxn];
int sum[maxn];
int belong[maxn];
int next[maxn];
int R,K,n;
void main()
{
	int t,caseid,i,j;
//	ifstream fin("C.in");
//	ifstream fin("C-small-attempt4.in");
//	ifstream fin("C-small-attempt1.in");
	ifstream fin("C-large.in");
	FILE* pout=fopen("C.out","w");
	FILE* pTest=fopen("test.out","w");
	fin>>t;
    for (caseid=1;caseid<=t;caseid++)
    {
		fin>>R>>K>>n;
		memset(sum,0,sizeof(sum));
		memset(lable,0,sizeof(lable));
		for (i=0;i<n;i++)
		{
			fin>>g[i];
		}
		int s=0;
	    i=0;
		lable[0]=1;
		belong[0]=0;
		int flag=0;
		while (1)
		{
			if (sum[s]+g[i]<=K)
			{
				sum[s]+=g[i];
				i=(i+1)%n;
				if(!i&&!flag) 
				{
					assert(s==0);
					s=1;break;
				}
			}
			else
			{
				s++;
				if (lable[i]==0)
				{
					lable[i]++;
					belong[i]=s;
				}
				else
				{
					break;
				}
				flag=1;
			}
		}
		next[s-1]=belong[i];
		for (i=0;i<s-1;i++)
		{
			next[i]=i+1;
		}
		ll ans=0;
		int cnt=0;
		i=0;
		while (cnt<R)
		{
			ans+=sum[i];
			i=next[i];
			cnt++;
		}
//		fprintf(pTest,"s%d q%d r%d\n",s,a,b);
		fprintf(pout,"Case #%d: %I64d\n",caseid,ans);
    }
	fin.close();
	fclose(pout);
}

