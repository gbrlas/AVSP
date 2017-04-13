
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct ss
{
	int B;
	int E;
	int w;
};
bool cmp(struct ss s1,struct ss s2)
{
	return s1.w<s2.w;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-ans-small.txt","w",stdout);

	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		struct ss s[1001];
		int X,S,R,t,N;
		cin>>X>>S>>R>>t>>N;
		int all=0;
		for(int j=1;j<=N;j++)
		{
			cin>>s[j].B>>s[j].E>>s[j].w;
			all+=s[j].E-s[j].B;
		}
		s[0].B=0;
		s[0].E=X-all;
		s[0].w=0;
		sort(s,s+N+1,cmp);
		//cout<<s[0].w<<s[1].w<<s[2].w;
		double ans=0;
		int j;
		//for(j=N;j>=0;j--)
		//{
			//if(s[j].w>=R)
			//{
				//ans+=(s[j].E-s[j].B)/(s[j].w*1.0);
			//}
			//else
				//break;
		//}
		double left=t;
		for(int k=0;k<=N;k++)
		{
			if(left*(R+s[k].w)>=s[k].E-s[k].B)
			{
				ans+=(s[k].E-s[k].B)/((R+s[k].w)*1.0);
				left-=(s[k].E-s[k].B)/((R+s[k].w)*1.0);
			}
			else
			{
				ans+=left+(s[k].E-s[k].B-left*(R+s[k].w))/((s[k].w+S)*1.0);
				left=0;

			}
		}
		cout<<"Case #"<<i<<": ";
		printf("%.8lf\n",ans);
		
	}

	fclose(stdin);
	fclose(stdout);
}