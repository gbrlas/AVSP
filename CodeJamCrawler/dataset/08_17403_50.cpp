#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define fo(i,n) for(i=0;i<(n);++i) 
#define CL(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
typedef vector<int> vi ; 
typedef vector<string> vs ;

FILE *in = fopen("test1.in","r");
FILE *out= fopen("test.out","w");

string readline()
{
	char ch;
	string ret;

	while(fscanf(in,"%c",&ch)!=EOF)
	{
		if(ch=='\n') return ret;
		ret+=ch;
	}

	return ret;
}




int n,qnum;
map<string,int> p;
vi q;
int best[110][1010];

int solve(int pos, int turn)
{
	if(turn==q.size())
		return 0;

	int &ret=best[pos][turn];
	if(ret!=-1) return ret;
	ret=inf;
	int cur,i;

	if(pos!=q[turn])
		return ret = solve(pos,turn+1);

	fo(i,n)
		if(i!=pos)
		{
			cur= 1+solve(i,turn+1);
			if(cur<ret) ret=cur;
		}

	return ret;
}

int main()
{
	int i,z,tests,cur,ret;
	string str;
	str=readline();
	sscanf(str.c_str(),"%d",&tests);

	fo(z,tests)
	{
		p.clear();
		q.clear();

		str=readline();
		sscanf(str.c_str(),"%d",&n);
		fo(i,n)
		{
			str=readline();
			p[str]=i;
		}

		str=readline();
		sscanf(str.c_str(),"%d",&qnum);
		fo(i,qnum)
		{
			str=readline();
			q.push_back(p[str]);
		}

		fprintf(out,"Case #%d: ",z+1);
		ret=1000000;
		CL(best,-1);

		if(qnum<=1)
		{
			ret=0;
		}

		else
		{
			fo(i,n)
			if(i!=q[0])
			{
				cur=solve(i,1);
				if(cur<ret)
					ret=cur;
			}
		}

		fprintf(out,"%d\n",ret);
	}

	return 0;
}

