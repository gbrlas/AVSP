#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	freopen("B-small.in","r",stdin);
	freopen("result.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=0;z<T;z++)
	{
		int N,K,B,t;
		bool possible[100];
		memset(possible,0,100);
		vector<int> X,XCopy;
		vector<int> V;
		scanf("%d%d%d%d",&N,&K,&B,&t);
		for(int i=0;i<N;i++)
		{
			int a;
			scanf("%d",&a);
			X.push_back(a);
			XCopy.push_back(a);
		}
		for(int i=0;i<N;i++)
		{
			int a;
			scanf("%d",&a);
			V.push_back(a);
		}
		if(K==0)
		{
			printf("Case #%d: 0\n",z+1);
			continue;
		}

		for(int i=0;i<X.size();i++)
		{
			if(V[i]*t<B-X[i])
			{
				X.erase(X.begin()+i);
				V.erase(V.begin()+i);
				i--;
			}
		}
		bool impossible = false;
		int kst = 0;
		if(X.size()<K)
			printf("Case #%d: IMPOSSIBLE\n",z+1);
		else
		{
			int p = 0;
			for(int i=0;i<XCopy.size();i++)
				if(XCopy[i] == X[X.size()-K])
				{
					p = i;
					break;
				}
			X.push_back(0);
			int away = 0;
			int p1 = X.size()-K-1;
			for(int i=p;i<XCopy.size();i++)
				if(X[p1]!=XCopy[i])
				{
					kst += i - p;
					XCopy.erase(XCopy.begin()+i);
					i--;
	
				}
				else
					p1++;
			printf("Case #%d: %d\n",z+1,kst);
		}		
	}
	return 0;
}