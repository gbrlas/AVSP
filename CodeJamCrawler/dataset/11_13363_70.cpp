#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;

char go[26][26];
bool del[26][26];

int main()
{
	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		for(int i=0;i<26;i++)
			for(int j=0;j<26;j++)
			{
				go[i][j]=0;
				del[i][j]=false;
			}
		int C;
		cin>>C;
		for(int i=0;i<C;i++)
		{
			string s;
			cin>>s;
			go[s[0]-'A'][s[1]-'A']=s[2];
			go[s[1]-'A'][s[0]-'A']=s[2];
		}
		int D;
		cin>>D;
		for(int i=0;i<D;i++)
		{
			string s;
			cin>>s;
			del[s[0]-'A'][s[1]-'A']=true;
			del[s[1]-'A'][s[0]-'A']=true;
		}
		int N;
		cin>>N;
		string r,s;
		cin>>s;
		r="";
		for(int i=0;i<N;i++)
		{
			r+=s[i];
			if (r.length()<2) continue;
			char x = go[r[r.length()-1]-'A'][r[r.length()-2]-'A'];
			if (x)
				r = r.substr(0,r.length()-2)+x;
			else
			{
				int j;
				for(j=0;j<r.length()-1;j++)
					if (del[r[j]-'A'][r[r.length()-1]-'A'])
					{
						r="";
						break;
					}
			}
		}
		printf("Case #%d: [",test_num+1);
		for(int i=0;i<int(r.length())-1;i++)
			printf("%c, ",r[i]);
		if (r.length()>0)
			printf("%c",r[r.length()-1]);
		printf("]\n");
	}

	return 0;
}