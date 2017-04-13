#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <bitset>
#include <ctime>
#include <climits>
using namespace std;

#define maxn 1010
#define inf 1000000000

int record[maxn];
int dis[maxn];
int result,l,t,nStars,c,cnt,sum,lla;

int test1(int data)
{
	data = data*2+1;
	return data;
}

int extreme1(int numerous)
{
	numerous = numerous*3+5;
	return numerous;
}

int main ()
{
	int i,j,k,loop;

	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small.out","w",stdout);

	int test,cases;

	scanf("%d",&test);
	for(cases = 1;cases<=test;cases++)
	{
		int tmpChar,tmpAns,numRemain;
		memset(record,0,sizeof(record));
		cnt=0;
		printf("Case #%d: ",cases);
		scanf("%d %d %d %d",&l,&t,&nStars,&c);
		for(i=0;i<c;i++)
		{
			scanf("%d",record+i);
		}

		for(i=0;i<nStars;i++)
		{
			test1(i);
			dis[i]=record[cnt++];
			if(cnt==c)cnt=0;
		}
		if(l==0)
		{
			sum=0;
			for(i=0;i<nStars;i++)
			{
				test1(i);
				tmpAns = 0;
				for (j=1;j<3;j++)
				{
					tmpAns += extreme1(i);
				}
				sum+=dis[i];
			}
			printf("%d\n",sum*2);
			continue;
		}
		tmpChar = inf;
		if(l==1)
		{
			for(i=0;i<nStars;i++)
			{
				test1(i);
				tmpAns = 0;
				for (j=1;j<3;j++)
				{
					tmpAns += extreme1(i);
				}
				result=0;
				for(k=0;k<nStars;k++)
				{
					if(k==i)
					{
						if(result>=t)
						{
							result+=dis[k];
							tmpAns = result;
						}
						else
						{
							tmpAns = 0;
							for (j=1;j<3;j++)
							{
								tmpAns += extreme1(i);
							}
							if(result+dis[k]*2<=t)
							{
								result+=dis[k]*2;
								tmpAns = result;
							}
							else
							{
								test1(i);
								tmpAns = 0;
								for (j=1;j<3;j++)
								{
									tmpAns += test1(i);
								}
								numRemain=t-result;
								result=t;
								tmpAns = result;
								result+=(dis[k]-numRemain*0.5);
							}
						}
					}
					else
					{
						result+=dis[k]*2;
					}
				}
				tmpChar=min(result,tmpChar);
			}
			printf("%d\n",tmpChar);
			lla = tmpChar;
			continue;
		}
		if(l==2)
		{
			for(i=0;i<nStars;i++)
			{
				for(j=i+1;j<nStars;j++)
				{
					tmpAns = 0;
					for (loop=1;loop<13;loop++)
					{
						tmpAns += test1(loop);
					}
					result=0;
					for(k=0;k<nStars;k++)
					{
						if(k==i||k==j)
						{
							if(result>=t)
							{
								result+=dis[k];
								tmpAns = result;
							}
							else
							{
								if(result+dis[k]*2<=t)
								{
									result+=dis[k]*2;
									tmpAns = result;
									for (loop=1;loop<13;loop++)
									{
										tmpAns += test1(loop);
									}
								}
								else
								{
									numRemain=t-result;
									result=t;
									tmpAns = result;
									result+=(dis[k]-numRemain*0.5);
									for (loop=1;loop<13;loop++)
									{
										tmpAns += test1(loop);
									}
								}
							}
						}
						else 
						{
							result+=dis[k]*2;
							for (loop=1;loop<13;loop++)
							{
								tmpAns += test1(loop);
							}
						}
					}
					tmpChar=min(tmpChar,result);
					tmpAns = tmpChar;
				}
			}
		}
		tmpAns = tmpChar;
		//tmpAns = tmpChar;
		printf("%d\n",tmpChar);
	}
}