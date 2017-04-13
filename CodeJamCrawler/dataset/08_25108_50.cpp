#pragma warning (disable:4786)
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main()
{
	int S,Q;
	int pk,j;
//	freopen("A.txt","r",stdin);
	freopen("A-small-attempt1.in.txt","r",stdin);
	freopen("A-small.txt","w",stdout);
	scanf("%d\n",&pk);
	for(j=1;j<=pk;j++)
	{
		
		int i;
		char str[256];
		set<string> ss;
		map<string,bool> sb;
		vector<string> vs;
		scanf("%d\n",&S);
		
		for(i=0;i<S;i++)
		{
			gets(str);
			ss.insert(str);
		}
		scanf("%d\n",&Q);
		for(i=0;i<Q;i++)
		{
			gets(str);
			vs.push_back(str);
		}
		int sw=0;
		int count=0;
		for(i=0;i<Q;i++)
		{
			
			if(ss.find(vs[i])!=ss.end())
			{
				if(sb[vs[i]]==0)
				{
					sb[vs[i]]=1;
					count++;
				}
				if(count==S)
				{
					sw++;
					sb.clear();
					sb[vs[i]]=1;
					count=1;
				}
			}
		}
		printf("Case #%d: %d\n",j,sw);
	}
	return 0;
}
