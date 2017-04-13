#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,times,re,ma,t,now,all;
string s[1000],str;
inline int check(const string& s1,const string& s2)
{
	int p=1;
	int total=0;
	while ((p<s1.size())&&(p<s2.size()))
	{
		if (s1[p]!=s2[p]) return total;
		if (s1[p]=='/') total++;
		++p;
	}
	return total;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		scanf("%d%d",&n,&m);
		for (int a=1;a<=n;++a)
		{
			cin>>s[a];
			s[a]+='/';
		}
		s[0]="/";
		re=0;
		for (int a=1;a<=m;++a)
		{
			cin>>str;
			str+='/';
			all=0;
			ma=0;
			for (int b=1;b<str.size();++b) if (str[b]=='/') all++;
			for (int b=0;b<=n;++b)
			{
				t=check(str,s[b]);
				ma=max(ma,t);
			}
			if (ma<all)
			re+=all-ma;
	//		printf("[%d,%d,%d]",ma,all,re);
			n++;
			s[n]=str;
		}
		printf("Case #%d: ",z);
		printf("%d\n",re);
	}
}
